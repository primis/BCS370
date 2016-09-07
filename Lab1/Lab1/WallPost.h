//******************************************
// File: WallPost.h
//
// Purpose: Models a simple Facebook Wall Post
//
// Written By: Nicholas Sargente
// 
// Compiler: Visual C++ 2015 (MSVC++ 14.0)
//
// Update Information
// ===================
//
// Date: 9/7/16
// Name: Nicholas Sargente
// Description: Initial Writeup
//
//******************************************

#ifndef __WALLPOST_H
#define __WALLPOST_H

#include <string>
#include <list>

class WallPost {
private:
    std::string name, comment;
    std::list<std::string> likes;
public:
    WallPost();
    WallPost(std::string _name, std::string _comment);
    WallPost(const WallPost &_w);

    std::string getName();
    std::string getComment();
    void setName(std::string _n);
    void setComment(std::string _c);
    
    void AddLike(std::string _n);
    friend std::ostream & operator<<(std::ostream & os, const WallPost & w);
};


#endif // __WALLPOST_H