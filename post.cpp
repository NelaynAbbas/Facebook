//#include"post.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//
//using namespace std;
//
//
//void Post::setID(int id) {
//	this->postID = id;
//}
//
//const int Post::getID() {
//	return this->postID;
//}
//
//Post::Post() {
//	lCount = 0;
//	cCount = 0;
//}
//
//void Post::addPost(int id) {
//	cout << "Enter Message you want to post  :  ";
//	cin.ignore();
//	getline(cin, message);
//	/*user.*/setID(id);
//
//	int count;
//	ifstream in;
//	in.open("postCount.txt");
//	in >> count;
//	count++;
//	in.close();
//
//	ofstream out;
//	out.open("postCount.txt");
//	out << count;
//	out.close();
//
//	postID = count;
//
//	out.open("post.txt", ios::app);
//
//	out << message << endl << postID << endl << id << endl << lCount << endl << cCount << endl;
//
//	out.close();
//}
//
//void Post::viewPosts(int uID) {
//	Comment comment;
//	Like like;
//	ifstream in;
//	int count;
//	in.open("postCount.txt");
//	in >> count;
//	in.close();
//	Post* ptr = new Post[count];
//
//	in.open("post.txt");
//	int id;
//	for (int i = 0; i < count; i++) {
//		in.ignore();
//		getline(in, ptr[i].message);
//		in >> ptr[i].postID >> id >> ptr[i].lCount >> ptr[i].cCount;
//		ptr[i]./*user.*/setID(id);
//	}
//	int i = 0;
//	int inp;
//	ofstream out;
//	do
//	{
//		system("pause");
//		system("CLS");
//		cout << "\n\n-------------------POSTS-------------------\n\n";
//		cout << "\n\nPOST  :  " << ptr[i].message;
//		cout << "\n\nLike Count  :  " << ptr[i].lCount << "Comments Count  :  " << ptr[i].cCount;
//		cout << "\n\n------------------OPTIONS------------------\n\n";
//		cout << "\n\nEnter to Perform Action\n\n";
//		cout << "\n1. Like Post";
//		cout << "\n2. Comment";
//		cout << "\n3. View Like List";
//		cout << "\n4. View Comment List";
//		cout << "\n5. Next Post";
//		cout << "\n6. Previous Post";
//		cout << "\n0. EXIT";
//		cout << "\n\nENTER  :  ";
//		cin >> inp;
//		if (inp == 1)
//		{
//			if (ptr[i].lCount < 10) {
//				like.addLike(postID, uID);
//				ptr[i].lCount++;
//			}
//		}
//		else if (inp == 2)
//		{
//			if (ptr[i].cCount < 10) {
//				comment.addComment(postID, uID);
//				ptr[i].cCount++;
//			}
//		}
//		else if (inp == 3)
//		{
//			like.listLike(ptr[i].postID);
//		}
//		else if (inp == 4)
//		{
//			comment.listCom(ptr[i].postID);
//		}
//		else if (inp == 5)
//		{
//			if (i < count)
//				i++;
//			else
//				i = 0;
//		}
//		else if (inp == 6)
//		{
//			if (i > 0)
//				i--;
//			else
//				i = count - 1;
//		}
//
//	} while (inp != 0);
//
//	out.open("post.txt");
//	out.close();
//	out.open("post.txt");
//	for (int j = 0; j < count; j++) {
//		out << ptr[j].message << endl << ptr[j].postID << endl << ptr[j]./*user.*/getID() << endl << ptr[j].lCount << endl << ptr[j].cCount << endl;
//	}
//	out.close();
//}
//
//void Post::viewPostsByID(int id) {
//	ifstream in;
//	int count;
//	in.open("postCount.txt");
//	in >> count;
//	in.close();
//	Post* ptr = new Post[count];
//	int idd;
//	in.open("post.txt");
//	for (int i = 0; i < count; i++) {
//		in.ignore();
//		getline(in, ptr[i].message);
//		in >> ptr[i].postID >> idd >> ptr[i].lCount >> ptr[i].cCount;
//		ptr[i]./*user.*/setID(idd);
//	}
//
//	for (int i = 0; i < count; i++) {
//		if (id == ptr[i]./*user.*/getID())
//		{
//			cout << "\n\n--------------------POST" << i + 1 << "--------------------\n\n";
//			cout << "\n\nPOST  :  " << ptr[i].message;
//			cout << "\n\nLike Count  :  " << lCount << "Comments Count  :  " << cCount;
//		}
//	}
//}