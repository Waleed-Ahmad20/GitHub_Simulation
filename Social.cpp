#include"User.h"
#include "Social.h"
#include<fstream>
#include<sstream>

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
		ifstream input("followingID.csv");
		
		if (input.is_open()) {
			string line;
			while (getline(input, line)) {
				stringstream ss(line);
				string csvSourceID, csvDestinationID;

				if (getline(ss, csvSourceID, '-') && getline(ss, csvDestinationID)) {
					if (csvSourceID == to_string(source.getUserID()) && csvDestinationID == to_string(destination.getUserID())) {
						input.close();
						return true;
					}
				}
			}
			input.close();
		}
		else {
			cout << "Cannot open the followingID.csv file" << endl;
		}
	}
	else {
		cout << "Either one or both of the users do not exist!" << endl;
	}
	return false;
}

void Social::printSocialNetwork() {
	ifstream input("followingName.csv");

	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			stringstream ss(line);
			string csvSourceName, csvDestinationName;

			if (getline(ss, csvSourceName, '-') && getline(ss, csvDestinationName)) {
				cout << csvSourceName << "->" << csvDestinationName << " ";
				input.close();
			}
		}
		input.close();
	}
	else {
		cout << "Cannot open the following.csv file" << endl;
	}
}

void Social::followUser(User& source, User& destination) {
	if (source.getUserID() >= 0 && destination.getUserID() >= 0) {
		if (!isFollowingUser(source, destination)) {
			addEdge(source, destination);

			ofstream output("followingID.csv", ios::app);
			ofstream network("followingName.csv", ios::app);

			if (output.is_open()) {
				output << source.getUserID() << '-' << destination.getUserID() << endl;
				if (network.is_open()) {
					network << source.getName() << '-' << destination.getName() << endl;
				}
				else {
					cout << "Cannot open the followingName.csv file" << endl;
				}
			}
			else {
				cout << "Cannot open the followingID.csv file" << endl;
			}
			output.close();
			network.close();
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

