#include"User.h"

int UNode::numOfUsers = 0;

UNode::UNode(string uName, int uID, string uPass) {
	username = uName;
	password = uPass;
	userLoginStatus = false;
	userID = uID;
	numOfUsers++;
	next = nullptr;
}

string UNode::getName() {
	return username;
}

int UNode::getUserID() {
	return userID;
}

int UNode::getNumofUsers() {
	return numOfUsers;
}

ChainHash::ChainHash() {
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
}
int ChainHash::hashFunction(string uName) {
	int ASCIIValue = 0;
	for (int i = 0; i < uName.size(); i++) {
		ASCIIValue = ASCIIValue + ((int) uName[i]);
	}	
	return ASCIIValue % size;
}
UNode* ChainHash::signUp(string uName, int uID, string uPass) {
	int index = hashFunction(uName);
	UNode* newNode = new UNode(uName, uID, uPass);
	if (table[index] == nullptr) {
		table[index] = newNode;
	}
	else {
		UNode* current = table[index];
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}

	ofstream write("registeredUsers.csv", ios::app);
	if (write.is_open()) {
		write << uID << "," << uName << "," << uPass << endl;
		write.close();
	}
	else {
		cout << "Cannot open registeredUsers.csv" << endl;
	}
	return newNode;
}
void ChainHash::signIn(string uName, string uPass) {

}
void ChainHash::signOut(string uName) {

}
void ChainHash::loadUsers() {
	ifstream read("registeredUsers.csv");
	if (read.is_open()) {
		string oneLine;
		while (getline(read, oneLine)) {
			stringstream ss(oneLine);
			string uID, uName, uPass;
			getline(ss, uID, ',');
			getline(ss, uName, ',');
			getline(ss, uPass);
			signUp(uName, stoi(uID), uPass);
		}
		read.close();
	}
	else {
		cout << "Cannot open registeredUsers.csv" << endl;
	}
}