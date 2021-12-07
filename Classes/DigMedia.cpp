#include <iostream>
#include <cstring>

#include "DigMedia.h"

using namespace std;

DigMedia::DigMedia(){
  cout << "In constructor of parent digital media" << endl;
  m_title = new char[80];
  m_year=1900;
  //This m_mediaType value is set to 0 in this parent class.
  //Child class constructors will set it to actual mediaType, 1, 2 or 3 depending on music, movies or video games
  m_mediaType = 0;
}

DigMedia::~DigMedia(){
    cout << "Invoking the destructor of parent class" << endl;
    delete[] m_title;
}

void DigMedia::setTitle(char* newTitle)
{
  //Just a dummy. Does not do anything. Will be overridden at child level. 
  //m_title = new char[80];
  //strcpy(m_title, newTitle);
}

void DigMedia::setYear(int newYear)
{
  m_year = newYear;
}

char* DigMedia::getTitle(){
  return m_title;
}

int DigMedia::getYear(){
  return m_year;
}

int DigMedia::getMediaType(){
  return m_mediaType;
}
