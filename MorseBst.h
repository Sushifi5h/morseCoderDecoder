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
#include <fstream>

//Include local libraries
#include "BstNode.h"

//for convience
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fstream;
using namespace std;

//main class to run Bst
class MorseBst {
public://public access functions
	MorseBst() { this->bstHeadNode = nullptr; this->makeTree(); }//defualt construct
	~MorseBst() { this->deleteTree(this->bstHeadNode); } //destructor delete tree
	void printInOrder() { this->printInOrder(this->bstHeadNode); } //call print function
	void search(string &input) { searchForMorse(this->bstHeadNode, input); }//call it
	void app(string input)
	{
		input = "";
		this->printInOrder(); //prints tree
		cout << "Done priting tree." << endl;
		this->readEnglishInput(input);//readenglish from file
		cout << "Done reading from file." << endl;
		cout << input << endl;
		this->allTogetherNow(input); //do the morse coding
		cout << "Done Converting to morse.\nMorse: " << input << endl;
	}
private://private vars and functions
	BstNode *bstHeadNode; //will store the head of the BST

	BstNode * makeTreeNode(char englishAlpha, string morseAlpha); //allocate memory in heap
	void insertBstTree(BstNode *& bstHeadNode, char englishAlpha, string morseAlpha); //inser in order
	void printInOrder(BstNode *& bstHeadNode) const; //print in order
	void makeTree(); //makes tree from file have head pointer and file delcared 
	void deleteTree(BstNode *& bstHeadNode); //delete tree
	void searchForMorse(BstNode *& bstHeadNode, string &searchingAplha) const; //search alpha return morse
	void readEnglishInput(string &mainScope); //read from file may need more inputs
	void allTogetherNow(string &mainScope); //should encrypt
};