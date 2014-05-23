#include "Channel.h"
#include "Program.h"
#include "fuctions.h"

#include <iostream>
#include <cstdlib>
#include <iomanip> 
#include <string>
#include <cctype> 
#include <cstddef> 
#include <vector>
#include <fstream>
#include <algorithm> 
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <fstream>

using namespace std;

Channel::Channel(string &n){
	name = n;
}

bool Channel::compareName(Program &prog1, Program &prog2){
	bool result = false;
	string name1 = string_to_upper(prog1.getName());
	string name2 = string_to_upper(prog2.getName());
	int i = 0;
	while (i < name1.size() && i < name2.size())
	{
		int letter1, letter2;

		letter1 = int(name1[i]);
		letter2 = int(name2[i]);


		if (letter2 == letter1)
		{

		}
		else
		{
			return (letter1 < letter2);
		}
		i++;
	}
}

void Channel::orderPrograms(){
	sort(programs.begin(), programs.end(), compareName);
}

void Channel::addProgram(string &n, int dur, string &t, bool state, string &d, int h, int min){
	programs.push_back(Program(n,dur,t,state,d,h,min));
}

void Channel::addProgram(Program p1){
	programs.push_back(p1);
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

void Channel::setProgramState(int pos, bool state){
	programs[pos].setRecord(state);
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