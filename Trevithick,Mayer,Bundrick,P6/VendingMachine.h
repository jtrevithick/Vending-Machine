#include "MoneyCtr.h"
#include "Dispenser.h"
#include "Logger.h"
class vendingMachine
{
private:
	int selection;
	string dispenseString;
	
	MoneyCtr bank;
	Dispenser desp[5];
	Logger writeLogger;
	void DispenseItem();

public:
	vendingMachine();
	~vendingMachine();
	void SetPurchase(int dol, int quar, int dime, int nick, int selection);

	string ReturnAllMoneyAndExit(); //no dispense
//	double GetMoneyInput() { return bank.GetInputTotal; }
	string GetDispenseString() { return dispenseString; }
	double GetMoneyInput() { return bank.GetInputTotal(); }
	bool IsFileOpen() { return writeLogger.IsLogOpen(); }

};
