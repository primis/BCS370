//******************************************
// File: VideoGameCollection.h
//
// Purpose: Prototype definition for VideoGameCollection Class
//
// Written By: Nicholas Sargente
// 
// Compiler: Visual C++ 2015 (MSVC++ 14.0)
//
// Update Information
// ===================
//
// Date: 8/31/16
// Name: Nicholas Sargente
// Description: Initial Writeup
//
//******************************************
#ifndef __VIDEOGAMECOLLECTION_H
#define __VIDEOGAMECOLLECTION_H

#include "VideoGame.h"

#define COLLECTION_SIZE 32

// For the GetAuthor() function.
#define WHY_IS_THIS_PART_OF_THE_HOMEWORK "Nicholas Sargente"

class VideoGameCollection {
private:
    // Size defined above class.
    VideoGame games[COLLECTION_SIZE];

public:
    // Constructor
    VideoGameCollection();
    
    // Index Object manipulation
    void Set(int index, VideoGame v);
    VideoGame Get(int);
    void Initialize();
    
    // Metadata
    int Size();
    double TotalValue();
    VideoGame MostExpensive();
    int PriceRangeCount(double, double);
    
    // Search Function
    bool FindByTitle(string title, VideoGame &v);
    
    // Misc.
    string GetAuthor();
};

#endif // __VIDEOGAMECOLLECTION_H