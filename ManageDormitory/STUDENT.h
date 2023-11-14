#pragma once
#include <iostream>
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
	string roomID;
	string exitDate;
	bool status;

	void printInfo()
	{
		string s = "";
		if (status == true)
		{
			s = "Hiring";
			cout << studentID << "\t " << lastName << " " << middleName << " " << firstName << "\t " << dob << "\t " << gender << "\t "
				<< address << "\t " << phoneNo << "\t " << falcuty << "\t " << major << "\t "
				<< enterDate << "\t " << roomID << "\t " << s << "\n";
		}
		else
		{
			s = "Ended";
			cout << studentID << "\t " << lastName << " " << middleName << " " << firstName << "\t " << dob << "\t " << gender << "\t "
				<< address << "\t " << phoneNo << "\t " << falcuty << "\t " << major << "\t "
				<< enterDate << "\t " << roomID << "\t " << s << "\t " << exitDate << "\n";
		}
	}

	Student(string studentID, string lastName, string middleName, string firstName, string dob, string gender, string address, string phoneNo, string falcuty, string major, string enterDate, string roomID)
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
		this->enterDate = enterDate;
		this->roomID = roomID;
		this->status = true;

	}
	Student() {}


};