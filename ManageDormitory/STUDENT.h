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
//	string roomID;
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
				<< enterDate << "\t " /* << roomID << "\t "*/ << s << "\n";
		}
		else
		{
			s = "Ended";
			cout << studentID << "\t " << lastName << " " << middleName << " " << firstName << "\t " << dob << "\t " << gender << "\t "
				<< address << "\t " << phoneNo << "\t " << falcuty << "\t " << major << "\t "
				<< enterDate << "\t " /* << roomID << "\t "*/ << s << "\t " << exitDate << "\n";
		}
	}
	void createStudent()
	{
		cin.ignore();
		Student s;
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
		cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
		cout << "Input studenn's first name: "; getline(cin, firstName); s.lastName = firstName;
		cout << "Input studenn's birthday: "; getline(cin, dob); s.dob = dob;
		cout << "Input studenn's address: "; getline(cin, address); s.address = address;
		cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
		cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
		cout << "Input studenn's major: "; getline(cin, major); s.major = major;
	}
	Student(string studentID, string lastName, string middleName, string firstName, string dob, string gender, string address, string phoneNo, string falcuty, string major, string enterDate)
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
//		this->roomID = roomID;
		this->status = true;
	}

	Student() {}
	~Student() {}


};