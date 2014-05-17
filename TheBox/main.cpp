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

#include "Date.h"
#include "Box.h"
#include "menu.h"

// Randomly generates a valid day, hour and minute
/*Date currentDate()
{
	Date d1;
	string wd;
	int d, h, m;
	srand (time(NULL));
    d = rand() % 7 + 1;
	h = rand() % 25;
	m = rand() % 60;
	wd = d1.getStr(d);
	d1.setDate(wd, h, m);
	return d1;
}*/


using namespace std;

int main(){
  //Box box = Box("naotem", currentDate());
  welcome();
  Sleep(2000);
  start_menu();
  return 0;
  exit(0);
}
