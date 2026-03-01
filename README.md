# GitHub Simulation

A console-based C++ application that simulates core GitHub features, including user account management, repository operations, commit history, file tracking, and a social follow/unfollow network.

---

## Features

### User Management
- **Sign Up** – Register a new account with a unique username and password. Accounts are persisted across sessions via CSV storage.
- **Sign In / Sign Out** – Authenticate using stored credentials and maintain a login session.

### Repository Management
- **Create Repository** – Create a new public or private repository under the logged-in user.
- **Delete Repository** – Remove an existing repository and all associated data.
- **Commit** – Record a commit message to a repository's commit history.
- **Add File** – Attach a file to a repository.
- **Delete File** – Remove a file from a repository.
- **View Statistics** – Display repository details including commit log and file list.
- **Fork** – Fork another user's public repository.

### Social Network
- **Follow User** – Follow another registered user.
- **Unfollow User** – Remove a follow relationship.
- **View Social Network** – Display the full follow graph showing who follows whom.

---

## Data Structures Used

| Component | Data Structure |
|-----------|---------------|
| User store | Hash table with chaining (`ChainHash`) |
| Repository tree | Binary tree (`node`) |
| Commit history | Singly linked list (`LinkedlistNode`) |
| File list | Singly linked list (`LinkedlistNode`) |
| Social network | Adjacency list graph (`Social`) |

---

## Project Structure

```
GitHub_Simulation/
├── main.cpp                  # Entry point and main menu loop
├── User.h / User.cpp         # User accounts and hash table
├── Repository.h / Repository.cpp  # Repository and commit management
├── Social.h / Social.cpp     # Social follow/unfollow graph
├── registeredUsers.csv       # Persisted user records
├── repository.csv            # Persisted repository records
├── commits.csv               # Persisted commit records
├── file.csv                  # Persisted file records
├── followingID.csv           # Persisted follow relationships (by ID)
├── followingName.csv         # Persisted follow relationships (by name)
└── GitHub_Simulation.vcxproj # Visual Studio project file
```

---

## Getting Started

### Prerequisites
- Windows with [Visual Studio](https://visualstudio.microsoft.com/) (2019 or later recommended), or any C++17-compatible compiler.

### Build & Run

**Using Visual Studio:**
1. Open `GitHub_Simulation.vcxproj` in Visual Studio.
2. Select **Build → Build Solution** (or press `Ctrl+Shift+B`).
3. Run the application with **Debug → Start Without Debugging** (`Ctrl+F5`).

**Using g++ (command line):**
```bash
g++ -std=c++17 main.cpp User.cpp Repository.cpp Social.cpp -o GitHub_Simulation
./GitHub_Simulation
```

---

## Usage

On launch, the main menu offers three options:

```
Welcome to the GitHub Simulation!
---------------------------
1. Sign up for a new user account
2. Sign in to an existing user account
3. Exit the program!
```

After signing in, you can navigate to the **Socials** or **Manage Repositories** sub-menus to use the features described above.

---

## Screenshots

<img width="353" alt="Main menu" src="https://github.com/Waleed-Ahmad20/GitHub_Simulation/assets/154059636/a6f5a354-a37e-49d5-81b9-3f67f8067d5b">
<img width="271" alt="Sign up" src="https://github.com/Waleed-Ahmad20/GitHub_Simulation/assets/154059636/543b1fc8-16bf-4bf3-9af9-f864ea69c7de">
<img width="325" alt="Repository menu" src="https://github.com/Waleed-Ahmad20/GitHub_Simulation/assets/154059636/0dde9228-a6de-4a2a-94ca-385fa0c47f12">
<img width="341" alt="Commit" src="https://github.com/Waleed-Ahmad20/GitHub_Simulation/assets/154059636/9dac6ff4-faa9-4af6-a3be-ccd95de152e0">
<img width="289" alt="Social network" src="https://github.com/Waleed-Ahmad20/GitHub_Simulation/assets/154059636/29ec7e60-f270-4cc5-9375-3d0db40d27c2">
