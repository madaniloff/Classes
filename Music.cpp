//This file returns values for the type of media, publisher, artist, and duration for music
#include <iostream>
#include <string.h>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

Music::Music() {

}
int Music::getType() {
	return 3;
}
char* Music::getPublisher() {
	return Publisher;
}
char* Music::getArtist() {
	return Artist;
}
float Music::getDuration() {
	return Duration;
}
