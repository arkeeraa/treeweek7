#include <iostream>
#include <string>
#include<sstream>
#include<fstream>
#include "tree.h"
#include "time.h"
#include<vector>
using namespace std;

int main()
{

	Tree<string> mytree;

	srand(time(NULL));
	for (int i = 0; i < 500; i++){
		int data = rand() % 99+1;
		char buff[8];
		sprintf_s(buff, "%d", data);
		mytree.insert(buff);
		printf("%s | ", buff);
	}
	cout << ">>>>>>>" << endl << endl;


	int h = mytree.inorder();
	cout << "height: " << h << endl << endl;
	mytree.balance();
	h = mytree.inorder();
	cout << "height balance : " << h << endl;
	getchar();

	return 0;

}
