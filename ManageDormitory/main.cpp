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


	MS.initListStudent();
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
	MS.readfile("D:/code/c++/nam2/datastructures/ProjectCuoiKi/FinalProJectDasa/students.txt");
//	MS.displayListStudent();

//	a.printListRoom();
	//Room b12 (1,"normal",5,4,150), 
	//	b13(2, "normal", 5, 2, 180), 
	//	b14(3, "normal", 5, 3, 180),
	//	b15(4, "normal", 3, 2, 200),
	//	b16(5, "normal", 2, 2, 210);
	//b12.addStudent(s6);
	//b13.addStudent(s10);
	//a.InsertRoom(b12);
	//a.InsertRoom(b13);
	//a.InsertRoom(b14);
	//a.InsertRoom(b15);
	//a.InsertRoom(b16);
	ManageRoom a;
	a.readfile("D:/code/c++/nam2/datastructures/ProjectCuoiKi/FinalProJectDasa/rooms.txt");
	a.automaticallyAddRoom(MS);
	a.printStudentInRoom();
	a.printListEmptyRoom();
	a.checkOut();
	a.hiringRoom();

	a.printStudentInRoom();
	//a.suggestRoom(s8);
	//MS.displayListStudent();
	/*MS.deleteStudent(s1.studentID);
	MS.displayListStudent();*/
	/*b13.automaticallyAddStudent(MS);
	b13.printListStudent();
	MS.displayListStudent();
	b12.automaticallyAddStudent(MS);
	b12.printListStudent();
	MS.displayListStudent();
	b14.automaticallyAddStudent(MS);
	b14.printListStudent();
	MS.displayListStudent();*/

	/*ManageHiringRoom MH(a);
	MH.hireRoom();
	a.printListRoom();*/
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

