/*
* Programmer: Kyle Mayer
* Email: kmayer1@cnm.edu
* File: MoneyCtr.cpp
*/


#include "MoneyCtr.h"
#include <sstream>

//-------------Constructor
MoneyCtr::MoneyCtr()
{
	//member variables initialized within header file
	CalcTotalMoney();
}

//-------------Private Member Functions
void MoneyCtr::CalcTotalMoney()
{
	/*
	 * Method CalcTotalMoney calculates the total money that
	 * the bank holds any time it is called.
	*/
	double sum = 0;
	sum += (numNickels * .05);
	sum += (numDimes * 0.1);
	sum += (numQuarters * .25);
	sum += numDollars;

	totalMoney = sum;
}

void MoneyCtr::CalcInputAmount()
{
	/*
	 * Method CalcInputAmount calculates the total money that
	 * has been input by the user.
	*/
	inputAmount = inputAmount + (inputNickels * .05);
	inputAmount = inputAmount + (inputDimes * 0.1);
	inputAmount = inputAmount + (inputQuarters * .25);
	inputAmount = inputAmount + inputDollars;
}


void MoneyCtr::MakeChange()
{

	stringstream ss;
	int cost = inputAmount < purchaseAmount ? 0 : static_cast<int>(purchaseAmount * 100); //I added this as well James.
	//change = inputAmount - purchaseAmount +.00001; //Not need this since I add extra stuff James.

	//convert change variable into type int so that operations can be done in cents
	int calculatedChange = static_cast<int>(inputAmount * 100) - cost;// had to add this to fix the change. James
	change = static_cast<double>(calculatedChange) / 100.0; //Also had to add this to fix the change James.
	//---------find change for each denomination
	/*
	* The following process is the same for each denomination
	*	1. get amount of <denomination> by dividing by that amount
	*	2. subtract the number of <denomination> from the bank
	*	3. store remainder of modulus operation in calculatedChange
	*/

	returnedDollars = calculatedChange / 100;	//1
	numDollars -= returnedDollars;				//2
	calculatedChange = calculatedChange % 100;  //3

	returnedQuarters = calculatedChange / 25;	//1
	numQuarters -= returnedQuarters;			//2
	calculatedChange = calculatedChange % 25;	//3

	returnedDimes = calculatedChange / 10;		//1
	numDimes -= returnedDimes;					//2
	calculatedChange = calculatedChange % 10;	//3

	returnedNickels = calculatedChange / 5;		//1
	numNickels -= returnedNickels;				//2
	calculatedChange = calculatedChange % 5;	//3

	CalcTotalMoney();
	
	//create a string to describe the change in coins
	ss.precision(2);
	ss.setf(ios::fixed | ios::showpoint);
	ss << "\nTotal money returned: $" << change;
	ss << "\nReturned Change:";
	ss << "\n\tNickels:  " << returnedNickels;
	ss << "\n\tDimes:    " << returnedDimes;
	ss << "\n\tQuarters: " << returnedQuarters;
	ss << "\n\tDollars:  " << returnedDollars << "\n";

	myChange = ss.str();
}


//-------------Public Member Functions
string MoneyCtr::GetBeginningFile()
{
	/*
	 * Method GetBeginningFile creates a string summarizing the Bank
	 * after initialization. (At the beginning.)
	*/
	stringstream ss;

	ss << "\nInitial Coin Totals: ";
	ss << "\n\tDollars:  " << numDollars;
	ss << "\n\Quarters:  " << numQuarters;
	ss << "\n\tDimes:    " << numDimes;
	ss << "\n\tNickels:  " << numNickels;
	ss << "\n\t	-----------------";

	CalcTotalMoney(); //calculate total sets totalMoney instance variable
	//set formatting to display as dollar amounts
	ss.precision(2);
	ss.setf(ios::fixed | ios::showpoint);

	ss << "\nInitial Bank:\t$" << totalMoney;

	return ss.str();

}


string MoneyCtr::GetWriteInLog()
{
	/*
	* Method GetWriteInLog creates a string that gives the change
	* tendered, which are coins tendered, and the state of the Bank.
	* meaning the totalMoney, and the number of coins present.
	*/
	stringstream ss;
	ss.precision(2);
	ss.setf(ios::fixed | ios::showpoint);
	ss << "\nChange tendered: $" << GetChange();

	ss << "\nTotal Coins Used: ";
	ss << "\n\tDollars:  " << returnedDollars;
	ss << "\n\tQuarters: " << returnedQuarters;
	ss << "\n\tDimes:    " << returnedDimes;
	ss << "\n\tNickels:  " << returnedNickels;

	ss << "\n\nTotal Bank Left: "; //TODO: add handler for this
	ss << "\n\tDollars:  " << numDollars;
	ss << "\n\tQuarters: " << numQuarters;
	ss << "\n\tDimes:    " << numDimes;
	ss << "\n\tNickels:  " << numNickels;

	CalcTotalMoney(); //recalculate totalMoney before reporting contents of bank 
	ss << "\n\nTotal Money: $" << totalMoney << "\n"; //TODO: add handler for this

	return ss.str();
}


string MoneyCtr::GetReturnMoney()
{
	/*
	 * Method GetReturnMoney returns myChange, a formatted string containing 
	 * how many dollars, quarters, dimes, and nickels are to be returned to user.
	*/

	//this should not be in this method only return my change James.
	//stringstream ss;
	//ss << "\nNo snacks were vended. Change was returned.";
	//ss << "\nTotal Coins Returned: ";
	//ss << "\n\tDollars:  " << inputDollars;
	//ss << "\n\tQuarters: " << inputQuarters;
	//ss << "\n\tDimes:    " << inputDimes;
	//ss << "\n\tNickels:  " << inputNickels;


	
	return myChange;
}


double MoneyCtr::GetChange()
{
	/*
	 * Method GetChange returns the amount of the change as a double.
	*/
	return change;
}


double MoneyCtr::GetInputTotal()
{
	return inputAmount;
}


void MoneyCtr::SetInputMoney(int dol, int quar, int dime, int nick)
{
	//set values into class variables
	inputDollars = dol;
	inputQuarters = quar;
	inputDimes = dime;
	inputNickels = nick;

	CalcInputAmount();
	//add the change to the bank
	numDollars += inputDollars;
	numQuarters += inputQuarters;
	numDimes += inputDimes;
	numNickels += inputNickels;
	
	CalcTotalMoney();
}


void MoneyCtr::SetSnackCost(double cost)
{
	this->purchaseAmount = cost;
	MakeChange();
}


void MoneyCtr::ReturnMoney()
{
	//remove change for snack that was not dispensed
	numDollars -= inputDollars;
	numQuarters -= inputQuarters;
	numDimes -= inputDimes;
	numNickels -= inputNickels;
	//etc.

	CalcTotalMoney();
}

