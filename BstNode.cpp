/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 6					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program that will use BST to slove morse code            		   *
*******************************************************************************************/

//include local libar
#include "BstNode.h"

//default constructor
BstNode::BstNode(char englishAlpha, string morseAlpha)
{
	this->englishAlpha = englishAlpha;
	this->morseAlpha = morseAlpha;
	this->leftNode = nullptr;
	this->rightNode = nullptr;
}