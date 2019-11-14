//Initializes returns and variables for movie
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie:public Media{
 public:
  Movie();
  char* getDirector();
  float getDuration();
  int getRating();
  int getType();
  char Director[40];
  float Duration;
  int Rating;
  int Type;
}; 
#endif
