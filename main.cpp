#include <iostream>
#include <string>
#include "Repository.h"
#include"Social.h"
using namespace std;

int main()
{
	Repository rep;
	bool flag = 0;

	rep.repositoryCreate(flag, "rep4");
	rep.repositoryCreate(flag, "rep3");
	rep.repositoryCreate(flag, "rep5");
	rep.repositoryCreate(flag, "rep2");
	rep.repositoryCreate(flag, "rep1");
	rep.repositoryCreate(flag, "rep6");
	rep.repositoryCreate(flag, "rep7");
	rep.repositoryCreate(flag, "rep8");

	node* n = rep.findRepository("rep8");

	if (n)
	{
		cout << "Repository found!" << endl;
	}
	else
	{
		cout << "Repository not found!" << endl;
	}

	rep.showAllRepositories(rep.getRoot());
	rep.showAllRepositories(rep.getRoot());

	cout << endl;

	ChainHash hashobj;
	hashobj.loadUsers();

	UNode* obj1 = hashobj.signUp("Waleed", 0, "Pass");
	UNode* obj2 = hashobj.signUp("Soban", 1, "Pass");
	UNode* obj3 = hashobj.signUp("Mani", 2, "Pass");
	UNode* obj4 = hashobj.signUp("Faran", 3, "Pass");

	Social network;
	network.followUser(obj1, obj2);
	network.followUser(obj1, obj4);
	network.followUser(obj2, obj1);
	network.followUser(obj2, obj3);
	network.followUser(obj2, obj4);
	network.followUser(obj4, obj2);

	cout << endl;

	network.printSocialNetwork();

	cout << endl;

	cout << network.isFollowingUser(obj1, obj2);
	cout << network.isFollowingUser(obj1, obj3);
	cout << network.isFollowingUser(obj2, obj1);


	cout << endl;

	cout << "After unfollowing: " << endl;
	network.unfollowUser(obj1, obj2);
	cout << network.isFollowingUser(obj1, obj2);

	return 0;
}