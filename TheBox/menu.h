#ifndef MENU_H
#define MENU_H

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

#include "fuctions.h"
#include "Date.h"
#include "Box.h"

using namespace std;

void start_menu();

void movieclub_menu();

void movieclub_menu_RentMovie();

void movieclub_menu_timesWatched();

void movieclub_menu_neverSeen();

void movieclub_menu_seen();

void movieclub_menu_totalCost();

void tv_menu();

void tv_menu_setprogram();

void tv_menu_removeToBeRecorded();

void tv_menu_removeRecorded();

void tv_menu_showRecorded();

void advanced_menu1();

void advanced_menu2();

void advanced_menu_password1();

void advanced_menu_password2();

void advanced_menu_password3();

void advanced_menu_channels();

void advanced_menu_channels_create();

void advanced_menu_channels_update1();

void advanced_menu_channels_remove();

void advanced_menu_programs();

void advanced_menu_programs_create();

void advanced_menu_programs_update();

void advanced_menu_programs_remove();

void advanced_menu_movies();

void advanced_menu_movies_create();

void advanced_menu_movies_update1();

void advanced_menu_movies_remove();

void endprogram_menu();

void welcome();

void goodbye();

void loadConfigs(Box &box);

void ListbyDay();

void ListbyChannel();

void ListbyType();

void EditPass();

void EditChannels();

void EditPrograms();

void EditMovies();

void pass();

#endif