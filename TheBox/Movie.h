#ifndef _MOVIE
 #define _MOVIE

#include<iostream>

using namespace std;


class Movie{								// RETIREI A CATEGORIA "TIPO DE FILME" PORQUE O PROF ELIMINOU ISSO NO NOVO ENUNCIADO
private: 
  string title;
  float cost;
  unsigned timesRented;
  /*string type;*/
public:
  Movie(string &t, /*string type,*/ float &c);
  // Data member mutators
  void setTitle(string &t);
  void setCost(float &c);
  void addTimesRented();
  // Data member accessors
  string getTitle();
  float getCost();
  unsigned getTimesRented();
};

#endif
