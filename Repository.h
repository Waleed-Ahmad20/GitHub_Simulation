
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include<iostream>
#include<string>
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

	LinkedlistNode* commit;
	LinkedlistNode* file;

	bool visibility;
};
class Repository {
private:
	node* rootRepository;

	void repDelete(node* repName);

public:
	Repository();
	node* findRepository(string repName);
	void repositoryCreate(bool _visibility, string repName);
	void repositoryDelete(string repName);
	void repositoryFork(string originalRepName, string newRepName);
	void PerformCommit(string repName, string commitText);
	void viewStats(string repName);
	void fileAdd(string repName, string fileName);
	void fileDelete(string repName, string fileName);
	void showAllRepositories(node* root);
	node* getRoot();
};

#endif
