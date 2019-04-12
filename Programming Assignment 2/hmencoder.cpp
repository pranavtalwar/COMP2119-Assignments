#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<iomanip>
using namespace std;
class node{
private:
  string code;
  int frequency;
public:
  node(){
    code = "";
    frequency = 1;
  }
  void setCode (string code){
    this->code = code;
  }
  void setFrequency (int frequency){
    this->frequency = frequency;
  }
  string getCode() const{
    return this->code;
  }
  int getFrequency() const {
    return this->frequency;
  }
  void increaseFrequency(){
    this->frequency++;
  }
  void addCode(string addString) {
    this->code = addString + this->code;
  }
};


bool compare(const node &a, const node &b){
  if(a.getFrequency() == b.getFrequency()){
      int asciimin1 = a.getCode()[0], asciimin2 = b.getCode()[0];
      for(int i=1;i<a.getCode().length();i++){
        if(asciimin1>=a.getCode()[i]){
          asciimin1 = a.getCode()[i];
        }
      }
      for(int i=1;i<b.getCode().length();i++){
        if(asciimin2>=b.getCode()[i]){
          asciimin2 = b.getCode()[i];
        }
      }
      return asciimin1 < asciimin2;
  }
  return a.getFrequency() < b.getFrequency();
}
int main(int argc, char** argv) {
  string filecontent;
  string sentence;
  ifstream ifile;
  string filetoread = argv[1];
  ofstream ofile1, ofile2;
  ofile1.open("code.txt");
  ofile2.open("encodemsg.txt");
  ifile.open(filetoread);
  while(getline(ifile,sentence)){
    filecontent+=sentence;
  }
  ifile.close();
  map<char, node> Dictionary;
  for(int i=0;i<filecontent.length();i++){
    if(Dictionary.find(filecontent[i])==Dictionary.end()){
      node newnode;
      Dictionary[filecontent[i]] = newnode;
    }
    else{
      Dictionary[filecontent[i]].increaseFrequency();
    }
  }
  map<char, node>::iterator mapitr;
  vector<node> Tree;
  vector<node>:: iterator vecitr;
  for(mapitr=Dictionary.begin();mapitr!=Dictionary.end();mapitr++){
    node newnode;
    string s;
    s.push_back((*mapitr).first);
    newnode.setCode(s);
    newnode.setFrequency((*mapitr).second.getFrequency());
    Tree.push_back(newnode);
  }
  sort(Tree.begin(), Tree.end(), compare);
  while(Tree.size() > 1){
    sort(Tree.begin(), Tree.end(), compare);
    int newFreq = Tree[0].getFrequency() + Tree[1].getFrequency();
    string newCode;
    string left = Tree[0].getCode(), right = Tree[1].getCode();
    int ascii1 = left[0], ascii2 = right[0];
    for(int i=1;i<left.length();i++){
      if(ascii1>left[i]){
        ascii1 = left[i];
      }
    }
    for(int i=1;i<right.length();i++){
      if(ascii2>right[i]){
        ascii2 = right[i];
      }
    }
    if(ascii1>ascii2){
      string mid;
      mid = left;
      left = right;
      right = mid;
    }
    newCode = left + right;
    node newnode;
    newnode.setCode(newCode);
    newnode.setFrequency(newFreq);
    Tree.push_back(newnode);
    for(int i=0;i<left.length();i++){
      Dictionary[left[i]].addCode("0");
    }
    for(int j=0;j<right.length();j++){
      Dictionary[right[j]].addCode("1");
    }
    Tree.erase(Tree.begin(),Tree.begin()+2);
  }
  string Huffmanstring = "";
  float bitsused = 0;
  for(int i=0;i<filecontent.length();i++){
    Huffmanstring+=Dictionary[filecontent[i]].getCode();
    bitsused+=Dictionary[filecontent[i]].getCode().length();
  }
  int counter = 0;
  for(int i = 0 ; i< Huffmanstring.length() ; i++)
  {
      ofile2<<Huffmanstring[i];
      counter++;
      if(counter == 80)
      {
          ofile2<<endl;
          counter=0;
      }
  }
  for(mapitr=Dictionary.begin();mapitr!=Dictionary.end();mapitr++)
   {
       string name;
       string hmcodes;
       name = (*mapitr).first;
       if(name==" ")
       {
           name = "Space";
       }
       hmcodes = (*mapitr).second.getCode();
       ofile1<<name<<": "<<hmcodes<<endl;
   }
  ofile1<<"Ave = "<<setprecision(3)<<bitsused/filecontent.length()<<" bits per symbol";
  ofile2.close();
  ofile1.close();
  return 0;
}
