#include <cstdlib>
#include <iostream>
//#include <string>
#include <string.h>
using namespace std;

class StringSort{

public:
  StringSort()
  {
    string curr;
    int i = 0;
    char outFileName[20] = "../data/data.out";
    
  }
};

int main(){
  int compFlag,arrSize=0;
  bool sorted=false;
  string temp;
  cout << "Array size: "; 
  cin >> dec >> arrSize;
  cout << "Enter " << arrSize << " words to sort:";
  if(arrSize>0){
    string *p_strarr = new string[arrSize]; // Выделение памяти для массива
    for(int i = 0; i < arrSize; i++){
      cin >> p_strarr[i];
    }
    for(int i = 0; i < arrSize; i++){
      if(i<arrSize-1){
	compFlag = strcmp(p_strarr[i].c_str(),p_strarr[i+1].c_str());
	if(compFlag>0){
	  // cout << "comparing " << p_strarr[i] << " and " << p_strarr[i+1] << ", result is " << compFlag << endl; 
	  temp = p_strarr[i];
	  p_strarr[i] = p_strarr[i+1];
	  p_strarr[i+1] = temp;
	  i = -1;
	}
      }
    }
    
    for(int i = 0; i < arrSize; i++){
      cout << p_strarr[i] << endl;
    }
  } else {
    cout << "Array size must be greater than zero!";
    return 1;
  }
  //cout << "Output file name: "; cin >> outFileName;
  //corrector newCorrector(inFileName);
  return 0;
}
