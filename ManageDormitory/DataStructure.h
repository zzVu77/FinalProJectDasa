#pragma once
#include"Student.h"
#include"Room.h"
struct NODE
{
	Student data;
	NODE* next;
};
struct NodeTree {
	Room data;
	NodeTree* left = NULL;
	NodeTree* right = NULL;
	int height = 0;
};