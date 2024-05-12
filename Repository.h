
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

	void repDelete(string user, node* repName);

public:
	Repository();
	bool findRepository(string user, string repName, node*& findRep);
	void repositoryCreate(string user, bool _visibility, string repName);
	void repositoryDelete(string user, string repName);
	void repositoryFork(string user1, string user2, string originalRepName, string newRepName);
	void PerformCommit(string user, string repName, string commitText);
	void viewStats(string user, string repName);
	void fileAdd(string user, string repName, string fileName);
	void fileDelete(string user, string repName, string fileName);
	void showAllRepositories(node* root);
	node* getRoot();
	bool getVisibility(node* rep);
	void getFile(string user, node* rep, string fileName);
	bool checkSameFiles(string user, string repName, string fileNAme);
	bool checkSameCommits(string user, string repName, string commitText);
};

#endif
