#pragma once
#include<iostream>
#include"ManageRoom.h"
#include"ManageStudent.h"
#include "Date.h"
#include <cstring>
#include <cctype>
using namespace std;
struct ManageHiringRoom {
	ManageRoom MR;
	ManageStudent MS;
	ManageHiringRoom(const ManageRoom& roomManager, const ManageStudent& MS) : MR(roomManager), MS(MS)
	{
	}
	void hireRoom()
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
		cout << "---------------------- INPUT STUDENT INFORMATION ----------------------" << endl;
		cin.ignore();
		Student s;
		cout << setw(0);
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		if (MS.isExisting(s.studentID) == true){
			cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
			cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
			cout << "Input studenn's first name: "; getline(cin, firstName); s.lastName = firstName;
			cout << "Input student's gender: "; getline(cin, gender); s.gender = gender;
			string dob;
			do {
				cout << "Input studenn's birthday: "; getline(cin, dob);
			} while (!checkDate(dob));
			s.dob = dob;
			cout << "Input studenn's address: "; getline(cin, address); s.address = address;
			cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
			cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
			cout << "Input studenn's major: "; getline(cin, major); s.major = major;
			float scoreID(MR.suggestRoom(s));
			if (scoreID != -1)
			{

				cout << "After analysing, the room " << scoreID << " is suitable for you\n";
				MR.findRoom(scoreID)->data.printListStudent();
				cout << "Do you want to hire this rom (Y/N): ";
				char input;
				cin >> input;
				if (toupper(input) == 'Y')
				{
					MR.findRoom(scoreID)->data.addToList(s);
				}
				else
				{
					cout << setw(0);
					cout << "Input ID room: ";
					int id; cin >> id;
					NodeTree* room = MR.findRoom(id);
					if (room == NULL)
					{
						cout << "Room does not exist !!!\n";
					}
					else room->data.addToList(s);
				}
			}

		}
		else cout << "Student already exists in this list \n";
		cout << "----------------------------------------------------------------------\n";
	}
	void addStudent2Room() {

		this->MR.automaticallyAddRoom(MS);
		return;
	}
	void showListEmptyRoom()
	{
		MR.printListEmptyRoom();
	}
	void transferRoom()
	{
		string sID;
		int rID;
		MR.printListEmptyRoom();
		cout << setw(0);
		cout << "Enter student ID: ";
		cin.ignore();
		cin >> sID;
		if (MS.searchNode(sID) == NULL)
		{
			cout << "Student does not exist !!!\n";
			return;
		}
		else
		{
			Student a = MS.searchNode(sID)->data;
			cout << "After analysing, the room " << MR.suggestRoom(a) << " is suitable for you\n";
			cout << "Do you want to transfer to this rom (Y/N): ";
			char input;
			cin >> input;
			if (toupper(input) == 'Y') {
				MR.findRoom(MR.suggestRoom(a))->data.deleteStudent(sID);
				MR.findRoom(MR.suggestRoom(a))->data.addToList(a);
			}
			else
			{
				cout << setw(0);
				cout << "Input ID room: ";
				int id; cin >> id;
				NodeTree* room = MR.findRoom(id);
				if (room == NULL)
				{
					cout << "Room does not exist !!!\n";
				}
				else
					if (room->data.empty == 0)
					{
						cout << setw(0) << "The room is full. Transfered failed !\n";
					}
					else
						room->data.addToList(a);
			}
		}
	}
	void checkoutRoom()
	{
		string sID;
		cout << setw(0) << "Enter student ID: ";
		cin.ignore();
		cin >> sID;
		if (MS.searchNode(sID) == NULL)
		{
			cout << "Student does not exist !!!\n";
			return;
		}
		else
		{
			Node* a = MS.searchNode(sID);
			a->data.status = false;
			MR.findRoom(MS.searchNode(sID)->data.roomID)->data.list.searchNode(sID)->data.status = false;
			//b.list.searchNode(sID)->data.status = false;
			MR.findRoom(MS.searchNode(sID)->data.roomID)->data.deleteStudent(sID);
			a->data.roomID = -999;
		}
	}
	void hireForOldStudent()
	{
		cin.ignore();
		string studentID;
		cout << "Input studenn's ID: "; getline(cin, studentID);
		Node* temp = MS.searchNode(studentID);
		if (temp == NULL)
		{
			cout << "Student does not exist !\n";
		}
		else
			if (temp->data.status == true)
			{
				cout << "Student is hiring room !\n";
			}
			else
			{
				if (MR.suggestRoom(temp->data) != -1)
				{
					cout << "After analysing, the room " << MR.suggestRoom(temp->data) << " is suitable for you\n";
					MR.findRoom(MR.suggestRoom(temp->data))->data.printListStudent();
					cout << "Do you want to hire this rom (Y/N): ";
					char input;
					cin >> input;
					if (toupper(input) == 'Y')
					{
						MR.findRoom(MR.suggestRoom(temp->data))->data.addToList(temp->data);
					}
					else
					{
						cout << setw(0);
						cout << "Input ID room: ";
						int id; cin >> id;
						NodeTree* room = MR.findRoom(id);
						if (room == NULL)
						{
							cout << "Room does not exist !!!\n";
						}
						else room->data.addToList(temp->data);
					}
				}
			}
	}
};