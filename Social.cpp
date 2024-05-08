#include"User.h"
#include "Social.h"

node::node(string u, int id) {
	user = u;
	uid = id;
	next = nullptr;
}

Social::Social() {
	vertices = User::getNumofUsers();
	adjacencyLists = new node * [vertices];
	for (int i = 0; i < vertices; i++) {
		adjacencyLists[i] = nullptr;
	}
}

void Social::addEdge(User& source, User& destination) {
	node* newNode = new node(destination.getName(), destination.getID());
	newNode->next = adjacencyLists[source.getID()];
	adjacencyLists[source.getID()] = newNode;
}

