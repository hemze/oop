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
  int i;
  ifstream inFile;
  ofstream outFile;
  
  cout << "Input file name: "; cin >> inFileName;
  cout << "Output file name: "; cin >> outFileName;  

  inFile.open(inFileName,fstream::in);
  outFile.open(outFileName,fstream::app);
  while(!inFile.eof()){
    getline(inFile,curr,'.');
    curr+=".\n";
    //temp = curr;
    /*while (i != string::npos){
      curr.replace(i, 1, ".\n");
      i = curr.find(".", i);
    }*/
    outFile.write(curr.c_str(),curr.size());
  }
  inFile.close();
  outFile.close();

  system("PAUSE");
  return EXIT_SUCCESS;
}
