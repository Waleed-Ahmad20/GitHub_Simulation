#include"Repository.h"
#include<iostream>

Repository::Repository() {
	rootRepository = nullptr;
}

LinkedlistNode::LinkedlistNode(string text)
{
	data = text;
	next = nullptr;
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

void Repository::repositoryCreate(bool _visibility, string repName)
{
	if (findRepository(repName) == nullptr)
	{
		node* newRepository = new node();
		newRepository->repositoryName = repName;
		newRepository->repositoryParent = nullptr;
		newRepository->repositoryleftChild = nullptr;
		newRepository->repositoryrightChild = nullptr;
		newRepository->repositoryForkCount = 0;
		newRepository->visibility = _visibility;

		/*newRepository->commit = nullptr;
		newRepository->file = nullptr;*/

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

void Repository::repositoryDelete(string repName)
{
	node* deleteNode = findRepository(repName);

	if (deleteNode)
	{
		repDelete(deleteNode);
	}
	else
	{
		cout << "No repository with this name exists" << endl;
	}

}

void Repository::repDelete(node* deleteNode)
{
	node* temp = deleteNode;
	node* parent = temp->repositoryParent;
	if (deleteNode->repositoryleftChild != nullptr && deleteNode->repositoryrightChild != nullptr)
	{
		parent = temp;
		temp = temp->repositoryrightChild;
		while (temp->repositoryleftChild != nullptr)
		{
			parent = temp;
			temp = temp->repositoryleftChild;
		}
		deleteNode->repositoryName = temp->repositoryName;
		deleteNode->repositoryForkCount = temp->repositoryForkCount;
		deleteNode->commit = temp->commit;
		deleteNode->file = temp->file;
		deleteNode->visibility = temp->visibility;
		repDelete(temp);

		return;
	}
	else if (deleteNode->repositoryleftChild != nullptr)
	{
		temp = deleteNode;
		parent = temp->repositoryParent;
		deleteNode = deleteNode->repositoryleftChild;
		if (parent->repositoryleftChild == temp)
		{
			parent->repositoryleftChild = deleteNode;
		}
		else if (parent->repositoryrightChild == temp)
		{
			parent->repositoryrightChild = deleteNode;
		}
		delete temp;
		temp = nullptr;
		return;
	}
	else if (deleteNode->repositoryrightChild != nullptr)
	{
		temp = deleteNode;
		parent = temp->repositoryParent;
		deleteNode = deleteNode->repositoryrightChild;
		if (parent->repositoryleftChild == temp)
		{
			parent->repositoryleftChild = deleteNode;
		}
		else if (parent->repositoryrightChild == temp)
		{
			parent->repositoryrightChild = deleteNode;
		}
		delete temp;
		temp = nullptr;
		return;
	}
	else
	{
		temp = deleteNode;
		parent = temp->repositoryParent;
		if (parent->repositoryleftChild == temp)
		{
			parent->repositoryleftChild = nullptr;
		}
		else if (parent->repositoryrightChild == temp)
		{
			parent->repositoryrightChild = nullptr;
		}
		delete deleteNode;
		deleteNode = nullptr;
		return;
	}
}



node* Repository::getRoot()
{
	return rootRepository;
}
