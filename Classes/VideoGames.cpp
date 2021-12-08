/*just the functionality of the video games class*/

#include <iostream>
#include <cstring>
#include "VideoGames.h"
using namespace std;

VideoGames::VideoGames(){
  cout << "In constructor of VideoGames media" << endl;
  m_mediaType = 3;
}

VideoGames::~VideoGames(){
    cout << "Invoking the destructor of Movies class" << endl;
    delete[] m_publisher;
    delete[] m_rating;
}

//Override of parent method
void VideoGames::setTitle(char* newTitle){
    m_title = new char[80];
    strcpy(m_title, newTitle);
}

void VideoGames::setPublisher(char* newPublisher){
    m_publisher = new char[80];
    strcpy(m_publisher, newPublisher);
}

void VideoGames::setRating(char* newRating){
    m_rating = new char[80];
    strcpy(m_rating, newRating);
}
    
char* VideoGames::getPublisher(){
    return m_publisher;
}

char* VideoGames::getRating(){
    return m_rating;
}

