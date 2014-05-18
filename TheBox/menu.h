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

void movieclub_menu_neverSeen();

void tv_menu();

void advanced_menu1();

void advanced_menu2();

void advanced_menu_password1();

void advanced_menu_password2();

void advanced_menu_password3();

void advanced_menu_channels();

void advanced_menu_programs();

void advanced_menu_movies();

void endprogram_menu();

void welcome();

void goodbye();

void ListbyDay();

void ListbyChannel();

void ListbyType();

void EditPass();

void EditChannels();

void EditPrograms();

void EditMovies();

void pass();

#endif