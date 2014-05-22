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
	bool removeProgram(string &n);
	void removeProgram(int pos);
	void setName(string &n);
	// Data member accessors
	string getName();
	vector<Program> getPrograms();
};

#endif
