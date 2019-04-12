#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<map>
#include<iterator>
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
  void setCode(string code){
    this->code = code;
  }
  void setFrequency(int frequency){
    this->frequency = frequency;
  }
  string getCode(){
    return this->code;
  }
  int getFrequency(){
    return this->frequency;
  }
  void increaseFrequency(){
    this->frequency++;
  }
  void addCode(string addString){
    this->code = addString + this->code;
  }
};


bool compare(const Node a, const Node b){
  if(a.getFrequency() == b.getFrequency()){
    if(a.getCode().length() == b.getCode().length()){
      int asciisum1 = 0, asciisum2 = 0;
      for(int i=0;i<a.getCode().length();i++){
        asciisum1+=a.getCode()[i];
      }
      for(int i=0;i<b.getCode().length();i++){
        asciisum2+=b.getCode()[i];
      }
      return asciisum1 > asciisum2;
    }
    return a.getCode().length() < b.getCode().length();
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
  while(Tree.size() > 1){

  }
  return 0;
}
