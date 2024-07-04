//#include"like.h"
//#include<iostream>
//#include<fstream>
//
//using namespace std;
//
//void Like::addLike(int pID, int uID) {
//	ifstream in;
//	int count;
//	in.open("likeCount.txt");
//	in >> count;
//	count++;
//	in.close();
//	ofstream out;
//	out.open("likeCount.txt");
//	out << count;
//	out.close();
//	out.open("like.txt", ios::app);
//	out << pID << endl << uID << endl;
//	out.close();
//}
//
//void Like::listLike(int pID) {
//	ifstream in;
//	int count;
//	in.open("likeCount.txt");
//	in >> count;
//	in.close();
//	Like* ptr = new Like[count];
//
//	int pp, uu;
//	in.open("like.txt");
//	int id;
//	for (int i = 0; i < count; i++) {
//		in >> postID >> uu;
//		ptr[i]./*user.*/setID(uu);
//	}
//	int j = 1;
//	cout << "\n\n--------------------ID'S OF PERSON Liked--------------------\n\n";
//	for (int i = 0; i < count; i++) {
//		if (pID == ptr[i].postID)
//		{
//			cout << "Person " << j << ptr[i]./*user.*/getID();
//			j++;
//		}
//	}
//}