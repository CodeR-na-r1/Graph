#pragma once

#include <string>

using namespace std;

class Node
{

public:

	Node(const string& aname)
	{
		this->name = aname;
	}

	const string getName() const
	{
		return this->name;
	}

	~Node()
	{
		neighbours.clear();
	}

private:

	std::set<Node*> neighbours;
	std::string name;

	void addNeigbours(Node* neighbour)
	{
		if (!neighbour)
			return;

		this->neighbours.insert(neighbour);

		return;
	}

	void removeNeigbours(Node* neighbour)
	{
		if (!neighbour)
			return;

		this->neighbours.erase(neighbour);

		return;
	}

	std::set<Node*>::const_iterator neighbours_begin()
	{
		return this->neighbours.begin();
	}

	std::set<Node*>::const_iterator neighbours_end()
	{
		return this->neighbours.end();
	}

	friend class Graph;
	friend class BFS;
	friend class DFS;
};