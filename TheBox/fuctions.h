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



#include "Channel.h"
#include "Program.h"
#include "Movie.h"
#include "fuctions.h"

using namespace std;

void RentMovie();

void ListNeverSeen();

void ListPreviouslySeen();

void MoneySpent();

void saveChannels(vector<Channel> &channels);

string LoadPassword();

void loadConfigs();

#endif