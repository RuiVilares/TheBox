#include "Movie.h"

#include <iostream>
#include <cstdlib>
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

using namespace std;


Movie::Movie(const string &t, /*string type,*/ float c){
	title = t;
	cost = c;
	timesRented = 0;
}

Movie::Movie(const string &n, float c, int t)
{
	title = n;
	cost = c;
	timesRented = t;
}

// Data member mutators
void Movie::setTitle(string &t){
	title = t;
}
void Movie::setCost(float &c){
	cost = c;
}

void Movie::addTimesRented(){
	timesRented++;
}

// Data member accessors

string Movie::getTitle(){
	return title;
}

float Movie::getCost(){
	return cost;
}

unsigned Movie::getTimesRented(){
	return timesRented;
}