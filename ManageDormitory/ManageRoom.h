#pragma once
#include"Node.h"
#include"NodeTree.h"
#define MAX 100
double convertAddress(string address)
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
double convertMajor(string major)
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
struct ManageRoom2
{
private:
	NodeTree* head = NULL;
	//util print
	void preOrder(NodeTree* root)
	{
		if (root != NULL)
		{
			preOrder(root->left);
			root->data.printPhong();
			preOrder(root->right);
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
	bool ifNodeExists(NodeTree* node, int key)
	{
		if (node == NULL)
			return false;
		if (node->data.getID() == key)
			return true;
		bool res1 = ifNodeExists(node->left, key);
		if (res1) return true;
		bool res2 = ifNodeExists(node->right, key);

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
	double similarity(Student a, Student b)
	{
		double x1 = convertAddress(a.address), x2 = convertMajor(a.major), y1(convertAddress(b.address)), y2(convertMajor(b.major));
		return (x1 * y1 + x2 * y2) / (sqrt(x1 * x1 + x2 * x2) * sqrt(y1 * y1 + y2 * y2));
	}
public:
	ManageRoom2() {}
	ManageRoom2(Room a)
	{
		NodeTree* p = new NodeTree();
		p->data = a;
		p->left = NULL;
		p->right = NULL;
		p->height = 1;
		head = p;
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
};

