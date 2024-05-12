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
	void addEdge(UNode*& source, UNode*& destination);
public:
	Social();
	void printSocialNetwork();
	void followUser(UNode*& source, UNode*& destination);
	void unfollowUser(UNode*& source, UNode*& destination);
	bool isFollowingUser(UNode*& source, UNode*& destination);
};

#endif
