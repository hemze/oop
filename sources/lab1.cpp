#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

class DateTime{

  friend ostream& operator<<( ostream&, const DateTime& );
  time_t seconds;
  struct tm * td;
  char buffer[80];
public:
  DateTime(bool flag){
    cout << "Initialized by default with current date and time." << endl;
    this->td = this->initCurrent();
    cout << *this;
  }
  DateTime(int secs) {
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

  DateTime(int year,int month,int day,int hours,int mins,int secs) {
    cout << "Initialized with cutom both date and time." << endl;
    struct tm * timeinfo;
    timeinfo = this->initCurrent();
    initDate(year, month, day, hours, mins, secs);
  }
  void initDate(int year,int month,int day,int hours,int mins,int secs){
    time_t rawtime;
    const char * weekday[] = { "Понедельник", "Вторник",
                               "Среда", "Четверг",
                               "Пятница", "Суббота",
                               "Воскресенье"};
    /* get current timeinfo and modify it to the user's choice */

    time ( &rawtime );
    this->td = localtime ( &rawtime );
    this->td->tm_year = (year ? year - 1900 : this->td->tm_year);
    this->td->tm_mon = month - 1;
    this->td->tm_mday = day;
    this->td->tm_hour = hours;
    this->td->tm_min = mins;
    this->td->tm_sec = secs;
    this->seconds = mktime(this->td);
    cout << "(" << this->seconds << ")\n";
    cout << *this;
  }

  struct tm * initCurrent(){
    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    this->seconds = rawtime;
    return localtime ( &rawtime );
  }

  void initCustom(time_t rawtime){
    this->td = localtime ( &rawtime );
    this->seconds = rawtime;
    cout << *this;
  }

  int getSeconds(){
    return this->seconds;
  }

  DateTime operator ++(int){
    DateTime dt(*this);
    seconds++;
    this->td = localtime(&seconds);
    return dt;
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
  /*operator char*(){
    strftime (this->buffer,80,"%d-%m-%Y %H:%M:%S, %A.",this->td);
    return this->buffer;
  }*/
};

ostream& operator <<( ostream& os, const DateTime &dt ){
  char buffer[80];
  strftime (buffer,80,"%d-%m-%Y %H:%M:%S, %A.\n===========================\n", dt.td);
  os << "(" << dt.seconds << ")\n" << buffer;
  return os;
}

int main(){
  int year,month,day,hour,min,sec,lsec;
  //prompt user for date
  cout << "Enter year: "; cin >> dec  >> year;
  cout << "Enter month: "; cin >> dec >> month;
  cout << "Enter day: "; cin >> dec >> day;
  cout << "Enter hours: "; cin >> dec >> hour;
  cout << "Enter minutes: "; cin >> dec >> min;
  cout << "Enter seconds: "; cin >> dec >> sec;
  cout << "Enter seconds (long): "; cin >> dec >> lsec;

  //DateTime newDate1(true);
  //DateTime newDate2(lsec);
  //DateTime newDate3(year,month,day);
  //DateTime newDate4(true,hour,min,sec);
  //DateTime newDate5(year,month,day,hour,min,sec);

  return 0;
}
