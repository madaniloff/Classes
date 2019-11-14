//This program creates a media database for music, movies, and video games. Users can add, search, and delete media
//Author: Mark Daniloff
//Date: 10/21/2019

#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <iomanip>
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include "Vg.h"

using namespace std;

//Initialize methods

void addMovie(vector<Media*>* m);
void addMusic(vector<Media*>* m);
void addVG(vector<Media*>* m);
void searchTitle(char* title, vector<Media*>* m);
void searchYear(int year, vector<Media*>* m);
void delTitle(char* title, vector<Media*>* m);
void delYear(int year, vector<Media*>* m);

int main() {
  bool playing = true;
  vector<Media*> *m = new vector<Media*>();
  char mainInput[8];
  char input[12];
  //Ask user if they want to add search and delete media, or quit
  cout << "Type in ADD to add media, SEARCH to search media, DELETE to delete media, or QUIT to quit" << endl;
  while (playing == true) {
    while(strcmp(mainInput, "QUIT")!= 0) {
      cin.getline(mainInput, 8,'\n');
      //ADD
      if(strcmp(mainInput, "ADD") == 0) {
	//What type of media
	cout << "Enter 1 to add a movie, 2 to enter music, and 3 to enter a video game" << endl;
	cin.get(input, 12);
	cin.ignore();
        //Movie
        if (strcmp(input, "1") == 0) {
	  addMovie(m);
        }
        //Music
        if (strcmp(input, "2") == 0) {
	  addMusic(m);
        }
        //Video game
        if (strcmp(input, "3") == 0) {
	  addVG(m);
        }
    }
      //SEARCH
      if(strcmp(mainInput, "SEARCH") == 0) {
        cout << "Enter TITLE to search by title or YEAR to search by year or EXIT to return" << endl;
        char searchInput[7];
	char titleInput[30];
	int yearInput;
        cin.getline(searchInput, 7,'\n');
        //TITLE
        if (strcmp(searchInput, "TITLE") == 0) {
	  cout << "Enter the title you wish to search for" << endl;
	  cin.get(titleInput, 30);
	  searchTitle(titleInput, m);
	  cin.clear();
	  cin.ignore();
        }
        //YEAR
        else if (strcmp(searchInput, "YEAR") == 0) {
	  cout << "Enter the year you wish to search for" << endl;
	  cin >> yearInput;
	  searchYear(yearInput, m);
	  cin.clear();
	  cin.ignore();
        }
        //ELSE
        else {
	  cout << "Enter TITLE or YEAR" << endl;   
        }
      }
      //DELETE
      if(strcmp(mainInput, "DELETE") == 0) {
        cout << "Enter TITLE to search by title or YEAR to search by year" << endl;
        char delSearchInput[7];
	char titleInput[30];
	int yearInput;
        cin.getline(delSearchInput, 7,'\n');
        //TITLE
	if (strcmp(delSearchInput, "TITLE") == 0) {
	  cout << "Enter the title you wish to delete" << endl;
	  cin.get(titleInput, 30);
	  delTitle(titleInput, m);
	  cin.clear();
	  cin.ignore();
        }
        //YEAR
        else if (strcmp(delSearchInput, "YEAR") == 0) {
	  cout << "Enter the year you wish to delete" << endl;
	  cin >> yearInput;
	  delYear(yearInput, m);
	  cin.clear();
	  cin.ignore();
        }
      }
      //QUIT
      if (strcmp(mainInput, "QUIT") == 0) {
	playing = false;
      }
      //ELSE
      else {
	cout << "Enter ADD, DELETE, SEARCH, or QUIT" << endl;
      }
    }
  }
}
//Method to add movies
//All the add methods work the same
//It asks the user for user input for the fields for their respective media type
//Then adds it into the media vector
void addMovie(vector<Media*>* m) {
  Movie* mv = new Movie();
  cout << "Title: " << endl;
  cin.get(mv->Title, 100);
  cin.clear();
  cin.ignore();
  cout << "Director: " << endl;
  cin.get(mv->Director, 100);
  cin.clear();
  cin.ignore();
  cout << "Year: " << endl;
  cin >> mv->Year;
  cin.clear();
  cin.ignore();
  cout << "Duration: " << endl;
  cin >> mv->Duration;
  cin.clear();
  cin.ignore();
  cout << "Rating: " << endl;
  cin >> mv->Rating;
  cin.clear();
  cin.ignore();
  m->push_back(mv);
}
 
//Method to add music
void addMusic(vector<Media*>* m) {
  Music* ms = new Music();
  cout << "Title: " << endl;
  cin.get(ms->Title, 100);
    cin.clear();
  cin.ignore();
  cout << "Artist: " << endl;
  cin.get(ms->Artist, 50);
    cin.clear();
  cin.ignore();
  cout << "Year: " << endl;
  cin >> ms->Year;
    cin.clear();
  cin.ignore();
  cout << "Duration: " << endl;
  cin >> ms->Duration;
    cin.clear();
  cin.ignore();
  cout << "Publisher: " << endl;
  cin.get(ms->Publisher, 50);
    cin.clear();
  cin.ignore();
  m->push_back(ms);
  }

//Method to add video games
void addVG(vector<Media*>* m) {
  Vg* vg = new Vg();
  cout << "Title: " << endl;
  cin.get(vg->Title, 100);
  cin.clear();
  cin.ignore();
  cout << "Year: " << endl;
  cin >> vg->Year;
  cin.clear();
  cin.ignore();
  cout << "Publisher: " << endl;
  cin.get(vg->Publisher, 50);
  cin.clear();
  cin.ignore();
  cout << "Rating: " << endl;
  cin >> vg->Rating;
  cin.clear();
  cin.ignore();
  m->push_back(vg);
  } 

//Method to search by title
void searchTitle(char* title, vector<Media*>* m) {
    //Creates an iterator to go through the media vector
    vector <Media*>::iterator it;
    for (it = m->begin(); it != m->end(); it++) {
        //If the title matches a title in the array
        if(strcmp(title, (*it)->getTitle()) == 0) {
            //Print out title and year
            cout << "Title: " << (*it)->getTitle() << endl;
            cout << "Year: " << (*it)->getYear() << endl;
            //Based on the type return the appropriate fields
            //If the type is Movie
            if((*it)->getType() == 1) {
            cout << "Director: " << static_cast<Movie*>(*it)->getDirector() << endl;
            cout << "Duration: " << static_cast<Movie*>(*it)->getDuration() << endl;
            cout << "Rating: "  << static_cast<Movie*>(*it)->getRating() << endl;
            }
            //If the type is Video Game
            if((*it)->getType() == 2) {
            cout << "Publisher: " << static_cast<Vg*>(*it)->getPublisher() << endl;
            cout << "Rating: " << static_cast<Vg*>(*it)->getRating() << endl;                 
            }
            //If the type is Music
            if((*it)->getType() == 3) {
            cout << "Artist: " << static_cast<Music*>(*it)->getArtist() << endl;
            cout << "Duration: " << static_cast<Music*>(*it)->getDuration() << endl;
            cout << "Publisher: " << static_cast<Music*>(*it)->getPublisher() << endl;
            }
        }
    }
}

//Method to search by year
void searchYear(int year, vector<Media*>* m) {
    //Creates an iterator to go through the media array
    vector <Media*>::iterator it;
    for (it = m->begin(); it != m->end(); it++) {
     //If the year matches a year in the array   
        if (year == (*it)->getYear()) {
            //Print out the title and year
            cout << "Title: " << (*it)->getTitle() << endl;
            cout << "Year: " << (*it)->getYear() << endl;
            //Based on the type return the appropriate fields
            //If the type is Movie
            if((*it)->getType() == 1) {
            cout << "Director: " << static_cast<Movie*>(*it)->getDirector() << endl;
            cout << "Duration: " << static_cast<Movie*>(*it)->getDuration() << endl;
            cout << "Rating: "  << static_cast<Movie*>(*it)->getRating() << endl;
            }
            //If the type is Video Game
            if((*it)->getType() == 2) {
            cout << "Publisher: " << static_cast<Vg*>(*it)->getPublisher() << endl;
            cout << "Rating: " << static_cast<Vg*>(*it)->getRating() << endl;                 
            }
            //If the type is Music
            if((*it)->getType() == 3) {
            cout << "Artist: " << static_cast<Music*>(*it)->getArtist() << endl;
            cout << "Duration: " << static_cast<Music*>(*it)->getDuration() << endl;
            cout << "Publisher: " << static_cast<Music*>(*it)->getPublisher() << endl;
            }
        }        
    }    
}

//Method to delete by title
void delTitle(char* title, vector<Media*>* m) {
    char yninput[3];
    //Creates an iterator to go through the media vector
    vector <Media*>::iterator it;
    for (it = m->begin(); it != m->end(); it++) {
        //If the title matches a title in the array
        if(strcmp(title, (*it)->getTitle()) == 0) {
            //Print out title and year
            cout << "Title: " << (*it)->getTitle() << endl;
            cout << "Year: " << (*it)->getYear() << endl;
            //Based on the type return the appropriate fields
            //If the type is Movie
            if((*it)->getType() == 1) {
            cout << "Director: " << static_cast<Movie*>(*it)->getDirector() << endl;
            cout << "Duration: " << static_cast<Movie*>(*it)->getDuration() << endl;
            cout << "Rating: "  << static_cast<Movie*>(*it)->getRating() << endl;
            }
            //If the type is Video Game
            if((*it)->getType() == 2) {
            cout << "Publisher: " << static_cast<Vg*>(*it)->getPublisher() << endl;
            cout << "Rating: " << static_cast<Vg*>(*it)->getRating() << endl;                 
            }
            //If the type is Music
            if((*it)->getType() == 3) {
            cout << "Artist: " << static_cast<Music*>(*it)->getArtist() << endl;
            cout << "Duration: " << static_cast<Music*>(*it)->getDuration() << endl;
            cout << "Publisher: " << static_cast<Music*>(*it)->getPublisher() << endl;
            }
            cout << "Do you want to delete this this/these item(s)? y/n" << endl;
            //If the answer is y
	    cin.ignore(80, '\n');
            cin.getline(yninput, 3, '\n');
            if (strcmp(yninput, "y")==0) {
                //Destructor is used
                delete *it;
                it = m->erase(it);
                return;
            }
        }
    }
}
//Method to delete by year
void delYear(int year, vector<Media*>* m) {
    char yninput[3];
    //Creates an iterator to go through the media vector
    vector <Media*>::iterator it;
    for (it = m->begin(); it != m->end(); it++) {
        //If the title matches a title in the array
        if(year ==  (*it)->getYear())  {
            //Print out title and year
            cout << "Title: " << (*it)->getTitle() << endl;
            cout << "Year: " << (*it)->getYear() << endl;
            //Based on the type return the appropriate fields
            //If the type is Movie
            if((*it)->getType() == 1) {
            cout << "Director: " << static_cast<Movie*>(*it)->getDirector() << endl;
            cout << "Duration: " << static_cast<Movie*>(*it)->getDuration() << endl;
            cout << "Rating: "  << static_cast<Movie*>(*it)->getRating() << endl;
            }
            //If the type is Video Game
            if((*it)->getType() == 2) {
            cout << "Publisher: " << static_cast<Vg*>(*it)->getPublisher() << endl;
            cout << "Rating: " << static_cast<Vg*>(*it)->getRating() << endl;                 
            }
            //If the type is Music
            if((*it)->getType() == 3) {
            cout << "Artist: " << static_cast<Music*>(*it)->getArtist() << endl;
            cout << "Duration: " << static_cast<Music*>(*it)->getDuration() << endl;
            cout << "Publisher: " << static_cast<Music*>(*it)->getPublisher() << endl;
            }
            cout << "Do you want to delete this this/these item(s)? y/n" << endl;
            //If the answer is y
	    cin.ignore(80,'\n');
            cin.getline(yninput, 3,'\n');
            if (strcmp(yninput, "y")==0) {
                //Destructor is used
                delete *it;
                it = m->erase(it);
                return;
            }
        }
    }    
}
