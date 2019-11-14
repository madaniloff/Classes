//This file initializes the variables and return methods for the media fields
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  char* getTitle();
  int getYear();
  virtual int getType();
  int Type;
  char Title[30];
  int Year;
}; 

#endif
