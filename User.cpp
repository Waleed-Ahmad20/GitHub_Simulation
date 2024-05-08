#include"User.h"

int User::numOfUsers = 0; 

User::User(string uName, int uID) {
	username = uName;
	userID = uID;
	numOfUsers++;
}

string User::getName() {
	return username;
}

int User::getID() {
	return userID;
}

int User::getNumofUsers() {
	return numOfUsers;
}