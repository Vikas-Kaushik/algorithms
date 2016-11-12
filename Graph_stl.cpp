#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

// Node ~ vertex
class Node {
public:
	char key; // Node/Vertex ID
	int weight; // applicable to only source vertex in an edge
	Node(char key = '\0', int weight = 0) : key(key), weight(weight) {};
};

class Graph {
public:
	unsigned int size;
	vector<list<Node>> adList;
	map<char, int> key_index; // for quick char to vector index mapping
	 
	Graph(vector<char> &v) { // list of nodes is provided while creating a graph
		this->size = v.size();
		for (int i = 0; i < size; ++i) {
			adList[i].insert(adList[i].begin(), Node(v[i]));
			key_index[v[i]] = i;
		}
	}

	void addEdge(char src, char dest, int weight = 0) {
		int i = key_index[src];
		adList[i].insert(adList[i].begin(), Node(dest, weight));
	}

	void printAdList() {
		cout << "Printing adjecency list..." << endl;
		for (auto & it : adList) {
			cout << "head";
			for (auto & it1 : it) {
				cout << " -> " << it1.key << "(" << it1.weight << ")";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	cout << "Inside main..." << endl;
	vector<char> vertices = { 'a', 'b', 'c', 'd', 'e' };
	Graph *g = new Graph(vertices);

	g->addEdge('a', 'b');
	g->addEdge('a', 'e', 2);
	g->addEdge('b', 'e', 3);
	g->addEdge('b', 'c', 4);
	g->addEdge('b', 'd', 2);
	g->addEdge('d', 'c', 3);
	g->addEdge('d', 'e', 5);

	g->printAdList();

	//g->BFS_Traversal();
	//g->DFS_Traversal();

	getchar();
	return 0;
}
