#include "DirectedGraph.h"

DirectedGraph::DirectedGraph(Edge* edges, int size) {
	for (int i = 0; i < size; i++) {
		int src = edges[i].src, dest = edges[i].dest;
		if (nodes.count(src) == 0) {
			nodes[src] = new SingleLinkedList<int>();
		}
		nodes[src]->add(dest);
		if (nodes.count(dest) == 0) {
			nodes[dest] = new SingleLinkedList<int>();
		}
	}
}

DirectedGraph::~DirectedGraph() {
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		delete (*it).second;
	}
}

void DirectedGraph::printGraph() {
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		printf("node(%d) has edges: ", (*it).first);
		for (auto itl = (*it).second->begin(); itl != (*it).second->end(); itl++) {
			printf("%d ", (*itl));
		}
		printf("\n");
	}
}

/* Incredibly helpful website for insipration.
https://www.geeksforgeeks.org/topological-sorting/
*/
void DirectedGraph::topologySort(int node, LinkedStack<int>& stack, set<int>& set) {

	// inserts this node into the set, so we can keep track that we've visited it
	set.insert(node);

	// iterates through this node's edges
	for (auto it = nodes.at(node)->begin(); it != nodes.at(node)->end(); it++) {
		if (set.count((*it)) == 0) { // if node has not been visited, call topologySort for this node
			topologySort((*it), stack, set);
		}
	}

	// pushes this node to the stack for returning later
	stack.push(node);
	
}

vector<int>* DirectedGraph::topologySort() {

	// fields, empty stack and set for algorithm, empty vector for returning
	LinkedStack<int> stack;
	set<int> set;
	vector<int>* retVal = new vector<int>();

	// iterate through the entire map
	for (auto it = nodes.begin(); it != nodes.end(); it++) {
		if (set.count((*it).first) == 0) { // if the node at this point has not been visited, call topologySort
			topologySort((*it).first, stack, set);
		}
	}

	// take this stack and empty it out into the vector for returning
	while (stack.isEmpty() == false) {
		retVal->push_back(stack.peek());
		stack.pop();
	}
	return retVal;

}


