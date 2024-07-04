//#include"comment.h"
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<iomanip>
//
//using namespace std;
//
//void Comment::addComment(int pID, int uID) {
//	cout << "Enter Comment  :  ";
//	cin.ignore();
//	getline(cin, msg);
//	ifstream in;
//	int count;
//	in.open("ComCount.txt");
//	in >> count;
//	count++;
//	in.close();
//	ofstream out;
//	out.open("ComCount.txt");
//	out << count;
//	out.close();
//	out.open("comment.txt", ios::app);
//	out << msg << endl << pID << endl << uID << endl;
//	out.close();
//}
//
//void Comment::listCom(int pID) {
//	ifstream in;
//	int count;
//	in.open("ComCount.txt");
//	in >> count;
//	in.close();
//	Comment* ptr = new Comment[count];
//
//	int pp, uu;
//	in.open("comment.txt");
//	int id;
//	for (int i = 0; i < count; i++) {
//		in.ignore();
//		getline(in, ptr[i].msg);
//		in >> ptr[i].postID >> ptr[i].id;
//	}
//	int j = 1;
//	cout << "\n\n--------------------ID'S OF PERSON COMMENTED--------------------\n\n";
//	cout << setw(5) << "Sr." << setw(10) << "ID'S" << setw(20) << "Message" << endl << endl;
//	for (int i = 0; i < count; i++) {
//		if (pID == ptr[i].postID)
//		{
//			cout << setw(5) << j << setw(10) << ptr[i].id << setw(20) << ptr[i].msg << endl;
//			j++;
//		}
//	}
//}