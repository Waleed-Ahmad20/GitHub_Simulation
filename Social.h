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
	void addEdge(User& source, User& destination);
public:
	Social();
	void printSocialNetwork();
	void followUser(User& source, User& destination);
	void unfollowUser(User& source, User& destination);
	bool isFollowingUser(User& source, User& destination);
};

#endif
