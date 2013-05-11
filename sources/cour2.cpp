/* itoa example */
#include <iostream>
//#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

class converter{
  map <char,int> dec2hex;
  map <int,char> hex2dec;
  int inradix,outradix;
  char result[150];
  string num;
public:
  converter(int inradix, string num){
    this->inradix = inradix;
    this->num = num;
    for(int i=0; i < 10; i++){
      this->dec2hex[i]=i;
      this->hex2dec[i]=i;
    }
    for(char i='a' int j=10; ;i<'g';i++,j++){
      this->dec2hex[j]=i;
    }
    for(char i='a',int j=10; ;j<16;i++,j++){
      this->hex2dec[i]=j;
    }
    
    /*this->read_num(inradix);
      this->write_num(outradix);*/
    
  }
  
  void echo(){
    cout << "Result: " << showbase << hex << this->result;
  }

  void convert2(int outradix){
    this->outradix = outradix;
    if(this->inradix == 10){
      this->fromDec();
    } else if(this->outradix == 10){

    } else {
      this->toDec();
      this->fromDec();
    }
    this->echo();
  }
  
  int toDec(string str,int base=10){
    int result = 0;
    char ch[30];
    int lim = str.length()-1;
    for(int i = 0; i <= lim; i++){
      result += pow(base,lim-i) * this->hex2dec[str[lim-i]];
    }
    return result;
  }

  void fromDec(int num, int base)
  {
    char * numberArred = new char[this->num.length()];
    if( num).length; i++){
	this->fromDec(this->toDec(this->num,this->outradix) / this->outradix, this->outradix);
       	if(intrad){
	  numberArred[i] = this->toDec(this->num,this->outradix)%this->outradix;
	}
      }
  }

  char formatInt(int remain){
    return this->dec2hex[remain];
  }

  /*
  void read_num(int radix){
    cout << "Enter input number: ";
    switch(radix){
    case 2:
      this->base = "binary";
      break;
    case 8:
      this->rad = oct;
      this->base = "octal";
      cin >> oct >> this->num;
      break;
    case 16:
      this->rad = hex;
      this->base = "hexadecimal";
      cin >> hex >> this->num;
      break;
    case 10:
    default:
      this->base = "decimal";
      cin >> dec >> this->num;
      break;
    }
  }
  void write_num(int radix){
    switch(radix){
    case 2:
    
      break;
    case 8:
      cout << "Octal variant for " << this->base << " '" << this->num << "\' is: " << oct << this->num;
      break;
    case 16:
      cout << "Hexadecimal variant for " << this->base << " '" << this->num << "\' is: " << hex << this->num;
      break; 
    case 10:
    default:
      cout << "Decimal variant for " << this->base << " '" << this->num << "\' is: " << dec << this->num;
      break;
    }
    }*/
};



int main ()
{
  int inradix,outradix;
  cout << "Enter input radix: ";
  cin >> dec >> inradix;
  
  //converter newConv(inradix,outradix);
  cout << "Enter number to convert: ";
  cin >> uppercase >>num;
  converter newConvert(inradix,num);
  cout << "Enter output radix: ";
  cin >> dec >> outradix;
  newConvert->convert2(ourtadix);
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
