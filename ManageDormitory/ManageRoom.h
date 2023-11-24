#pragma once
#include"Node.h"
#include"NodeTree.h"
#define MAX 100

struct ManageRoom
{
private:
	NodeTree* head = NULL;
	//util print
	void preOrder(NodeTree* root)
	{
		if (root != NULL)
		{
			root->data.printPhong();
			preOrder(root->left);
			preOrder(root->right);
		}
		return;
	}
	void preOrderEmpty(NodeTree* root)
	{
		if (root != NULL)
		{
			if(root->data.isEmpty())
				root->data.printPhong();
			preOrderEmpty(root->left);
			preOrderEmpty(root->right);
		}
		return;
	}
	void utilFindIdRoomWithStudent(NodeTree* root, string id, int& saveID)
	{
		if (root != NULL )
		{
			if (root->data.checkStudentInRoom(id))
			{
				saveID = root->data.getID();
			}
			utilFindIdRoomWithStudent(root->left,id, saveID);
			utilFindIdRoomWithStudent(root->right,id, saveID);
		}
		return;
	}
	void UtilprintStudentInRoom(NodeTree* root)
	{
		if (root != NULL)
		{
			UtilprintStudentInRoom(root->left);
			cout <<"=====================================" << root->data.getID()<<"==================================\n";
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
		if(y->left == NULL && y->right == NULL)
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
	bool ifNodeExists(NodeTree*& node, int key)
	{
		if (node == NULL)
			return false;
		if (node->data.getID() == key)
		{
			return true;
		}
		bool res1 = ifNodeExists(node->left, key);
		if (res1) {
			node = node->left;
			return true;
		}
		bool res2 = ifNodeExists(node->right, key);
		if (res2)
		{
			node = node->right;
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
	void UtilautomaticallyAddRoom(NodeTree* root, ManageStudent &liststudent)
	{
		if (root != NULL)
		{
			root->data.automaticallyAddStudent(liststudent);
			UtilautomaticallyAddRoom(root->left, liststudent);
			UtilautomaticallyAddRoom(root->right, liststudent);
		}
		return;
	}
	void UtilSuggestRoom(NodeTree* root, Student datas, float &saved, int& savedID)
	{
		if (root != NULL)
		{
			float  p = root->data.scoreSimilarityOfRoom(datas);
			if (saved <= p)
			{
				saved = p;
				savedID = root->data.getID();
			}
			UtilSuggestRoom(root->left, datas,saved,savedID);
			UtilSuggestRoom(root->right, datas,saved,savedID);
		}
		return;
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
		int ok;
		file.open(fname);
		if (!file) {
			cerr << "Error: file not opened." << endl;
			return;
		}

		//Node* q = head;
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
			getline(file, type, ',');
			getline(file, beds, ',');
			getline(file, capacity, ',');
			getline(file, cost, '\n');

			Room a(stoi(id), type, stoi(beds), stoi(capacity), stod(cost) * 1.0);
			InsertRoom(a);
		}
		file.close();
	}
	void InsertRoom(Room a)
	{
		head = insert(head, a);
	}
	void printListRoom()
	{
		preOrder(head);
	}
	NodeTree* findRoom(int id)
	{
		NodeTree* p = new NodeTree();
		p = head;
		if (ifNodeExists(p, id))
		{
			return p;
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
		return;
	}
	void printStudentInRoom()
	{
		UtilprintStudentInRoom(head);
		return;
	}
	void printRoomEmpty()
	{

	}
	void suggestRoom(Student a)
	{
		float score = -1;
		int id(-1);
		UtilSuggestRoom(head, a,score,id);
		cout << id<<": "<< score;
		return;
	}
	// in danh sách các phòng đang còn chỗ trống
	void printListEmptyRoom()
	{
		cout << "==========================empty room===============================================\n";
		preOrderEmpty(head);
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
			if (q->data.People - q->data.list.countStudent() != 0)
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
};

