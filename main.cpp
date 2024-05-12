#include <iostream>
#include <string>
#include "Repository.h"
#include "Social.h"
#include "User.h"
using namespace std;

int main() {
	//Repository rep;
	//ChainHash hashobj;
	//Social network;


	//UNod user1("name1", 1, "a");
	//UNod user2("name2", 2, "b");
	//UNod user3("name3", 3, "c");

	//int choice;
	//string username, password, repName, commitText, fileName;

	//while (true) {
	//	cout << "Welcome to the Social Coding Platform!" << endl;
	//	cout << "---------------------------" << endl;
	//	cout << "1. Create a new repository" << endl;
	//	cout << "2. Sign up for a new user account" << endl;
	//	cout << "3. Sign in to an existing user account" << endl;
	//	cout << "4. Follow another user" << endl;
	//	cout << "5. Unfollow another user" << endl;
	//	cout << "6. View social network" << endl;
	//	cout << "7. Create a new commit" << endl;
	//	cout << "8. Add a file to a repository" << endl;
	//	cout << "9. Delete a file from a repository" << endl;
	//	cout << "10. View repository statistics" << endl;
	//	cout << "11. Exit" << endl;
	//	cout << "Enter your choice: ";
	//	cin >> choice;

	//	switch (choice) {
	//	case 1:

	//		cout << "Enter repository name: ";
	//		cin >> repName;
	//		rep.repositoryCreate(user1, true, repName);
	//		break;
	//	case 2:
	//		cout << "Enter username: ";
	//		cin >> username;
	//		cout << "Enter password: ";
	//		cin >> password;
	//		hashobj.signUp(username, 0, password);
	//		break;
	//	case 3:
	//		cout << "Enter username: ";
	//		cin >> username;
	//		cout << "Enter password: ";
	//		cin >> password;
	//		hashobj.signIn(username, password);
	//		break;
	//	case 4:
	//		cout << "Enter source username: ";
	//		cin >> username;
	//		UNode* source = hashobj.findUser(username);
	//		cout << "Enter destination username: ";
	//		cin >> username;
	//		UNode* destination = hashobj.findUser(username);
	//		network.followUser(source, destination);
	//		break;
	//	case 5:
	//		cout << "Enter source username: ";
	//		cin >> username;
	//		UNode* sourceUnfollow = hashobj.findUser(username);
	//		cout << "Enter destination username: ";
	//		cin >> username;
	//		UNode* destinationUnfollow = hashobj.findUser(username);
	//		network.unfollowUser(sourceUnfollow, destinationUnfollow);
	//		break;
	//	case 6:
	//		network.printSocialNetwork();
	//		break;
	//	case 7:
	//		cout << "Enter repository name: ";
	//		cin >> repName;
	//		cout << "Enter commit text: ";
	//		cin >> commitText;
	//		rep.PerformCommit(repName, commitText);
	//		break;
	//	case 8:
	//		cout << "Enter repository name: ";
	//		cin >> repName;
	//		cout << "Enter file name: ";
	//		cin >> fileName;
	//		rep.fileAdd(repName, fileName);
	//		break;
	//	case 9:
	//		cout << "Enter repository name: ";
	//		cin >> repName;
	//		cout << "Enter file name: ";
	//		cin >> fileName;
	//		rep.fileDelete(repName, fileName);
	//		break;
	//	case 10:
	//		cout << "Enter repository name: ";
	//		cin >> repName;
	//		rep.viewStats(repName);
	//		break;
	//	case 11:
	//		return 0;
	//	default:
	//		cout << "Invalid choice. Please try again." << endl;
	//	}
	//}

	return 0;
}

