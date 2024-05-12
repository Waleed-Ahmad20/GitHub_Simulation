#ifndef SOCIAL_H
#define SOCIAL_H

#include"User.h"

class unode {
public:
	string user;
	int uid;
	unode* next;
	unode(string u, int id);
};

class Social {
private:
	int vertices;
	unode** adjacencyLists;
	void addEdge(UNod*& source, UNod*& destination);
public:
	Social();
	void printSocialNetwork();
	void followUser(UNod*& source, UNod*& destination);
	void unfollowUser(UNod*& source, UNod*& destination);
	bool isFollowingUser(UNod*& source, UNod*& destination);
};

#endif