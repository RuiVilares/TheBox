#ifndef _BOX
 #define _BOX

#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<stdlib.h>

#include "Date.h"
#include "Channel.h"
#include "Program.h"
#include "Movie.h"
#include "fuctions.h"
//#include "menu.h"

using namespace std;


class Box{
private:
  string password;
  Date currentDate;
  vector<Channel> channels;
  vector<Movie> movieClub;
  vector<Movie> seenMovies;
  vector<Program> recordList;
  //vector<Program> recorded;    // removed in the final version of the work text

public:
  Date Box::GetCurrentDate();
  string Box::GetPassword();
  Box(string passwd, Date currentDate);
  vector<Program> listByDay(string day) const;
  vector<Program> listByChannel(string  channel, string day) const;
  vector<Program> listByType(string  type, string day) const;
  void saveInfo();
  vector<Channel> getChannels();

 //Password
  bool changePassword(string np);         // ask, verify and change the password
  //Movies
  void rentMovies(const string &title);
  float moneySpent();
  void show_timesWhatched(const string &title);
  bool Whatched(const string &title);
  bool exist_in_movieClub(const string &title);



  void show_movies_movieClub();
  void load_movies_movieClub();
  void show_movies_seen();
  void load_movies_seen();
  void save_movies();

  //Television
  void SetProgramRecorded();
  void RemoveProgramToBeRecorded();
  void RemoveProgramRecorded();
  bool RecordProgram(string &program_name, string &channel_name);

  void showPrograms(vector<Program> &list_programs);

  //Channels
  void saveChannels();
  void loadChannels(int channels_number);
  void showChannels();
  // Channel CRUD
  int searchChannel(string &channel_name);
  void createChannel();
  void removeChannel();
  void updateChannel(string &name);
  // Program CRUD
  bool checkProgramDate(Date new_program_date, int duration, Channel &channel);
  int searchProgram(string &program_name, Channel &channel);


  bool createdProgram(string &channel);
  bool removeProgram(string &channel, string &program);
  bool updateProgram(string &channel, string &program);
  // Movie CRUD
  void createMovie();
  void removeMovie();
  void updateMovie(int i, string name);

};

#endif
