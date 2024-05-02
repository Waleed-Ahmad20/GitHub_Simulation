#ifndef REPOSITORY_H
#define REPOSITORY_H

#include<iostream>
#include<string>
using namespace std;

class Repository {
private:
	class node {
		string repositoryName;
		node* repositoryParent;
		node* repositoryleftChild;
		node* repositoryrightChild;
		int repositoryForkCount;
	};
	class LinkedlistNode {
		string data;
		LinkedlistNode* next;
	};
	LinkedlistNode* commit;
	LinkedlistNode* file;

	node* rootRepository;
public:
	Repository();
	void repositoryCreate(string repName);
	void repositoryDelete(string repName);
	void repositoryFork(string originalRepName, string newRepName);
	void commit(string commitName, string commitText);
	void viewStats(string repName);
	void fileAdd(string repName, string fileName);
	void fileDelete(string repName, string fileName);
};

#endif
