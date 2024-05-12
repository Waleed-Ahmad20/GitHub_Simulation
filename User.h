#ifndef USER_H
#define USER_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class UNode {
private:
	string username;
	string password;
	bool userLoginStatus;
	int userID;
	static int numOfUsers;
	UNode* next;
public:
	friend class ChainHash;
	UNode(string uName, int uID, string uPass);
	string getName();
	int getUserID();
	static int getNumofUsers();
};

class ChainHash {
private:
	static const int size = 25;
	UNode* table[size];
public:
	ChainHash();
	int hashFunction(string uName);
	UNode* signUp(string uName, int uID, string uPass);
	void signIn(string uName, string uPass);
	void signOut(string uName);
	void loadUsers();
};

#endif 
