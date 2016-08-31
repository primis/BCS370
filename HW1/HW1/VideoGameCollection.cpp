#include "VideoGameCollection.h"
//******************************************
// File: VideoGameCollection.cpp
//
// Purpose: Stores VideoGame Classes
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

//******************************************
// Function: VideoGameCollection()
// 
// Purpose: Constructor for the collection.
//
//******************************************
VideoGameCollection::VideoGameCollection()
{   
    // This constructor is blank because the array is initialized when it's
    // Created and the VideoGame default constructor takes care of making
    // "sane" default values for us.
}

//******************************************
// Function: Set(int index, VideoGame v)
// 
// Purpose: Put the *values* of VideoGame v into the Collection
//
//******************************************
void VideoGameCollection::Set(int index, VideoGame v)
{
    // Remember, you have to deal with v when you're done storing it.
    // This isn't a reference copy.
    Get(index).setPrice  = v.getPrice();
    Get(index).setRating = v.getRating();
    Get(index).setTitle  = v.getTitle();
}

//******************************************
// Function: Size()
// 
// Purpose: Return the Size of the Collection
//
//******************************************
int VideoGameCollection::Size()
{
    // Defined in VideoGameCollection.h
    return COLLECTION_SIZE;
}

//******************************************
// Function: Get(int index)
// 
// Purpose: Get the object from the collection.
//
//******************************************
VideoGame VideoGameCollection::Get(int index)
{
    return games[index];
}

//******************************************
// Function: PriceRangeCount(double lowerBound, double upperBound)
// 
// Purpose: Count the number of games within a price range
//
//******************************************
int VideoGameCollection::PriceRangeCount(double lowerBound, double upperBound)
{
    // Counter.
    int c = 0;
    int i;
    // Walk the array
    for (i = 0; i < Size(); i++) {
        if (upperBound >= Get(i).getPrice >= lowerBound) {
            c++;
        }
    }
    return c;
}

//******************************************
// Function: MostExpensive()
// 
// Purpose: Find the most expensive game
//
//******************************************
VideoGame VideoGameCollection::MostExpensive()
{
    int i;
    double max = 0.0;
    VideoGame v;

    // Traverse the list, find most pricey.
    // If prices are the same, uses last instance.
    for (i = 0; i < Size(); i++) {
        if (Get(i).getPrice >= max) {
            max = Get(i).getPrice;
            v = Get(i);
        }
    }
    return v;
}

//******************************************
// Function: FindByTitle(string title, VideoGame &V)
// 
// Purpose: Find a VideoGame in the colleciton, if found, return true with 
//      v being a reference back to it.
//
//******************************************
bool VideoGameCollection::FindByTitle(string title, VideoGame &v)
{
    int i;
    for (i = 0; i < Size(); i++) {
        if (Get(i).getTitle == title) {
            v = Get(i);
            return true;
        }
    }
    return false;
}

//******************************************
// Function: TotalValue()
// 
// Purpose: Summation of the Prices
//
//******************************************
double VideoGameCollection::TotalValue()
{
    int i;
    double total = 0.0;

    for (i = 0; i < Size(); i++) {
        total += Get(i).getPrice();
    }
    return total;
}

//******************************************
// Function: Initialize()
// 
// Purpose: Return the Array back to clean slate
//
//******************************************
void VideoGameCollection::Initialize()
{
    int i;

    for (i = 0; i < Size(); i++) {
        Get(i).setPrice  = 0.0;
        Get(i).setRating = "";
        Get(i).setTitle  = "";
    }
}

//******************************************
// Function: GetAuthor()
// 
// Purpose: Hard Coded String of my Name
//
//******************************************
string VideoGameCollection::GetAuthor()
{
    return WHY_IS_THIS_PART_OF_THE_HOMEWORK;
}
