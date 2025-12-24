#include<iostream>
using namespace std;
int change(char c) {
	return c - '0';
}
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;
Node* buildBST(int *post, int l, int r) {
	if (l > r) return 0;
	Node* root = new Node;
	root->data = post[r];
	root->left = 0;
	root->right = 0;
	int k = l;
	while (k < r && post[k] < post[r]) {
		k++;
	}
	root->left = buildBST(post, l, k - 1);
	root->right = buildBST(post, k, r - 1);
	return root;
}
void preorder(Node* root) {
	if (!root)return;
	cout << root->data;
	if (root->left) {
		cout << "<";
		preorder(root->left);
		cout << ">";
	}if (root->right) {
		cout << "<";
		preorder(root->right);
		cout << ">";
	}
}
int main() {
	int n;
	cin >> n;
	int mole[1001];
	for (int i = 0; i < n; i++) {
		cin >> mole[i];
	}
	Node* root = buildBST(mole, 0, n - 1);
	preorder(root);
	return 0;
}