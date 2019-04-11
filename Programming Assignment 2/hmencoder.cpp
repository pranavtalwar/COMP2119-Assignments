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
  map<char, node>::iterator itr;
  for(itr=Dictionary.begin();itr!=Dictionary.end();itr++)
  {
    cout<<(*itr).first<<" : "<<(*itr).second.getFrequency()<<endl;
  }
  return 0;
}
