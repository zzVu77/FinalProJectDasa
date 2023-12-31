#pragma once
#include <iostream>
#include"Node.h"
#include"Sort.h"
#include"Date.h"
#include"ChuanHoa.h"
#include <fstream>
using namespace std;
struct ManageStudent
{
	Node* head;
	Node* tail;
public:	
	// Function for adding a new node to the last of list
	void addLast(const Student& x) {
		Node* node = new Node();
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
		return;
	}
	void readfile(const char fname[])
	{
		ifstream file;

		file.open(fname);
		if (!file) {
			cerr << "Error: file not opened." << endl;
			return;
		}		
		while (!file.eof())
		{
			Student a;
			string roomID;
		
			getline(file, a.studentID, ',');
			getline(file, a.lastName, ',');
			getline(file, a.middleName, ',');
			getline(file, a.firstName, ',');
			getline(file, a.dob, ',');
			getline(file, a.gender, ',');
			getline(file, a.address, ',');
			getline(file, a.phoneNo, ',');
			getline(file, a.falcuty, ',');
			getline(file, a.major, ',');
			getline(file, a.enterDate, '\n');				
			a.status = false;			
			addLast(a);

		}
		file.close();
		return;
	}
	void writeFile(const char fname[])
	{
		ofstream file;
		file.open(fname);
		Node* p = head;
		do
		{
			file << p->data.studentID << "," << p->data.lastName << "," << p->data.middleName << ","
				<< p->data.firstName << "," << p->data.dob << "," << p->data.gender << ","
				<< p->data.address << "," << p->data.phoneNo << "," << p->data.falcuty << ","
				<< p->data.major << "," << p->data.enterDate << '\n';
			p = p->next;
		} while (p->next != NULL);
		file << p->data.studentID << "," << p->data.lastName << "," << p->data.middleName << ","
			<< p->data.firstName << "," << p->data.dob << "," << p->data.gender << ","
			<< p->data.address << "," << p->data.phoneNo << "," << p->data.falcuty << ","
			<< p->data.major << "," << p->data.enterDate;
		file.close();
		return;
	}

	// Function for adding a new node to list
	void addNode(Node* a)
	{
		Node* node = new Node();
		node = a;
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

	// Function for removing first node
	void removeFirst()
	{
		if (isEmptyList() == false)
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			if (isEmptyList() == true) tail = NULL;
		}
		return;
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
				Node* temp = head;
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
	Node* getPreviousNode(Node* node)
	{
		Node* curr = head;
		while (curr != NULL)
		{
			if (curr->next != NULL and curr->next == node) return curr;
			curr = curr->next;
		}
		return NULL;
	}

	void initListStudent()
	{
		head = NULL;
		tail = NULL;
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
		cout << "Input studenn's last name: "; getline(cin, lastName); s.lastName = lastName;
		cout << "Input studenn's middle name: "; getline(cin, middleName); s.middleName = middleName;
		cout << "Input studenn's first name: "; getline(cin, firstName); s.lastName = firstName;
		cout << "Input studenn's birthday: "; getline(cin, dob); s.dob = dob;
		cout << "Input studenn's address: "; getline(cin, address); s.address = address;
		cout << "Input studenn's phone number: "; getline(cin, phoneNo); s.phoneNo = phoneNo;
		cout << "Input studenn's falcuty: "; getline(cin, falcuty); s.falcuty = falcuty;
		cout << "Input studenn's major: "; getline(cin, major); s.major = major;
		//cout << "Input studenn's enterDate: "; getline(cin, enterDate); s.enterDate = enterDate;
		//cout << "Input studenn's roomID: "; getline(cin, roomID); s.roomID = roomID;
		addLast(s);
	}

	Node* searchNode(string id)
	{
		if (head == NULL) return NULL;
		Node* node = head;
		while (node != NULL and node->data.studentID != id)
		{
			if (node->next == NULL and node->data.studentID != id) return NULL;
			node = node->next;
		}
		return node;
	}

	// Fuunction for searching a student by using ID and printing on screen
	void searchStudent(string id)
	{
		Node* s = searchNode(id);
		if (s == NULL) { cout << "Student does not exist !!!\n"; return; }
		else s->data.printInfo();
	}

	// Function for deleting a student by seaching student by ID and deleting him
	void deleteStudent(string id)
	{

		if (searchNode(id) == NULL)
		{
			cout << "Student does not exist in the list !!!\n";
			cout << "Delete failed !!!\n";
		}
		else if (searchNode(id)->data.status == true) cout << "Student is hiring room. Delete failed !!! \n";
		else
		{
			Node* node = searchNode(id);
			if (node == head) {
				removeFirst();
				cout << "Successfully deleted \n";
				return;
			}
			if (node == tail)
			{
				removeLast();
				cout << "Successfully deleted \n";
				return;
			}
			Node* pre = getPreviousNode(node);
			if (pre != NULL)
				pre->next = node->next;
			else {
				pre = node->next;
				head = pre;
			}
			cout << "Successfully deleted \n";
			delete(node);
			return;
		}
	}

	void deleteNode(string id)
	{
		Node* node = searchNode(id);
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
		Node* pre = getPreviousNode(node);
		if (pre != NULL)
			pre->next = node->next;
		else {
			pre = node->next;
			head = pre;
		}
		cout << "Successfully deleted \n";
		delete(node);
		return;
	}

	// Function for displaying list student
	void displayListStudent()
	{
		Node* curr = head;
		int i = 0;
		while (curr != NULL)
		{
			i++;
			cout<<setw(4) << i << "\t |";
			curr->data.printInfo();
			curr = curr->next;
		}
	}

	// Function for updating information of student
	Student updateInfo(string id)
	{
		if (searchNode(id) == NULL)
		{
			cout << "Student does not exist in the list !!!\n";
			cout << "Update failed\n";
			Student a;
			return a;
		}
		Node* p = searchNode(id);
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

			string strCheck;
			do {
				cout << "Input: "; cin >> strCheck;
			} while (!checkSo(strCheck));
			int n = stoi(strCheck);
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
				cout << "Update new birthdate: \n";
				string str;
				do
				{
					cin >> str;		
					if (checkDate(str) == false) cout << "The date you entered is not valid. Please re-enter !!!\n";
				} while (!checkDate(str));
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
		return p->data;
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
//			cout << "6. Student's roomID:\n";
			cout << "0. Exit\n";
			cout << "*********************************************************\n";
			string strCheck;
			do {
				cout << "Input: "; cin >> strCheck;
			} while (!checkSo(strCheck));
			int n = stoi(strCheck);
			switch (n)
			{
			case 1:
			{
				cout << "Input name: "; string str; cin >> str;
				Node* current = head;
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
				Node* current = head;
				while (current != nullptr)
				{
					if (current->data.gender == str) { current->data.printInfo(); }
					current = current->next;
				}
				break;
			}
			case 3:
			{
				cout << "Input address: "; 
				cin.ignore();
				string str; getline(cin,str);
				Node* current = head;
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
				Node* current = head;
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
				Node* current = head;
				while (current != nullptr)
				{
					if (current->data.major == str) { current->data.printInfo(); }
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

	//Function for using Merge sort to sort list student by first and last name
	void sortStudent() {
		mergeSort(head);
	}

	// Funtion for counting the number of students in the list
	int countStudent()
	{
		int dem = 0;
		Node* curr = head;
		while (curr != NULL)
		{
			dem++;
			curr = curr->next;
		}
		return dem;
	}

	int countStudentGender(string gender)
	{
		int dem = 0;
		Node* curr = head;
		while (curr != NULL)
		{
			if(curr->data.gender==gender)
				dem++;
			curr = curr->next;
		}
		return dem;
	}

	bool isExisting(string id)
	{
		if (searchNode(id) == NULL) return true; else return false;
	}
};

