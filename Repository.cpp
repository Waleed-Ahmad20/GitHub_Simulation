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

node::node(string name, bool _visibility)
{
	repositoryName = name;
	visibility = _visibility;
	repositoryParent = nullptr;
	repositoryleftChild = nullptr;
	repositoryrightChild = nullptr;
	repositoryForkCount = 0;
	commit = nullptr;
	file = nullptr;

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
		node* newRepository = new node(repName, _visibility);

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

void Repository::PerformCommit(string repName, string commitText)
{
	node* current = findRepository(repName);
	LinkedlistNode* newCommit = new LinkedlistNode(commitText);
	if (current->commit == nullptr)
	{
		current->commit = newCommit;
	}
	else
	{
		LinkedlistNode* tempCommit = current->commit;
		while (tempCommit->next != nullptr)
		{
			tempCommit = tempCommit->next;
		}
		tempCommit->next = newCommit;
	}
}

void Repository::viewStats(string repName)
{
	node* tempRep = findRepository(repName);
	cout << "Repository Name: " << tempRep->repositoryName << ", " << "Repository Visibility: ";
	if (tempRep->visibility == 0)
	{
		cout << "Private!" << endl;
	}
	else
	{
		cout << "Public!" << endl;
	}
	LinkedlistNode* tempList = tempRep->file;

	cout << "Files in repository: ";
	if (tempList != nullptr)
	{
		while (tempList != nullptr)
		{
			cout << tempList->data << " ";
			tempList = tempList->next;
		}
		cout << endl;
	}
	else cout << "No Files!" << endl;


	tempList = tempRep->commit;
	if (tempList != nullptr)
	{
		cout << "Commits in Repository: ";
		while (tempList != nullptr)
		{
			cout << tempList->data << " ";
			tempList = tempList->next;
		}
		cout << endl;
	}
	else
	{
		cout << "No Commits!" << endl;
	}

	cout << "Fork Count: " << tempRep->repositoryForkCount << endl << endl;
}

void Repository::fileAdd(string repName, string fileName)
{
	node* current = findRepository(repName);
	LinkedlistNode* newFile = new LinkedlistNode(fileName);
	if (current->file == nullptr)
	{
		current->file = newFile;
	}
	else
	{
		LinkedlistNode* tempFile = current->file;
		while (tempFile->next != nullptr)
		{
			tempFile = tempFile->next;
		}
		tempFile->next = newFile;
	}
}

void Repository::fileDelete(string repName, string fileName)
{
	node* current = findRepository(repName);
	LinkedlistNode* tempFile = current->file;
	while (tempFile->next->data != fileName)
	{
		tempFile = tempFile->next;
	}
	LinkedlistNode* temp = tempFile->next;
	tempFile->next = temp->next;
	delete temp;
	temp = nullptr;
}


node* Repository::getRoot()
{
	return rootRepository;
}
