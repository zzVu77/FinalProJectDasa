#pragma once
#include"ManageStudent.h"
#include <string>
#include <iostream>
using namespace std;

struct Room
{
public:
	int RoomID=-1;
	string TypeRoom;
	int NumberOfBed;
	int People;
	double Cost;
	int empty;
	ManageStudent list;	 	
public:
	Room(int idRoom, string typeRoom, int numberOfBed, int people, double cost)
	{
		this->RoomID = idRoom;
		this->TypeRoom = typeRoom;
		this->NumberOfBed = numberOfBed;
		this->People = people;
		this->Cost = cost;	
		this->list.initListStudent();
		this->empty = this->People;		
	}
	Room(){}
	void printPhong() {
		
		cout <<"ID Room: " << RoomID << "\tType: " << TypeRoom << "\tNumber Of Bed : " << NumberOfBed << "\tMax people: " << People <<"\tEmpty: "<<empty << "\tCost: " << Cost << '\n';
		return;
	}
	int getID()
	{
		return this->RoomID;
	}
	void editRoom()
	{
		cout << "ID: ";
		cin >> RoomID;
		cout << "Type: ";
		cin >> TypeRoom;
		cout << "Number Of Bed: ";
		cin >> NumberOfBed;
		cout << "People: ";
		cin >> People;
		cout << "Cost: ";
		cin >> Cost;
		return;
	}
	bool check(Room a)
	{
		return a.getID() == RoomID;
	}
	void addToList()
	{
		Student s;
		s.createStudent();		
		s.roomID = this->RoomID;
		s.status = true;
		this->list.addLast(s);
		this->empty = this->empty - this->list.countStudent();
		
	}
};


