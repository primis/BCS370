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
    // We want to have a clean slate when we start.
    Initialize();
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
    Get(index).setPrice(v.getPrice());
    Get(index).setRating(v.getRating());
    Get(index).setTitle(v.getTitle());
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
    // This is the only time we use the raw array.
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
    // Iterator.
    int i;
    // Walk the collection
    for (i = 0; i < Size(); i++) {
        if (upperBound >= Get(i).getPrice() && Get(i).getPrice() >= lowerBound) {
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
    // Init max to 0.0 so we can check properly.
    double max = 0.0;
    VideoGame v;

    // Traverse the list, find most pricey.
    // If prices are the same, uses last instance.
    for (i = 0; i < Size(); i++) {
        if (Get(i).getPrice() >= max) {
            max = Get(i).getPrice();
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
        if (Get(i).getTitle() == title) {
            // We found it, set v and return true.
            v = Get(i);
            return true;
        }
    }
    // If we've reached this point, it doesn't exist.
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
    // Iterator.
    int i;
    // Init total to 0.0 so we don't end up with an incorrect answer.
    double total = 0.0;
    // Add them all up.
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
    // Init each individual object to a clean value.
    for (i = 0; i < Size(); i++) {
        Get(i).setPrice(0.0);
        Get(i).setRating("");
        Get(i).setTitle("");
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
    // Located in VideoGameCollection.h
    // Default Value is Nicholas Sargente
    return WHY_IS_THIS_PART_OF_THE_HOMEWORK;
}
