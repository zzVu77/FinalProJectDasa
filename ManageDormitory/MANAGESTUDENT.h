#pragma once
#include <iostream>
#include"DataStructure.h"
using namespace std;
struct ManageStudent
{
	NODE* head;
	NODE* tail;
	void initListStudent()
	{
		head = NULL;
		tail = NULL;
	}
	// Function for adding a new node to the last of list
	void addLast(const Student& x) {
		NODE* node = new NODE();
		node->data = x;
		node->next = NULL;
		if (head == NULL) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}
	// Function for adding a new node to list
	void addNode(const Student& x)
	{
		NODE* node = new NODE();
		node->data = x;
		node->next = NULL;
		if (head == NULL)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	bool isEmptyList()
	{
		return head == NULL;
	}
	// Function for adding a new student
	void addStudent()
	{
		Student s;
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
		bool status = true;
		s.status = status;
		cout << "*************** Add Student ***************\n";
		cin.ignore();
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		cout << "Input studenn's first name: "; getline(cin, firstName); s.firstName = firstName;
		cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
		cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
		cout << "Input studenn's birthday: "; getline(cin, dob); s.dob = dob;
		cout << "Input studenn's address: "; getline(cin, address); s.address = address;
		cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
		cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
		cout << "Input studenn's major: "; getline(cin, major); s.major = major;
		cout << "Input studenn's enterDate: "; getline(cin, enterDate); s.enterDate = enterDate;
		cout << "Input studenn's roomID: "; getline(cin, roomID); s.roomID = roomID;
		/*cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;
		cout << "Input studenn's ID: "; getline(cin, studentID); s.studentID = studentID;*/
		addLast(s);
	}
	// Function for removing first node
	void removeFirst()
	{
		if (isEmptyList() == false)
		{
			NODE* temp = head;
			head = head->next;
			delete temp;
			if (isEmptyList() == true) tail = NULL;
		}
	}
	// Function for removing last node
	void removeLast()
	{
		if (isEmptyList() == true) return;
		else
		{
			if (head == tail)
			{
				delete head;
				head = NULL;
				tail = NULL;
			}
			else
			{
				NODE* temp = head;
				do
				{
					temp = temp->next;
				} while (temp->next != tail);
				delete tail;
				tail = temp;
				tail->next = NULL;
			}
		}
	}
	// Function for getting previous node
	NODE* getPreviousNode(NODE*& node)
	{
		NODE* curr = head;
		while (curr != NULL)
		{
			if (curr->next != NULL and curr->next == node) return curr;
			curr = curr->next;
		}
		return NULL;
	}
	// Fuunction for searching a student by using ID
	NODE* searchStudent(string id)
	{
		if (head == NULL) return NULL;
		NODE* node = head;
		int i = 0;
		while (node != NULL and node->data.studentID != id)
		{
			if (node->next == NULL and node->data.studentID != id) return NULL;
			node = node->next;
			i++;
		}
		return node;
	}
	// Function for deleting a student by seaching student by ID and deleting him
	void deleteStudent(string id)
	{

		if (searchStudent(id) == NULL)
		{
			cout << "Student does not exist in the list !!!\n";
			cout << "Delete failed !!!";
		}
		else
		{
			NODE* node = searchStudent(id);
			if (head == tail) {
				removeFirst();
				cout << "Successfully deleted \n";
				return;
			}
			if (head == tail)
			{
				removeLast();
				cout << "Successfully deleted \n";
				return;
			}
			NODE* pre = getPreviousNode(node);
			pre->next = node->next;
			cout << "Successfully deleted \n";
			delete(node);
		}

	}
	// Function for displaying list student
	void displayListStudent()
	{
		NODE* curr = head;
		int i = 0;
		while (curr != NULL)
		{
			i++;
			cout << i << "\t |";
			curr->data.printInfo();
			curr = curr->next;
		}
	}
	// Function for updating information of student
	void updateInfo(string id)
	{
		if (searchStudent(id) == NULL)
		{
			cout << "Student does not exist in the list !!!\n";
			cout << "Update failed\n";
			return;
		}
		NODE* p = searchStudent(id);
		bool flag = true;
		do
		{
			cout << "\n";
			cout << "*********************** Update **************************\n";
			cout << "Select type of information that you want to update: \n";
			cout << "1. Student's ID \n";
			cout << "2. Student's name \n";
			cout << "3. Student's birthdate \n";
			cout << "4. Student's gender \n";
			cout << "5. Student's phone number \n";
			cout << "6. Student's address \n";
			cout << "7. Student's major \n";
			cout << "8. Student's falcuty\n";
			cout << "0. Exit\n";
			cout << "*********************************************************\n";
			int n; cout << "Input: "; cin >> n;
			switch (n)
			{
			case 0:
			{
				flag = false;
				break;
			}
			case 1:
			{
				cout << "Update new ID: ";
				string str;
				cin >> str;
				p->data.studentID = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 2:
			{
				string lastName;
				string middleName;
				string firstName;
				cout << "Update new last name:"; cin >> lastName;
				cout << "Update new middle name:"; cin >> middleName;
				cout << "Update new first name:"; cin >> firstName;
				p->data.lastName = lastName;
				p->data.middleName = middleName;
				p->data.firstName = firstName;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 3:
			{
				cout << "Update new birthdate: ";
				string str;
				cin >> str;
				p->data.dob = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 4:
			{
				cout << "Update new gender: ";
				string str;
				cin >> str;
				p->data.gender = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 5:
			{
				cout << "Update new phone number: ";
				string str;
				cin >> str;
				p->data.phoneNo = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 6:
			{
				cout << "Update new address: ";
				string str;
				cin >> str;
				p->data.address = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 7:
			{
				cout << "Update new major: ";
				string str;
				cin >> str;
				p->data.major = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			case 8:
			{
				cout << "Update new falcuty: ";
				string str;
				cin >> str;
				p->data.falcuty = str;
				cout << "Update success !!!\n";
				cout << "New information: "; p->data.printInfo(); cout << endl;
				break;
			}
			}
		} while (flag);

	}
	// Function for filtering list student
	void filterStudent()
	{
		bool flag = true;
		do
		{
			cout << endl;
			cout << "*********************** Filter **************************\n";
			cout << "Select type of information that you want to filter: \n";
			cout << "1. Student's name: \n";
			cout << "2. Student's gender: \n";
			cout << "3. Student's address: \n";
			cout << "4. Student's falcuty: \n";
			cout << "5. Student's major: \n";
			cout << "6. Student's roomID:\n";
			cout << "0. Exit\n";
			cout << "*********************************************************\n";
			int n; cout << "Input: "; cin >> n;
			switch (n)
			{
			case 1:
			{
				cout << "Input name: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.firstName == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 2:
			{
				cout << "Input gender: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.gender == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 3:
			{
				cout << "Input address: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.address == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 4:
			{
				cout << "Input falcuty: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.falcuty == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 5:
			{
				cout << "Input major: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.major == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 6:
			{
				cout << "Input roomID: "; string str; cin >> str;
				NODE* current = head;
				while (current != nullptr)
				{
					if (current->data.roomID == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 0:
			{
				flag = false;
				break;
			}
			}
		} while (flag);
	}
};

