#include <bits/stdc++.h>
using namespace std;

class treeNode
{
public:
	int data;
	treeNode *leftChild;
	treeNode *rightChild;

	treeNode(int value) {
		data = value;
		leftChild = NULL;
		rightChild = NULL;
	}
};

void printTree(treeNode *root, int level);
void printSpace(int level);

void inOrder(treeNode *root, string &chk) {
	if (root == NULL) return;
	inOrder(root->leftChild, chk);
	chk += to_string(root->data);
	inOrder(root->rightChild, chk);
}

void preOrder(treeNode *root, string &chk) {
	if (root == NULL) return;
	chk += to_string(root->data);
	preOrder(root->leftChild, chk);
	preOrder(root->rightChild, chk);
}

void postOrder(treeNode *root, string &chk) {
	if (root == NULL) return;
	postOrder(root->leftChild, chk);
	postOrder(root->rightChild, chk);
	chk += to_string(root->data);
}

void printLeafNodes(treeNode *root) {
	if (root == NULL) return;
	if (root->leftChild == NULL && root->rightChild == NULL) {
		cout << root->data << ' ';
		return;
	}

	printLeafNodes(root->leftChild);
	printLeafNodes(root->rightChild);
}

void printNonLeafNodes(treeNode *root) {
	if (root == NULL) return;
	if (root->leftChild == NULL && root->rightChild == NULL) {
		return;
	}
	cout << root->data << " ";
	printNonLeafNodes(root->leftChild);
	printNonLeafNodes(root->rightChild);
}

void boundaryTraversal(treeNode *root) {
	if (root == NULL) return;
	cout << root->data << ' ';

	printLeafNodes(root->leftChild);
	printNonLeafNodes(root->leftChild);

	printLeafNodes(root->rightChild);
	printNonLeafNodes(root->rightChild);
}

void levelOrderTraversal(treeNode *root) {
	if (root == NULL) return;

	queue<treeNode *> q;
	q.push(root);

	while(!q.empty()) {
		treeNode *current = q.front();
		q.pop();

		cout << current->data << " ";

		if (current->leftChild != NULL) q.push(current->leftChild);
		if (current->rightChild != NULL) q.push(current->rightChild);
	}

}

void printTree(treeNode *root, int level) {
	if (root == NULL) return;
	
	if (root->leftChild == NULL && root->rightChild == NULL) {
		cout << root->data << '\n';
		return;
	} else {
		cout << '\n';
		printSpace(level);
		cout << "Root: " << root->data << '\n';
	}

	if (root->leftChild != NULL) {
		printSpace(level);
		cout << "Left: ";
		printTree(root->leftChild, level + 1);
	}

	if (root->rightChild != NULL) {
		printSpace(level);
		cout << "Right: ";
		printTree(root->rightChild, level + 1);
	}
}

void printSpace(int level) {
	for (int i = 0; i < level; i++) {
		cout << "	";
	}
	return;
}

int main() {
	int n; cin >> n;

	treeNode *allNodes[n];

	for (int i = 0; i < n; i++) {
		allNodes[i] = new treeNode(-1);
	}

	for (int i = 0; i < n; i++) {
		int value, left, right;
		cin >> value >> left >> right;
		allNodes[i]->data = value;
		if (left > n - 1 || right > n - 1) {
			cout << "Invalid index";
			break;
		}

		if (left != -1) allNodes[i]->leftChild = allNodes[left];
		if (right != -1) allNodes[i]->rightChild = allNodes[right]; 
	}


	printTree(allNodes[0], 0);

	string inorder = "", preorder = "", postorder = "";

	inOrder(allNodes[0], inorder);
	preOrder(allNodes[0], preorder);
	postOrder(allNodes[0], postorder);

	cout << "Inorder: " << inorder << '\n';
	cout << "Preorder: " << preorder << '\n';
	cout << "Postorder: " << postorder << '\n';

	cout << "Leaf nodes: ";
	printLeafNodes(allNodes[0]);
	cout << '\n';
	cout << "Nonleaf nodes: ";
	printNonLeafNodes(allNodes[0]);
	cout << '\n';
	cout << "Level order traversal: ";
	levelOrderTraversal(allNodes[0]);
	cout << '\n';
	cout << "Boundary traversal: ";
	boundaryTraversal(allNodes[0]);
}
