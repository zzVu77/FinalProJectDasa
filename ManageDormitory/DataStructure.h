#pragma once
#include"STUDENT.h"
#include"ROOM.h"
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