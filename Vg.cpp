//This file returns the type, publisher, and rating for Video Games
#include <iostream>
#include <string.h>
#include <cstring>
#include "Vg.h"
#include "Media.h"

using namespace std;

Vg::Vg() {

}
int Vg::getType() {
  return 2;
}
char* Vg::getPublisher() {
  return Publisher;
}
int Vg::getRating() {
  return Rating;
}
