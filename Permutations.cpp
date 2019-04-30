//============================================================================
// Name        : Permutations.cpp
// Author      : Aristeidis Angelopoulos
// Version     : 1.0
// Copyright   : 
// Description : Calculate all permutations for N places
//============================================================================

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <vector>
using namespace std;

//Characters to use.
static char Letters[] ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*(){}[]=+-_:;\"\'`<,>.?/|\\~";
vector<string> Words;
ofstream Output;
//Recursive function to get all possible permutations of specific Characters for N spaces.
int Recursion(int Depth, string CurrentWord, string PreviousWord, int Counter) {
	Depth--;
	//Loops for all characters
	for (unsigned int i=0; i<strlen(Letters); i++) {
		Counter++;
		CurrentWord = CurrentWord + Letters[i];
		if (Depth > 0) {
			//Calls itself
			Counter = Recursion(Depth, CurrentWord, CurrentWord,Counter);
		} else {
			//Put words into Vector
			Words.push_back(CurrentWord);
			//Put words into a file
			//Output << CurrentWord << endl;
		}
		CurrentWord = PreviousWord;
		if (Counter % 100000 == 0){
			cout << Counter << endl;
		}
	}
	return Counter;
}

int main() {
	Output.open("Output.txt", ios_base::app);
	Recursion(4, "", "", 1);
	for (int i=0; i<Words.size(); i++) {
		Output << Words[i] << endl;
	}
	return 0;
}
