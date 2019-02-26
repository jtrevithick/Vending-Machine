/*
 * Programmer: Kyle Mayer
 * Email: kmayer1@cnm.edu
 * File: MoneyCtr.h
*/


#ifndef _MONEY_CTR
#define _MONEY_CTR

#include <string>

using namespace std;

/* 
 * The MoneyCtr handles all of the financial transactions and financial record 
 * keeping for the program. It accepts the money, counts it, makes change, keeps
 * track of the “Bank”(the initial coins that are placed in the MoneyCtr 
 * at the beginning of each day), and keeps track of all the coins entered 
 * and returned as change.
 *
 * Snack Items/Prices:
 *		Pop tarts    -   $1.60
 *	 	Sun chips    -   $1.25
 *	 	Snickers     -   $0.50
 *	 	Buble yum    -   $0.80
 *	 	Granola Bar  -   $0.95
*/

class MoneyCtr
{
private:
	//private member variables

	//-------Variables used in processing purchases
	double change = 0;	
	double inputAmount = 0;
	double purchaseAmount = 0;

	//-------User input variables
	//holds the count of each denonimation of user inputted money
	int inputNickels = 0;
	int inputDimes = 0;
	int inputQuarters = 0;
	int inputDollars = 0;

	//-------Bank variables
	//holds the count of each denomination in bank
	int numNickels = 20;
	int numDimes = 20;
	int numQuarters = 20;
	int numDollars = 20;
	double totalMoney = 28.0;

	//holds the count of denominations that are returned
	int	returnedNickels = 0;
	int	returnedDimes = 0;
	int	returnedQuarters = 0;
	int	returnedDollars = 0;

	string myChange; //holds formatted string description for change returned
	
	//private member functions
	void MakeChange();		//calculates the amount of change to give
	void CalcTotalMoney();  //calculates total money of the bank
	void CalcInputAmount(); //calculates total input from user/


public:
	MoneyCtr(); //default constructor

	//public member functions
	void SetInputMoney(int inputDollars, int inputQuarters, int inputDimes, int inputNickels);
	void SetSnackCost(double purchaseAmount); //sets purchase amount and calls MakeChange()
	string GetReturnMoney();	//returns string myChange
	double GetChange();			//returns double change
	string GetBeginningFile();  
	double GetInputTotal();
	string GetWriteInLog();
	void ReturnMoney(); //returns money if it is already added to bank and not dispensed
};

#endif