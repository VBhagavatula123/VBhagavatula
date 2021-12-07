#pragma once
#include <iostream>
#include <cstring>
using namespace std;


class DigMedia {
  public:
    DigMedia();
    ~DigMedia();
    
    //Just a dummy. Does not do anything. Will be overridden at child level. 
    //Therefore declared virtual
    virtual void setTitle(char*);
    char* getTitle();
    
    void setYear(int);
    int getYear();
    
    int getMediaType();
    
    
  protected:
    char* m_title;
    int m_year;
    
    int m_mediaType;
};
