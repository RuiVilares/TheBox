#include "Channel.h"
#include "Program.h"

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

Channel::Channel(string &n){
	name = n;
}

void Channel::addProgram(string &n, int dur, string &t, bool state, string &d, int h, int min){
	programs.push_back(Program(n,dur,t,state,d,h,min));
}


// Data member mutators
bool Channel::removeProgram(string &n){
	bool state = false;
	for (int i = 0; i < programs.size(); i++)
	{
		if (n == programs[i].getName())
		{
			programs.erase(programs.begin()+i);
			state = true;
			break;
		}
	}
	return state;
}

void Channel::removeProgram(int pos){
	programs.erase(programs.begin() + pos);
}

void Channel::setProgramName(string &n, int pos){
	programs[pos].setName(n);
}

void Channel::setProgramDuration(int dur, int pos){
	programs[pos].setDuration(dur);
}

void Channel::setProgramType(string &n, int pos){
	programs[pos].setType(n);
}

void Channel::setProgramState(int pos){
	programs[pos].setRecord(!programs[pos].getState());
}

void Channel::setProgramDate(string d, int h, int m, int pos){
	programs[pos].setDate(d, h, m);
}

void Channel::setName(string &n){
	name = n;
}



// Data member accessors
string Channel::getName(){
	return name;
}

vector<Program> Channel::getPrograms(){
	return programs;
}