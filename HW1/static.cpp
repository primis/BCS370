#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{   
    // Number of elements in the array.
    const int arraySize = 100;
    double numbers[arraySize];
    double average;
    int i;
    
    // I program on linux, so I run from command line.
    
    if (argc < 2) // See if we got a file name
    {
        cout << "Usage: " << argv[0] << " <File>" << endl;
        return 0;
        // Quit early, no file.
    }

    // I follow the unix philosophy: Be terse. No uneeded output here.

    ifstream in(argv[1]);
    if (!in) { // Check if file exists
        // Write to Stderr if not.
        cerr << "File " << argv[1] << " not found on disk." << endl;
        // Close early
        in.close();
        return -1;
    }
    for (i = 0; i<arraySize; i++) {
        in >> numbers[i];  
    }
    in.close();
    // As soon as we finish with the file as an iStream, try as oStream.

    ofstream out(argv[1], ios::app); // Appending to end.
    if (!out) {
        cerr << "Unable to open " << argv[1] << " for output." << endl;
        out.close();
        return -1;
    }
    
    for (i=0; i<arraySize; i++) {
        average += numbers[i];
    }

    average = average / (float)arraySize;   // Floating point division   


    out << endl << average << endl; // output average.
    
    return 0;
}
