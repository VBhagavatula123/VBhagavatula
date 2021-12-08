/* header file for 1 of 3 sub-classes. Must include the headerfile of the parent to inherit and follows similar structure. as the other 2.
Protected objects are ones that are unique to the Media Type.*/

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
