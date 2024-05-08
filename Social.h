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
public:
	Social();
	void addEdge(User& source, User& destination);
	void printSocialNetwork();
	void followUser(User& source, User& destination);
	void unfollowUser(User& source, User& destination);
	bool isFollowing(User& source, User& destination);
};

#endif
