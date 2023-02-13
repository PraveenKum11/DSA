#include <iostream>
#include "Node.cpp"
using namespace std;

Node *takeInput()
{
	int data;
	cin >> data;
	Node *head = nullptr;
	Node *tail = nullptr;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
}

int printLL(Node *head)
{
	int count = 0;
	if (head == nullptr) return count;
	Node *temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
		count++;
	}
	cout << endl;
	return count;
}

int getNodeAt(Node *head, int k)
{
	Node *temp = head;
	while (temp != nullptr && k--)
		temp = temp->next;
	return temp->data;
}

Node *insertNodeAt(Node *head, int k, int data)
{
	Node *tempHead = head;
	Node *newNode = new Node(data);
	if (tempHead == nullptr) tempHead = newNode;
	if (k == 0)
	{
		newNode->next = tempHead;
		tempHead = newNode;
		return tempHead;
	}
	while (tempHead->next != nullptr && --k > 0)
		tempHead = tempHead->next;
	Node *temp = tempHead->next;
	tempHead->next = newNode;
	newNode->next = temp;
	return head;
}

Node *deleteNode(Node *head, int k)
{
	Node *tempHead = head;
	if (k == 0)
	{
		tempHead = tempHead->next;
		delete head;
		return tempHead;
	}
	while (tempHead->next != nullptr && --k > 0)
		tempHead = tempHead->next;
	Node *temp = tempHead->next;
	if (temp == nullptr) return head;
	tempHead->next = tempHead->next->next;
	delete temp;
	return head;
}

int lenghtLL(Node *head)
{
	if (head == nullptr)
		return 0;
	return 1 + lenghtLL(head->next);
}

Node *insertNodeREC(Node *head, int k, int data)
{
	if (head == nullptr && k > 0)
		k = 0;
	if (k == 0)
	{
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node *smallAns = insertNodeREC(head->next, k - 1, data);
	head->next = smallAns;
	return head;
}

Node *deleteNodeREC(Node *head, int k)
{
	if (k == 0)
	{
		Node *temp = head->next;
		delete head;
		return temp;
	}
	Node *smallAns = deleteNodeREC(head->next, k - 1);
	head->next = smallAns;
	return head;
}

int main()
{
	Node *head = takeInput();
	int k; cin >> k;
	// cout << lenghtLL(head);
	// Node *head1 = insertNodeAt(head, k, 99);
	// Node *head2 = deleteNode(head, k);
	// Node *head2 = insertNodeREC(head, k, 99);
	Node *head2 = deleteNodeREC(head, k);
	printLL(head2);
}