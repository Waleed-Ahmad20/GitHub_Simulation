#ifndef USER_H
#define USER_H

#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

class UNod {
private:
	string username;
	string password;
	bool userLoginStatus;
	int userID;
	static int numOfUsers;
	UNod* next;
	string getPass();
public:
	friend class ChainHash;
	UNod(string uName, int uID, string uPass);
	string getName();
	int getUserID();
	static int getNumofUsers();
};

class ChainHash {
private:
	static const int size = 25;
	UNod* table[size];
public:
	ChainHash();
	static const int sizeReturn();
	int hashFunction(string uName);
	UNod* findUser(string uName);
	bool signUp(string uName, int uID, string uPass);
	void signIn(string uName, string uPass);
	void signOut(string uName);
	void loadUsers();
};

#endif 