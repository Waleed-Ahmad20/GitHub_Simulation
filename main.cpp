#include <iostream>
#include <string>
#include "Repository.h"
#include"Social.h"
using namespace std;

int main()
{
	Repository rep;


	rep.repositoryCreate("rep4");
	rep.repositoryCreate("rep3");
	rep.repositoryCreate("rep5");
	rep.repositoryCreate("rep2");
	rep.repositoryCreate("rep1");
	rep.repositoryCreate("rep6");
	rep.repositoryCreate("rep7");
	rep.repositoryCreate("rep8");

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

	User obj1("Waleed", 0);
	User obj2("Soban", 1);
	User obj3("Mani", 2);
	User obj4("Faran", 3);

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