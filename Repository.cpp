#include"Repository.h"
#include<iostream>
#include<vector>
#include <fstream>
#include <sstream>

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

bool Repository::checkSameFiles(UNod& user, string repName, string fileName)
{
	ifstream read("file.csv");
	if (read.is_open())
	{
		string line;
		while (getline(read, line))
		{
			stringstream ss(line);
			string uName, reposName, fName;
			if (getline(ss, uName, ' ') && getline(ss, reposName, ' ') && getline(ss, fName))
			{
				if (reposName == repName && uName == user.getName() && fileName == fName)
				{
					read.close();
					return true;
				}
			}

		}
		read.close();
		return false;
	}
	else
	{
		cout << "file cant be opened" << endl;
		return false;
	}
}
bool Repository::checkSameCommits(UNod& user, string repName, string commitText)
{
	ifstream read("commits.csv");
	if (read.is_open())
	{
		string line;
		while (getline(read, line))
		{
			stringstream ss(line);
			string uName, reposName, cText;
			if (getline(ss, uName, ' ') && getline(ss, reposName, ' ') && getline(ss, cText))
			{
				if (reposName == repName && uName == user.getName())
				{
					read.close();
					return true;
				}
			}

		}
		read.close();
		return false;
	}
	else
	{
		cout << "file cant be opened" << endl;
	}
}

bool Repository::findRepository(UNod& user, string repName, node*& findRep) {
	node* current = rootRepository;
	while (current) {
		if (repName.compare(current->repositoryName) < 0) {
			current = current->repositoryleftChild;
		}
		else if (repName.compare(current->repositoryName) > 0) {
			current = current->repositoryrightChild;
		}
		else {

			findRep = current;
			break;
		}
	}

	ifstream read("repository.csv");
	if (read.is_open())
	{
		string line;
		while (getline(read, line))
		{
			stringstream ss(line);
			string uName, reposName, _visibility;
			if (getline(ss, uName, ' ') && getline(ss, reposName, ' ') && getline(ss, _visibility))
			{
				if (reposName == repName && uName == user.getName())
				{
					read.close();
					return true;
				}
			}

		}
		read.close();
		return false;
	}
	else
	{
		cout << "file cant be opened" << endl;
	}

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

void Repository::repositoryCreate(UNod& user, bool _visibility, string repName)
{
	node* repNode = nullptr;
	findRepository(user, repName, repNode);

	if (repNode == nullptr)
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

		if (findRepository(user, repName, repNode) == false)
		{
			ofstream write("repository.csv", ios::app);
			if (write.is_open())
			{
				write << user.getName() << " " << repNode->repositoryName << " " << repNode->visibility << endl;
			}
			write.close();
		}

	}
	else
	{
		cout << "Repository of the same name already exists!" << endl;
	}
}

void Repository::repositoryDelete(UNod& user, string repName)
{
	node* deleteNode = nullptr;
	findRepository(user, repName, deleteNode);

	if (deleteNode)
	{
		repDelete(user, deleteNode);
	}
	else
	{
		cout << "No repository with this name exists" << endl;
	}

}

void Repository::repositoryFork(UNod& user1, UNod& user2, string originalRepName, string newRepName)
{
	node* temp1;
	node* temp2;

	if (findRepository(user2, newRepName, temp2) && (findRepository(user1, originalRepName, temp1)))
	{
		if (temp2->visibility == 0)
		{
			cout << "Profile is private! Fork cannot be created " << endl;
			return;
		}
		else
		{
			bool _visibility;
			do {
				cout << "Choose visibility of the fork repository that you are copying(1,0): ";
				cin >> _visibility;

			} while (_visibility != 1 && _visibility != 0);

			bool Write = true;
			ifstream read1("repository.csv");
			if (read1.is_open())
			{
				string line;
				while (getline(read1, line))
				{
					stringstream ss(line);
					string u, rep, vis;
					if (getline(ss, u, ' ') && getline(ss, rep, ' ') && getline(ss, vis))
					{
						if (user1.getName() == u && rep == originalRepName)
						{
							Write = false;
						}
					}

				}
			}
			if (Write == false)
			{
				ofstream write1("repository.csv", ios::app);
				if (write1.is_open())
				{
					write1 << user1.getName() << " " << newRepName << " " << to_string(_visibility) << endl;
				}
				write1.close();
			}

			ifstream read("file.csv");
			ofstream write("newFile.csv", ios::app);

			if (read.is_open() && write.is_open())
			{
				string line;
				vector<string> forkFiles;
				while (getline(read, line))
				{
					stringstream ss(line);
					string uname, repName, file;

					if (getline(ss, uname, ' ') && getline(ss, repName, ' ') && getline(ss, file))
					{
						if (uname == user2.getName() && repName == newRepName)
						{
							forkFiles.push_back(file);
							write << line << endl;
						}
					}
				}
				for (int i = 0; i < forkFiles.size(); i++)
				{
					cout << forkFiles[i] << endl;
					write << user1.getName() << " " << originalRepName << " " << forkFiles[i] << endl;
				}
			}
			read.close();
			write.close();
			remove("file.csv");
			rename("newFile.csv", "file.csv");
		}
	}
	else
	{
		cout << "Either one or both repositories do not exist!" << endl;
	}



}

void Repository::repDelete(UNod& user, node* deleteNode)
{
	ifstream read("repository.csv");
	ofstream write("newRepository.csv");

	if (read.is_open())
	{
		if (write.is_open())
		{
			string line;
			while (getline(read, line))
			{
				stringstream ss(line);
				string uName, repName, _visibility;

				if (getline(ss, uName, ' ') && getline(ss, repName, ' ') && getline(ss, _visibility))
				{
					if (uName != user.getName() || repName != deleteNode->repositoryName || _visibility != to_string(deleteNode->visibility))
					{
						write << line << endl;
					}
				}
			}
			read.close();
			write.close();
			remove("repository.csv");
			rename("newRepository.csv", "repository.csv");
		}
		else
		{
			cout << "Write file not opened!" << endl;
		}

	}
	else
	{
		cout << "Read file cannot be opened!" << endl;
	}

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
		repDelete(user, temp);

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
		delete temp;;
		temp = nullptr;
	}



}

void Repository::PerformCommit(UNod& user, string repName, string commitText)
{
	node* current = nullptr;
	findRepository(user, repName, current);
	LinkedlistNode* newCommit = new LinkedlistNode(commitText);

	if (current)
	{
		LinkedlistNode* tempCommit = current->commit;
		if (current->commit != nullptr)
		{
			while (tempCommit->next != nullptr)
			{
				if (tempCommit->data == commitText)
				{
					cout << "Same commit cannot be made more than once!" << endl;
					return;
				}
				tempCommit = tempCommit->next;
			}
		}

		if (checkSameCommits(user, repName, commitText))
		{
			cout << "Same commit cannot be made more than once!" << endl;
			return;
		}


		newCommit->next = current->commit;
		current->commit = newCommit;

		ifstream read("commits.csv");
		ofstream write("newCommits.csv");

		if (read.is_open() && write.is_open())
		{
			write << user.getName() << " " << current->repositoryName << " " << current->commit->data << endl;
			string line;
			while (getline(read, line))
			{
				stringstream ss(line);
				string uName, repName, commitName;
				if (getline(ss, uName, ' ') && getline(ss, repName, ' ') && getline(ss, commitName, ' '))
				{
					write << uName << " " << repName << " " << commitName << endl;
				}
			}

			read.close();
			write.close();
			remove("commits.csv");
			rename("newCommits.csv", "commits.csv");
		}
		else
		{
			cout << "read file not opened!" << endl;
		}
	}
	else
	{
		cout << "Repository for the said user not found!";
	}
}


void Repository::viewStats(UNod& user, string repName)
{
	node* tempRep = nullptr;
	findRepository(user, repName, tempRep);

	ifstream read1("file.csv");
	if (read1.is_open())
	{
		cout << "User: " << user.getName() << ", Repository: " << tempRep->repositoryName << ", Files: ";
		string line;
		while (getline(read1, line))
		{
			stringstream ss(line);
			string username, reposname, filename;
			if (getline(ss, username, ' ') && getline(ss, reposname, ' ') && getline(ss, filename, ' '))
			{
				if (username == user.getName() && reposname == tempRep->repositoryName)
				{
					cout << filename << " ";
				}
			}
		}
		cout << endl;
	}
	read1.close();

	ifstream read2("commits.csv");
	if (read2.is_open())
	{
		cout << "User: " << user.getName() << ", Repository: " << tempRep->repositoryName << ", Commits: ";
		string line;
		while (getline(read2, line))
		{
			stringstream ss(line);
			string username, reposname, commit;
			if (getline(ss, username, ' ') && getline(ss, reposname, ' ') && getline(ss, commit, ' '))
			{
				if (username == user.getName() && reposname == tempRep->repositoryName)
				{
					cout << commit << " ";
				}
			}
		}
		cout << endl;
	}
	read2.close();

}

void Repository::fileAdd(UNod& user, string repName, string fileName)
{
	node* current = nullptr;
	findRepository(user, repName, current);
	LinkedlistNode* newFile = new LinkedlistNode(fileName);
	if (current)
	{


		if (current->file == nullptr)
		{
			current->file = newFile;
		}
		else
		{
			LinkedlistNode* tempFile = current->file;
			while (tempFile->next != nullptr || tempFile->data != newFile->data)
			{
				tempFile = tempFile->next;
			}
			if (tempFile->data != newFile->data)
			{
				tempFile->next = newFile;
			}
		}

		if (checkSameFiles(user, repName, fileName))
		{
			cout << "Same file cannot be saved more than once!" << endl;
			return;
		}

		//file handling
		if (findRepository(user, repName, current))
		{
			ofstream write("file.csv", ios::app);
			if (write.is_open())
			{
				write << user.getName() << " " << current->repositoryName << " " << newFile->data << endl;
			}
			write.close();
		}
		else
		{
			cout << "Repository for adding the file not found!" << endl;
		}
	}

}

void Repository::fileDelete(UNod& user, string repName, string fileName)
{
	node* current = nullptr;
	findRepository(user, repName, current);
	if (current)
	{
		if (current->file != nullptr)
		{
			LinkedlistNode* tempFile = current->file;

			if (tempFile->data == fileName)
			{
				current->file = current->file->next;
				delete tempFile;
				tempFile = nullptr;
			}
			else
			{
				while (tempFile->next != nullptr && tempFile->next->data != fileName)
				{
					tempFile = tempFile->next;
				}
				if (tempFile->next != nullptr)
				{
					LinkedlistNode* temp = tempFile->next;
					tempFile->next = temp->next;
					delete temp;
					temp = nullptr;
				}
			}

		}
		if (checkSameFiles(user, repName, fileName))
		{
			ifstream read("file.csv");
			ofstream write("newFile.csv");

			if (read.is_open() && write.is_open())
			{
				string line;
				while (getline(read, line))
				{
					stringstream ss(line);
					string uName, reposName, fName;
					if (getline(ss, uName, ' ') && getline(ss, reposName, ' ') && getline(ss, fName, ' '))
					{
						if (uName != user.getName() || reposName != current->repositoryName || fName != fileName)
						{
							write << line << endl;
						}
					}

				}
			}

			read.close();
			write.close();
			remove("file.csv");
			rename("newFile.csv", "file.csv");
		}
		else
		{
			cout << "File does not exist!" << endl;
		}

	}
	else
	{
		cout << "Repository does not exist!" << endl;
	}

}


node* Repository::getRoot()
{
	return rootRepository;
}

bool Repository::getVisibility(node* rep)
{
	return rep->visibility;
}

void Repository::getFile(UNod& user, node* rep, string fileName)
{
	LinkedlistNode* temp = rep->file;
	while (temp != nullptr && temp->data != fileName)
	{
		temp = temp->next;
	}
	if (temp)
	{
		cout << "File: " << temp->data << endl;
	}
	else
	{
		cout << "file doesn't exist!" << endl;
	}
}