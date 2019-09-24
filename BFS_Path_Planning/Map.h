#pragma once
#include <iostream>
#include "Node.h"
#include <vector>

using namespace std;

class Map
{
public:
	Map();
	~Map();
	void setStart(int x,int y);
	void setDestination(int x,int y);
	int searchThePath();
	void display();
	void setObstacle(int x,int y,int width,int height);
	void getPath();

private:
	Node map_[100][100];
	int x0_;
	int y0_;
	int x1_;
	int y1_;
	vector<Node> node_searched_;
	void setNodeState(int x,int y);
	int currentSearchNode();
};

