//This file contains the return methods for type director duration and rating
#include <iostream>
#include <string.h>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie() {

}
int Movie::getType() {
  return 1;
}
char* Movie::getDirector() {
  return Director;
}

float Movie::getDuration() {
  return Duration;
}
int Movie::getRating() {
  return Rating;
} 
