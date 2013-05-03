#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class corrector{

  ifstream inFile;
  ofstream outFile;
public:
  corrector(char * inFileName)
  {
    string curr;
    int i = 0;
    char outFileName[20] = "../data/data.out";
    this->inFile.open(inFileName,fstream::in);
    if(!std::ifstream(inFileName)){
      cout << "No such file: \"" << inFileName << "\"" << endl;
    } else {
      this->outFile.open(outFileName,fstream::app);
      while(!this->inFile.eof()){
	getline(this->inFile,curr,'.');
	curr += ".\n";
	if(curr[0]==' '){
	  curr = curr.substr(1,curr.length()-1);
	}
	while ((i = curr.find("  ", 0)) > 0){
	  curr.replace(i, 2, " ");
	}
	this->outFile.write(curr.c_str(),curr.length());
      }
      cout << "Wrote to \"" << outFileName << "\"" << endl;
    }
    this->inFile.close();
    this->outFile.close();
  }
};

int main(){
  char inFileName[20]/*,outFileName[20]*/;
  cout << "Input file name: "; cin >> inFileName;
  //cout << "Output file name: "; cin >> outFileName;
  corrector newCorrector(inFileName);
  return 0;
}
