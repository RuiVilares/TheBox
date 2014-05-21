#ifndef _DATE
 #define _DATE

#include <iostream>
#include <string>
#include <cstdlib> 
#include <iomanip> 
#include <cctype> 
#include <cstddef> 
#include <vector>
#include <fstream>
#include <algorithm> 
#include "stdlib.h"
#include <windows.h>
#include <conio.h>

using namespace std;


class Date{
	string weekDay;
	unsigned hour;
	unsigned minutes;
 public:
	Date();  
	Date(string day, unsigned h, unsigned m);
	void setDay(string d);
	void setHour(unsigned int h);
	void setMinutes(unsigned int m);
	void setDate(string d, unsigned int h, unsigned int m);
	string getDay();
	unsigned int getHour();
	unsigned int getMinutes();
	string getStr(int day); 
	int getInt(string daysentence);
	int getTotalDate();
	void showDate();
	
	//Date currentDate();
};

#endif
