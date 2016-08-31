//******************************************
// File: VideoGame.cpp
//
// Purpose: Class which stores video game information
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

#include "VideoGame.h"

//******************************************
// Function: VideoGame()
// 
// Purpose: Default Constructor. Set things
//      So they don't have garbage in them.
//
//******************************************
VideoGame::VideoGame()
{
    price  = 0.0;
    rating = "";
    title  = "";
}

//******************************************
// Function: VideoGame(string, string, double)
// 
// Purpose: Constructor with arguments for game
//
//******************************************
VideoGame::VideoGame(string _title, string _rating, double _price)
{
    price  = _price;
    rating = _rating;
    title = _title;
}

//******************************************
// Function: VideoGame(const VideoGame)
// 
// Purpose: Copy Constructor.
//
//******************************************
VideoGame::VideoGame(const VideoGame &_v)
{
    price  = _v.price;
    rating = _v.rating;
    title  = _v.title;
}

//******************************************
// Function: getTitle()
// 
// Purpose: Returns Title (string)
//
//******************************************
string VideoGame::getTitle()
{
    return title;
}

//******************************************
// Function: getRating()
// 
// Purpose: Returns Rating (string)
//
//******************************************
string VideoGame::getRating()
{
    return rating;
}

//******************************************
// Function: getPrice()
// 
// Purpose: Returns Price (double)
//
//******************************************
double VideoGame::getPrice()
{
    return price;
}

//******************************************
// Function: setTitle(string)
// 
// Purpose: Set the video game's title.
//
//******************************************
void VideoGame::setTitle(string _title)
{
    title = _title;
}

//******************************************
// Function: setRating(string)
// 
// Purpose: Set the Rating of the video game
//
//******************************************
void VideoGame::setRating(string _rating)
{
    rating = _rating;
}

//******************************************
// Function: setPrice(double)
// 
// Purpose: Set the price of the video game
//
//******************************************
void VideoGame::setPrice(double _price)
{
    price = _price;
}
