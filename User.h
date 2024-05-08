#ifndef USER_H
#define USER_H

#include<iostream>
#include<string>
using namespace std;

class User {
private: 
	string username;
	int userID;
	static int numOfUsers;
public:
	User(string uName, int uID);
	string getName();
	int getUserID();
	static int getNumofUsers();
};

#endif 
