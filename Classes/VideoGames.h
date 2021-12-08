/* header file for 1 of 3 sub-classes. Must include the headerfile of the parent to inherit and follows similar structure. as the other 2.
Protected objects are ones that are unique to the Media Type.*/

#pragma once
#include <iostream>
#include <cstring>
#include "DigMedia.h"
using namespace std;

class VideoGames : public DigMedia {
  public:
    VideoGames();
    ~VideoGames();
    
    void setTitle(char*);
    
    void setPublisher(char*);
    void setRating(char*);
    char* getPublisher();
    char* getRating();
    
  protected:
    char* m_publisher;
    char* m_rating;
};
