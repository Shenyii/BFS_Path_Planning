#include "Node.h"



Node::Node()
	:distance_(-1),enlighten_value_(0),previous_node_(nullptr),obstacle_(false),x_(-1),y_(-1),state_(0)
{
}


Node::~Node()
{
	//delete previous_node_;
}

int Node::getX()
{
	return x_;
}

int Node::getY()
{
	return y_;
}

double Node::getDistance()
{
	return distance_;
}

double Node::getEnlightenValue()
{
	return enlighten_value_;
}

Node* Node::getPreviousNode()
{
	return previous_node_;
}

bool Node::getObstacle()
{
	return obstacle_;
}

void Node::setPosition(int current_position_x, int current_position_y)
{
	x_ = current_position_x;
	y_ = current_position_y;
}

int Node::getState()
{
	return state_;
}

void Node::setEnlightValue(int destination_x, int destination_y)
{
	if (obstacle_ == true)
	{
		return;
	}
	int x1, y1;
	x1 = destination_x;
	y1 = destination_y;
	enlighten_value_ = sqrt((x_ - x1) * (x_ - x1) + (y_ - y1) * (y_ - y1));
}

void Node::setDistanceAndPreviousNode(double distance, Node* previous_node)
{
	distance_ = distance;
	previous_node_ = previous_node;
}

void Node::setObstacle(bool obstacle)
{
	obstacle_ = obstacle;
}

void Node::setState(int state)
{
	state_ = state;
}
