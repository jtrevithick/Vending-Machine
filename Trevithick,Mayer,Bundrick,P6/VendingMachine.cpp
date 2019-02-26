//James Trevithick						jtrevithick2@cnm.edu				Trevithick,Mayer,Bundrick
#include "VendingMachine.h"
const int snack_total = 25;


void vendingMachine::DispenseItem()
{
	if (desp[selection].GetStock() == 0)
	{
		dispenseString = "Out of Stock" + ReturnAllMoneyAndExit();
	}
	else 
	{
		if (desp[selection].GetCost() <= bank.GetInputTotal()) {
			dispenseString = desp[selection].GetWritenEntry() + bank.GetReturnMoney();
			desp[selection].DispenseSoda();
		} else
		{
			dispenseString = "Not enough cash" + ReturnAllMoneyAndExit();
		}

	}
	writeLogger.WriteLog(dispenseString);

}

vendingMachine::vendingMachine() :
	selection(0), dispenseString("")
{
	desp[0].SetStock("Pop Tarts",1.60,snack_total);
	
	desp[1].SetStock("Sun Chips",1.25, snack_total);

	desp[2].SetStock("Snickers",0.50, snack_total);

	desp[3].SetStock("Bubble Yum",0.80, snack_total);

	desp[4].SetStock("Granla Bar",0.90, snack_total);
	
	string firstLog = "in logfile: Name" + bank.GetBeginningFile();
		

	writeLogger.StartLog(firstLog);
}

vendingMachine::~vendingMachine()
{
	writeLogger.CloseLog("Turning off\n" + bank.GetBeginningFile());
}

void vendingMachine::SetPurchase(int dol, int quar, int dime, int nick, int selection)
{
	this->selection = selection;
	bank.SetInputMoney(dol, quar, dime, nick);
	bank.SetSnackCost(desp[this->selection].GetCost());
	DispenseItem();
}

string vendingMachine::ReturnAllMoneyAndExit()
{
	bank.ReturnMoney();
	return bank.GetReturnMoney();
}
