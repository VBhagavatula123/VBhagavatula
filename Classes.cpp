#include <iostream>
#include <vector>
#include <cstring>

#include "DigMedia.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"

using namespace std;

//void printVectorDesc(vector<DigMedia*> &);

//Prototype the three functions
void ADD(vector<DigMedia*> &vect);
void PRINT(DigMedia* digMediaPtr);
void SEARCH(vector<DigMedia*> &vect);
void DELETE(vector<DigMedia*> &vect);
void LIST(vector<DigMedia*> &vect);

int main() {
   
  char inputString[7];
  vector<DigMedia*> digMediaVectPtr;

  while(true)
  {
      //Prompt for input from user, ADD, SEARCH, DELETE or QUIT
      cout << "What would you like to do, ADD, SEARCH or DELETE?" << endl;
      cout << "If you like to quit, just type QUIT !!!" << endl;
      cin >> inputString;
     
      //Based on what the input is, call different functions
      //passing vector pointer to vector of student struct pointers
      if (strcmp(inputString, "ADD") == 0)
            ADD(digMediaVectPtr);
      else if (strcmp(inputString, "SEARCH") == 0)
            SEARCH(digMediaVectPtr);
      else if (strcmp(inputString, "LIST") == 0)
            LIST(digMediaVectPtr);
      else if (strcmp(inputString, "DELETE") == 0)
            DELETE(digMediaVectPtr);
      else if(strcmp(inputString, "QUIT") == 0)
            break;
   };
 
   return 0;
}



void ADD(vector<DigMedia*> &digMediaVect) {
   
    //Prompt for student firstname, lastname, id and gpa
    cout << "Input media type: music, movies or videogames.." << endl;
   
    char* mediaType = new char[10];
    char* title = new char[80];
    char* publisher = new char[80];
    char* director = new char[80];
    char* rating = new char[80];
    char* artist = new char[80];
    int year = 1900;
    int duration = 0;
   
    cin >> mediaType;
    
    if(strcmp(mediaType, "music") == 0)
    {
        //Prompt user for student firstname, lastname, id and gpa
        cout << "Type music media info: title year artist duration publisher in this order" << endl;
       
        cin >> title;
        cin >> year;
        cin >> artist;
        cin >> duration;
        cin >> publisher;
        
        //newMedia is pointer to new media object
        Music* newMusic = new Music();
        
        newMusic->setTitle(title);
        newMusic->setYear(year);
        newMusic->setArtist(artist);
        newMusic->setDuration(duration);
        newMusic->setPublisher(publisher);
        
        digMediaVect.push_back(newMusic);
        
    }
    if(strcmp(mediaType, "movies") == 0)
    {
        //Prompt user for student firstname, lastname, id and gpa
        cout << "Type movie media info: title year director duration rating in order" << endl;
       
        cin >> title;
        cin >> year;
        cin >> director;
        cin >> duration;
        cin >> rating;

        //Call the music media object constructor by passing these values.
        //newMedia is pointer to new media object
        Movies* newMovie = new Movies();
        
        newMovie->setTitle(title);
        newMovie->setYear(year);
        newMovie->setDirector(director);
        newMovie->setDuration(duration);
        newMovie->setRating(rating);
        
        digMediaVect.push_back(newMovie);
        
    }
    if(strcmp(mediaType, "videogames") == 0)
    {
        //Prompt user for student firstname, lastname, id and gpa
        cout << "Type videogame media info: title year rating publisher" << endl;
       
        cin >> title;
        cin >> year;
        cin >> rating;
        cin >> publisher;

        //Call the music media object constructor by passing these values.
        //newMedia is pointer to new media object
        VideoGames* newVideoGame = new VideoGames();
        
        newVideoGame->setTitle(title);
        newVideoGame->setYear(year);
        newVideoGame->setRating(rating);
        newVideoGame->setPublisher(publisher);
        
        digMediaVect.push_back(newVideoGame);
    }
    
}

void SEARCH(vector<DigMedia*> &digMediaVect) {
   
   //Prompt user for search type
    cout << "Search by title or year?" << endl;
    char* searchType = new char[10];
    char* searchtitle = new char[80];
    int searchyear = 0;
    cin >> searchType;
    
    if(strcmp(searchType, "title") == 0)
    {
        //Prompt user for student firstname, lastname, id and gpa
        cout << "Enter the title of the media: " << endl;
        cin >> searchtitle;
        
        //Loop through the vector and if match found, print it.
        for(int i =0; i < digMediaVect.size(); i++) {
            if(strcmp(searchtitle, digMediaVect[i]->getTitle()) == 0)
            {
                //Print media information
                PRINT(digMediaVect[i]);
            }
        }
    }
    else if(strcmp(searchType, "year") == 0)
    {
        cout << "Enter the year of the media: " << endl;
        cin >> searchyear;
        
        //Loop through the vector and if match found, print it.
        for(int i =0; i < digMediaVect.size(); i++) {
            if(searchyear == digMediaVect[i]->getYear())
            {
                //Print media information
                PRINT(digMediaVect[i]);
            }
        }
    }
    cout << endl;
}

void PRINT(DigMedia* digMediaPtr) {
   
    //Print information about the specific media by getting the mediaType
    switch(digMediaPtr->getMediaType())
    {
        case 1:
            cout << "Music--" ;
            cout << "Title: " << digMediaPtr->getTitle() << ", ";
            cout << "Year: " << digMediaPtr->getYear() << ", ";
            cout << "Artist: " << ((Music*)digMediaPtr)->getArtist() << ", ";
            cout << "Duration: " << ((Music*)digMediaPtr)->getDuration() << ", ";
            cout << "Publisher: " << ((Music*)digMediaPtr)->getPublisher() << endl;
            break;
        case 2:
            cout << "Movie--" ;
            cout << "Title: " << digMediaPtr->getTitle() << ", ";
            cout << "Year: " << digMediaPtr->getYear() << ", "; 
            cout << "Director: " << ((Movies*)digMediaPtr)->getDirector() << ", ";
            cout << "Duration: " << ((Movies*)digMediaPtr)->getDuration() << ", ";
            cout << "Rating: " << ((Movies*)digMediaPtr)->getRating() << endl;
            break;
        case 3:
            cout << "Video Game--" ;
            cout << "Title: " << digMediaPtr->getTitle() << ", ";
            cout << "Year: " << digMediaPtr->getYear() << ", ";
            cout << "Publisher: " << ((VideoGames*)digMediaPtr)->getPublisher() << ", ";
            cout << "Rating: " << ((VideoGames*)digMediaPtr)->getRating() << endl;
            break;
    }
   
}

void LIST(vector<DigMedia*> &digMediaVect) {
   
    //Print all the media looping through all elements of the vecor
    cout << endl << "Below is the list of all media currently stored: " << endl;
   
    for(int i =0; i < digMediaVect.size(); i++) {
        
        switch(digMediaVect[i]->getMediaType())
        {
            case 1:
                cout << "Music--" ;
                cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
                cout << "Year: " << digMediaVect[i]->getYear() << ", ";
                cout << "Artist: " << ((Music*)digMediaVect[i])->getArtist() << ", ";
                cout << "Duration: " << ((Music*)digMediaVect[i])->getDuration() << ", ";
                cout << "Publisher: " << ((Music*)digMediaVect[i])->getPublisher() << endl;
                break;
            case 2:
                cout << "Movie--" ;
                cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
                cout << "Year: " << digMediaVect[i]->getYear() << ", "; 
                cout << "Director: " << ((Movies*)digMediaVect[i])->getDirector() << ", ";
                cout << "Duration: " << ((Movies*)digMediaVect[i])->getDuration() << ", ";
                cout << "Rating: " << ((Movies*)digMediaVect[i])->getRating() << endl;
                break;
            case 3:
                cout << "Video Game--" ;
                cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
                cout << "Year: " << digMediaVect[i]->getYear() << ", ";
                cout << "Publisher: " << ((VideoGames*)digMediaVect[i])->getPublisher() << ", ";
                cout << "Rating: " << ((VideoGames*)digMediaVect[i])->getRating() << endl;
                break;
        }
        
    }
   
    cout << endl;
   
}

void DELETE(vector<DigMedia*> &digMediaVect) {
    
    char* searchType = new char[10];
    char* delTitle = new char[80];
    int searchyear = 0;
    char* confirm =  new char[2];
    
    //Prompt for media to delete
    cout << "Which title to delete; Search by title or year?" << endl;
    cin >> searchType;
    
    if(strcmp(searchType, "title") == 0)
    {
        //Prompt user for student firstname, lastname, id and gpa
        cout << "Enter the title of the media: " << endl;
        cin >> delTitle;
        
        //Loop through the vector and if match found, print it.
        for(int i =0; i < digMediaVect.size(); i++) {
            if(strcmp(delTitle, digMediaVect[i]->getTitle()) == 0)
            {
                //Print media information
                PRINT(digMediaVect[i]);
            }
        }
        
        //Have the user confirm that the media need to  be deleted.
        //Loop again to delete them
        cout << "Please confirm you want to delete all listed media above: y or n ?" << endl;
        cin >> confirm;
        
        if(strcmp(confirm, "y") == 0)
        {
            int size = digMediaVect.size();
            int i = 0;
            
            while(i < size) {
                if(delTitle == digMediaVect[i]->getTitle())
                {
                    //delete the data
                    delete digMediaVect[i];
                    //Remove the student from vector
                    digMediaVect.erase(digMediaVect.begin()+i);
    
                    //Confirm deletion
                    cout << "Media with year " << searchyear << " is now deleted. " << endl;
                    size = digMediaVect.size();
                }
                else
                    i++;
            }
        }
    }
    else if(strcmp(searchType, "year") == 0)
    {
        cout << "Enter the year of the media: " << endl;
        cin >> searchyear;
        
        //Loop through the vector and if match found, print it.
        for(int i =0; i < digMediaVect.size(); i++) {
            if(searchyear == digMediaVect[i]->getYear())
            {
                //Print media information
                PRINT(digMediaVect[i]);
            }
        }
        
        //Have the user confirm that the media need to  be deleted.
        //Looping again and delete them
        cout << "Please confirm you want to delete all listed media above: y or n ?" << endl;
        cin >> confirm;
        
        if(strcmp(confirm, "y") == 0)
        {
            int size = digMediaVect.size();
            int i = 0;
            
            while(i < size) {
                if(searchyear == digMediaVect[i]->getYear())
                {
                    //delete the data
                    delete digMediaVect[i];
                    //Remove the student from vector
                    digMediaVect.erase(digMediaVect.begin()+i);
    
                    //Confirm deletion
                    cout << "Media with year " << searchyear << " is now deleted. " << endl;
                    size = digMediaVect.size();
                }
                else
                    i++;
            }
        }
        
        
    }

    //Print media list after deletion
    LIST(digMediaVect);
    cout << endl;
    
}

/*void printVectorDesc(vector<DigMedia*> &newVect)
{
  for(vector<DigMedia*>::iterator it = newVect.begin(); it != newVect.end(); it++){
    cout << (*it)->getTitle() << endl;
  }
}*/
