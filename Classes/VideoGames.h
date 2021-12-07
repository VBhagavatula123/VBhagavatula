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
