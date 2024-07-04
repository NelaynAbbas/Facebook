//#include<iostream>
//#include"comment.h"
//#include"like.h"
//#include"post.h"
//#include"user.h"
//
//using namespace std;
//
//int main()
//{
//	User user;
//	Post post;
//	int inp, id, inp2;
//	do {
//		cout << "\n\nEnter to Perform Action\n\n";
//		cout << "\n1. SIGNUP";
//		cout << "\n2. LOGIN";
//		cout << "\n0. EXIT";
//		cout << "\n\nEnter  :  ";
//		cin >> inp;
//		if (inp == 1)
//			user.addUser();
//		else if (inp == 2)
//		{
//			do {
//				cout << "Enter ID or 0 to EXIT  :  ";
//				cin >> id;
//				if (id == 0) {
//					cout << "\n\nEXITING SYSTEM..........\n\n";
//					return 0;
//				}
//				if (!user.search(id)) {
//					cout << "\n\nUSER NOT FOUND, ENTER AGAIN!!\n\n";
//				}
//			} while (!user.search(id));
//			user.loadUser(id);
//			do {
//				cout << "\n\nEnter to Perform Action\n\n";
//				cout << "\n1. View Home";
//				cout << "\n2. View Posts";
//				cout << "\n3. Add Posts";
//				cout << "\n0. EXIT";
//				cout << "\n\nENTER  :  ";
//				cin >> inp2;
//
//				if (inp2 == 1) {
//					user.viewHome();
//				}
//				else if (inp2 == 2) {
//					post.viewPosts(id);
//				}
//				else if (inp2 == 3) {
//					post.addPost(id);
//				}
//			} while (inp2 != 0);
//		}
//	} while (inp != 0);
//
//}