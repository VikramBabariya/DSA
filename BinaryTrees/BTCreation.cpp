#include<bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}

};

Node* createBT() {
	cout << "Enter Data " << endl;
	int data;
	cin >> data;
	Node *root = new Node(data);

	if (data == -1) return NULL;

	cout << "Enter data for left node of " << data << endl;
	root->left = createBT();
	cout << "Enter data for right node of " << data << endl;
	root->right = createBT();
	return root;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif

	Node *root = NULL;
	createBT();
	return 0;
}
