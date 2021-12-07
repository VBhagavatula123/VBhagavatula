#include <iostream>
#include <cstring>

#include "Music.h"

using namespace std;

Music::Music(){
  cout << "In constructor of Music media" << endl;
  m_mediaType = 1;
}

Music::~Music(){
    cout << "Invoking the destructor of Music class" << endl;
    delete[] m_artist;
    delete[] m_publisher;
}

//Override of parent method
void Music::setTitle(char* newTitle){
    m_title = new char[80];
    strcpy(m_title, newTitle);
}

void Music::setArtist(char* newArtist){
    m_artist = new char[80];
    strcpy(m_artist, newArtist);
}

void Music::setDuration(int newDuration){
    m_duration = newDuration;
    
}

void Music::setPublisher(char* newPublisher){
    m_publisher = new char[80];
    strcpy(m_publisher, newPublisher);
}

char* Music::getArtist(){
    return m_artist;
}

int Music::getDuration(){
    return m_duration;
}

char* Music::getPublisher(){
    return m_publisher;
}

