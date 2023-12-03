#pragma once
#include <iostream>
#include<iomanip>
#include "Date.h"
using namespace std;
struct Student
{
	string studentID;
	string firstName;
	string middleName;
	string lastName;
	string phoneNo;
	string gender;
	string address;
	string dob;
	string major;
	string falcuty;
	string enterDate;
	int roomID=0;
	string exitDate;
	bool status;

	void printInfo()
	{
		
		string s = "";
		if (status == true)
		{
			s = "Hiring";
			cout << studentID << setw(10) << lastName << " " << middleName << " " << firstName << setw(15)
				<< dob << setw(10) <<
				gender << setw(18)
				<< address << setw(14)
				<< phoneNo << setw(12) <<
				falcuty << setw(25) <<
				major << setw(15)
				<< enterDate << setw(10)
				<< roomID << setw(14)
				<< s << "\n";
		}
		else
		{
			s = "Check-out";
			cout << studentID << setw(10) << lastName << " " << middleName << " " << firstName << setw(15)
				<< dob << setw(10) <<
				gender << setw(18)
				<< address << setw(14)
				<< phoneNo << setw(12) <<
				falcuty << setw(25) <<
				major << setw(15)
				<< enterDate << setw(10)
				<< roomID << setw(14)
				<< s << "\n";
		}
	}	
	Student(string studentID, string lastName, string middleName, string firstName,
		string dob, string gender, string address, string phoneNo, string falcuty, string major, string enterDate)
	{
		this->studentID = studentID;
		this->lastName = lastName;
		this->middleName = middleName;
		this->firstName = firstName;
		this->dob = dob;
		this->gender = gender;
		this->address = address;
		this->phoneNo = phoneNo;
		this->falcuty = falcuty;
		this->major = major;
		this->enterDate = enterDate;
		this->status = false;
	}

	Student() {}
	~Student() {}


};