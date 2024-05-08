
#ifndef REPOSITORY_H
#define REPOSITORY_H

#include<iostream>
#include<string>
using namespace std;

class node {
public:
	string repositoryName;
	node* repositoryParent;
	node* repositoryleftChild;
	node* repositoryrightChild;
	int repositoryForkCount;
};
class Repository {
private:
	
	class LinkedlistNode {
	public:
		string data;
		LinkedlistNode* next;
	};
	LinkedlistNode* commit;
	LinkedlistNode* file;

	node* rootRepository;

public:
	Repository();
	node* findRepository(string repName);
	void repositoryCreate(string repName);
	void repositoryDelete(node* root, string repName);
	void repositoryFork(string originalRepName, string newRepName);
	void PerformCommit(string commitName, string commitText);
	void viewStats(string repName);
	void fileAdd(string repName, string fileName);
	void fileDelete(string repName, string fileName);
	void showAllRepositories(node* root);
	node* getRoot();
};

#endif
