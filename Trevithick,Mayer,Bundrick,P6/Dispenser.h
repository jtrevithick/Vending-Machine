#ifndef DISPENSER_H
#define DISPENSER_H
#include <iostream>

using namespace std;

class Dispenser
{
private:
	string name;
	double cost;
	int totalStock;



public:
	Dispenser();
	void Dispenser::SetStock(string iName, double iCost, int iTotalStock);
	double GetCost() { return cost; }
	string GetSodaName() { return name; }
	int GetStock() { return totalStock; }
	string DispenseSoda();
	string GetWritenEntry();

	~Dispenser();
};


#endif // !DISPENSER_H