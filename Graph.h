#pragma once

#include <set>
#include <fstream>

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

	void addNode(string& name)
	{
		Node* node = new Node(name);

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

	void full_clear()
	{

	}

	bool in(const string& name) const
	{
		for (auto i = nodes.begin(); i != nodes.end(); ++i)
		{
			if ((*i)->name == name)
				return true;
		}

		return false;
	}

	Node* find(string& name)
	{
		for (auto i = nodes.begin(); i != nodes.end(); ++i)
		{
			if ((*i)->name == name)
				return *i;
		}

		return nullptr;
	}

	bool empty()
	{
		if (nodes.size())
			return false;
		else
			return true;
	}

	friend ifstream& operator>>(ifstream& in, Graph& graph)
	{
		string temp_name_1, temp_name_2;

		while (!in.eof())
		{
			in >> temp_name_1 >> temp_name_2;

			if (!graph.in(temp_name_1))
				graph.addNode(temp_name_1);

			if (!graph.in(temp_name_2))
				graph.addNode(temp_name_2);

			graph.addEdge(graph.find(temp_name_1), graph.find(temp_name_2));
		}

		return in;
	}

	friend ofstream& operator<<(ofstream& out, Graph& graph)
	{
		while (!graph.empty())
		{
			auto it = graph.begin();
			for (auto i = (*it)->neighbours_begin(); i != (*it)->neighbours_end(); ++i)
			{
				out << (*it)->getName() << " " << (*i)->getName() << endl;
			}
			graph.removeNode(*it);
		}

		return out;
	}

	std::set<Node*>::const_iterator begin()
	{
		return nodes.begin();
	}

	std::set<Node*>::const_iterator end()
	{
		return nodes.end();
	}

private:

	std::set<Node*> nodes;
};