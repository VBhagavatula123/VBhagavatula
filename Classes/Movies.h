#pragma once
#include <iostream>
#include <cstring>
#include "DigMedia.h"
using namespace std;

class Movies : public DigMedia {
  public:
    Movies();
    ~Movies();
    
    void setTitle(char*);
    
    void setDirector(char*);
    void setDuration(int);
    void setRating(char*);
    
    char* getDirector();
    int getDuration();
    char* getRating();
    
  protected:
    char* m_director;
    int m_duration;
    char* m_rating;

};
