//******************************************
// File: WallPost.cpp
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

#include "WallPost.h"
#include <iostream>
using namespace std;

//******************************************
// Function: Default Constructor
// 
// Purpose: Sets comment + name to blank.
//
//******************************************
WallPost::WallPost()
{
    comment = "";
    name = "";
}

//******************************************
// Function: Initial Condition constructor
// 
// Purpose: Set initial Conditions.
//
//******************************************
WallPost::WallPost(string _name, string _comment)
{
    comment = _comment;
    name = _name;
}

//******************************************
// Function: Copy Constructor
// 
// Purpose: Copies over from one instance to another
//
//******************************************
WallPost::WallPost(const WallPost & _w)
{
    comment = _w.comment;
    name = _w.name;
    // Deep Copy the List.
    likes = list<string>(_w.likes);
}

//******************************************
// Function: getName()
// 
// Purpose: Returns name of the poster.
//
//******************************************
string WallPost::getName()
{
    return name;
}

//******************************************
// Function: getComment()
// 
// Purpose: Returns string object of the Comment
//
//******************************************
string WallPost::getComment()
{
    return comment;
}

//******************************************
// Function: setName(string)
// 
// Purpose: Set's the wall post's original poster
//
//******************************************
void WallPost::setName(string _n)
{
    name = _n;
}

//******************************************
// Function: setComment(string)
// 
// Purpose: Set the actual comment of the post
//
//******************************************
void WallPost::setComment(string _c)
{
    comment = _c;
}

//******************************************
// Function: AddLike(string)
// 
// Purpose: Add to the list of users who liked this.
//
//******************************************
void WallPost::AddLike(string _n)
{
    likes.push_back(_n);
}

//******************************************
// Function: << operator overload
// 
// Purpose: Display the post in possibly the worst possible
//          Format imaginable.
//
//******************************************
ostream &operator<<(ostream &_os, const WallPost & _w)
{
    // I don't like dealing with const objects.
    WallPost post = WallPost(_w);

    // List comes with an iterator.
    list<string>::iterator i;

    _os << post.getName() << " said:"<< endl << post.getComment()<< endl;

    // Start at the first list node, end on the last one, pretty simple.
    for (i = post.likes.begin(); i != post.likes.end(); i++) {
        // We need to dereference i to it's type (string in this case) or
        // we'd end up spitting out a pointer.
        _os << *i << ", ";
    }
    _os << "all liked this.";
    return _os;
}