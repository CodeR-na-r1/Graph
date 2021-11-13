#pragma once

#include <set>

using namespace std;

#include "Node.h"
#include "BFS.h"
#include "DFS.h"

class Graph
{
public:

	Graph()
	{

	}

	void addNode(Node* node)
	{
		nodes.insert(node);

		return;
	}

	void removeNode(Node* node)
	{
		nodes.erase(node);

		for (auto it = nodes.begin(); it != nodes.end(); ++it)
		{
			(*it)->removeNeigbours(node);
		}

		return;
	}

	void addEdge(Node* begin, Node* end)
	{
		if (nodes.find(begin) == nodes.end())
			return;

		if (nodes.find(end) == nodes.end())
			return;

		begin->addNeigbours(end);
		end->addNeigbours(begin);

		return;
	}

	void removeEdge(Node* begin, Node* end)
	{
		if (nodes.find(begin) == nodes.end())
			return;

		if (nodes.find(end) == nodes.end())
			return;

		begin->removeNeigbours(end);
		end->removeNeigbours(begin);

		return;
	}

	~Graph()
	{
		for (auto it = nodes.begin(); it != nodes.end(); ++it)
		{
			(*it)->~Node();
		}

		nodes.clear();
	}

private:

	std::set<Node*> nodes;

	std::set<Node*>::const_iterator begin()
	{
		return nodes.begin();
	}

	std::set<Node*>::const_iterator end()
	{
		return nodes.end();
	}
};