
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include<iostream>
#include<string>
#include"Social.h"
#include"User.h"
using namespace std;

class LinkedlistNode {
public:
	string data;
	LinkedlistNode* next;

	LinkedlistNode(string text);
};

class node {
public:
	string repositoryName;
	node* repositoryParent;
	node* repositoryleftChild;
	node* repositoryrightChild;
	int repositoryForkCount;

public:
	LinkedlistNode* commit;
	LinkedlistNode* file;

	bool visibility;

	node(string name, bool _visibility);
};
class Repository {
private:
	node* rootRepository;

	void repDelete(UNod& user, node* repName);

public:
	Repository();
	bool findRepository(UNod& user, string repName, node*& findRep);
	void repositoryCreate(UNod& user, bool _visibility, string repName);
	void repositoryDelete(UNod& user, string repName);
	void repositoryFork(UNod& user1, UNod& user2, string originalRepName, string newRepName);
	void PerformCommit(UNod& user, string repName, string commitText);
	void viewStats(UNod& user, string repName);
	void fileAdd(UNod& user, string repName, string fileName);
	void fileDelete(UNod& user, string repName, string fileName);
	void showAllRepositories(node* root);
	node* getRoot();
	bool getVisibility(node* rep);
	void getFile(UNod& user, node* rep, string fileName);
	bool checkSameFiles(UNod& user, string repName, string fileNAme);
	bool checkSameCommits(UNod& user, string repName, string commitText);
};

#endif
