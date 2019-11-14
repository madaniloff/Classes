//This parent class returns the type, title, and year, of all the various child classes
#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "Vg.h"

using namespace std;

Media::Media() {

}

int Media::getType() {
  return 0;
}

char* Media::getTitle() {
  return Title;
}

int Media::getYear() {
  return Year;
}

//Help provided by Tejash Panda
//Period 2
//October 23 2019 
