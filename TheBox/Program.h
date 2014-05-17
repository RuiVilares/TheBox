#ifndef _PROGRAM
 #define _PROGRAM

#include<iostream>
#include "Date.h"


using namespace std;


class Program{
 private:
  string name;
  string type;
  int duration;  // in minutes
  bool recorded;
  Date exhibitionDate;

 public:
  Program(string &n, int dur,string &t,bool state, string &d, int h, int min);
  
  // Data member mutators
  void setName(string &n);
  void setDuration(int &dur);
  void setDate(string &d, int &h, int &min);
  void setType(string &t);
  void setRecord(bool &state);

  // Data member accessors
  string getName();
  int getDuration();
  Date getDate();
  string getType();
  bool getState();
};

#endif
