// ManageDormitory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include"ManageStudent.h"
#include"ManageRoom.h"
#include"ManageHiringRoom.h"
#include"Date.h"

using namespace std;
int main()
{
	ManageStudent MS;
	Student s1("22110099", "Nguyen", "Van", "J", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D0");
	Student s2("22110022", "Nguyen", "Van", "E", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s3("22110062", "Nguyen", "Van", "I", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D011");
	Student s4("22110072", "Nguyen", "Van", "D", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D012");
	Student s5("22110082", "Nguyen", "Van", "B", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D013");
	Student s6("22110012", "Nguyen", "Van", "G", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D011");
	Student s7("22110052", "Nguyen", "Van", "F", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s8("22110032", "Nguyen", "Van", "H", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D016");
	Student s9("22110042", "Nguyen", "Van", "C", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s10("2211024", "Nguyen", "Van", "A", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D013");
	ManageRoom2 a;
	Room b12 (1,"normal",5,2,150);
	Room b11(2, "normal", 6, 2, 200);
	NodeTree* b13;
	a.InsertRoom(b12);
	a.InsertRoom(b11);
	ManageHiringRoom MH(a);
	MH.hireRoom();
	MH.showListEmptyRoom();
	
	//a.printListRoom();
	//b12.editRoom();	
	//b12.addToList();
	//b12.list.displayListStudent();
	//cout << b12.empty;
	////a.printListRoom();
	//b13 = a.findRoom(1);
	//b13->data.printPhong();
	//b13->data.editRoom();
	//a.printListRoom();
	//a.deleteRoom(b13->data);
	//cout << "after delete! ";
	//a.printListRoom();
	//MS.initListStudent();
	//MS.addLast(s1);
	//MS.addLast(s2);
	//MS.addLast(s3);
	//MS.addLast(s4);
	//MS.addLast(s5);
	//MS.addLast(s6);
	//MS.addLast(s7);
	//MS.addLast(s8);
	//MS.addLast(s9);
	//MS.addLast(s10);
	//cout << MS.countStudent();
	//MS.deleteStudent("22110022");
	//MS.updateInfo("22110022");
	//MS.filterStudent();
	//MS.displayListStudent();
	//cout << "----------------------------------------------------------\n";
	//MS.sortStudent();
	//MS.displayListStudent();
	
	//string input = "11/11/2024";
	//if (checkDate(input) == true) cout << "Hop le !!!"; else cout << "Khong hop le";

	
	
}

