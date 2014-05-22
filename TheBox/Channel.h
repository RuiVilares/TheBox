#ifndef _CHANNEL
 #define _CHANNEL

#include<iostream>
#include<vector>
#include<string>

#include "Program.h"

using namespace std;

class Channel{
private:
	string name;
	vector<Program> programs;
public:
	Channel(string &n);

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
	void setProgramDate(string d, int h, int m, int pos);
	// Data member accessors
	string getName();
	vector<Program> getPrograms();
};

#endif
