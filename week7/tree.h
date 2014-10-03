#include <queue>
#include <stack>
#include <cstddef>
#include <iostream>
using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	//	int get_linenum(){ return linenum; } //***
	//void set_line(int li){ linenum = li; }//***
	T key;
	Node *left, *right;
	//private:
	//	int linenum;

};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() { clear(root); root = 0; }
	bool isEmpty() { return root == 0; }
	int inorder() { return inorder(root, 0); }
	void balance();
	//void inorder_line(int ln) { inorder_line(root, ln); }//*** for mix lines of words are separate with ascii
	void insert(const T& el);//*** insert data with line's number
	void deleteNode(Node<T> *& node);

protected:
	Node<T> *root;

	void clear(Node<T> *p);
	int inorder(Node<T> *p, int h);
	void inorderArr(Node<T> *p, int arr[]);
	void Tree<T>::balanceRec(int arr[], int start, int range);
	int now_arr_count;
	//void inorder_line(Node<T> *p, int ln);//***

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}

template<class T>
int Tree<T>::inorder(Node<T> *p, int h) {
	//TO DO! This is for an inorder tree traversal!
	/* if (p!=0) {
	inorder(p->left);
	visit(p);// print p.key and print p.get_lin
	inorder(p->right);
	} */


	if (p != 0) {
		int hl = inorder(p->left, h + 1);
		//cout << p->key << endl;
		int hr = inorder(p->right, h + 1);
		return hl > hr ? hl : hr;
	}
	else{
		return h;
	}



}

template<class T>
void Tree<T>::inorderArr(Node<T> *p, int arr[]) {

	if (p != 0) {
		inorderArr(p->left, arr);
		//cout << p->key << endl;
		arr[now_arr_count++] = atoi(p->key.c_str());
		inorderArr(p->right, arr);

	}



}
template<class T>
void Tree<T>::balance(){
	int arr[500];
	now_arr_count = 0;
	inorderArr(root, arr);
	root = 0;
	// int size = Size of Tree
	int size = 500;
	// But the index of tree not equal size
	balanceRec(arr, 0, size - 1);
}

template<class T>
void Tree<T>::balanceRec(int arr[], int start, int end){

	int mid = (start + end) / 2;
	char buff[8];
	sprintf_s(buff, "%d", arr[mid]);
	insert(buff);
	if (end - start + 1 <= 3){
		if (mid - 1 >= start){
			char buff[8];
			sprintf_s(buff, "%d", arr[mid - 1]);
			insert(buff);
		}
		if (mid + 1 <= end){
			char buff[8];
			sprintf_s(buff, "%d", arr[mid + 1]);
			insert(buff);
		}
	}
	else{
		balanceRec(arr, start, mid - 1);
		balanceRec(arr, mid + 1, end);
	}


}


/*template<class T>//##########
void Tree<T>::inorder_line(Node<T> *p, int ln) {

if (p != 0) {
inorder_line(p->left, ln);
if (p->get_linenum() == ln)
cout << p->key << " "; //print all of data in a line's number
inorder_line(p->right, ln);
}

}//###########
*/

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	while (p != 0) {
		prev = p;
		if (atoi(p->key.c_str()) < atoi(el.c_str()))
			p = p->right;
		else
			p = p->left;
	}
	if (root == 0){
		root = new Node<T>(el);
		//root->set_line(ln);//***
	}
	else if (atoi(prev->key.c_str())<atoi(el.c_str())){
		prev->right = new Node<T>(el);
		//prev->right->set_line(ln);//***
	}
	else{
		prev->left = new Node<T>(el);
		//prev->left->set_line(ln);//***
	}
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp = node;
	if (node->right == 0)
		node = node->left;
	else if (node->left == 0)
		node = node->right;
	else {
		tmp = node->left;
		prev = node;
		while (tmp->right != 0) {
			prev = tmp;
			tmp = tmp->right;
		}
		node->key = tmp->key;
		if (prev == node)
			prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

#endif // Binary_Search_Tree

