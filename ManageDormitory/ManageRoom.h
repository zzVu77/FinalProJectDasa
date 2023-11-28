#pragma once
#include"Node.h"
#include"NodeTree.h"
#define MAX 100

struct ManageRoom
{
private:
	NodeTree* head = NULL;
	//util print
	void inOrder(NodeTree* root)
	{
		if (root != NULL)
		{

			inOrder(root->left);
			root->data.printPhong();
			inOrder(root->right);
		}
		return;
	}
	void inOrderRoomBill(NodeTree* root)
	{
		if (root != NULL)
		{
			inOrderRoomBill(root->left);
			root->data.printRoomBill();
			inOrderRoomBill(root->right);
		}
		return;
	}
	void inOrderInputBill(NodeTree* root)
	{
		if (root != NULL)
		{
			inOrderInputBill(root->left);
			cout << "Room " << root->data.RoomID << endl;
			root->data.inputElectricityBill();
			root->data.inputWaterBill();
			inOrderInputBill(root->right);
		}
		return;
	}
	void inOrderEmpty(NodeTree* root)
	{
		if (root != NULL)
		{
			inOrderEmpty(root->left);
			if (root->data.isEmpty())
			{
				root->data.printPhong();
			}
			inOrderEmpty(root->right);
		}
	}
	void utilFindIdRoomWithStudent(NodeTree* root, string id, int& saveID)
	{
		if (root != NULL)
		{
			if (root->data.checkStudentInRoom(id))
			{
				saveID = root->data.getID();
			}
			utilFindIdRoomWithStudent(root->left, id, saveID);
			utilFindIdRoomWithStudent(root->right, id, saveID);
		}
		return;
	}
	void UtilprintStudentInRoom(NodeTree* root)
	{
		if (root != NULL)
		{
			UtilprintStudentInRoom(root->left);
			cout << "=====================================" << root->data.getID() << "==================================\n";
			root->data.printListStudent();
			UtilprintStudentInRoom(root->right);
		}
		return;
	}
	// cân bằng nếu bên trái thừa
	NodeTree* rightRotate(NodeTree* y)
	{
		NodeTree* x = y->left;
		NodeTree* T2 = x->right;

		x->right = y;
		y->left = T2;
		if (y->left == NULL && y->right == NULL)
			y->height = 1;
		else if (y->left == NULL)
		{
			y->height = 1 + y->right->height;
		}
		else if (y->right == NULL)
		{
			y->height = 1 + y->left->height;
		}
		else if (y->left->height >= y->right->height)
		{
			y->height = 1 + y->left->height;
		}
		else
			y->height = 1 + y->right->height;

		//
		if (x->left == NULL && x->right == NULL)
			x->height = 1;
		else if (x->left == NULL)
		{
			x->height = 1 + x->right->height;
		}
		else if (x->right == NULL)
		{
			x->height = 1 + x->left->height;
		}
		else if (x->left->height >= x->right->height)
		{
			x->height = 1 + x->left->height;
		}
		else
			x->height = 1 + x->right->height;

		return x;
	}
	// cân bằng nếu bên phải thừa
	NodeTree* leftRotate(NodeTree* x)
	{
		NodeTree* y = x->right;
		NodeTree* T2 = y->left;

		y->left = x;
		x->right = T2;

		if (x->left == NULL && x->right == NULL)
			x->height = 1;
		else if (x->left == NULL)
		{
			x->height = 1 + x->right->height;
		}
		else if (x->right == NULL)
		{
			x->height = 1 + x->left->height;
		}
		else if (x->left->height >= x->right->height)
		{
			x->height = 1 + x->left->height;
		}
		else
			x->height = 1 + x->right->height;

		//

		if (y->left == NULL && y->right == NULL)
			y->height = 1;
		else if (y->left == NULL)
		{
			y->height = 1 + y->right->height;
		}
		else if (y->right == NULL)
		{
			y->height = 1 + y->left->height;
		}
		else if (y->left->height >= y->right->height)
		{
			y->height = 1 + y->left->height;
		}
		else
			y->height = 1 + y->right->height;

		return y;
	}
	int Balance(NodeTree* N)
	{
		if (N == NULL)
			return 0;
		else if (N->right == NULL)
			return N->left->height - 0;
		else if (N->left == NULL)
			return 0 - N->right->height;
		return N->left->height - N->right->height;
	}
	NodeTree* insert(NodeTree* node, Room key)	
	{
		if (node == NULL)
		{
			NodeTree* p = new NodeTree();
			p->data = key;
			p->left = NULL;
			p->right = NULL;
			p->height = 1;
			return p;
		}

		if (key.getID() < node->data.getID())
			node->left = insert(node->left, key);
		else if (key.getID() > node->data.getID())
			node->right = insert(node->right, key);
		else
			return node;
		if (node->left == NULL && node->right == NULL)
			node->height = 1;
		else if (node->left == NULL)
		{
			node->height = 1 + node->right->height;
		}
		else if (node->right == NULL)
		{
			node->height = 1 + node->left->height;
		}
		else if (node->left->height >= node->right->height)
		{
			node->height = 1 + node->left->height;
		}
		else
			node->height = 1 + node->right->height;

		int balance = Balance(node);

		if (balance > 1 && key.getID() < node->left->data.getID())
			return rightRotate(node);


		if (balance < -1 && key.getID() > node->right->data.getID())
			return leftRotate(node);


		if (balance > 1 && key.getID() > node->left->data.getID())
		{
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		if (balance < -1 && key.getID() < node->right->data.getID())
		{
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}
	//tìm node trong tree
	bool ifNodeExists(NodeTree*& node, int key, NodeTree*& saved,int &savedInt)
	{
		if (node == NULL)
			return false;
		if (node->data.getID() == key)
		{
			return true;
		}
		bool res1 = ifNodeExists(node->left, key,saved,savedInt);
		if (res1 && savedInt !=1) {
			savedInt = 1;
			saved = node->left;
			return true;
		}
		bool res2 = ifNodeExists(node->right, key,saved,savedInt);
		if (res2 && savedInt != 1)
		{
			savedInt = 1;
			saved = node->right;
			return true;
		}
		return res2;
	}
	//tìm node nhỏ nhất
	NodeTree* findMin(NodeTree* node)
	{
		while (node->left != NULL)
		{
			node = node->left;
		}
		return node;
	}
	NodeTree* UtildeleteRoom(NodeTree* root, Room data)
	{
		if (root == NULL)
		{
			return root;
		}
		else if (data.getID() < root->data.getID()) root->left = UtildeleteRoom(root->left, data);
		else if (data.getID() > root->data.getID()) root->right = UtildeleteRoom(root->right, data);
		else {
			//case1 : no leaf
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
				return root;
			}// case2: 1 leaf
			else if (root->left == NULL)
			{
				NodeTree* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				NodeTree* temp = root;
				root = root->left;
				delete temp;
			}
			else {
				NodeTree* temp = findMin(root->right);
				root->data = temp->data;
				root->right = UtildeleteRoom(root->right, temp->data);
			}
		}
		return root;
	}
	void UtilautomaticallyAddRoom(NodeTree* root, ManageStudent& liststudent)
	{
		if (root != NULL)
		{
			root->data.automaticallyAddStudent(liststudent);
			UtilautomaticallyAddRoom(root->left, liststudent);
			UtilautomaticallyAddRoom(root->right, liststudent);
		}
		return;
	}
	void UtilSuggestRoom(NodeTree* root, Student datas, float& saved, int& savedID)
	{
		if (root != NULL)
		{
			float  p = root->data.scoreSimilarityOfRoom(datas);
			if ((saved <= p or p==0 )  and root->data.list.countStudentGender(datas.gender) != 0 and root->data.isEmpty())
			{
				saved = p;
				savedID = root->data.getID();
			}
			UtilSuggestRoom(root->left, datas, saved, savedID);
			UtilSuggestRoom(root->right, datas, saved, savedID);
		}
		return;
	}
	void utilWriteFile(ofstream& saved,NodeTree* root)
	{
		if (root != NULL)
		{	
			root->data.writeFile(saved);
			utilWriteFile(saved,root->left);
			utilWriteFile(saved, root->right);
		}

	}
public:
	ManageRoom() {}
	ManageRoom(Room a)
	{
		NodeTree* p = new NodeTree();
		p->data = a;
		p->left = NULL;
		p->right = NULL;
		p->height = 1;
		head = p;
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
			string id;
			string type;
			string beds;
			string capacity;
			string cost;
			//xoa utf neu neu can
			//if (i == 0)
			//{
			//	a.id.erase(a.id.begin(), a.id.begin() + 3);
			//}
				
			getline(file, id, ',');
			getline(file, beds, ',');
			getline(file, capacity, ',');
			getline(file, cost, '\n');
			if (id=="")
				break;
			Room a(stoi(id), stoi(beds), stoi(capacity), stod(cost));
			InsertRoom(a);
		}
		file.close();
		return;
	}
	void writefile(const char fname[])
	{
		ofstream file;
		file.open(fname);
		utilWriteFile(file,head);
		file.close();
		return;
	}
	void InsertRoom(Room a)
	{
		head = insert(head, a);
	}
	void printListRoom()
	{
		inOrder(head);
	}
	NodeTree* findRoom(int id)
	{
		NodeTree* p = new NodeTree(), *saved= new NodeTree();
		p = this->head;
		int a(0);
		if (ifNodeExists(p, id, saved,a))
		{
			return saved;
		}
		else /*cout << "Room does not exist! \n";*/ return NULL;
	}
	void deleteRoom(int id)
	{
		head = UtildeleteRoom(head, findRoom(id)->data);
		return;
	}
	void deleteRoom(Room a)
	{
		head = UtildeleteRoom(head, a);
		return;
	}
	void automaticallyAddRoom(ManageStudent &liststudent)
	{
		UtilautomaticallyAddRoom(head, liststudent);
		cout << "Added successfully !!!\n";
		return;
	}
	void printStudentInRoom()
	{
		UtilprintStudentInRoom(head);
		return;
	}
	int suggestRoom(Student a)
	{
		float score = 0;
		int id(-1);
		UtilSuggestRoom(head, a,score,id);		
		return id;
	}
	// in danh sách các phòng đang còn chỗ trống
	void printListEmptyRoom()
	{		
		inOrderEmpty(head);
		return;
	}
	void hiringRoom()
	{
		
		cout << "enter id: ";
		string id;
		getline(cin, id);
		int saveID(-1);
		NodeTree* run = head;
		utilFindIdRoomWithStudent(run, id, saveID);
		if (saveID != -1)
		{
			NodeTree* p = findRoom(saveID);
			Student sv = p->data.getStudent(id);
			cout << "enter ID room: ";
			int idRoom;
			cin >> idRoom;
			NodeTree* q = findRoom(idRoom);
			if (q->data.Capacity - q->data.list.countStudent() != 0)
			{
				p->data.deleteStudent(id);
				q->data.addStudent(sv);
				cout << "success!!\n";
			}
			else
			{
				cout << "room is full\n";
			}
		}
		else cout << "couldn't find it\n";
		return;
	}
	void checkOut()
	{
		cout << "enter id: ";
		string id;
		getline(cin, id);
		int saveID(-1);
		NodeTree* run = head;
		utilFindIdRoomWithStudent(run, id, saveID);
		if (saveID != -1)
		{
			NodeTree* p = findRoom(saveID);
			p->data.deleteStudent(id);
			cout << "success!!!\n";
		}
		else cout << "couldn't find it\n";
		return;
	}
	void updateRomInfo(int id)
	{
		NodeTree* p = findRoom(id);
		if (p == NULL)
		{
			cout << "Room does not exist in the list !!!\n Update failed \n";
			return;
		}
		//NodeTree* p = findRoom(id);
		bool flag = true;
		do
		{
			cout << "\n";
			cout << "*********************** Update **************************\n";
			cout << "Select type of information that you want to update: \n";
			cout << "1. Room ID \n";
			cout << "2. Numnber of Bed \n";
			cout << "3. Capacity \n";
			cout << "4. Cost\n";
			cout << "0. Exit !!! \n";
			int n;
			cout << "Enter: ";
			cin >> n;
			switch (n)
			{
			case 0:
			{
				flag = false;
				break;
			}
			case 1:
			{
				cout << "Update new Room ID: ";
				int n;
				cin >> n;
				p->data.RoomID = n;
				break;
			}
			case 2:
			{
				cout << "Update the number of bed: ";
				int n;
				cin >> n;
				p->data.NumberOfBed = n;
				break;
			}
			case 3:
			{
				cout << "Update the capacity of room: ";
				int n;
				cin >> n;
				p->data.Capacity = n;
				p->data.empty = n - p->data.list.countStudent();
				break;
			}
			case 4:
			{
				cout << "Update the cost: ";
				double n;
				cin >> n;
				p->data.Cost = n;
				break;
			}
			}
		} while (flag);
		//InsertRoom(p->data);
	}
	void printRoomBill()
	{
		cout << setw(0) << "Month: " << getCurrentMonth() << endl;
		inOrderRoomBill(head);
	}
	void inputRomBill()
	{
		cout << "Input Room Bill Month " << getCurrentMonth() << endl;
		inOrderInputBill(head);
	}

};

