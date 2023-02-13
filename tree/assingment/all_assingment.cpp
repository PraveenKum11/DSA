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

// Question 1
TreeNode<int> *helperGreater(TreeNode<int> *root, int n)
{
	TreeNode<int> *ans = root;
	for (int i = 0; i < root->children.size(); i++)
	{
		TreeNode<int> *smallAns = helperGreater(root->children[i], n);
		if ((ans->data <= n) || (smallAns->data - n) < (ans->data - n))
			ans = smallAns;
	}
	return ans;
}

void getNextGreater(TreeNode<int> *root, int n)
{
	TreeNode<int> *ans = helperGreater(root, n);
	if (ans->data <= n)
	{
		cout << "NOT FOUND" << endl;
		return;
	}
	cout << ans->data << endl;
}
// END Question 1

// Question 2
void replaceDepth(TreeNode<int> *root, int depth)
{
	for (int i = 0; i < root->children.size(); i++)
		replaceDepth(root->children[i], depth + 1);
	root->data = depth;
}
// END Question 2

// Question 3
TreeNode<int> *maxNodeSum(TreeNode<int> *root)
{
	queue<TreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	int maxSum = INT_MIN;
	TreeNode<int> *nodeAns = root;
	while (!pendingNodes.empty())
	{
		TreeNode<int> *front = pendingNodes.front();
		int sum = front->data;
		pendingNodes.pop();
		for (int i = 0; i < front->children.size(); i++)
		{
			sum += front->children[i]->data;
			pendingNodes.push(front->children[i]);
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			nodeAns = front;
		}
	}
	cout << "maxSum " << maxSum << endl;
	return nodeAns;
}
// END Question 3

// Question 4 (Navie Way - Modifies the input)
// void replaceLargest(TreeNode<int> *root, int largest)
// {
// 	if (root->data == largest)
// 		root->data = INT_MIN;
// 	for (int i = 0; i < root->children.size(); i++)
// 		replaceLargest(root->children[i], largest);
// }

// int getLargest(TreeNode<int> *root)
// {
// 	int largest = root->data;
// 	for (int i = 0; i < root->children.size(); i++)
// 		largest = max(largest, getLargest(root->children[i]));
// 	return largest;
// }

// int getSecondLargest(TreeNode<int> *root)
// {
// 	int largest = getLargest(root);
// 	replaceLargest(root, largest);
// 	int secondLargest = getLargest(root);
// 	if (secondLargest == INT_MIN)
// 		cout << "NO SECOND LARGEST";
// 	return secondLargest;
// }

// Method 2 // din't get to work
struct msm
{
	TreeNode<int> *max;
	TreeNode<int> *sMax;
};

msm getSecondLargest(TreeNode<int> *root)
{
	TreeNode<int> *fMax = root;
	TreeNode<int> *fSmax = nullptr;

	for (int i = 0; i < root->children.size(); i++)
	{
		msm smallAns = getSecondLargest(root->children[i]);
		TreeNode<int> *tmp;
		if (smallAns.max->data > fMax->data)
		{
			tmp = fMax;
			fMax = smallAns.max;
			if (smallAns.sMax == nullptr) continue;
			if (smallAns.sMax->data > tmp->data)
				fSmax = smallAns.sMax;
			else
				fSmax = tmp;
		}
		if (smallAns.sMax->data > fSmax->data)
			fSmax = smallAns.sMax;
	}
	return {fMax, fSmax};
}


int main()
{
	TreeNode<int> *root = takeInputLevelWise();
	// printTreeLevelWise(root);

	// cout << "Enter the n : ";
	// int n; cin >> n;
	// getNextGreater(root, n);
	// replaceDepth(root, 0);
	// cout << maxNodeSum(root)->data << endl;
	cout << "---" << endl;
	cout << getSecondLargest(root).sMax->data;

	delete root;
}
