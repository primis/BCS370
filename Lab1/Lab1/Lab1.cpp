//******************************************
// File: Lab1.cpp
//
// Purpose: Contains main() Function
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

int main()
{
    WallPost w;
    w = WallPost();
    // Couldn't think of anything good to write. 
    w.setComment("First Post");
    w.setName("Nick Sargente");
    w.AddLike("God");
    w.AddLike("Myspace Tom");
    w.AddLike("Mom");
    cout << w << endl;

    // Seemed more portable than WAIT
    while (true);
    return 0;

}

