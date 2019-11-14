//This file initializes the variables and return methods for video games
#ifndef VG_H
#define VG_H

#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"

using namespace std;

class Vg:public Media{
 public:
  Vg();
  char* getPublisher();
  int getRating();
  int getType();
  int Type;
  char Publisher[30];
  int Rating;
};

#endif
