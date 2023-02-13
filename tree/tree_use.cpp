#include "TreeNode.hpp"

TreeNode<int> *takeInput()
{
	int rootData; cout << "Enter the root data : "; cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	int childrenCount; cout << "Enter the number of children : "; cin >> childrenCount;
	for (int i = 0; i < childrenCount; i++)
	{
		cout << "Enter the " << i << "th for " << rootData << ": \n";
		TreeNode<int> *child = takeInput();
		root->children.push_back(child);
	}
	return root;
}

TreeNode<int> *takeInputLevelWise()
{
	cout << "Enter the root data : ";
	int rootData; cin >> rootData;
	TreeNode<int> *root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		TreeNode<int> *front = pendingNodes.front();
		cout << "Enter the number of children of " << front->data << " : ";
		int numChild; cin >> numChild;
		pendingNodes.pop();
		for (int i = 0; i < numChild; i++)
		{
			cout << "Enter the " << i << "th child of " << front->data << endl;
			int nodeData; cin >> nodeData;
			TreeNode<int> *child = new TreeNode<int>(nodeData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}
	cout << endl;
	return root;
}

void printTree(TreeNode<int>* root)
{
	cout << root->data << " : ";
	for (int i = 0; i < root->children.size(); i++)
		cout << root->children[i]->data << " ";
	cout << endl;
	for (int i = 0; i < root->children.size(); i++)
		printTree(root->children[i]);
}

void printTreeLevelWise(TreeNode<int>* root)
{
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		TreeNode<int> *front = pendingNodes.front();
		cout << front->data << " : ";
		pendingNodes.pop();
		for (int i = 0; i < front->children.size(); i++)
		{
			cout << front->children[i]->data << " ";
			pendingNodes.push(front->children[i]);
		}
		cout << endl;
	}
}

int countNodes(TreeNode<int> *root)
{
	int count = 0;
	for (int i = 0; i < root->children.size(); i++)
		count += countNodes(root->children[i]);
	return count + 1;
}

int treeHeight(TreeNode<int> *root)
{
	int smallHeight = 0;
	for (int i = 0; i < root->children.size(); i++)
		smallHeight = max(smallHeight, treeHeight(root->children[i]));
	return smallHeight + 1;
}

void printDepthK(TreeNode<int> *root, int k)
{
	if (root == nullptr) return;	// Edge case
	if (k == 0)
	{
		cout << root->data << " ";
		return;
	}
	for (int i = 0; i < root->children.size(); i++)
		printDepthK(root->children[i], k - 1);
}

int countLeaf(TreeNode<int> *root)
{
	if (root->children.size() == 0)
		return 1;
	int smallCount = 0;
	for (int i = 0; i < root->children.size(); i++)
		smallCount += countLeaf(root->children[i]);
	return smallCount;
}

void preOrder(TreeNode<int> *root)
{
	cout << root->data << " ";
	for (int i = 0; i < root->children.size(); i++)
		preOrder(root->children[i]);
}

void postOrder(TreeNode<int> *root)
{
	for (int i = 0; i < root->children.size(); i++)
		postOrder(root->children[i]);
	cout << root->data << " ";
}

int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	// printTreeLevelWise(root);
	// cout << "Node count : ";
	// cout << countNodes(root) << endl;
	// cout << "Height : ";
	// cout << treeHeight(root) << endl;
	// printDepthK(root, 2);
	// cout << countLeaf(root) << endl;
	// preOrder(root);
	// cout << endl;
	postOrder(root);
	delete root;

	// TODO delete our tree
}

// 10 2 20 30 2 40 50 2 60 70 0 0 0 0