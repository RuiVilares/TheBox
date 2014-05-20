#include "fuctions.h"
#include "menu.h"



void RentMovie()
{
	// Completar depois
}

void ListNeverSeen()
{
	// Completar
}

void ListPreviouslySeen()
{
	// Completar
}

void MoneySpent()
{
	// Completar
}


string LoadPassword()
{
	string pass;
	ifstream file;
	file.open("info//General Information.txt");
	getline(file, pass);
	file.close();
	return pass;
}


float string_to_float(string s)
{
	float d = std::stof(s);
	return d;
}

int string_to_int(string s)
{
	int d = std::stoi(s);
	return d;
}

string string_to_upper(string s)
{
	for (size_t i = 0; i<s.length(); i++)
		s[i] = toupper(s[i]);
	return s;
}

bool compDates(Date d1, Date d2) // true se for passado 
{
	if (d1.getInt(d1.getDay()) < d2.getInt(d2.getDay()))
		return true;
	if (d1.getInt(d1.getDay()) == d2.getInt(d2.getDay()) && d1.getHour() < d2.getHour())
		return true;
	if (d1.getInt(d1.getDay()) == d2.getInt(d2.getDay()) && d1.getHour() == d2.getHour() && d1.getMinutes() < d2.getMinutes())
		return true;
	else
		return false;
}

void loadConfigs(){
}