#pragma once

#include <queue>

class BFS {

public:

	BFS(const Graph& agraph) : graph(agraph) {}

	bool connected(Node* begin, Node* end)
	{
		std::queue<Node*> nodes;
		std::set<Node*> visited;
		Node* next;
		
		nodes.push(begin);
		
		while (!nodes.empty())
		{
			next = nodes.front();
			nodes.pop();

			if (next == end)
			{
				return true;
			}

			visited.insert(next);

			for (std::set<Node*>::const_iterator it = next->neighbours_begin(); it != next->neighbours_end(); ++it)
			{
				if (visited.find(*it) == visited.end())
				{
					nodes.push(*it);
				}
			}
		}

		return false;
	}

private:

	const Graph& graph;
};