#pragma once
#include"Room.h"
struct NodeTree {
	Room data;
	NodeTree* left = NULL;
	NodeTree* right = NULL;
	int height = 0;
};