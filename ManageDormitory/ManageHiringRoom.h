#pragma once
#include<iostream>
#include"ManageRoom.h"
#include"ManageStudent.h"
using namespace std;
struct ManageHiringRoom {
	ManageRoom2 MR;
	ManageStudent MS;
	ManageHiringRoom(const ManageRoom2& roomManager) : MR(roomManager) {}
	void hireRoom()
	{
		cout << "Input ID room: ";
		int id; cin >> id;		
		cout << "---------------------- INPUT STUDENT INFORMATION ----------------------\n ";
		NodeTree* room= MR.findRoom(id);
		if (room == NULL) 
		{
			cout << "Room does not exist !!!\n";			
		}
		else room->data.addToList();
	}
	void showListEmptyRoom()
	{
		cout << "-------------------------------------------- LIST EMPTY ROOM --------------------------------------------\n";
		MR.printListEmptyRoom();
	}
};