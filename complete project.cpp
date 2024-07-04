#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

#ifndef SOCIAL_NETWORK_H
#define SOCIAL_NETWORK_H

class SocialEntity {
public:
	SocialEntity(int id, const string& name) : id(id), name(name) {}

	virtual ~SocialEntity() {}

	virtual void display() const = 0;

	int getID() const { return id; }

	const string& getName() const { return name; }

protected:
	int id;
	string name;
};

class Post {
public:
	Post(int postId, int ownerId, const string& content)
		: postId(postId), ownerId(ownerId), content(content), timestamp(time(nullptr)), likes(0) {}

	void display() const {
		cout << "Post ID: " << postId << "\nOwner ID: " << ownerId
			<< "\nContent: " << content << "\nTimestamp: " << timestamp << "\nLikes: " << likes << "\n";
	}

	int getID() const { return postId; }

	int getOwnerID() const { return ownerId; }

	time_t getTimestamp() const { return timestamp; }

	int getLikes() const { return likes; }

	void like() {
		likes++;
		cout << "Post liked!\n";
	}

	const vector<int>& getLikedUserIDs() const {
		return likedUserIDs;
	}

	void addLike(int userID) {
		likedUserIDs.push_back(userID);
	}

	const vector<string>& getComments() const {
		return comments;
	}

	void addComment(const string& comment) {
		comments.push_back(comment);
		cout << "Comment added!\n";
	}

	void setTimestamp(time_t time) {
		timestamp = time;
	}

	void setLikes(int likeCount) {
		likes = likeCount;
	}

	void setLikedUserIDs(const vector<int>& likedUsers) {
		likedUserIDs = likedUsers;
	}

	void setComments(const vector<string>& postComments) {
		comments = postComments;
	}

	void displayLikedUsers() const {
		cout << "People who liked this post:\n";
		for (int likedUserID : likedUserIDs) {
			cout << likedUserID << "\n";
		}
	}

	void displayComments() const {
		cout << "Comments on this post:\n";
		for (const string& comment : comments) {
			cout << comment << "\n";
		}
	}

	void viewPost() const {
		display();
		displayLikedUsers();
		displayComments();
	}

private:
	int postId;
	int ownerId;
	string content;
	time_t timestamp;
	int likes;
	vector<int> likedUserIDs;
	vector<string> comments;
};

class User;

class Page : public SocialEntity {
public:
	Page(int id, const string& name) : SocialEntity(id, name) {}

	void display() const override {
		cout << "Page ID: " << id << "\nName: " << name << "\n";
	}

	void addPost(const Post& post) {
		posts.push_back(post);
		cout << "Post added to the page!\n";
	}

	const vector<Post>& getPosts() const {
		return posts;
	}

private:
	vector<Post> posts;
};

class User : public SocialEntity {
public:
	User(int id, const string& name, const string& username, const string& password)
		: SocialEntity(id, name), username(username), password(password) {}

	void display() const override {
		cout << "User ID: " << id << "\nName: " << name << "\n";
	}

	void addFriend(int friendID) {
		if (find(friendList.begin(), friendList.end(), friendID) == friendList.end()) {
			friendList.push_back(friendID);
			cout << "Friend added successfully!\n";
		}
		else {
			cout << "This user is already your friend.\n";
		}
	}

	void addPost(const Post& post) {
		posts.push_back(post);
		cout << "Post added successfully!\n";
	}

	void likePost(int postID, vector<Post>& allPosts) {
		auto postIterator = find_if(allPosts.begin(), allPosts.end(), [postID](const Post& post) {
			return post.getID() == postID;
			});

		if (postIterator != allPosts.end()) {
			Post& post = *postIterator;
			post.like();
			post.addLike(getID());
		}
		else {
			cout << "Post with ID " << postID << " not found.\n";
		}
	}

	void commentOnPost(int postID, const string& comment) {
		auto postIterator = find_if(posts.begin(), posts.end(), [postID](const Post& post) {
			return post.getID() == postID;
			});

		if (postIterator != posts.end()) {
			Post& post = *postIterator;
			post.addComment(comment);
		}
		else {
			cout << "Post with ID " << postID << " not found.\n";
		}
	}

	void viewPost(int postID) const {
		auto postIterator = find_if(posts.begin(), posts.end(), [postID](const Post& post) {
			return post.getID() == postID;
			});

		if (postIterator != posts.end()) {
			const Post& post = *postIterator;
			post.viewPost();
		}
		else {
			cout << "Post with ID " << postID << " not found.\n";
		}
	}

	const vector<int>& getFriendList() const {
		return friendList;
	}

	const vector<Post>& getPosts() const {
		return posts;
	}

	const string& getUsername() const {
		return username;
	}

	const string& getPassword() const {
		return password;
	}

private:
	vector<int> friendList;
	vector<Post> posts;
	string username;
	string password;
};

class SocialNetwork {
public:
	void setCurrentUser(int userID) {
		auto userIterator = find_if(users.begin(), users.end(), [userID](const User& user) {
			return user.getID() == userID;
			});

		if (userIterator != users.end()) {
			currentUserID = userID;
			cout << "Current user set to User ID: " << userID << "\n";
		}
		else {
			cout << "User with ID " << userID << " not found in the network.\n";
		}
	}

	bool authenticateUser(const string& username, const string& password) {
		auto userIterator = find_if(users.begin(), users.end(), [username, password](const User& user) {
			return user.getUsername() == username && user.getPassword() == password;
			});

		if (userIterator != users.end()) {
			currentUserID = userIterator->getID();
			cout << "User '" << username << "' authenticated. Current user set to User ID: " << currentUserID << "\n";
			return true;
		}
		else {
			cout << "Authentication failed. User not found or incorrect password.\n";
			return false;
		}
	}

	bool signUpUser(const string& name, const string& username, const string& password) {
		auto userIterator = find_if(users.begin(), users.end(), [username](const User& user) {
			return user.getUsername() == username;
			});

		if (userIterator == users.end()) {
			int newUserID = generateUniqueUserID();
			users.emplace_back(newUserID, name, username, password);
			cout << "User '" << username << "' signed up successfully. User ID: " << newUserID << "\n";
			currentUserID = newUserID;
			saveDataToFile();
			return true;
		}
		else {
			cout << "Username '" << username << "' is already taken. Please choose a different username.\n";
			return false;
		}
	}

	void viewHomeOfCurrentUser() {
		auto currentUserIterator = find_if(users.begin(), users.end(), [this](const User& user) {
			return user.getID() == currentUserID;
			});

		if (currentUserIterator != users.end()) {
			const User& currentUser = *currentUserIterator;
			vector<Post> friendPosts;

			for (int friendID : currentUser.getFriendList()) {
				auto friendIterator = find_if(users.begin(), users.end(), [friendID](const User& user) {
					return user.getID() == friendID;
					});

				if (friendIterator != users.end()) {
					const User& friendUser = *friendIterator;
					friendPosts.insert(friendPosts.end(), friendUser.getPosts().begin(), friendUser.getPosts().end());
				}
			}

			auto currentTime = time(nullptr);
			auto isWithinLast24Hours = [currentTime](const Post& post) {
				return (currentTime - post.getTimestamp()) <= 24 * 60 * 60;
			};

			vector<Post> recentPosts;
			recentPosts.insert(recentPosts.end(), friendPosts.begin(), friendPosts.end());

			cout << "Recent posts from friends:\n";
			for (const Post& post : recentPosts) {
				if (isWithinLast24Hours(post)) {
					post.display();
					cout << "------------------------\n";
				}
			}
		}
		else {
			cout << "Current user not found in the network.\n";
		}
	}

	void likePost(int postID) {
		auto currentUserIterator = find_if(users.begin(), users.end(), [this](const User& user) {
			return user.getID() == currentUserID;
			});

		if (currentUserIterator != users.end()) {
			User& currentUser = *currentUserIterator;
			currentUser.likePost(postID, posts);
		}
		else {
			cout << "Current user not found in the network.\n";
		}
	}

	void addPost(const Post& post) {
		posts.push_back(post);
		cout << "Post added to the network!\n";
	}

	void viewLikedUsers(int postID) const {
		auto postIterator = find_if(posts.begin(), posts.end(), [postID](const Post& post) {
			return post.getID() == postID;
			});

		if (postIterator != posts.end()) {
			const Post& post = *postIterator;
			post.displayLikedUsers();
		}
		else {
			cout << "Post with ID " << postID << " not found.\n";
		}
	}

	void commentOnPost(int postID, const string& comment) {
		auto currentUserIterator = find_if(users.begin(), users.end(), [this](const User& user) {
			return user.getID() == currentUserID;
			});

		if (currentUserIterator != users.end()) {
			User& currentUser = *currentUserIterator;
			currentUser.commentOnPost(postID, comment);
		}
		else {
			cout << "Current user not found in the network.\n";
		}
	}

	void viewPost(int postID) const {
		auto postIterator = find_if(posts.begin(), posts.end(), [postID](const Post& post) {
			return post.getID() == postID;
			});

		if (postIterator != posts.end()) {
			const Post& post = *postIterator;
			post.viewPost();
		}
		else {
			cout << "Post with ID " << postID << " not found.\n";
		}
	}

	void saveDataToFile() {
		ofstream outFile("social_network_data.txt");

		// Save users
		outFile << "Users:\n";
		for (const User& user : users) {
			outFile << user.getID() << "," << user.getName() << "," << user.getUsername() << "," << user.getPassword() << "\n";
		}

		// Save posts
		outFile << "Posts:\n";
		for (const Post& post : posts) {
			outFile << post.getID() << "," << post.getOwnerID() << "," << post.getTimestamp() << ","
				<< post.getLikes() << "," << post.getLikedUserIDs().size() << ",";
			for (int likedUserID : post.getLikedUserIDs()) {
				outFile << likedUserID << ",";
			}
			outFile << post.getComments().size() << ",";
			for (const string& comment : post.getComments()) {
				outFile << comment << ",";
			}
			outFile << "\n";
		}

		outFile << "CurrentUserID:" << currentUserID << "\n";

		outFile.close();
	}

	void loadDataFromFile() {
		ifstream inFile("social_network_data.txt");

		if (!inFile.is_open()) {
			cout << "Unable to open file. Starting with an empty network.\n";
			return;
		}

		users.clear();
		posts.clear();

		string line;
		while (getline(inFile, line)) {
			if (line == "Users:") {
				loadUsersFromFile(inFile);
			}
			else if (line == "Posts:") {
				loadPostsFromFile(inFile);
			}
			else if (line.substr(0, 14) == "CurrentUserID") {
				currentUserID = stoi(line.substr(15));
			}
		}

		inFile.close();
	}

private:
	void loadUsersFromFile(ifstream& inFile) {
		string line;
		while (getline(inFile, line) && !line.empty()) {
			int userID;
			string userName, username, password;
			stringstream ss(line);
			ss >> userID >> userName >> username >> password;
			users.emplace_back(userID, userName, username, password);
		}
	}

	void loadPostsFromFile(ifstream& inFile) {
		string line;
		while (getline(inFile, line) && !line.empty()) {
			int postID, ownerID, timestamp, likes, likedUserCount, commentCount;
			stringstream ss(line);
			ss >> postID >> ownerID >> timestamp >> likes >> likedUserCount;

			vector<int> likedUserIDs;
			for (int i = 0; i < likedUserCount; ++i) {
				int likedUserID;
				ss >> likedUserID;
				likedUserIDs.push_back(likedUserID);
			}

			ss >> commentCount;
			vector<string> comments;
			for (int i = 0; i < commentCount; ++i) {
				string comment;
				getline(ss, comment, ',');
				comments.push_back(comment);
			}

			Post post(postID, ownerID, "");
			post.setTimestamp(timestamp);
			post.setLikes(likes);
			post.setLikedUserIDs(likedUserIDs);
			post.setComments(comments);
			posts.push_back(post);
		}
	}

	int generateUniqueUserID() const {
		int newUserID;
		do {
			newUserID = rand() % 1000 + 1;
		} while (find_if(users.begin(), users.end(), [newUserID](const User& user) {
			return user.getID() == newUserID;
			}) != users.end());

		return newUserID;
	}

public:
	vector<User> users;
	vector<Post> posts;
	int currentUserID;
};

#endif 

int main() {
	SocialNetwork socialNetwork;
	socialNetwork.loadDataFromFile();

	int choice;
	do {
		cout << setfill('=') << setw(40) << "\n";
		cout << "            Menu\n";
		cout << setfill('=') << setw(40) << "\n";
		cout << "1. Authenticate User\n";
		cout << "2. Sign Up\n";
		cout << "3. Set Current User\n";
		cout << "4. View Home of Current User\n";
		cout << "5. Like a Post\n";
		cout << "6. Add a Post\n";
		cout << "7. View Liked Users of a Post\n";
		cout << "8. Comment on a Post\n";
		cout << "9. View a Post\n";
		cout << "10. Save Data to File\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: {
			string username, password;
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			socialNetwork.authenticateUser(username, password);
			break;
		}
		case 2: {
			string name, username, password;
			cout << "Enter your name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter desired username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			socialNetwork.signUpUser(name, username, password);
			break;
		}
		case 3: {
			int userID;
			cout << "Enter the user ID: ";
			cin >> userID;
			socialNetwork.setCurrentUser(userID);
			break;
		}
		case 4:
			socialNetwork.viewHomeOfCurrentUser();
			break;
		case 5: {
			int postID;
			cout << "Enter the post ID to like: ";
			cin >> postID;
			socialNetwork.likePost(postID);
			break;
		}
		case 6: {
			int postID, ownerID;
			string content;
			cout << "Enter post ID: ";
			cin >> postID;
			cout << "Enter owner ID: ";
			cin >> ownerID;
			cout << "Enter post content: ";
			cin.ignore();
			getline(cin, content);
			Post post(postID, ownerID, content);
			socialNetwork.addPost(post);
			break;
		}
		case 7: {
			int postID;
			cout << "Enter the post ID to view liked users: ";
			cin >> postID;
			socialNetwork.viewLikedUsers(postID);
			break;
		}
		case 8: {
			int postID;
			string comment;
			cout << "Enter the post ID to comment on: ";
			cin >> postID;
			cout << "Enter your comment: ";
			cin.ignore();
			getline(cin, comment);
			socialNetwork.commentOnPost(postID, comment);
			break;
		}
		case 9: {
			int postID;
			cout << "Enter the post ID to view: ";
			cin >> postID;
			socialNetwork.viewPost(postID);
			break;
		}
		case 10:
			socialNetwork.saveDataToFile();
			cout << "Data saved to file.\n";
			break;
		case 0:
			cout << "Exiting...\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}

	} while (choice != 0);

	system("pause");
}
