#pragma once
#include"ManageStudent.h"
#include <cmath>
#include <string>
#include <iostream>
#include<iomanip>
using namespace std;
float convertAddress(string address)
{
	if (address == "Lai Chau")
		return 1;
	else if (address == "Dien Bien")
		return 2;
	else if (address == "Son La")
		return 3;
	else if (address == "Lao Cai")
		return 4;
	else if (address == "Yen Bai")
		return 5;
	else if (address == "Ha Giang")
		return 6;
	else if (address == "Tuyen Quang")
		return 7;
	else if (address == "Cao Bang")
		return 8;
	else if (address == "Bac Kan")
		return 9;
	else if (address == "Phu Tho")
		return 10;
	else if (address == "Thai Nguyen")
		return 11;
	else if (address == "Vinh Phuc")
		return 12;
	else if (address == "Lang Son")
		return 13;
	else if (address == "Bac Giang")
		return 14;
	else if (address == "Quang Ninh")
		return 15;
	else if (address == "Bac Ninh")
		return 16;
	else if (address == "Hai Duong")
		return 17;
	else if (address == "Hai Phong")
		return 19.5;
	else if (address == "Hung Yen")
		return 18;
	else if (address == "Ha Noi")
		return 18.5;
	else if (address == "Hoa Binh")
		return 19;
	else if (address == "Ha Nam")
		return 20;
	else if (address == "Thai Binh")
		return 21;
	else if (address == "Nam Dinh")
		return 22;
	else if (address == "Ninh Binh")
		return 23;
	else if (address == "Thanh Hoa")
		return 24;
	else if (address == "Nghe An")
		return 25;
	else if (address == "Ha Tinh")
		return 26;
	else if (address == "Quang Binh")
		return 27;
	else if (address == "Quang Tri")
		return 28;
	else if (address == "Hue")
		return 28.5;
	else if (address == "Da Nang")
		return 28.7;
	else if (address == "Quang Nam")
		return 29;
	else if (address == "Quang Ngai")
		return 30;
	else if (address == "Kon Tum")
		return 31;
	else if (address == "Binh Dinh")
		return 32;
	else if (address == "Gia Lai")
		return 33;
	else if (address == "Phu Ten")
		return 34;
	else if (address == "Dak Lak")
		return 35;
	else if (address == "Khanh Hoa")
		return 36;
	else if (address == "Dak Nong")
		return 37;
	else if (address == "Lam Dong")
		return 38;
	else if (address == "Ninh Thuan")
		return 39;
	else if (address == "Binh Thuan")
		return 40;
	else if (address == "Dong Nai")
		return 41;
	else if (address == "Binh Phuoc")
		return 42;
	else if (address == "Tay Ninh")
		return 43;
	else if (address == "Binh Duong")
		return 44;
	else if (address == "Vung Tau")
		return 45;
	else if (address == "Ho Chi Minh")
		return 44.5;
	else if (address == "Long An")
		return 46;
	else if (address == "Dong Thap")
		return 47;
	else if (address == "Tien Giang")
		return 48;
	else if (address == "Ben Tre")
		return 49;
	else if (address == "Vinh Long")
		return 50;
	else if (address == "Tra Vinh")
		return 51;
	else if (address == "Can Tho")
		return 53.4;
	else if (address == "Soc Trang")
		return 52;
	else if (address == "Hau Giang")
		return 53;
	else if (address == "An Giang")
		return 54;
	else if (address == "Kien Giang")
		return 55;
	else if (address == "Bac Lieu")
		return 56;
	else if (address == "Ca Mau")
		return 57;
	else return 0;
}
float convertMajor(string major)
{
	if (major == "IT")
		return 10;
	else if (major == "Marketing")
		return 50;
	else if (major == "Food Technology")
		return 30;
	else if (major == "Mechanics")
		return 20;
	else if (major == "Accounting")
		return 40;
	else if (major == "Hotel Management")
		return 60;
	else return 0;
}
struct Room
{
public:
	int RoomID = -1;
	//string TypeRoom;
	int NumberOfBed;
	int Capacity;
	double Cost;
	int empty;
	ManageStudent list;
	float similarity(Student a, Student b)
	{
		float x1 = convertAddress(a.address), x2 = convertMajor(a.major), y1(convertAddress(b.address)), y2(convertMajor(b.major));
		return (x1 * y1 + x2 * y2) / (sqrt(x1 * x1 + x2 * x2) * sqrt(y1 * y1 + y2 * y2));
	}
public:
	Room(int idRoom, /*string typeRoom, */int numberOfBed, int people, double cost)
	{
		this->RoomID = idRoom;
		//this->TypeRoom = typeRoom;
		this->NumberOfBed = numberOfBed;
		this->Capacity = people;
		this->Cost = cost;
		this->list.initListStudent();
		this->empty = this->Capacity;
	}
	Room() {}
	void printPhong() {
		cout << setw(0);

		cout << "ID Room: " << RoomID <</* "\tType: " << TypeRoom <<*/ "\tNumber Of Bed : " << NumberOfBed << "\tCapacity: " << Capacity << "\tEmpty: " << empty << "\tCost: " << Cost << '\n';
		return;
	}
	int getID()
	{
		return this->RoomID;
	}
	void editRoom()
	{
		cout << setw(0);
		cout << "Input Room ID: ";
		cin >> RoomID;
		/*cout << "Type: ";
		cin >> TypeRoom;*/
		cout << "Input Number Of Bed: ";
		cin >> NumberOfBed;
		cout << "Input capacity: ";
		cin >> Capacity;
		cout << "Input cost: ";
		cin >> Cost;
		return;
	}
	bool check(Room a)
	{
		return a.getID() == RoomID;
	}
	void addToList(Student& s)
	{
		/*if (this->list.isExisting(s.studentID) == true)
		{
			cout << "Student already exists in this list\n ";
		}*/
		if (list.countStudentGender("Nu") > 0 and s.gender == "Nam")
		{
			cout << "This room is for female. Added failed !\n";
			return;
		}
		else
			if (list.countStudentGender("Nam") > 0 and s.gender == "Nu")
			{
				cout << "This room is for male. Added failed !\n";
				return;
			}
		if (this->empty > 0)
		{
			s.roomID = this->RoomID;
			s.status = true;
			this->list.addLast(s);
			this->empty = this->empty - 1;
			cout << setw(0);

			cout << "Added successfully\n";
		}
		else cout << "The room is full !!!\n";

	}
	void printListStudent()
	{
		list.displayListStudent();
		//cout << "========================================================================\n";
		return;
	}
	void automaticallyAddStudent(ManageStudent& liststudent)
	{
		//ManageStudent liststudent = listS;


		if (list.countStudent() == 0)
		{
			Node* first = liststudent.head;
			while (first != NULL and first->data.status != false)
			{
				first = first->next;
			}
			if (first == NULL) return;
			float max(-99999);
			first->data.status = true;
			first->data.roomID = this->RoomID;
			Student curr = first->data;
			int numberOfGender(liststudent.countStudentGender(curr.gender));
			list.addLast(curr);
			this->empty--;
			// tìm ra sv phù hợp, add vào list sv của room, xóa khởi list đầu vào
			while (list.countStudent() != Capacity and liststudent.head != NULL and numberOfGender != list.countStudent())
			{
				max = -99999;
				Node* p = liststudent.head;

				while (p != NULL and max != 1)
				{
					if (curr.gender == p->data.gender and p->data.status == false)
					{
						if (max < similarity(curr, p->data)) {
							max = similarity(curr, p->data);
						}
					}
					p = p->next;
				}

				Node* p1 = liststudent.head;
				while ((p1->next != NULL and similarity(curr, p1->data) != max) or (p1->next != NULL and curr.gender != p1->data.gender) or (p1->next != NULL and p1->data.status == true))
				{
					p1 = p1->next;
				}

				this->empty--;
				p1->data.roomID = this->RoomID;
				p1->data.status = true;
				list.addLast(p1->data);
			}
			return;
		}
		else {
			float max = 0;
			// tìm ra sv phù hợp so với sv có sẵn trong list, add vào list sv của room, xóa khởi list đầu vào
			while (list.countStudent() != Capacity and liststudent.head != NULL)
			{
				max = 0;
				Node* p = liststudent.head;
				while (p != NULL)
				{
					Node* curr = list.head;
					float total = 0;
					if (p->data.gender == curr->data.gender)
					{
						while (curr != NULL)
						{
							total += similarity(curr->data, p->data);
							curr = curr->next;
						}
						if (total >= max) {
							max = total;
						}
					}
					p = p->next;
				}
				Node* p1 = liststudent.head;
				float sumScore(0);
				while (p1 != NULL)
				{
					sumScore = 0;
					Node* curr1 = list.head;
					if (p1->data.gender == curr1->data.gender)
					{
						while (curr1 != NULL)
						{
							sumScore += similarity(curr1->data, p1->data);
							curr1 = curr1->next;
						}
					}
					if (sumScore != max)
						p1 = p1->next;
					else break;
				}
				this->empty--;
				p1->data.roomID = this->RoomID;
				p1->data.status = true;
				list.addLast(p1->data);


			}
			return;
		}
	}
	void addStudent(const Student a)
	{
		list.addLast(a);
		this->empty--;
		return;
	}
	float scoreSimilarityOfRoom(Student a)
	{
		Node* p = list.head;
		float total(0);
		while (p != NULL and list.countStudent() != Capacity)
		{
			total += similarity(a, p->data);
			p = p->next;
		}
		return total / list.countStudent() * 1.0;
	}
	void deleteStudent(string id)
	{
		list.deleteStudent(id);
		this->empty = Capacity - list.countStudent();
		return;
	}
	bool checkStudentInRoom(string id)
	{
		if (list.searchNode(id) == NULL)
			return false;
		else return true;
	}
	Student getStudent(string id)
	{
		Student a;
		Node* p = list.searchNode(id);
		a = p->data;
		return a;
	}
	bool isEmpty()
	{
		if ((list.countStudent() - Capacity) == 0)
			return false;
		return true;
	}
	~Room() {}
};


