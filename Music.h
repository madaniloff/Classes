//This file initializes variables and return methods for Music
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"

using namespace std;

class Music:public Media {
 public:
    Music();
    char* getArtist();
    char* getPublisher();
    float getDuration();
    int getType();
    int Type;
    char Artist[50];
    float Duration;
    char Publisher[30];
};
    
#endif
