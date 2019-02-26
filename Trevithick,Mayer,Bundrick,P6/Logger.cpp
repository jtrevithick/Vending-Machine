#include "Logger.h"
#include "Date.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

Logger::Logger()
{
	FileName(); //create file name
	Time();

	output.open(filename);
	//check if file opened
	//set bLogOpen
	output << "In Time: " << timeRightNow;

}

void Logger::StartLog(string s) {
	output << s;
}

void Logger::WriteLog(string s) {
	Time();
	output << "In Time: " << timeRightNow;
	output << s;
}

void Logger::CloseLog(string s) {
	output << s;
	output.close();
	//use popup if you want
}

void Logger::Time() {

	_strtime_s(timeRightNow);
	
}

void Logger::FileName() {
	//get system date and time
	Date date;
	day = date.GetDayOfYear();
	month = date.GetMonth();
	year = date.GetYear();
	//create file name 
	filename = "Log - " + to_string(month) + '/' + to_string(day) + '/' + to_string(year);
	//   Log - month.day.year.txt
}




Logger::~Logger()
{
}
