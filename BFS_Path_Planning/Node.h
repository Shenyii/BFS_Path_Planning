#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	Node();
	~Node();
	int getX();
	int getY();
	double getDistance();
	double getEnlightenValue();
	Node* getPreviousNode();
	bool getObstacle();
	int getState();
	void setPosition(int current_position_x, int current_position_y);
	void setEnlightValue(int destination_x,int destination_y);
	void setDistanceAndPreviousNode(double distance,Node* previous_node);
	void setObstacle(bool obstacle);
	void setState(int state);

private:
	int x_;
	int y_;
	double distance_;
	double enlighten_value_;
	Node* previous_node_;
	bool obstacle_;
	int state_;                                                                                                                         //"0":don't be searched,"1":have been searched.
};

