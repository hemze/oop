#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class recorder{

  ifstream inFile;
  ofstream outFile;
public:
  recorder()
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
  splitString(string str){
    unsigned found = str.find_first_of("|");
    string arr[100];
    unsigned start = 0, i = 0;
    while (found!=std::string::npos){
      arr[i]=str.substr(start,found-start);
      i++;
      start = found+1;
      found=str.find_first_of("|",found+1);
    }
  }

  glueString(string * arr,string sep){
    string result = "";
    for(int i=0; i < arr.size(); i++){
      result += arr[i] + "|";
    }
    cout << result;
  }

  clearString(string str){
    unsigned found = str.find_first_of("|");
    while (found!=std::string::npos){
      str[found]='';
      found=str.find_first_of("|",found+1);
    }
  }
};

int main(){
  char inFileName[20]/*,outFileName[20]*/;
  cout << "Input file name: "; cin >> inFileName;
  //cout << "Output file name: "; cin >> outFileName;
  recorder newRecord();
  return 0;
}
