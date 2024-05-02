#include"Repository.h"
#include<iostream>

Repository::Repository() {
	commit = file = nullptr;
	rootRepository = nullptr;
}

Repository::node* Repository::findRepository(string repName) {
	node* current = rootRepository;
	while (current) {
		if (current->repositoryleftChild && repName.compare(current->repositoryName) < 0) {
			current = current->repositoryleftChild;
		}
		else if (current->repositoryrightChild && repName.compare(current->repositoryName) > 0) {
			current = current->repositoryrightChild;
		}
		else {
			return current;
		}
	}
	return nullptr;
}
