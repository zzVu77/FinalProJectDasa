#pragma once
#include <iostream>
#include<string>
#include"ManageStudent.h"
#include"ManageRoom.h"
#include"ManageHiringRoom.h"
#include"Date.h"
#include"ChuanHoa.h"
#include<iomanip>
using namespace std;

void printMenuForManageDormitory() {
	cout << "-------------------- MANAGE DORMITORY --------------------\n";
	cout << "| 1. Manage Student \t \t \t \t \t" << " | \n";
	cout << "| 2. Manage Room \t \t \t \t \t" << " | \n";
	cout << "| 3. Manage HiringRoom \t \t \t \t \t | \n";	
	cout << "| 0. Exit !!! \t \t \t \t \t \t | \n";
	cout << "----------------------------------------------------------\n";
}
void printMenuForManageStudent()
{
	cout << "--------------------- MANAGE STUDENT ---------------------\n";
	cout << "| 1. Display List Student \t \t \t \t | \n";
	cout << "| 2. Update Student Information \t \t \t | \n";
	cout << "| 3. Search Student \t \t \t \t \t | \n";
	cout << "| 4. Sort List Student \t \t \t \t \t | \n";
	cout << "| 5. Filter List Student \t \t \t \t | \n";	
	cout << "| 6. Delete Student \t \t \t \t \t | \n";
	cout << "| 0. Exit !!! \t \t \t \t \t \t | \n";
	cout << "----------------------------------------------------------\n";
}
void doMenuForManageStudent(ManageStudent& MS)
{
	bool flag = true;
	do
	{
		printMenuForManageStudent();
		string strCheck;
		do {
			cout << "Enter: "; cin >> strCheck;
		} while (!checkSo(strCheck));
		int input = stoi(strCheck);
		switch (input)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			cout << "----------------------------------------------------------------------------- LIST STUDENT -----------------------------------------------------------------------------\n";
			cout << "| No" << setw(5) << " |       ID" << setw(15) << "|      Name" << setw(16) << "|     DoB" << setw(14)
				<< "|  Gender" << setw(15) << "|    Address" << setw(16)
				<< "|  Phone" << setw(14) << "|   Falcuty" << setw(14) << "|   Major" << setw(23)
				<< "|   Enter Date" << setw(15) << "|    Room ID" << setw(16) << "|   Status  |\n";
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
			MS.displayListStudent();
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
			break;
		}
		case 2:
		{
			string id;
			cout << setw(0);
			cout << "Enter the student ID:";
			cin >> id;
			MS.updateInfo(id);
			break;
		}
		case 3:
		{
			string id;
			cout << setw(0);
			cout << "Enter the student ID:";
			cin >> id;
			MS.searchStudent(id);
			cout << endl;
			break;
		}
		case 4:
		{
			MS.sortStudent();
			cout << "Sort sucessfully !!! \n";
			break;
		}
		case 5:
		{
			MS.filterStudent();
			cout << endl;
			break;
		}
		case 6:
		{
			string id;
			cout << setw(0);
			cout << "Enter the student ID:";
			cin >> id;
			MS.deleteStudent(id);
		}

		}
	} while (flag);
}
void printMenuForManageRoom()
{
	cout << "----------------------- MANAGE ROOM ----------------------\n";
	cout << "| 1. Add New Room \t \t \t \t \t | \n";
	cout << "| 2. Update Room Information \t \t \t \t | \n";
	cout << "| 3. Delete Room \t \t \t \t \t | \n";
	cout << "| 4. Display List Student In Room \t \t \t | \n";
	cout << "| 5. Display List Room \t \t \t \t \t | \n";
	cout << "| 6. Enter electricity and water bill \t \t \t | \n";
	cout << "| 7. Print Rooms Bill \t \t \t \t \t | \n";
	cout << "| 0. Exit !!! \t \t \t \t \t \t | \n";
	cout << "----------------------------------------------------------\n";
}
void doMenuForManageRoom(ManageRoom& MR)
{
	bool flag = true;
	do
	{
		printMenuForManageRoom();
		string strCheck;
		do {
			cout << "Enter: "; cin >> strCheck;
		} while (!checkSo(strCheck));
		int input = stoi(strCheck);
		switch (input)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			int RoomID;
			int NumberOfBed;
			int Capacity;
			double Cost;
			cout << setw(0);
			bool flag = true;
			do
			{
				cout << "Input Room ID: ";
				cin >> RoomID;
				if (MR.findRoom(RoomID) != NULL) cout << "Room ID existed. Please input again !\n";
				else flag = false;
			} while (flag);		
			cout << "Input Number Of Bed: ";
			cin >> NumberOfBed;
			cout << "Input capacity: ";
			cin >> Capacity;
			cout << "Input cost: ";
			cin >> Cost;
			Room room;
			room.RoomID = RoomID;
			room.NumberOfBed = NumberOfBed;
			room.Capacity = Capacity;
			room.empty = room.Capacity;
			room.Cost = Cost;
			room.list.initListStudent();
			MR.InsertRoom(room);
			break;
		}
		case 2:
		{
			int id;
			cout << setw(0);
			cout << "Enter the Room ID:";
			cin >> id;
			MR.updateRomInfo(id);
			break;
		}
		case 3:
		{
			int id;
			cout << setw(0);
			cout << "Enter the Room ID:";
			cin >> id;
			NodeTree* p = MR.findRoom(id);
			if (p == NULL) { cout << "Room does not exist !\n"; }
			else
				if (p->data.empty == 0)
				{
					cout << "Students are still hiring room. Cannot delete this room\n";
				}
				else
				{
					MR.deleteRoom(p->data);
					cout << "Delete success !!!\n";
				}

			break;
		}
		case 4:
		{
			int id;
			cout << setw(0);
			cout << "Enter the Room ID:";
			cin >> id;
			NodeTree* p = MR.findRoom(id);
			p->data.printListStudent();
			break;
		}
		case 5:
		{
			MR.printListRoom();
			break;
		}
		case 6:
		{
			MR.inputRomBill();
			break;
		}
		case 7:
		{
			MR.printRoomBill();
			break;
		}
		}
	} while (flag);
}
void printMenuForManageHiringRoom() {
	cout << "-------------------- MANAGE HIRING ROOM ------------------\n";
	cout << "| 1. Hire Room \t \t \t \t \t \t | \n";
	cout << "| 2. Display List Empty Room \t \t \t \t | \n";
	cout << "| 3. Automatically Add Student \t \t \t \t | \n";
	cout << "| 4. Transfer Room \t \t \t \t \t |\n";
	cout << "| 5. Check-out Room \t \t \t \t \t |\n";
	cout << "| 0. Exit !!! \t \t \t \t \t \t | \n";
	cout << "----------------------------------------------------------\n";
}
void doMenuForManageHiringRoom(ManageHiringRoom& MHR)
{
	bool flag = true;
	do
	{
		printMenuForManageHiringRoom();
		string strCheck;
		do {
			cout << "Enter: "; cin >> strCheck;
		} while (!checkSo(strCheck));
		int input = stoi(strCheck);
		switch (input)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			bool check = true;
			do
			{
				cout << "------------------ Option ----------------\n";
				cout << "| 1. New Student \t \t \t | \n";
				cout << "| 2. Old Student \t \t \t | \n";
				cout << "| 0. Exit !!! \t \t \t \t | \n";
				cout << "------------------------------------------\n";
				string strCheck;
				do {
					cout << "Enter: "; cin >> strCheck;
				} while (!checkSo(strCheck));
				int n = stoi(strCheck);
				switch (n)
				{
				case 0:
					{
						check = false;
						break;
					}
				case 1:
				{
					MHR.hireRoom();
					break;
				}
				case 2:
				{
					MHR.hireForOldStudent();
					break;
				}				
				}
			} while (check);
			
			break;
		}
		case 2:
		{
			MHR.showListEmptyRoom();
			break;
		}
		case 3:
		{
			MHR.addStudent2Room();
			break;
		}
		case 4:
		{
			
			MHR.transferRoom();
			break;
		}
		case 5:
		{
			MHR.checkoutRoom();
			break;
		}

		}
	} while (flag);
}
void doMenu()
{
	ManageStudent MS;
	MS.initListStudent();
	MS.readfile("E:/HCM_UTE/Semester 3/New folder (2)/hi/FinalProJectDasa/students.txt");
	ManageRoom MR;

	MR.readfile("E:/HCM_UTE/Semester 3/New folder (2)/hi/FinalProJectDasa/rooms.txt");
	ManageHiringRoom MHR(MR,MS);
	bool flag = true;
	do
	{
		printMenuForManageDormitory();
		string strCheck;
		do {
			cout << "Enter: "; cin >> strCheck;
		} while (!checkSo(strCheck));
		int input = stoi(strCheck);
		switch (input)
		{
		case 0:
		{
			flag = false;
			break;
		}
		case 1:
		{
			doMenuForManageStudent(MHR.MS);
			break;
		}
		case 2:
		{
			doMenuForManageRoom(MHR.MR);
			break;
		}
		case 3:
		{
			doMenuForManageHiringRoom(MHR);
			break;
		}
		}
	} while (flag);
	MR.writefile("E:/HCM_UTE/Semester 3/New folder (2)/hi/FinalProJectDasa/students.txt");
	MS.writeFile("E:/HCM_UTE/Semester 3/New folder (2)/hi/FinalProJectDasa/rooms.txt");
}
