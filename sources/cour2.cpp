/* itoa example */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;

float n2dec(char*,char*);

void convert(const int num, int base)
{
  if(source)
    {
      convert(num/base,base);
      printf("%d",num%base);
    }
}

int main ()
{
  int i;
  char num[33],radix[2],result[33];
  convert(128,2);
  return 0;
  /*printf ("Enter a number: ");
    scanf ("%d",&i);*/
  cout << "Enter number: ";
  cin >> num;
  cout << "Enter radix: ";
  cin >> radix;
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
    }*/
  return fresult;
}
