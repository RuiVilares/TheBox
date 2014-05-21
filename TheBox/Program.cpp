#include "Program.h"
#include "Date.h"

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


Program::Program(string &n, int dur, string &t, bool state, string &d, int h, int min) :exhibitionDate(d, h, min){
	name = n;
	duration = dur;
	recorded = state;
	type = t;
}



void Program::showProgramDetails(){
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Duration: " << duration << endl;
	cout << "Exhibition Date: "; exhibitionDate.showDate();
}


// Data member mutators
void Program::setName(string &n){
	name = n;
}

void Program::setDuration(int &dur){
	duration = dur;
}

void Program::setDate(string &d, int &h, int &min){
	exhibitionDate = Date(d, h, min);
}

void Program::setRecord(bool state){
	recorded = state;
}

void Program::setType(string &t){
	type = t;
}


// Data member accessors
string Program::getName(){
	return name;
}

int Program::getDuration(){
	return duration;
}

Date Program::getDate(){
	return exhibitionDate;
}

string Program::getType(){
	return type;
}

bool Program::getState(){
	return recorded;
}