#include "Date.h"


Date::Date()
{
	weekDay = "Sunday";
	hour = 0;
	minutes = 0;
}


Date::Date(string day, unsigned h, unsigned m)
{
	weekDay = day;
	hour = h;
	minutes = m;
}

//-----------------------------------------------

void Date::setDay(string d)
{
	weekDay = d;
}

//-----------------------------------------------
void Date::setHour(unsigned int h)
{
	hour = h;
}

//-----------------------------------------------
void Date::setMinutes(unsigned int m)
{
	minutes = m;
}

//-----------------------------------------------
 void Date::setDate(string d, unsigned int h, unsigned int m)
 {
	weekDay = d;
	hour = h;
	minutes = m;
 }

//-----------------------------------------------

 string Date::getDay()
 {
	 return weekDay;
 }

//------------------------------------------------

 unsigned int Date::getHour()
 {
	 return hour;
 }

//----------------------------------------------
 
 unsigned int Date::getMinutes()
 {
	 return minutes;
 }


//-----------------------------------------------



 void Date::showDate()
 {
	 cout << weekDay << " ";
	 
	 if (hour < 10)
	 {
		 cout << 0 << hour;
	 }
	 else
	 {
		 cout << hour;
	 }

	 cout <<  ":";

	 if (minutes < 10)
	 {
		 cout << 0 << minutes;
	 }
	 else
	 {
		 cout << minutes;
	 }
 }

//-----------------------------------------------

string Date::getStr(int day)
{
	string daysentence;
	if (day == 1)
		daysentence = "Sunday";
	if (day == 2)
		daysentence = "Monday";
	if (day == 3)
		daysentence = "Tuesday";
	if (day == 4)
		daysentence = "Wednesday";
	if (day == 5)
		daysentence = "Thursday";
	if (day == 6)
		daysentence = "Friday";
	if (day == 7)
		daysentence = "Saturday";
	return daysentence;
}
//--------------------------------------------
int Date::getInt(string daysentence)
{
	int day;
	if (daysentence == "Sunday")
		day = 1;
	if (daysentence == "Monday")
		day = 2;
	if (daysentence == "Tuesday")
		day = 3;
	if (daysentence == "Wednesday")
		day = 4;
	if (daysentence == "Thursday")
		day = 5;
	if (daysentence == "Friday")
		day = 6;
	if (daysentence == "Saturday")
		day = 7;
	return day;
}


int Date::getTotalDate(){
	int totalDate;

	totalDate = Date::getInt(weekDay) * 24 * 60 + getHour() * 60 + getMinutes();
	return totalDate;
}