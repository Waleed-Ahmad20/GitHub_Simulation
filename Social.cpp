#include"User.h"
#include "Social.h"

unode::unode(string u, int id) {
	user = u;
	uid = id;
	next = nullptr;
}

Social::Social() {
	vertices = User::getNumofUsers();
	adjacencyLists = new unode * [vertices];
	for (int i = 0; i < vertices; i++) {
		adjacencyLists[i] = nullptr;
	}
}

void Social::addEdge(User& source, User& destination) {
	unode* newNode = new unode(destination.getName(), destination.getUserID());
	newNode->next = adjacencyLists[source.getUserID()];
	adjacencyLists[source.getUserID()] = newNode;
}

bool Social::isFollowing(User& source, User& destination) {
	unode* current = adjacencyLists[source.getUserID()];
	while (current) {
		if (current->user == destination.getName() && current->uid == destination.getUserID()) {
			return true;
		}
		else {
			current = current->next;
		}
	}
	return false;
}

void Social::printSocialNetwork() {
	for (int i = 0; i < vertices; i++) {
		unode* current = adjacencyLists[i];
		cout << "User ID " << i << " -> ";
		while (current) {
			cout << current->user << " ";
			current = current->next;
		}
		cout << endl;
	}
}

