#ifndef _BOX
 #define _BOX

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>

#include "Date.h"
#include "Channel.h"
#include "Program.h"
#include "Movie.h"
#include "fuctions.h"

using namespace std;


class Box{
private:
  string password;
  Date currentDate;
  vector<Channel> channels;
  vector<Movie> movieClub;
  vector<Movie> seenMovies;
  vector<Program> recordList;
  //  vector<Program> recorded;    // removed in the final version of the work text

public:
  Date Box::GetCurrentDate(Box box);
  string Box::GetPassword();
  Box(string passwd, Date currentDate);
  vector<Program> listByDay(string day) const;
  vector<Program> listByChannel(string  channel, string day) const;
  vector<Program> listByType(string  type, string day) const;
  bool rentMovies(string &title);
  float moneySpent()/* const*/;
  int timesWhatched(string &title)/* const*/;
  bool changePassword(string np);         // ask, verify and change the password
  void show_movies_movieClub();
  void load_movies_movieClub();
  void show_movies_seen();
  void load_movies_seen();


  // Channel CRUD
  bool createdChannel(string &n);
  bool removeChannel(string &n);
  bool updateChannel(string &channel_name);
  // Program CRUD
  int searchProgram(string &program_name);
  bool createdProgram(string &channel);
  bool removeProgram();
  bool updateProgram();
  // Movie CRUD
  bool createdMovie();
  bool removeMovie();
  bool updateMovie();

};

#endif
