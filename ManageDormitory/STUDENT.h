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
				falcuty << setw(16) <<
				major << setw(17)
				<< enterDate << setw(12)
				<< roomID << setw(16)
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
				falcuty << setw(16) <<
				major << setw(17)
				<< enterDate << setw(12)
				<< roomID << setw(16)
				<< s << "\n";
		}
	}
	void createStudent()
	{
		cin.ignore();
		Student s;
		cout << setw(0);
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
		cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
		cout << "Input studenn's first name: "; getline(cin, firstName); s.lastName = firstName;
		string dob;
		do {
			cout << "Input studenn's birthday: "; getline(cin, dob);
		} while (!checkDate(dob));
		s.dob = dob;
		cout << "Input studenn's address: "; getline(cin, address); s.address = address;
		cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
		cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
		cout << "Input studenn's major: "; getline(cin, major); s.major = major;
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
//		this->enterDate = enterDate;
		//this->roomID = roomID;
		this->status = false;
	}

	Student() {}
	~Student() {}


};