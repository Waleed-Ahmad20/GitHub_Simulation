#include <iostream>
#include <string>
#include "Repository.h"
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

	return 0;
}