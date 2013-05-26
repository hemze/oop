#include <cstdlib>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

class DateTime{

  time_t seconds;
  struct tm * td;

public:
  char * buffer;
  DateTime(bool flag){
    cout << "Initialized by default with current date and time." << endl;
    this->td = this->initCurrent();
    cout << this;
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
    initDate(0, timeinfo->tm_mon, timeinfo->tm_mday, hours, mins, secs);
  }

  DateTime(int year,int month,int day,int hours,int mins,int secs) {
    cout << "Initialized with cutom both date and time." << endl;
    struct tm * timeinfo;
    timeinfo = this->initCurrent();
    initDate(year, month,day, hours, mins, secs);
  }
  void initDate(int year,int month,int day,int hours,int mins,int secs){
    time_t rawtime;
    struct tm * timeinfo;
    const char * weekday[] = { "Понедельник", "Вторник",
                               "Среда", "Четверг",
                               "Пятница", "Суббота",
                               "Воскресенье"};
    /* get current timeinfo and modify it to the user's choice */
    time ( &rawtime );

    this->td = localtime ( &rawtime );
    this->td->tm_year = (year ? year - 1900 : timeinfo->tm_year);
    this->td->tm_mon = month - 1;
    this->td->tm_mday = day;
    this->td->tm_hour = hours;
    this->td->tm_min = mins;
    this->td->tm_sec = secs;
    this->seconds = mktime(this->td);
    cout << "(" << this->seconds << ")\n";
    cout << this;
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
    cout << this;
  }

  struct tm * getDate(){
    return this->td;
  }

  int getSeconds(){
    return this->seconds;
  }

  friend ostream& operator <<(ostream& s,const DateTime dt);

  DateTime operator ++(int){
    time_t rawtime;
    rawtime = mktime(this->td);
    rawtime++;
    this->td = localtime(&rawtime);
    return *this;;
  }

  operator char*(){
    strftime (this->buffer,80,"%d-%m-%Y %H:%M:%S, %A.",this->td);
    return this->buffer;
  }
};

ostream& operator<<(ostream& s, const DateTime& dt)
{
  char buffer[80];
  strftime (buffer,80,"%d-%m-%Y %H:%M:%S, %A.",dt.getDate());
  s << dt.buffer << endl;
  return s;
}


int main(){
  int year,month,day,hour,min,sec,lsec;
  char ans;
  /* prompt user for date
  printf ("Enter year: "); scanf ("%d",&year);
  printf ("Enter month: "); scanf ("%d",&month);
  printf ("Enter day: "); scanf ("%d",&day);
  printf ("Enter hours: "); scanf ("%d",&hour);
  printf ("Enter minutes: "); scanf ("%d",&min);
  printf ("Enter seconds: "); scanf ("%d",&sec);
  printf ("Enter seconds (long): "); scanf ("%d",&lsec);


  DateTime newDate2(lsec);
  DateTime newDate3(year,month,day);
  DateTime newDate4(true,hour,min,sec);
  DateTime newDate5(year,month,day,hour,min,sec);
  */DateTime newDate1(true);
  newDate1++;
  cout << newDate1;

  return 0;
}
