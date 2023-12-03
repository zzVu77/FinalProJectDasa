#pragma once
using namespace std;
#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>

struct Date {
	int day;
	int month;
	int year;
};
// Function for spliting date from string
Date parseDate(const  string& dateStr) {
	Date result;

	// Using stringstream to split string
	istringstream ss(dateStr);
	char delimiter;

	// Read day, month, year from string
	ss >> result.day >> delimiter >> result.month >> delimiter >> result.year;
	return result;
}
// Function for checking is leap year or not
bool isLeapYear(int year) {
	
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
// Function for checking the input date is wrong or right 
bool checkDate(string date)
{
	Date parsedDate = parseDate(date);
	// Get date now
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::tm localTime;	
	localtime_s(&localTime, &currentTime);
	int day = localTime.tm_mday;
	int month = localTime.tm_mon + 1;  // Month start at 0
	int year = localTime.tm_year + 1900;  // Year from 1900
	if (parsedDate.day > 31 or parsedDate.month > 12) return false;
	//if (parsedDate.day > day or parsedDate.month == month or parsedDate.year > year) return false;
	//if (parsedDate.day > day and parsedDate.month == month and parsedDate.year = year) return false;
	if ((parsedDate.year > year)  or (parsedDate.year == year and parsedDate.month > month) or (parsedDate.year == year and parsedDate.month == month and parsedDate.day > day)) return false;
	if (parsedDate.month == 2 and parsedDate.day > 29 ) return false;
	if (parsedDate.month == 2 and parsedDate.day == 29 and isLeapYear(parsedDate.year) == true) return false;
	if ((parsedDate.month == 1 or parsedDate.month == 3 or parsedDate.month == 5 or parsedDate.month == 7 or parsedDate.month == 8 or parsedDate.month == 10 or parsedDate.month == 12) and parsedDate.day > 31) return false;
	if ((parsedDate.month == 4 or parsedDate.month == 6 or parsedDate.month == 9 or parsedDate.month == 11) and parsedDate.day > 30) return false;
	return true;
}
int getCurrentMonth()
{
	// Get date now
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::tm localTime;

	localtime_s(&localTime, &currentTime);
	int day = localTime.tm_mday;
	int month = localTime.tm_mon + 1;  // Month start at 0
	int year = localTime.tm_year + 1900;  // Year from 1900
	return month;
}
