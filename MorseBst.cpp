/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 6					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program that will use BST to slove morse code            		   *
*******************************************************************************************/

//Include local libraries
#include "MorseBst.h"

//make Bst Node
BstNode * MorseBst::makeTreeNode(char englishAlpha, string morseAlpha)
{
	BstNode *temp = nullptr;
	temp = new BstNode;

	if (temp != nullptr)
	{//check for memory allocation
		temp->setEnglishAplha(englishAlpha);
		temp->setmorseAlpha(morseAlpha);
	}

	return temp; //will return null if memory issues
}

//make tree from file
void MorseBst::makeTree(void)
{
	//delcare file and open it with 
	fstream morseBstFile;
	morseBstFile.open("MorseTable.txt");

	//test vars
	char englishChar = '\0';
	string morseString = "";

	if (morseBstFile.is_open())
	{//if file stream is open
		while (!morseBstFile.eof())
		{
			morseBstFile >> englishChar >> morseString;
			insertBstTree(this->bstHeadNode, englishChar, morseString);
		}
	}
	morseBstFile.close();
}

//inser in order
void MorseBst::insertBstTree(BstNode *& bstHeadNode, char englishAlpha, string morseAlpha)
{
	
			//set values
			if (bstHeadNode == nullptr)
			{
				BstNode *temp = nullptr;
				temp = new BstNode;
				temp->setEnglishAplha(englishAlpha);
				temp->setmorseAlpha(morseAlpha);
				bstHeadNode = temp; //set node
			}
			else if (englishAlpha > bstHeadNode->getEnglishAlpha())//check if alpha is greater than go right
				insertBstTree(bstHeadNode->getRightNode(), englishAlpha, morseAlpha);
			else if (englishAlpha < bstHeadNode->getEnglishAlpha())// check if alpha is less go left
				insertBstTree(bstHeadNode->getLeftNode(), englishAlpha, morseAlpha);
}

void MorseBst::printInOrder(BstNode *& bstHeadNode) const //print in order
{
	if (bstHeadNode != nullptr)
	{
		printInOrder(bstHeadNode->getLeftNode()); //go as far left as possible
		cout << bstHeadNode->getEnglishAlpha() << " " << bstHeadNode->getMorseAlpha() << endl; //can't go anyfurther print it
		printInOrder(bstHeadNode->getRightNode()); //go right 
	}
}

void MorseBst::deleteTree(BstNode *& bstHeadNode) //delete tree use post trivarse
{
	if (bstHeadNode != nullptr)
	{
		deleteTree(bstHeadNode->getLeftNode()); //go as far left as possible
		deleteTree(bstHeadNode->getRightNode()); //go right 
		delete bstHeadNode;
	}
}

void MorseBst::searchForMorse(BstNode *& bstHeadNode, string &searchingAplha) const
{
	if (bstHeadNode->getEnglishAlpha() == searchingAplha.at(0))
		searchingAplha = bstHeadNode->getMorseAlpha();
	else if (searchingAplha.at(0) > bstHeadNode->getEnglishAlpha())
		searchForMorse(bstHeadNode->getRightNode(), searchingAplha);
	else if (searchingAplha.at(0) < bstHeadNode->getEnglishAlpha())
		searchForMorse(bstHeadNode->getLeftNode(), searchingAplha);	
}

void MorseBst::readEnglishInput(string &mainScope) //read from file may need mor
{
	//local vars
	int rawGetLineSize = 0;
	string rawGetLine = "", formatedGetLine = "";


	mainScope = "";

	//fstream objected opend
	fstream englishText;
	englishText.open("Covert.txt");

	if (englishText.is_open())
	{//check fstream object for properly opening file
		while (getline(englishText, rawGetLine))
		{//line from files
			formatedGetLine = "";//each line
			rawGetLineSize = rawGetLine.length();

			for (std::string::iterator curString = rawGetLine.begin(); curString != rawGetLine.end(); ++curString)
			{
				if (*curString != ' ')
				{//handle white space with else statement
					//formatedGetLine += *curString;
					mainScope += *curString;
				}
				else if(*curString == '\n')
				{
					mainScope += '/';
				}
				else {//handling white space
					//formatedGetLine += '/';
					mainScope += '/';
				}
			}
			//mainScope = formatedGetLine;

		}
	}
	//fstream object closed
	englishText.close();
}

void MorseBst::allTogetherNow(string &mainScope)
{
	//local var
	int stringLen = 0;
	string toBeEncrypted = "", encrypted = "";

	//get string leng
	stringLen = mainScope.length();

	for (std::string::iterator curString = mainScope.begin(); curString != mainScope.end(); ++curString)
	{//look at each string
		toBeEncrypted = ""; //init to be encrypted
		if (toBeEncrypted == "")
		{
			if (*curString != '/')
			{//get morse for each char
				toBeEncrypted = toupper(*curString);
				searchForMorse(this->bstHeadNode, toBeEncrypted);
				encrypted = encrypted + " " + toBeEncrypted;
			}
			else {//just handle white space right nwo
				encrypted += "   ";
			}
		}
	}
	mainScope = encrypted;
}