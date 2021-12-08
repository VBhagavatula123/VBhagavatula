/*the header file of the parent class. "a cookie cutter" for the .cpp file which contains the functionality of the class.
Anything listed under public can be accessed outside of the class and anything Protected can only be accessed by the class and the sub-class.
the year and the title is information that sub-classes are going to want so they are listed under protected, but not public because public also includes the main file.*/

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
