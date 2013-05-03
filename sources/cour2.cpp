/* itoa example */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

class converter{
  int num;
public:
  converter(int inradix, int outradix){
    this->read_num(inradix);
    this->write_num(outradix);
  }
  /*converter(const int num, int base)
  {
    if(source)
      {
	convert(num/base,base);
	printf("%d",num%base);
      }
      }*/


  void read_num(int radix){
    switch(radix){
    case 2:
    
      break;
    case 8:
      cin >> oct >> this->num;
      break;
    case 16:
      cin >> hex >> this->num;
      break;
    case 10:
    default:
      cin >> dec >> this->num;
      break;
    }
  }
  void write_num(int radix){
    switch(radix){
    case 2:
    
      break;
    case 8:
      cout << oct << this->num;
      break;
    case 16:
      cout << hex << this->num;
      break;
    case 10:
    default:
      cout << dec << this->num;
      break;
    }
  }
};



int main ()
{
  int inradix,outradix;
  cout << "Enter input radix: ";
  cin >> dec >> inradix;
  cout << "Enter output radix: ";
  cin >> dec >> outradix;
  converter newConv(inradix,outradix);
  return 0;
  /*
    
  
  
  //cout << n2dec(num,radix);
  cout << (int) num << endl;
  return 0;
}
float n2dec(char* num,char* radix){
  int i;
  float fresult = 0;
  return num[0];
  /*  for(i=0;i<33;i++){
    fresult+=pow(atoi ( num[i] ) *  atoi( radix ),i);
    }
  return fresult;*/
}
