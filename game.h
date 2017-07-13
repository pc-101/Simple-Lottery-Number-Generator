#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <cstdlib>
#include <ctime> 
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string> 

#include <Windows.h>
#include <stdexcept>
using namespace std; 

class Lotto {
public: 
	void start(); 

private: 
	struct lottoType
	{
		/******
		@var num is a count of how many numbers are in the lottery game
		@var numRange is a count of the range for regular numbers in the game
		@var numMega is a count of how many mega numbers are in the lottery game
		@var numMRange is a count of the range for mega numbers in the game
		@var name is a string that holds the name of the game
		@var resultMega is an integer variable that stores the value of the mega number
		*******/
		int num,
			numRange,
			numMega,
			numMRange,
			resultMega; 
		string name; 
	} mega, power, super, fantasy, daily4, daily3;

	int random_integer, nums;
	char choice = ' '; 

	  // Enum to ease decision process
	enum type {
		Mega,
		Power,
		Super,
		Fantasy,
		Daily4,
		Daily3
	};

	  // Users don't need to call the below functions
	void decision(char ch); 
	void display(lottoType t); 
	void dispAll(); 
	void init(type t); 
};

#endif // GAME_INCLUDED