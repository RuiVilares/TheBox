#ifndef FUCTIONS_H
#define FUCTIONS_H

#include <iostream> 
#include <iomanip> 
#include <string>
#include <cctype> 
#include <cstddef> 
#include <vector>
#include <fstream>
#include <algorithm> 
#include "stdlib.h"
#include <windows.h>
#include <conio.h>



#include "Channel.h"
#include "Program.h"
#include "Movie.h"
#include "fuctions.h"
#include "Date.h"

using namespace std;

void RentMovie();

void ListNeverSeen();

void ListPreviouslySeen();

void MoneySpent();


string LoadPassword();

float string_to_float(string s);

int string_to_int(string s);

string string_to_upper(string s);

bool compDates(Date d1, Date d2);



#endif