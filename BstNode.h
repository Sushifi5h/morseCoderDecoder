/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 6					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program that will use BST to slove morse code            		   *
*******************************************************************************************/

//gaurd code
#pragma once

//include std libraries
#include <iostream>
#include <string>

//get namespaces
using std::cout;
using std::cin;
using std::endl;
using std::string;

//Bst Node <- will data holder 
class BstNode {
public: //public access functions

		//construct destructor
		BstNode(char englishAlpha = '\0', string morseAlpha = "");

		//getters
		char getEnglishAlpha(void) { return this->englishAlpha; }
		string getMorseAlpha(void) { return this->morseAlpha; }
		BstNode *& getLeftNode(void) { return this->leftNode; }
		BstNode *& getRightNode(void) { return this->rightNode; }

		//setters
		void setEnglishAplha(char input) { this->englishAlpha = input; }
		void setmorseAlpha(string input) { this->morseAlpha = input; }

private: //private vars and functions
	char englishAlpha;
	string morseAlpha;
	BstNode *leftNode;
	BstNode *rightNode;
};