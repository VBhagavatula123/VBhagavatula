#pragma once
#include <iostream>
#include <cstring>

#include "DigMedia.h"
using namespace std;

class Music : public DigMedia {
  public:
    
    Music();
    ~Music();
    
    void setTitle(char*);
    void setArtist(char*);
    void setDuration(int);
    void setPublisher(char*);
    
    char* getArtist();
    int getDuration();
    char* getPublisher();
  
  protected:
    char* m_artist;
    int m_duration;
    char* m_publisher;

};
