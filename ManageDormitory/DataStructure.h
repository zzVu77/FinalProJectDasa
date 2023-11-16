#pragma once
#include"Student.h"
#include"Room.h"
struct Node
{
	Student data;
	Node* next;
};
struct NodeTree {
	Room data;
	NodeTree* left = NULL;
	NodeTree* right = NULL;
	int height = 0;
};