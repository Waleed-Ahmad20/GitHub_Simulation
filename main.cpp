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
	network.addEdge(obj1, obj2);
	network.addEdge(obj1, obj4);
	network.addEdge(obj2, obj1);
	network.addEdge(obj2, obj3);
	network.addEdge(obj2, obj4);
	network.addEdge(obj4, obj2);

	cout << endl;

	network.printSocialNetwork();

	cout << endl;

	cout << network.isFollowing(obj1, obj2);
	cout << network.isFollowing(obj1, obj3);
	cout << network.isFollowing(obj2, obj1);





	return 0;
}