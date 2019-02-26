#pragma once //TODO: FIX THIS
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

class Logger
{
private:
	string filename;
	char timeRightNow[20];
	bool bLogOpen;
	int sec, min, hour, day, month, year;
	ofstream output;
	void FileName();
	void Time();


public:
	Logger();
	void StartLog(string s);
	void WriteLog(string s);
	void CloseLog(string s);
	bool IsLogOpen() { return bLogOpen; }
	~Logger();
};

