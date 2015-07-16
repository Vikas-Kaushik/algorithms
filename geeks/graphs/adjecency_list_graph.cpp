/*
 * This program represents adjecency list representation of a graph
 */
#include <iostream>
using namespace std;

struct AdjNode {
  int vertex; // AdjNode vertex value
  AdjNode *next;
};

struct Graph {
  AdjNode *AdjList; // pointer to AdjNode list
  int vertices;   // number of vertices
};

AdjNode* createAdjNode(int j);
void addEdge(Graph *g, int i, int j);
Graph* createGraph(int n);

int main() {
  int n = 4; // n is no. of vertices
  Graph *g = createGraph(n);
  addEdge(g,0,1);
  addEdge(g,0,4);
  return 0;
}

Graph* createGraph(int n) {
  Graph *g = new Graph;
  // number of vertices in the graph
  g->vertices = n;
  // AdjList is array of AdjNodes of size n
  g->AdjList = new AdjNode[n];
  // Initializing each AdjNode in AdjList to NULL
  for(int i = 0; i < n; ++i) {
    g->AdjList[i] = NULL;
  }
}

void addEdge(Graph *g, int i, int j) {
  // if ith AdjNode in AdjList is NULL, then adding first edge for ith Vertex
  if(g->AdjList[i] == NULL) {
    g->AdjList[i] = createAdjNode(j);
  }
  else {
    AdjNode *newNode = createAdjNode(j);
    newNode->next = g->AdjList[i];
    g->AdjList[i] = newNode;
  }
}

AdjNode* createAdjNode(int j) {
  AdjNode *newNode = new AdjNode;
  newNode->vertex = j;
  newNode->next = NULL;
}
