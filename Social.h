#ifndef SOCIAL_H
#define SOCIAL_H

#include"User.h"

class node {
public:
	string user;
	int uid;
	node* next;
	node(string u, int id);
};

class Social {
private:
	int vertices;
	node** adjacencyLists;
public:
	Social();
	void addEdge(User& source, User& destination);
	void printSocialNetwork();
	void followUser(User& source, User& destination);
	void unfollowUser(User& source, User& destination);
	bool isFollowing(User& source, User& destination);
};

#endif
