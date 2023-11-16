#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Room
{
private:
	int RoomID=-1;
	string TypeRoom;
	int NumberOfBed;
	int People;
	double Cost;
public:
	void printPhong() {
		
		cout <<"ID Room: " << RoomID << " Type: " << TypeRoom << " Number Of Bed : " << NumberOfBed << " People: " << People << " Cost: " << Cost << '\n';
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
};


