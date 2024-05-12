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
	vertices = ChainHash::sizeReturn();
	adjacencyLists = new unode * [vertices];
	for (int i = 0; i < vertices; i++) {
		adjacencyLists[i] = nullptr;
	}
}

void Social::addEdge(UNod*& source, UNod*& destination) {
	unode* newNode = new unode(destination->getName(), destination->getUserID());
	newNode->next = adjacencyLists[source->getUserID()];
	adjacencyLists[source->getUserID()] = newNode;
}

bool Social::isFollowingUser(UNod*& source, UNod*& destination) {
	if (source->getUserID() >= 0 && destination->getUserID() >= 0) {
		ifstream input("followingID.csv");

		if (input.is_open()) {
			string oneLine;
			while (getline(input, oneLine)) {
				stringstream ss(oneLine);
				string csvSourceID, csvDestinationID;

				if (getline(ss, csvSourceID, '-') && getline(ss, csvDestinationID)) {
					if (csvSourceID == to_string(source->getUserID()) && csvDestinationID == to_string(destination->getUserID())) {
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
		string oneLine;
		string currentUser;
		string following;

		while (getline(input, oneLine)) {
			stringstream ss(oneLine);
			string csvSourceName, csvDestinationName;

			if (getline(ss, csvSourceName, '-') && getline(ss, csvDestinationName)) {
				if (csvSourceName != currentUser) {
					if (!currentUser.empty()) {
						cout << currentUser << "->" << following << endl;
					}
					currentUser = csvSourceName;
					following = csvDestinationName;
				}
				else {
					following += " " + csvDestinationName;
				}
			}
		}
		if (!currentUser.empty()) {
			cout << currentUser << "->" << following << endl;
		}
		input.close();
	}
	else {
		cout << "Cannot open the following.csv file" << endl;
	}
}

void Social::followUser(UNod*& source, UNod*& destination) {
	if (source->getUserID() >= 0 && destination->getUserID() >= 0) {
		if (!isFollowingUser(source, destination)) {
			addEdge(source, destination);

			ofstream output("followingID.csv", ios::app);
			ofstream network("followingName.csv", ios::app);

			if (output.is_open()) {
				output << source->getUserID() << '-' << destination->getUserID() << endl;
				if (network.is_open()) {
					network << source->getName() << '-' << destination->getName() << endl;
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
			cout << "You are already following " << destination->getName() << "!" << endl;
		}
	}
	else {
		cout << "Either one or both of the users do not exist!" << endl;
	}
}

void Social::unfollowUser(UNod*& source, UNod*& destination) {
	if (source->getUserID() >= 0 && destination->getUserID() >= 0) {
		if (!isFollowingUser(source, destination)) {
			cout << "You cannot unfollow a user that you haven't followed!" << endl;
		}
		else {
			ifstream input("followingID.csv");
			ofstream write("write.csv");

			if (input.is_open() && write.is_open()) {
				string oneLine;

				while (getline(input, oneLine)) {
					stringstream ss(oneLine);
					string csvSourceID, csvDestinationID;

					if (getline(ss, csvSourceID, '-') && getline(ss, csvDestinationID)) {
						if (csvSourceID != to_string(source->getUserID()) || csvDestinationID != to_string(destination->getUserID())) {
							write << oneLine << endl;
						}
					}
				}
				input.close();
				write.close();
				remove("followingID.csv");
				rename("write.csv", "followingID.csv");
			}
			else {
				cout << "Cannot open followingID.csv or write.csv or both" << endl;
			}
		}
	}
	else {
		cout << "Either one or both of the users do not exist!" << endl;
	}
}
