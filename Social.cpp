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

bool Social::isFollowingUser(User& source, User& destination) {
	if (source.getUserID() >= 0 && destination.getUserID() >= 0) {
		unode* current = adjacencyLists[source.getUserID()];
		while (current) {
			if (current->user == destination.getName() && current->uid == destination.getUserID()) {
				return true;
			}
			else {
				current = current->next;
			}
		}
	}
	else {
		cout << "Either one or both of the users do not exist!" << endl;
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

void Social::followUser(User& source, User& destination) {
	if (source.getUserID() >= 0 && destination.getUserID() >= 0) {
		if (!isFollowingUser(source, destination)) {
			addEdge(source, destination);
		}
		else {
			cout << "You are already following " << destination.getName() << "!" << endl;
		}
	}
	else {
		cout << "Either one or both of the users do not exist!" << endl;
	}
}

void Social::unfollowUser(User& source, User& destination) {
	if (source.getUserID() >= 0 && destination.getUserID() >= 0) {
		if (!isFollowingUser(source, destination)) {
			cout << "You cannot unfollow a user that you haven't followed!" << endl;
		}
		else {
			unode* previous = nullptr;
			unode* current = adjacencyLists[source.getUserID()];
			while (current) {
				if (current->uid == destination.getUserID() && current->user == destination.getName()) {
					break;
				}
				previous = current;
				current = current->next;
			}
			if (current) {
				if (previous) {
					previous->next = current->next;
					delete current;
				}
				else {
					adjacencyLists[source.getUserID()] = current->next;
					delete current;
				}
			}
		}
	}
		else {
		cout << "Either one or both of the users do not exist!" << endl;
	}
}

