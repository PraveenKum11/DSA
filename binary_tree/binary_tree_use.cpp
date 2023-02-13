#include "BinaryTreeNode.hpp"
#include "Node.cpp"

BinaryTreeNode<int> *takeInput()
{
	cout << "Enter data: ";
	int rootData;
	cin >> rootData;
	if (rootData == -1)
		return nullptr;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int> *leftChild = takeInput();
	BinaryTreeNode<int> *rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
	queue<BinaryTreeNode<int> *> pendingNodes;
	cout << "Enter root Data :";
	int rootData;
	cin >> rootData;
	if (rootData == -1)
		return nullptr;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter the left child for " << front->data << " :";
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
			front->left = leftChild;
			pendingNodes.push(leftChild);
		}
		cout << "Enter the right child for " << front->data << " :";
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
			front->right = rightChild;
			pendingNodes.push(rightChild);
		}
	}
	cout << endl;
	return root;
}

void printRec(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return;
	cout << root->data << " : ";
	if (root->left)
		cout << "L" << root->left->data;
	if (root->right)
		cout << ", R" << root->right->data;
	cout << endl;
	printRec(root->left);
	printRec(root->right);
}

void printLevelWise(BinaryTreeNode<int> *root)
{
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		cout << front->data << " : ";
		if (front->left)
		{
			cout << "L" << front->left->data;
			pendingNodes.push(front->left);
		}
		if (front->right)
		{
			cout << " R" << front->right->data;
			pendingNodes.push(front->right);
		}
		cout << endl;
	}
}

int countNodes(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return 0;
	int ans = 1;
	ans += countNodes(root->left);
	ans += countNodes(root->right);
	return ans;
}

int heightOfBinary(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return 0;
	return max(heightOfBinary(root->left), heightOfBinary(root->right)) + 1;
}

void preOrder(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return;
	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}

void inOrder(BinaryTreeNode<int> *root)
{
	if (root == nullptr)
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

// Question 1
queue<int> queueFromBinaryTree(BinaryTreeNode<int> *root)
{
	queue<int> ans;
	queue<BinaryTreeNode<int> *> pendingNodes;
	pendingNodes.push(root);
	while (!pendingNodes.empty())
	{
		BinaryTreeNode<int> *front = pendingNodes.front();
		pendingNodes.pop();
		if (front == nullptr) ans.push(-1);
		else
		{
			ans.push(front->data);
			pendingNodes.push(front->left);
			pendingNodes.push(front->right);
		}
	}
	return ans;
}

vector<Node*> levelWiseLL(BinaryTreeNode<int> *root)
{
	queue<int> seq = queueFromBinaryTree(root);
	vector<Node*> ans;
	int size = 1;
	while (!seq.empty())
	{
		Node *head = nullptr;
		Node *tail = nullptr;
		for (int i = 0; i < size; i++)
		{
			if (seq.empty()) break;
			if (seq.front() == -1)
			{
				seq.pop();
				continue;
			}
			Node *newNode = new Node(seq.front());
			seq.pop();
			if (head == nullptr)
			{
				head = newNode;
				tail = head;
			}
			else
			{
				tail->next = newNode;
				tail = tail->next;
			}
		}
		ans.push_back(head);
		size *= 2;
	}
	return ans;
}
// END Question 1

// Question 3
vector<int> longestPath(BinaryTreeNode<int> *root)
{
	if (root == nullptr) return {};
	vector<int> smallLeft = longestPath(root->left);
	vector<int> smallRight = longestPath(root->right);
	auto ans = (smallRight.size() > smallLeft.size() ? smallRight : smallLeft);
	ans.push_back(root->data);
	return ans;
}

// Question 5 (HARD)
long long helper(TreeNode<int> *root, long long &maxSoFar)
{
    if (root == nullptr) return 0;
    long long smallLeft = helper(root->left, maxSoFar);
    long long smallRight = helper(root->right, maxSoFar);
    long long currSum = smallLeft + smallRight + root->val;
    if (currSum > maxSoFar) maxSoFar = currSum;
    return max(smallLeft, smallRight) + root->val;
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    if (root == nullptr) return -1;
    if (root->left == nullptr || root->right == nullptr) return -1;
    long long maxSoFar = -1;
    helper(root, maxSoFar);
    return maxSoFar;
}
// NOTE : You can return some other value from a recursion
// which will be used to make bigger answer. And store the
// answer for current step in another variable, like in
// this question we have used maxSoFar.

int main()
{
	BinaryTreeNode<int> *root = takeInputLevelWise();
	printLevelWise(root);
	cout << endl;
	// printRec(root);

	// helper for Question 1
	// vector<Node*> ans = levelWiseLL(root);
	// cout << "SIZE " << ans.size() << endl;
	// for (int i = 0; i < ans.size(); i++)
	// {
	// 	Node *head = ans[i];
	// 	while (head != nullptr)
	// 	{
	// 		cout << head->data << " ";
	// 		head = head->next;
	// 	}
	// 	cout << endl;
	// }
	// END Question 1


	// helper for Question 3
	// vector<int> path = longestPath(root);
	// for (auto i : path) cout << i << " ";

	// cout << countNodes(root);
	// cout << heightOfBinary(root);
	// preOrder(root);
	// cout << endl;
	// postOrder(root);
	// cout << endl;
	// inOrder(root);
	delete root;
}

// 10 20 30 4 -1 5 -1 -1 -1 7 6 -1 -1 -1 -1