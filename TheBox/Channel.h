#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<sstream>


#include "Program.h"

using namespace std;

class Channel{
private:
	string name;
	vector<Program> programs;
public:
	Channel(string &n);
	static bool compareName(Program &prog1, Program &prog2);
	void orderPrograms();

	// Data member mutators
	void addProgram(string &n, int dur, string &t, bool state, string &d, int h, int min);
	void addProgram(Program p1);
	bool removeProgram(string &n);
	void removeProgram(int pos);
	void setName(string &n);
	void setProgramName(string &n, int pos);
	void setProgramDuration(int dur, int pos);
	void setProgramType(string &n, int pos);
	void setProgramState(int pos);
	void Channel::setProgramState(int pos, bool state);
	void setProgramDate(string d, int h, int m, int pos);
	// Data member accessors
	string getName();
	vector<Program> getPrograms();
};

#endif
