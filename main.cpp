//============================================================================
// Name        : Permutations.cpp
// Author      : Aristeidis Angelopoulos
// Version     : 1.0
// Copyright   : 
// Description : Main Program Example for Permutations
//============================================================================

#include "Permutations.h"
#include <vector>
#include <fstream>
using namespace std;

ofstream Output;
vector<string> Words;

int main() {
    //We can output the words into a file (takes a long time)
    Output.open("Output.txt", ios_base::app);
    int Depth=4;
    Recursion(Depth);
    for (int i=0; i < Words.size(); i++) {
        //We can also loop through them using Words[i]
        Output << Words[i] << endl;
    }
    return 0;
}
