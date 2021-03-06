// CST126_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
using namespace std;


#include "stock.h"

//--------------------------------------------------------------------
bool OpenFile(ifstream& input_file);
void fill_stock_from_file(Stock &, ifstream &, int & count);
void tokenizer(char line[], string & symbol, string & name_with_quotes, double & price, double & earnings);

int main(void)
{
	//  STUDENT TASK - define your variables

	// STUDENT TASK - look these up and add a comment to each one to describe what they are doing
	cout.setf(ios::fixed);   // 
	cout.setf(ios::showpoint); //
	cout.precision(2);  //

	ifstream stock_file;
	cout << "Welcome to the Stock Picker" << endl << endl;

	if (OpenFile(stock_file)) {
		while (!stock_file.eof()) {
			fill_stock_from_file(stock[number_stocks], stock_file, number_stocks);
		}
		cout << endl;
		// STUDENT TASK - Loop through your stocks and print them
		cout << endl;
		cout << endl;
		cout << "If you had a 10% appreciation in price the values would be" << endl;
		// STUDENT TASK - Loop through your stocks and 1 - give them a 10% price increase 2 - print them


	}

	return 0;

}

//--------------------------------------------------------------------
// Functions
//--------------------------------------------------------------------
//--------------------------------------------------------------------
// bool    OpenFile(file)
// Input:  file name (retrieved from user);
// Output: file pointer. 
//         Returns true if able to open file and false if 
//           unable to open file
//  Hint:  we've had hands on that did this.
bool OpenFile(ifstream& input_file)
{

	// STUDENT TASK - Prompt the end user for the name of the file like in the sample output.  

	if (input_file.fail())
	{
		//  STUDENT TASK:  GIVE THE USER AN ERROR MESSAGE
		return false;
	}
	else
		return true;


}


//--------------------------------------------------------------------
void fill_stock_from_file(Stock & s, ifstream & in_file, int & count)
{
	char line[81];

	//  STUDENT TASK - you'll need some variables.



	in_file.getline(line, 80);
	if (!in_file.eof()) {
		tokenizer(line, symbol, name_with_quotes, price, earnings);
	//  STUDENT TASK -  update your stock here
	}
}

void tokenizer(char line[], string & symbol,string & name_with_quotes,double & price, double & earnings)
{
	

	string token;
	istringstream iss(line);

	std::getline(iss, symbol, ',');
	std::getline(iss, name_with_quotes, ',');
	std::getline(iss, token, ',');
	price = atof(token.c_str());
	std::getline(iss, token, ',');
	earnings = atof(token.c_str());

}
