#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
	/* for tests 
	* 
	Graph g;
	Node* n_1 = new Node(string("1"));
	Node* n_2 = new Node(string("2"));
	Node* n_3 = new Node(string("3"));

	g.addNode(n_1);
	g.addNode(n_2);
	g.addNode(n_3);
	g.addEdge(n_1, n_3);

	g.removeNode(n_1);
	*/

	Graph graph;
	ifstream in("data.txt");
	in >> graph;

	std::set<Node*>::const_iterator it;
	Node* temp_node;
	int count(0);

	while (!graph.empty())
	{
		it = graph.begin();	// an iterator to pull out the next vertex to find a subgraph

		Graph temp_graph;	// subgraph in a graph

		queue<Node*> nodes;	// a queue for storing neighbors of vertices, for their further processing
		nodes.push(*it);

		while (!nodes.empty())
		{
			temp_node = nodes.front();
			temp_graph.addNode(temp_node);

			for (auto i = temp_node->neighbours_begin(); i != temp_node->neighbours_end(); ++i)
			{
				if (!temp_graph.in((*i)->getName()))	// if there are unadded neighbors, then add them for further processing
					nodes.push(*i);
			}

			nodes.pop();
			graph.removeNode(temp_node);
		}

		++count;

		string namefile;	// form the file name and output the graph to the file
		namefile = "export_graph_";
		namefile += to_string(count);
		namefile += ".txt";

		ofstream out(namefile);

		out << temp_graph;
	}

	return 0;
}