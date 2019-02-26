#include "Dispenser.h"
#include <string>


using namespace std;


Dispenser::Dispenser()
{	
}

void Dispenser::SetStock(string iName, double iCost, int iTotalStock) {
	name = iName;
	cost = iCost;
	totalStock = iTotalStock;
}

string Dispenser::DispenseSoda() {
	totalStock--;
	return name + "Dispensed!";
}

string Dispenser::GetWritenEntry() {

	return "Snack: " + name + " Dispensed enjoy"+" | Cost: " + to_string(cost);// had to change this James
}

Dispenser::~Dispenser()
{
}
