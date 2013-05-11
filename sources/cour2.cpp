/* itoa example */
#include <iostream>
//#include <stdio.h>
#include <map>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

class converter{
  map <int,char> dec2hex;
  map <char,int> hex2dec;
  int inradix,outradix,intResult;
  char chResult[150];
  string num;
public:
  converter(int inradix, string num){
    int i = 0;
    char j = '0';
    this->inradix = inradix;
    this->num = num;
    for(i=0; i < 10; i++,j++){
      this->dec2hex.insert(pair<int,char>(i,j));
      this->hex2dec.insert(pair<char,int>(j,i));
    }
    for(char j='A'; j<'G'; j++,i++) {
      this->dec2hex.insert(pair<int,char>(i,j));
      this->hex2dec.insert(pair<char,int>(j,i));
    }
    map<char,int>::iterator it;
    //for (it=this->hex2dec.begin(); it!=this->hex2dec.end(); ++it)
      //cout << it->first << " => " << it->second << endl;
    /*this->read_num(inradix);
      this->write_num(outradix);*/
    
  }
  
  void convert2(int outradix){
    this->outradix = outradix;
    if(this->outradix==10){
      cout << "Result: " << this->toDec(this->num,this->inradix) << endl;
    } else {
      int dec = this->toDec(this->num,this->inradix);
      if(this->outradix == 16 && this->dec2hex.count(dec)>0){
	cout << this->dec2hex[dec] << endl;
      } else {
	this->fromDec(dec,this->outradix);  
      }
    }
  }
  
  int toDec(string str,int base=10){
    int result = 0;
    int lim = str.length()-1;
    for(int i = 0; i <= lim; i++){
      result += pow(base,lim-i) * this->hex2dec[str[i]];
    }
    return result;
  }

  void fromDec(int num, int base)
  {
    int len = log10(num)/log10(base) + 1;
    char * numberArred = new char[len];
    int i = len-1;
    if(num){
      while(num >= base) {
	numberArred[i] = this->dec2hex[num%base];	
	num = num / base;
	i--;
      }
      numberArred[i] = this->dec2hex[num];
    }
    cout << "Result: " << numberArred << endl;
  }

  char formatInt(int remain){
    return this->dec2hex[remain];
  }
  int formatHex(char sym){
    return this->hex2dec[sym];
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
  string num;
  cout << "Enter input radix: ";
  cin >> dec >> inradix;
  cout << "Enter number to convert: ";
  cin >> uppercase >> num;
  cout << "Enter output radix: ";
  cin >> dec >> outradix;
  converter newConvert(inradix,num);
  newConvert.convert2(outradix);
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
