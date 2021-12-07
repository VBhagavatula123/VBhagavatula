
#include <iostream>
#include <vector>
#include <cstring>

#include "DigMedia.h"
#include "Movies.h"
#include "Music.h"
#include "VideoGames.h"

using namespace std;

//Prototype the all the functions
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
      //Prompt for input from user, ADD, SEARCH, DELETE, LIST  or QUIT
      cout << "What would you like to do, ADD, SEARCH or DELETE?" << endl;
      cout << "To list all currently entered media, type LIST, just type QUIT to quit !!!" << endl;
      cin >> inputString;
     
      //Based on input from user, call different functions
      //passing vector pointer to vector of media pointers
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
   
    //Prompt for type of digital media to be entered
    cout << "To enter music type 1, for movies type 2 and for video games type 3" << endl;
   
    
    int mediaType = 0;
    char title[80];
    char publisher[80];
    char director[80];
    char rating[80];
    char artist[80];
    int year = 0;
    int duration = 0;
   
    cin >> mediaType;

    if(mediaType == 1)
    {
        //Prompt to enter new music media info
        cout << "Enter Music media info: " << endl;
        cin.get();
        cout << "Enter Title: " << endl;
        cin.getline(title, 80);
        cout << "Enter Year: " << endl;
        cin >> year;
        cin.get();
        cout << "Enter Artist: " << endl;
        cin.getline(artist, 80);
        cout << "Enter Duration: " << endl;
        cin >> duration;
        cin.get();
        cout << "Enter Publisher: " << endl;
        cin.getline(publisher, 80);
        
        //Print the info that is entered
        cout << "You entered: " ;
        cout << "Title: " << title << ", ";
        cout << "Year: " << year << ", ";
        cout << "Artist: " << artist << ", ";
        cout << "Duration: " << duration << ", ";
        cout << "Publisher: " << publisher << endl;
        
        //newMusic is pointer to Music child class object
        Music* newMusic = new Music();
        
        //Call the methods on the Music object to set the values entered
        //Note that there is a setTitle method in the parent class but overridden at child class level.
        newMusic->setTitle(title);
        newMusic->setYear(year);
        newMusic->setArtist(artist);
        newMusic->setDuration(duration);
        newMusic->setPublisher(publisher);
        
        digMediaVect.push_back(newMusic);
        
    }
    if(mediaType == 2)
    {
        //Prompt to enter new movie media info
        cout << "Enter Movie media info: " << endl;
        cin.get();
        cout << "Enter Title: " << endl;
        cin.getline(title, 80);
        cout << "Enter Year: " << endl;
        cin >> year;
        cin.get();
        cout << "Enter Director: " << endl;
        cin.getline(director, 80);
        cout << "Enter Duration: " << endl;
        cin >> duration;
        cin.get();
        cout << "Enter Rating: " << endl;
        cin.getline(rating, 80);
        
        cout << "You entered: " ;
        cout << "Title: " << title << ", ";
        cout << "Year: " << year << ", ";
        cout << "Director: " << director << ", ";
        cout << "Duration: " << duration << ", ";
        cout << "Rating: " << rating << endl;

        //Call the methods on the Movies object to set the values entered
        //Note that there is a setTitle method in the parent class but overridden at child class level.
        Movies* newMovie = new Movies();
        
        newMovie->setTitle(title);
        newMovie->setYear(year);
        newMovie->setDirector(director);
        newMovie->setDuration(duration);
        newMovie->setRating(rating);
        
        digMediaVect.push_back(newMovie);
        
    }
    if(mediaType == 3)
    {
        
        //Prompt to enter new movie media info
        cout << "Enter Movie media info: " << endl;
        cin.get();
        cout << "Enter Title: " << endl;
        cin.getline(title, 80);
        cout << "Enter Year: " << endl;
        cin >> year;
        cin.get();
        cout << "Enter Rating: " << endl;
        cin.getline(rating, 80);
        cout << "Enter Publisher: " << endl;
        cin.getline(publisher, 80);
        
        cout << "You entered: " ;
        cout << "Title: " << title << ", ";
        cout << "Year: " << year << ", ";
        cout << "Rating: " << rating << ", ";
        cout << "Publisher: " << publisher << endl;
        

        //Call the methods on the VideoGames object to set the values entered
        //Note that there is a setTitle method in the parent class but overridden at child class level.
        VideoGames* newVideoGame = new VideoGames();
        
        newVideoGame->setTitle(title);
        newVideoGame->setYear(year);
        newVideoGame->setRating(rating);
        newVideoGame->setPublisher(publisher);
        
        digMediaVect.push_back(newVideoGame);
    }
    
}

void SEARCH(vector<DigMedia*> &digMediaVect) {
   
    int searchType = 1;
    char searchtitle[80];
    int searchyear = 0;
    
    //Prompt user for search type
    cout << "To search by title, type 1, to search by year type 2" << endl;
    cin >> searchType;
    
    if (searchType == 1)
    {
        //Prompt user for title
        cout << "Enter the title of the media: " << endl;
        cin >> searchtitle;
        
        //Loop through the vector and if match found, print the media info.
        for(int i =0; i < digMediaVect.size(); i++) {
            if(strcmp(searchtitle, digMediaVect[i]->getTitle()) == 0)
            {
                //Print media information
                PRINT(digMediaVect[i]);
            }
        }
    }
    else if(searchType == 2)
    {
        //Prompt user for year
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
    //Depending on mediaType print corresponding fields
    if(digMediaPtr->getMediaType() == 1)
    {
        cout << "Music--" ;
        
        //We can call the parent class methods to get Title and year
        cout << "Title: " << digMediaPtr->getTitle() << ", ";
        cout << "Year: " << digMediaPtr->getYear() << ", ";
        
        //To call the methods of the child class Music, static case the digMedia object with Music
        //We are able to do this because, we are tracking the media type in the object. We set it to 1 in the constructor.
        cout << "Artist: " << ((Music*)digMediaPtr)->getArtist() << ", ";
        cout << "Duration: " << ((Music*)digMediaPtr)->getDuration() << ", ";
        cout << "Publisher: " << ((Music*)digMediaPtr)->getPublisher() << endl;
    }
    else if(digMediaPtr->getMediaType() == 2)
    {
        cout << "Movie--" ;
        cout << "Title: " << digMediaPtr->getTitle() << ", ";
        cout << "Year: " << digMediaPtr->getYear() << ", "; 
        
        //To call the methods of the child class Movies, static case the digMedia object with Movies
        //We are able to do this because, we are tracking the media type in the object. We set it to 2 in the constructor.
        cout << "Director: " << ((Movies*)digMediaPtr)->getDirector() << ", ";
        cout << "Duration: " << ((Movies*)digMediaPtr)->getDuration() << ", ";
        cout << "Rating: " << ((Movies*)digMediaPtr)->getRating() << endl;
    }
    else if(digMediaPtr->getMediaType() == 3)
    {
        cout << "Video Game--" ;
        cout << "Title: " << digMediaPtr->getTitle() << ", ";
        cout << "Year: " << digMediaPtr->getYear() << ", ";
        
        //To call the methods of the child class VideoGames, static case the digMedia object with VideoGames
        //We are able to do this because, we are tracking the media type in the object. We set it to 3 in the constructor.
        cout << "Publisher: " << ((VideoGames*)digMediaPtr)->getPublisher() << ", ";
        cout << "Rating: " << ((VideoGames*)digMediaPtr)->getRating() << endl;
    }
   
}

void LIST(vector<DigMedia*> &digMediaVect) {
   
    //Print all the media looping through all elements of the vecor
    //Depending on mediaType print corresponding fields
    cout << endl << "Below is the list of all media currently stored: " << endl;
   
    for(int i =0; i < digMediaVect.size(); i++) {
        
        if(digMediaVect[i]->getMediaType() == 1)
        {
            cout << "Music--" ;
            cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
            cout << "Year: " << digMediaVect[i]->getYear() << ", ";
            //To call the methods of the child class Music, static case the digMedia object with Music
            //We are able to do this because, we are tracking the media type in the object. We set it to 1 in the constructor.
            cout << "Artist: " << ((Music*)digMediaVect[i])->getArtist() << ", ";
            cout << "Duration: " << ((Music*)digMediaVect[i])->getDuration() << ", ";
            cout << "Publisher: " << ((Music*)digMediaVect[i])->getPublisher() << endl;
        }
        else if(digMediaVect[i]->getMediaType() == 2)
        {
            cout << "Movie--" ;
            cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
            cout << "Year: " << digMediaVect[i]->getYear() << ", "; 
            //To call the methods of the child class Movies, static case the digMedia object with Movies
            //We are able to do this because, we are tracking the media type in the object. We set it to 2 in the constructor.
            cout << "Director: " << ((Movies*)digMediaVect[i])->getDirector() << ", ";
            cout << "Duration: " << ((Movies*)digMediaVect[i])->getDuration() << ", ";
            cout << "Rating: " << ((Movies*)digMediaVect[i])->getRating() << endl;
        }
        else if(digMediaVect[i]->getMediaType() == 3)
        {
            cout << "Video Game--" ;
            cout << "Title: " << digMediaVect[i]->getTitle() << ", ";
            cout << "Year: " << digMediaVect[i]->getYear() << ", ";
            //To call the methods of the child class VideoGames, static case the digMedia object with VideoGames
            //We are able to do this because, we are tracking the media type in the object. We set it to 3 in the constructor.
            cout << "Publisher: " << ((VideoGames*)digMediaVect[i])->getPublisher() << ", ";
            cout << "Rating: " << ((VideoGames*)digMediaVect[i])->getRating() << endl;
        }
        
    }
   
    cout << endl;
   
}

void DELETE(vector<DigMedia*> &digMediaVect) {
    
    int searchType = 1;
    char delTitle[80];
    int searchyear = 0;
    char confirm[2];
    
    //Prompt for media to delete
    cout << "Do you want to delete media by title or year?  Type 1 for title and 2 for year." << endl;
    cin >> searchType;
    
    if(searchType == 1)
    {
        //Prompt user for title
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
        
        //Have the user confirm that the media can be deleted.
        //If yes, loop again to delete them
        cout << "Please confirm you want to delete all listed media above: y or n ?" << endl;
        cin >> confirm;
        
        if(strcmp(confirm, "y") == 0)
        {
            int size = digMediaVect.size();
            int i = 0;
            
            while(i < size) {
                if(delTitle == digMediaVect[i]->getTitle())
                {
                    //delete the data - this will trigger the destructor
                    delete digMediaVect[i];
                    //Remove the student from vector
                    digMediaVect.erase(digMediaVect.begin()+i);
    
                    //Confirm deletion
                    cout << "Media with year " << searchyear << " is now deleted. " << endl;
                    size = digMediaVect.size();
                }
                else
                {
                    //Increment only if media at this position is not deleted.
                    i++;
                }
            }
        }
    }
    else if(searchType == 2)
    {
        //Prompt user for title
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
        
        //Have the user confirm that the media can be deleted.
        //If yes, looping again and delete them
        cout << "Please confirm you want to delete all listed media above: y or n ?" << endl;
        cin >> confirm;
        
        if(strcmp(confirm, "y") == 0)
        {
            int size = digMediaVect.size();
            int i = 0;
            
            while(i < size) {
                if(searchyear == digMediaVect[i]->getYear())
                {
                    //delete the data - this will trigger the destructor
                    delete digMediaVect[i];
                    //Remove the student from vector
                    digMediaVect.erase(digMediaVect.begin()+i);
    
                    //Confirm deletion
                    cout << "Media with year " << searchyear << " is now deleted. " << endl;
                    size = digMediaVect.size();
                }
                else
                {
                    //Increment only if media at this position is not deleted.
                    i++;
                }
            }
        }
        
        
    }
    
}
