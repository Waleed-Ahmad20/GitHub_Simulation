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

	Social network;
	if (hashobj.signUp("Waleed", 0, "Pass") && hashobj.signUp("Soban", 1, "Pass") && hashobj.signUp("Mani", 2, "Pass") && hashobj.signUp("Faran", 3, "Pass")) {
	UNod* obj1 = hashobj.findUser("Waleed");
	UNod* obj2 = hashobj.findUser("Soban");
	UNod* obj3 = hashobj.findUser("Mani");
	UNod* obj4 = hashobj.findUser("Faran");

	hashobj.signIn("Waleed", "Pass");
	hashobj.signIn("Faran", "Pass");
	hashobj.signOut("Waleed");
	hashobj.signOut("Mani");
	hashobj.signIn("Banana", "Pass");
	hashobj.signOut("Banana");
	network.followUser(obj1, obj2);
	network.followUser(obj1, obj4);
	network.followUser(obj2, obj1);
	network.followUser(obj2, obj3);
	network.followUser(obj2, obj4);
	network.followUser(obj4, obj2);

	cout << network.isFollowingUser(obj1, obj2);
	cout << network.isFollowingUser(obj1, obj3);
	cout << network.isFollowingUser(obj2, obj1);


	cout << endl;

	cout << "After unfollowing: " << endl;
	network.unfollowUser(obj1, obj2);
	cout << network.isFollowingUser(obj1, obj2);
}

	cout << endl;

	network.printSocialNetwork();

	cout << endl;

	return 0;
}