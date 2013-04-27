#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
  char inFileName[20],outFileName[20];
  string curr;
  string temp;
  int i = 0;
  ifstream inFile;
  ofstream outFile;
  
  cout << "Input file name: "; cin >> inFileName;
  cout << "Output file name: "; cin >> outFileName;
  inFile.open(inFileName,fstream::in);
  if(!std::ifstream(inFileName)){
    cout << "No such file: \"" << inFileName << "\"" << endl;
    return 1;
  }
  outFile.open(outFileName,fstream::app);
  while(!inFile.eof()){
    getline(inFile,curr,'.');
    curr += ".\n";
    if(curr[0]==' '){
      curr = curr.substr(1,curr.length()-1);
    }
    while ((i = curr.find("  ", 0)) > 0){
      cout << i << endl << curr << endl;
      sleep(2);
      curr.replace(i, 2, " ");
      ;
    }
    outFile.write(curr.c_str(),curr.length());
  }
  cout << "Wrote to \"" << outFileName << "\"" << endl;
  inFile.close();
  outFile.close();
  return 0;
}
