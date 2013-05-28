#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

class Vector{

  friend ostream& operator << ( ostream&, const Vector& );

  int contents[];
public:

  Vector(int *  intarr){
    for(int i = 0; i < sizeof(intarr); i++){
      this->contents[i] = intarr[i];
    }
    //cout << *this;
  }

  int operator [](unsigned id){
    return contents[id];
  }
  /*DateTime(int secs) {
    cout << "Initialized with seconds." << endl;
    this->initCustom(secs);
  }

  DateTime(int year,int month,int day) {
    cout << "Initialized with custom date and current time." << endl;
    struct tm * timeinfo;
    timeinfo = this->initCurrent();
    initDate(year,month,day,timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
  }

  DateTime(bool time,int hours, int mins, int secs) {
    cout << "Initialized with current date and custom time." << endl;
    struct tm * timeinfo;
    timeinfo = this->initCurrent();
    initDate(false, timeinfo->tm_mon, timeinfo->tm_mday, hours, mins, secs);
  }

  DateTime operator ++(){
    DateTime dt(*this);
    ++seconds;
    dt = localtime(&seconds);
    return dt;
  }

  bool operator > (const DateTime &dt) {
    if(seconds > dt.seconds) return true;
    return false;
  }

  bool operator >= (const DateTime &dt) {
    if(seconds >= dt.seconds) return true;
    return false;
  }

  bool operator < (const DateTime &dt) {
    if(seconds < dt.seconds) return true;
    return false;
  }

  bool operator <= (const DateTime &dt) {
    if(seconds <= dt.seconds) return true;
    return false;
  }

  bool operator == (const DateTime &dt) {
    if(seconds == dt.seconds) return true;
    return false;
  }

  bool operator != (const DateTime &dt) {
    if(seconds != dt.seconds) return true;
    return false;
  }

  int operator - (const DateTime &dt) {
    return seconds - dt.seconds;
  }

  DateTime operator += (const DateTime &dt) {
    if (&dt == this) return *this;
    if(dt.seconds) seconds += dt.seconds;
    this->td = localtime(&seconds);
    return *this;
  }

  int operator + (const DateTime &dt) {
    return seconds + dt.seconds;
  }
  */
};

ostream& operator << ( ostream& os, const Vector &vc ){
  os << "The contents of vector are:";
  for (int i = 0; i < sizeof(vc.contents); i++)
    os << ' ' << vc[i];
  os << '\n';
  return os;
}

int main(){
  int arrSize;
  cout << "Enter the vector size:"; cin << dec << arrSize;
  if(arrSize){
    int * p_vectVals = new int[arrSize];
    int i;
    for(i=0;i<arrSize;i++){
      cin >> dec >> p_vectVals[i];
    }
    Vector newVector(p_vectVals[i]);
  }

  return 0;
}
