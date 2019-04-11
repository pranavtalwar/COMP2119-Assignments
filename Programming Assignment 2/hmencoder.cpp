#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<map>
using namespace std;
class node{
private:
  string code;
  
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

  return 0;
}
