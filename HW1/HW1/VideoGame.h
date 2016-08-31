//******************************************
// File: VideoGame.h
//
// Purpose: Prototype definition for VideoGame Class
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

#ifndef __VIDEOGAME_H
#define __VIDEOGAME_H

#include <string>
using namespace std;

class VideoGame {
private:
    string title;
    string rating;
    double price;
public:
    // Constructors; Default, Custom Init, and Copy
    VideoGame();
    VideoGame(string _title, string _rating, double _price);
    VideoGame(const VideoGame &_v);
    // Getters
    string getTitle();
    string getRating();
    double getPrice();
    // Setters
    void setTitle(string _title);
    void setRating(string _rating);
    void setPrice(double _price);
};

#endif // __VIDEOGAME_H
