//#include"user.h"
//#include<iostream>
//#include<fstream>
//#include"post.h"
//
//using namespace std;
//
//User::User() {}
//
//void User::addUser() {
//	cout << "Enter Name  :  ";
//	cin >> name;
//	cout << "Enter id  :  ";
//	cin >> id;
//	ifstream in;
//	int count;
//	in.open("userCount.txt");
//	in >> count;
//	count++;
//	in.close();
//	ofstream out;
//	out.open("userCount.txt");
//	out << count;
//	out.close();
//	out.open("user.txt", ios::app);
//	out << name << endl << id << endl;
//	out.close();
//}
//
//bool User::search(int id) {
//	ifstream in;
//	int count;
//	in.open("userCount.txt");
//	in >> count;
//	in.close();
//	User* ptr = new User[count];
//
//	in.open("user.txt");
//
//	for (int i = 0; i < count; i++) {
//		in >> ptr[i].name >> ptr[i].id;
//	}
//
//	bool found = 0;
//
//	for (int i = 0; i < count; i++) {
//		if (id == ptr[i].id)
//			found = 1;
//	}
//
//	return found;
//}
//
//void User::setID(int id) {
//	this->id = id;
//}
//
//const int User::getID() {
//	return this->id;
//}
//
//void User::loadUser(int id) {
//	ifstream in;
//	int count;
//	in.open("userCount.txt");
//	in >> count;
//	in.close();
//	User* ptr = new User[count];
//
//	in.open("user.txt");
//
//	for (int i = 0; i < count; i++) {
//		in >> ptr[i].name >> ptr[i].id;
//	}
//
//	for (int i = 0; i < count; i++) {
//		if (id == ptr[i].id)
//		{
//			this->id = ptr[i].id;
//			this->name = ptr[i].name;
//		}
//	}
//}
//
//
//void User::viewHome() {
//	system("CLS");
//	Post posts;
//	cout << "\n\n-------------------------HOME PAGE-------------------------\n\n";
//	cout << "\n\nUSER ID  :  " << id << "                  NAME  :  " << name;
//	posts.viewPostsByID(id);
//}