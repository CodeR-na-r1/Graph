#pragma once

class DFS
{

public:

	DFS(const Graph& agraph) : graph(agraph)	{}

	bool connected(Node* begin, Node* end)
	{
		visited.clear();
		return connected(begin, end, 0);
	}

private:

	const Graph& graph;
	std::set<Node*> visited;

	bool connected(Node* begin, Node* end, int depth)
	{
		if (begin == end)
			return true;

		visited.insert(begin);

		for (std::set<Node*>::const_iterator it = begin->neighbours_begin(); it != begin->neighbours_end(); ++it)
		{
			if (visited.find(*it) == visited.end())
			{
				if (connected((*it), end, depth + 1))
					return true;
			}
		}

		return false;
	}
};