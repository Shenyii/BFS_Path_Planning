#include "Map.h"

Map::Map()
	:x0_(-1),y0_(-1),x1_(-1),y1_(-1)
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			map_[i][j].setPosition(i, j);
		}
	}
}


Map::~Map()
{
	node_searched_.clear();
}

void Map::setStart(int x, int y)
{
	x0_ = x;
	y0_ = y;
}

void Map::setDestination(int x, int y)
{
	x1_ = x;
	y1_ = y;
}

void Map::display()
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (map_[j][i].getObstacle() == 1)
			{
				cout << "X" << " ";
			}
			else if (map_[j][i].getState() == 1)
			{
				cout << "o" << " ";
			}
			else if (map_[j][i].getState() == 2)
			{
				cout << ">" << " ";
			}
			else
			{
				cout << "." << " ";
			}
		}
		cout << endl;
	}
}

void Map::getPath()
{
	Node* node = &map_[x1_][y1_];
	node->setState(2);
	while (node->getPreviousNode() != NULL)
	{
		node = node->getPreviousNode();
		node->setState(2);
	}
}

void Map::setObstacle(int x, int y, int width, int height)
{
	for (int i = x; i < x + width;i++)
	{
		for (int j = y;j < y + height; j++)
		{
			map_[i][j].setObstacle(true);
		}
	}
}

void Map::setNodeState(int x,int y)
{
	if ((x - 1 >= 0) && (y - 1 >= 0) && (map_[x - 1][y - 1].getObstacle() != 1))
	{
		if (map_[x - 1][y - 1].getState() == 0)
		{
			map_[x - 1][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x - 1][y - 1].setEnlightValue(x1_, y1_);
			map_[x - 1][y - 1].setState(true);
			node_searched_.push_back(map_[x - 1][y - 1]);
		}
		else if (map_[x][y].getDistance() + sqrt(2) < map_[x - 1][y - 1].getDistance())
		{
			map_[x - 1][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x - 1][y - 1].setEnlightValue(x1_, y1_);
			map_[x - 1][y - 1].setState(true);
		}
	}

	if ((y - 1 >= 0) && (map_[x][y - 1].getObstacle() != 1))
	{
		if (map_[x][y - 1].getState() == 0)
		{
			map_[x][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + 1, &map_[x][y]);
			map_[x][y - 1].setEnlightValue(x1_, y1_);
			map_[x][y - 1].setState(true);
			node_searched_.push_back(map_[x][y - 1]);
		}
		else if (map_[x][y].getDistance() + 1 < map_[x][y - 1].getDistance())
		{
			map_[x][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x][y - 1].setEnlightValue(x1_, y1_);
			map_[x][y - 1].setState(true);
		}
	}

	if ((x + 1 < 100) && (y - 1 >= 0) && (map_[x + 1][y - 1].getObstacle() != 1))
	{
		if (map_[x + 1][y - 1].getState() == 0)
		{
			map_[x + 1][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x + 1][y - 1].setEnlightValue(x1_, y1_);
			map_[x + 1][y - 1].setState(true);
			node_searched_.push_back(map_[x + 1][y - 1]);
		}
		else if (map_[x][y].getDistance() + sqrt(2) < map_[x + 1][y - 1].getDistance())
		{
			map_[x + 1][y - 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x + 1][y - 1].setEnlightValue(x1_, y1_);
			map_[x + 1][y - 1].setState(true);
		}
	}

	if ((x - 1 >= 0) && (map_[x - 1][y].getObstacle() != 1))
	{
		if (map_[x - 1][y].getState() == 0)
		{
			map_[x - 1][y].setDistanceAndPreviousNode(map_[x][y].getDistance() + 1, &map_[x][y]);
			map_[x - 1][y].setEnlightValue(x1_, y1_);
			map_[x - 1][y].setState(true);
			node_searched_.push_back(map_[x - 1][y]);
		}
		else if (map_[x][y].getDistance() + 1 < map_[x - 1][y].getDistance())
		{
			map_[x - 1][y].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x - 1][y].setEnlightValue(x1_, y1_);
			map_[x - 1][y].setState(true);
		}
	}

	if ((x + 1 < 100) && (map_[x + 1][y].getObstacle() != 1))
	{
		if (map_[x + 1][y].getState() == 0)
		{
			map_[x + 1][y].setDistanceAndPreviousNode(map_[x][y].getDistance() + 1, &map_[x][y]);
			map_[x + 1][y].setEnlightValue(x1_, y1_);
			map_[x + 1][y].setState(true);
			node_searched_.push_back(map_[x + 1][y]);
		}
		else if (map_[x][y].getDistance() + 1 < map_[x + 1][y].getDistance())
		{
			map_[x + 1][y].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x + 1][y].setEnlightValue(x1_, y1_);
			map_[x + 1][y].setState(true);
		}
	}

	if ((x - 1 >= 0) && (y + 1 < 100) && (map_[x - 1][y + 1].getObstacle() != 1))
	{
		if (map_[x - 1][y + 1].getState() == 0)
		{
			map_[x - 1][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x - 1][y + 1].setEnlightValue(x1_, y1_);
			map_[x - 1][y + 1].setState(true);
			node_searched_.push_back(map_[x - 1][y + 1]);
		}
		else if (map_[x][y].getDistance() + sqrt(2) < map_[x - 1][y + 1].getDistance())
		{
			map_[x - 1][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x - 1][y + 1].setEnlightValue(x1_, y1_);
			map_[x - 1][y + 1].setState(true);
		}
	}

	if ((y + 1 < 100) && (map_[x][y + 1].getObstacle() != 1))
	{
		if (map_[x][y + 1].getState() == 0)
		{
			map_[x][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + 1, &map_[x][y]);
			map_[x][y + 1].setEnlightValue(x1_, y1_);
			map_[x][y + 1].setState(true);
			node_searched_.push_back(map_[x][y + 1]);
		}
		else if (map_[x][y].getDistance() + 1 < map_[x][y + 1].getDistance())
		{
			map_[x][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x][y + 1].setEnlightValue(x1_, y1_);
			map_[x][y + 1].setState(true);
		}
	}

	if ((x + 1 < 100) && (y + 1 <100) && (map_[x + 1][y + 1].getObstacle() != 1))
	{
		if (map_[x + 1][y + 1].getState() == 0)
		{
			map_[x + 1][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x + 1][y + 1].setEnlightValue(x1_, y1_);
			map_[x + 1][y + 1].setState(true);
			node_searched_.push_back(map_[x + 1][y + 1]);
		}
		else if (map_[x][y].getDistance() + sqrt(2) < map_[x + 1][y + 1].getDistance())
		{
			map_[x + 1][y + 1].setDistanceAndPreviousNode(map_[x][y].getDistance() + sqrt(2), &map_[x][y]);
			map_[x + 1][y + 1].setEnlightValue(x1_, y1_);
			map_[x + 1][y + 1].setState(true);
		}
	}
}

int Map::currentSearchNode()
{
	Node* search_node = &node_searched_[0];
	int n = 0;
	for (unsigned int i = 0; i < node_searched_.size(); i++)
	{
		if (search_node->getEnlightenValue() > node_searched_[i].getEnlightenValue())
		{
			search_node = &node_searched_[i];
			n = i;
		}
	}
	return n;
}

int Map::searchThePath()
{
	map_[x0_][y0_].setDistanceAndPreviousNode(0, NULL);
	map_[x0_][y0_].setEnlightValue(x1_, y1_);
	map_[x0_][y0_].setState(true);
	node_searched_.push_back(map_[x0_][y0_]);
	while(map_[x1_][y1_].getDistance() == -1)
	{
		if (node_searched_.size() == 0)
		{
			return 0;
		}

		int n;
		n = currentSearchNode();
		int x = node_searched_[n].getX();
		int y = node_searched_[n].getY();
		node_searched_.erase(node_searched_.begin() + n, node_searched_.begin() + n + 1);
		setNodeState(x, y);
	}
	return 1;
}
