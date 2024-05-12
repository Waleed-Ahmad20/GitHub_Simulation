#include"User.h"

int UNod::numOfUsers = 0;

UNod::UNod(string uName, int uID, string uPass) {
	username = uName;
	password = uPass;
	userLoginStatus = false;
	userID = uID;
	numOfUsers++;
	next = nullptr;
}

string UNod::getPass() {
	return password;
}

string UNod::getName() {
	return username;
}

int UNod::getUserID() {
	return userID;
}

int UNod::getNumofUsers() {
	return numOfUsers;
}

ChainHash::ChainHash() {
	for (int i = 0; i < size; i++) {
		table[i] = nullptr;
	}
	loadUsers();
}

const int ChainHash::sizeReturn() {
	return size;
}

int ChainHash::hashFunction(string uName) {
	int ASCIIValue = 0;
	for (int i = 0; i < uName.size(); i++) {
		ASCIIValue = ASCIIValue + ((int)uName[i]);
	}
	return ASCIIValue % size;
}

UNod* ChainHash::findUser(string uName) {
	ifstream read("registeredUsers.csv");
	if (read.is_open()) {
		string oneLine;
		while (getline(read, oneLine)) {
			stringstream ss(oneLine);
			string uID, uNameFile, uPass;
			getline(ss, uID, ',');
			getline(ss, uNameFile, ',');
			getline(ss, uPass);
			if (uName == uNameFile) {
				read.close();
				int index = hashFunction(uName);
				UNod* preRegistered = table[index];
				while (preRegistered != nullptr && preRegistered->getName() != uName) {
					preRegistered = preRegistered->next;
				}
				return preRegistered;
			}
		}
		read.close();
	}
	else {
		cout << "Cannot open registeredUsers.csv" << endl;
	}
	return nullptr;
}

bool ChainHash::signUp(string uName, int uID, string uPass) {
	int index = hashFunction(uName);

	UNod* preRegistered = findUser(uName);
	if (preRegistered != nullptr) {
		return false;
	}

	UNod* newNode = new UNod(uName, uID, uPass);
	if (table[index] == nullptr) {
		table[index] = newNode;
	}
	else {
		UNod* current = table[index];
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
	cout << uName << " has been registered!" << endl;
	return true;
}

void ChainHash::signIn(string uName, string uPass) {
	int index = hashFunction(uName);
	UNod* current = table[index];
	while (current != nullptr) {
		if (current->getName() == uName && current->getPass() == uPass) {
			current->userLoginStatus = true;
			cout << current->getName() << " is now signed in!" << endl;
			return;
		}
		current = current->next;
	}
	cout << uName << " is not registered!" << endl;
	return;
}

void ChainHash::signOut(string uName) {
	int index = hashFunction(uName);
	UNod* current = table[index];
	while (current != nullptr) {
		if (current->getName() == uName) {
			if (current->userLoginStatus) {
				current->userLoginStatus = false;
				cout << uName << " has been signed out!" << endl;
				return;
			}
			else {
				cout << uName << " is not signed in!" << endl;
				return;
			}
		}
		current = current->next;
	}
	cout << uName << " is not registered!" << endl;
	return;
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
			int index = hashFunction(uName);
			UNod* newNode = new UNod(uName, stoi(uID), uPass);
			if (table[index] == nullptr) {
				table[index] = newNode;
			}
			else {
				UNod* current = table[index];
				while (current->next != nullptr) {
					current = current->next;
				}
				current->next = newNode;
			}
		}
		read.close();
	}
	else {
		cout << "Cannot open registeredUsers.csv" << endl;
	}
}


