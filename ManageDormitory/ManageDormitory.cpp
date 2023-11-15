// ManageDormitory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include"ManageStudent.h"
#include"ManageRoom.h"

using namespace std;
//struct STUDENT
//{
//	string studentID;
//	string firstName;
//	string middleName;
//	string lastName;
//	string phoneNo;
//	string gender;
//	string address;
//	string dob;
//	string major;
//	string falcuty;
//	string enterDate;
//	string roomID;
//	string exitDate;
//	bool status;
//
//	void printInfo()
//	{
//		string s = "";
//		if (status == true)
//		{
//			s = "Hiring";
//			cout << studentID << "\t " << lastName << " " << middleName << " " << firstName << "\t " << dob << "\t " << gender << "\t "
//				<< address << "\t " << phoneNo << "\t " << falcuty << "\t " << major << "\t "
//				<< enterDate << "\t " << roomID << "\t " << s << "\n";
//		}
//		else
//		{
//			s = "Ended";
//			cout << studentID << "\t " << lastName << " " << middleName << " " << firstName << "\t " << dob << "\t " << gender << "\t "
//				<< address << "\t " << phoneNo << "\t " << falcuty << "\t " << major << "\t "
//				<< enterDate << "\t " << roomID << "\t " << s << "\t " << exitDate << "\n";
//		}
//	}
//
//	STUDENT(string studentID, string lastName, string middleName, string firstName, string dob, string gender, string address, string phoneNo, string falcuty, string major, string enterDate, string roomID)
//	{
//		this->studentID = studentID;
//		this->lastName = lastName;
//		this->middleName = middleName;
//		this->firstName = firstName;
//		this->dob = dob;
//		this->gender = gender;
//		this->address = address;
//		this->phoneNo = phoneNo;
//		this->falcuty = falcuty;
//		this->major = major;
//		this->enterDate = enterDate;
//		this->enterDate = enterDate;
//		this->roomID = roomID;
//		this->status = true;
//		
//	}
//	STUDENT(){}
//		
//
//};
//struct NODE
//{
//	STUDENT data;
//	NODE* next;
//};
//
//struct MANAGE_STUDENT
//{
//	NODE* head;
//	NODE* tail;
//	void initListStudent()
//	{
//		head = NULL;
//		tail = NULL;
//	}
//	// Function for adding a new node to the last of list
//	void addLast(const STUDENT& x) {
//		NODE* node = new NODE();
//		node->data = x;
//		node->next = NULL;
//		if (head == NULL) {
//			head = node;
//			tail = node;
//		}
//		else {
//			tail->next = node;
//			tail = node;
//		}
//	}
//	// Function for adding a new node to list
//	void addNode(const STUDENT& x)
//	{
//		NODE* node = new NODE();
//		node->data = x;
//		node->next = NULL;
//		if (head == NULL)
//		{
//			head = node;
//			tail = node;
//		}
//		else
//		{
//			tail->next = node;
//			tail = node;
//		}
//	}
//	bool isEmptyList()
//	{
//		return head == NULL;
//	}
//	// Function for adding a new student
//	void addStudent()
//	{
//		STUDENT s;
//		string studentID;
//		string firstName;
//		string middleName;
//		string lastName;
//		string phoneNo;
//		string gender;
//		string address;
//		string dob;
//		string major;
//		string falcuty;
//		string enterDate;
//		string roomID;
//		string exitDate;
//		bool status = true;
//		s.status = status;
//		cout << "*************** Add Student ***************\n";
//		cin.ignore();
//		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
//		cout << "Input studenn's first name: "; getline(cin, firstName); s.firstName = firstName;
//		cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
//		cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
//		cout << "Input studenn's birthday: "; getline(cin, dob); s.dob = dob;
//		cout << "Input studenn's address: "; getline(cin, address); s.address = address;
//		cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
//		cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
//		cout << "Input studenn's major: "; getline(cin, major); s.major = major;
//		cout << "Input studenn's enterDate: "; getline(cin, enterDate); s.enterDate=enterDate;
//		cout << "Input studenn's roomID: "; getline(cin, roomID); s.roomID = roomID;
//		/*cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
//		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
//		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;*/
//		addLast(s);
//	}	
//	// Function for removing first node
//	void removeFirst()
//	{
//		if (isEmptyList() == false)
//		{
//			NODE* temp = head;
//			head = head->next;
//			delete temp;
//			if (isEmptyList() == true) tail = NULL;
//		}
//	}
//	// Function for removing last node
//	void removeLast()
//	{
//		if (isEmptyList() == true) return;
//		else
//		{
//			if (head == tail)
//			{
//				delete head;
//				head = NULL;
//				tail = NULL;
//			}
//			else
//			{
//				NODE* temp = head;
//				do
//				{
//					temp = temp->next;
//				} while (temp->next != tail);
//				delete tail;
//				tail = temp;
//				tail->next = NULL;
//			}
//		}
//	}
//	// Function for getting previous node
//	NODE* getPreviousNode(NODE*& node)
//	{
//		NODE* curr = head;
//		while (curr != NULL)
//		{
//			if (curr->next != NULL and curr->next == node) return curr;
//			curr = curr->next;
//		}
//		return NULL;
//	}
//	// Fuunction for searching a student by using ID
//	NODE* searchStudent(string id)
//	{
//		if (head == NULL) return NULL;
//		NODE* node = head;
//		int i = 0;
//		while (node != NULL and node->data.studentID != id)
//		{
//			if (node->next == NULL and node->data.studentID != id) return NULL;
//			node = node->next;
//			i++;
//		}
//		return node;
//	}
//	// Function for deleting a student by seaching student by ID and deleting him
//	void deleteStudent(string id)
//	{
//
//		if (searchStudent(id) == NULL)
//		{
//			cout << "Student does not exist in the list !!!\n";
//			cout << "Delete failed !!!";
//		}
//		else
//		{
//			NODE* node = searchStudent(id);
//			if (head == tail) {
//				removeFirst();
//				cout << "Successfully deleted \n";
//				return;
//			}
//			if (head == tail)
//			{
//				removeLast();
//				cout << "Successfully deleted \n";
//				return;
//			}
//			NODE* pre = getPreviousNode(node);
//			pre->next = node->next;
//			cout << "Successfully deleted \n";
//			delete(node);
//		}
//
//	}
//	// Function for displaying list student
//	void displayListStudent()
//	{
//		NODE* curr = head;
//		int i = 0;
//		while (curr != NULL)
//		{
//			i++;
//			cout << i << "\t |";
//			curr->data.printInfo();
//			curr=curr->next;
//		}
//	}
//	// Function for updating information of student
//	void updateInfo(string id)
//	{
//		if (searchStudent(id) == NULL)
//		{
//			cout << "Student does not exist in the list !!!\n";
//			cout << "Update failed\n";
//			return;
//		}
//		NODE* p = searchStudent(id);
//		bool flag = true;
//		do
//		{
//			cout << "\n";
//			cout << "*********************** Update **************************\n";
//			cout << "Select type of information that you want to update: \n";
//			cout << "1. Student's ID \n";
//			cout << "2. Student's name \n";
//			cout << "3. Student's birthdate \n";
//			cout << "4. Student's gender \n";
//			cout << "5. Student's phone number \n";
//			cout << "6. Student's address \n";
//			cout << "7. Student's major \n";
//			cout << "8. Student's falcuty\n";
//			cout << "0. Exit\n";
//			cout << "*********************************************************\n";
//			int n; cout << "Input: "; cin >> n; 
//			switch (n)
//			{
//			case 0:
//			{
//				flag = false;
//				break;
//			}
//			case 1:
//			{
//				cout << "Update new ID: ";
//				string str;
//				cin >> str;
//				p->data.studentID = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 2:
//			{
//				string lastName;
//				string middleName;
//				string firstName;
//				cout << "Update new last name:"; cin >> lastName;
//				cout << "Update new middle name:"; cin >> middleName;
//				cout << "Update new first name:"; cin >> firstName;
//				p->data.lastName = lastName;
//				p->data.middleName = middleName;
//				p->data.firstName = firstName;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 3:
//			{
//				cout << "Update new birthdate: ";
//				string str;
//				cin >> str;
//				p->data.dob = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 4:
//			{
//				cout << "Update new gender: ";
//				string str;
//				cin >> str;
//				p->data.gender = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 5:
//			{
//				cout << "Update new phone number: ";
//				string str;
//				cin >> str;
//				p->data.phoneNo = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 6:
//			{
//				cout << "Update new address: ";
//				string str;
//				cin >> str;
//				p->data.address = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 7:
//			{
//				cout << "Update new major: ";
//				string str;
//				cin >> str;
//				p->data.major = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			case 8:
//			{
//				cout << "Update new falcuty: ";
//				string str;
//				cin >> str;
//				p->data.falcuty = str;
//				cout << "Update success !!!\n";
//				cout << "New information: "; p->data.printInfo(); cout << endl;
//				break;
//			}
//			}
//		} while (flag);
//
//	}
//	// Function for filtering list student
//	void filterStudent()
//	{
//		bool flag = true;
//		do
//		{
//			cout << endl;
//			cout << "*********************** Filter **************************\n";
//			cout << "Select type of information that you want to filter: \n";
//			cout << "1. Student's name: \n";
//			cout << "2. Student's gender: \n";
//			cout << "3. Student's address: \n";
//			cout << "4. Student's falcuty: \n";
//			cout << "5. Student's major: \n";
//			cout << "6. Student's roomID:\n";
//			cout << "0. Exit\n";
//			cout << "*********************************************************\n";
//			int n; cout << "Input: "; cin >> n;
//			switch (n)
//			{
//			case 1:
//			{
//				cout << "Input name: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.firstName == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 2:
//			{
//				cout << "Input gender: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.gender == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 3:
//			{
//				cout << "Input address: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.address == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 4:
//			{
//				cout << "Input falcuty: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.falcuty == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 5:
//			{
//				cout << "Input major: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.major == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 6:
//			{			
//				cout << "Input roomID: "; string str; cin >> str;
//				NODE* current = head;
//				while (current != nullptr)
//				{
//					if (current->data.roomID == str) { current->data.printInfo(); }
//					current = current->next;
//				}
//				break;
//			}
//			case 0:
//			{
//				flag = false;
//				break;
//			}
//			}
//		} while (flag);
//	}
//};

int main()
{
	ManageStudent MS;
	Student s1("22110099", "Nguyen", "Van", "A", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D0");
	Student s2("22110022", "Nguyen", "Van", "B", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s3("22110062", "Nguyen", "Van", "C", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D011");
	Student s4("22110072", "Nguyen", "Van", "D", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D012");
	Student s5("22110082", "Nguyen", "Van", "E", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D013");
	Student s6("22110012", "Nguyen", "Van", "F", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D011");
	Student s7("22110052", "Nguyen", "Van", "G", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s8("22110032", "Nguyen", "Van", "H", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D016");
	Student s9("22110042", "Nguyen", "Van", "I", "24/06/2004", "Nam", "HCM", "12345", "FIE", "IT", "30/10/2023", "D01");
	Student s10("2211024", "Nguyen", "Van", "J", "24/06/2004", "Nam", "HN", "12345", "FIE", "IT", "30/10/2023", "D013");
	ManageRoom2 a;
	Room b12, b22,b23;
	NodeTree* b13;
	b12.editRoom();
	b22.editRoom();
	b23.editRoom();
	a.InsertRoom(b12);
	a.InsertRoom(b22);
	a.InsertRoom(b23);
	a.printListRoom();
	b13 = a.findRoom(1);
	b13->data.editRoom();
	a.deleteRoom(b13->data);
	cout << "after delete! ";
	a.printListRoom();

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
	////MS.deleteStudent("22110022");
	//MS.updateInfo("22110022");
	//MS.filterStudent();
	
	
	
	
}

