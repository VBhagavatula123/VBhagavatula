#include <iostream>
#include <cstring>
#include "Movies.h"
using namespace std;

Movies::Movies(){
  cout << "In constructor of Movies media" << endl;
  m_mediaType = 2;
}

Movies::~Movies(){
    cout << "Invoking the destructor of Movies class" << endl;
    delete[] m_director;
    delete[] m_rating;
}


//Override of parent method
void Movies::setTitle(char* newTitle){
    m_title = new char[80];
    strcpy(m_title, newTitle);
}

void Movies::setDirector(char* newDirector){
    m_director = new char[80];
    strcpy(m_director, newDirector);
}

void Movies::setDuration(int newDuration){
    m_duration = newDuration;
}

void Movies::setRating(char* newRating){
    m_rating = new char[80];
    strcpy(m_rating, newRating);
}
    
char* Movies::getDirector(){
    return m_director;
}

int Movies::getDuration(){
    return m_duration;
}

char* Movies::getRating(){
    return m_rating;
}
