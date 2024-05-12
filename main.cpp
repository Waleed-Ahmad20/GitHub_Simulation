#include <iostream>
#include <string>
#include "Repository.h"
#include "Social.h"
#include "User.h"
using namespace std;

int main() {
	Repository rep;
	ChainHash hashobj;
	Social network;

	static int count = 0;

	int choice1, choice2, choice3, choice4, choice5;
	bool _visibility = true;
	string username, username1, username2, password, repName, commitText, fileName;

	UNod* source = nullptr;
	UNod* destination = nullptr;
	UNod* sourceUnfollow = nullptr;
	UNod* destinationUnfollow = nullptr;

	while (true) {
		cout << "Welcome to the GitHub Simulation!" << endl;
		cout << "---------------------------" << endl;
		cout << "1. Sign up for a new user account" << endl;
		cout << "2. Sign in to an existing user account" << endl;
		cout << "3. Exit the program!" << endl;
		cout << "Enter choice: ";
		cin >> choice1;

		switch (choice1)
		{
		case 1:
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			hashobj.signUp(username, count++, password);
			break;
		case 2:
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			hashobj.signIn(username, password);
			break;
		case 3:
			cout << "Exiting!" << endl;
			break;
		default:
			cout << "Invalid Input!" << endl;

		}

		while (true)
		{
			cout << "1.Socials" << endl;
			cout << "2.Manage Repositories" << endl;
			cout << "3.SignOut" << endl;
			cout << "Enter you choice(1-3): ";
			cin >> choice2;
			if (choice2 == 1)
			{
				while (true)
				{
					cout << "1. Follow another user" << endl;
					cout << "2. Unfollow another user" << endl;
					cout << "3. View social network" << endl;
					cout << "4. Exit the program" << endl;
					cout << "Enter your choice: ";
					cin >> choice3;

					switch (choice3)
					{
					case 1:
						cout << "Enter source username: ";
						cin >> username1;
						source = hashobj.findUser(username1);
						cout << "Enter destination username: ";
						cin >> username2;
						destination = hashobj.findUser(username2);
						network.followUser(source, destination);
						break;
					case 2:
						cout << "Enter source username: ";
						cin >> username1;
						sourceUnfollow = hashobj.findUser(username1);
						cout << "Enter destination username: ";
						cin >> username2;
						destinationUnfollow = hashobj.findUser(username2);
						network.unfollowUser(sourceUnfollow, destinationUnfollow);
						break;
					case 3:
						network.printSocialNetwork();
						break;
					case 4:
						cout << "Exiting!" << endl;
						break;

					default:
						cout << "Invalid Input!" << endl;
					}

					if (choice3 == 4)
					{
						break;
					}
				}
			}
			else if (choice2 == 2)
			{
				while (true)
				{
					cout << "1. Create a new repository" << endl;
					cout << "2. Delete Repository" << endl;
					cout << "3. Create a new commit" << endl;
					cout << "4. Add a file to a repository" << endl;
					cout << "5. Delete a file from a repository" << endl;
					cout << "6. View repository statistics" << endl;
					cout << "7. Exit the program!" << endl;
					cout << "Enter the choice(1-7): ";
					cin >> choice4;

					switch (choice4)
					{
					case 1:
						cout << "Enter repository name: ";
						cin >> repName;
						cout << "Enter its visibility (1.Public, 0.private): ";
						cin >> _visibility;
						rep.repositoryCreate(username, _visibility, repName);
						break;

					case 2:
						cout << "Enter repository name: ";
						cin >> repName;
						rep.repositoryDelete(username, repName);
						break;

					case 3:
						cout << "Enter repository name: ";
						cin >> repName;
						cout << "Enter commit text: ";
						cin >> commitText;
						rep.PerformCommit(username, repName, commitText);
						break;

					case 4:
						cout << "Enter repository name: ";
						cin >> repName;
						cout << "Enter file name: ";
						cin >> fileName;
						rep.fileAdd(username, repName, fileName);
						break;

					case 5:
						cout << "Enter repository name: ";
						cin >> repName;
						cout << "Enter file name: ";
						cin >> fileName;
						rep.fileDelete(username, repName, fileName);
						break;
					case 6:
						cout << "Enter repository name: ";
						cin >> repName;
						rep.viewStats(username, repName);
						break;
					case 7:
						cout << "Exiting!" << endl;
						break;

					default:
						cout << "Invalid Input!" << endl;

						if (choice4 == 7)
						{
							break;
						}
					}

				}

			}
			else if (choice2 == 3)
			{
				hashobj.signOut(username);
				break;
			}

			if (choice2 == 3)
			{
				break;
			}
		}

		if (choice1 == 3)
		{
			break;
		}

	}

	system("pause");
	return 0;
}