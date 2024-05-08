#include"Repository.h"
#include<iostream>

Repository::Repository() {
	commit = file = nullptr;
	rootRepository = nullptr;
}

node* Repository::findRepository(string repName) {
	node* current = rootRepository;
	while (current) {
		if (repName.compare(current->repositoryName) < 0) {
			current = current->repositoryleftChild;
		}
		else if (repName.compare(current->repositoryName) > 0) {
			current = current->repositoryrightChild;
		}
		else {
			return current;
		}
	}
	return nullptr;
}

void Repository::showAllRepositories(node* root)
{
	if (root == nullptr)
	{
		return;
	}
	showAllRepositories(root->repositoryleftChild);
	cout << root->repositoryName << " ";
	showAllRepositories(root->repositoryrightChild);
}

void Repository::repositoryCreate(string repName)
{
	if (findRepository(repName) == nullptr)
	{
		node* newRepository = new node();
		newRepository->repositoryName = repName;
		newRepository->repositoryParent = nullptr;
		newRepository->repositoryleftChild = nullptr;
		newRepository->repositoryrightChild = nullptr;
		newRepository->repositoryForkCount = 0;

		if (rootRepository == nullptr)
		{
			rootRepository = newRepository;
		}
		else
		{
			node* current = rootRepository;
			node* parent = nullptr;

			while (current != nullptr)
			{
				parent = current;
				if (repName.compare(current->repositoryName) < 0)
				{
					current = current->repositoryleftChild;
				}
				else if (repName.compare(current->repositoryName) > 0)
				{
					current = current->repositoryrightChild;
				}
			}

			if (repName.compare(parent->repositoryName) < 0)
			{
				parent->repositoryleftChild = newRepository;
			}
			else if (repName.compare(parent->repositoryName) > 0)
			{
				parent->repositoryrightChild = newRepository;
			}
			newRepository->repositoryParent = parent;

		}
	}
	else
	{
		cout << "Repository of the same name already exists!" << endl;
	}
}



node* Repository::getRoot()
{
	return rootRepository;
}
