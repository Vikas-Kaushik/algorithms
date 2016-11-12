#include <iostream>
#include <set>
#include <queue>
#include <map>
#define N 5
using namespace std;

class Node {
public:
	char key;
	int weight;
	Node* next;
	Node(char key = '\0', int weight = 0) : key(key), weight(weight), next(NULL) {};
};

class Graph {
	unsigned int size;
	unsigned int current_size;
	Node **adList;
public:

	Graph(unsigned int size) : size(size) {
		cout << "Creating a Graph..." << endl;
		current_size = 0;
		adList = new Node*[size];
		for (int i = 0; i < size; ++i) {
			adList[i] = new Node;
		}
		cout << endl;
	}

	void addEdge(char src, char dest, int weight = 0) {
		cout << "Adding an edge " << src << " -> " << dest << " with weight " << weight << endl;
		int k = -1;
		for (int i = 0; i < current_size; ++i) {
			if (adList[i]->key == src) {
				k = i;
				break;
			}
		}
		if (k == -1 && current_size < size) {
			adList[current_size]->key = src;
			k = current_size;
			++current_size;
		}

		Node *newNode = new Node(dest, weight);
		cout << "Added " << src << " -> " << dest << "(" << weight << ")" << endl;
		newNode->next = adList[k]->next;
		adList[k]->next = newNode;
		cout << endl;
	}

	void printAdList() {
		cout << "Printing adjecency list:" << endl;
		for (int i = 0; i < current_size; ++i) {
			cout << adList[i]->key << " -> ";
			Node *current = adList[i]->next;
			while (current) {
				cout << current->key << "(" << current->weight << "), ";
				current = current->next;
			}
			cout << endl;
		}
		cout << endl;
	}

	void BFS_Traversal() {
		cout << "BFS Traversal..." << endl;
		set<char> visited;
		queue<Node*> q;
		Node *root = adList[0];		
		q.push(root);
		while (!q.empty()) {
			root = q.front(); q.pop();
			if (visited.cend() == visited.find(root->key)) { // if root is not already visited
				cout << " -> " << root->key;
				visited.insert(root->key);
			}			
			while (root != NULL) {
				if (visited.cend() == visited.find(root->key)) {
					for (int i = 0; i < current_size; ++i) {
						if (adList[i]->key == root->key) {
							root = adList[i];
						}
					}
					q.push(root);
				}
				root = root->next;
			}
		}
		cout << endl;
	}
	void DFS_Traversal() {
		cout << "DFS Traversal..." << endl;

		cout << endl;
	}
	//g->TopologicalSort();
};

int imain() {
	Graph *g = new Graph(N);

	g->addEdge('a', 'b');
	g->addEdge('a', 'e', 2);
	g->addEdge('b', 'e', 3);
	g->addEdge('b', 'c', 4);
	g->addEdge('b', 'd', 2);
	g->addEdge('d', 'c', 3);
	g->addEdge('d', 'e', 5);

	g->printAdList();

	g->BFS_Traversal();
	g->DFS_Traversal();
	//g->TopologicalSort();
	getchar();
	return 0;
}
