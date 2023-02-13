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

void printReverseREC(Node *head)
{
	if (head == nullptr)
		return;
	printReverseREC(head->next);
	cout << head->data << " ";
}

int lengthLL(Node *head)
{
	int count = 0;
	while (head != nullptr)
	{
		count++;
		head = head->next;
	}
	return count;
}

Node *reverseLL(Node *head)
{
	Node *prev = nullptr;
	Node *curr = head;
	Node *nxt;
	while (curr != nullptr)
	{
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	return prev;
}

bool isPalindrome(Node *head)
{
	int mid = lengthLL(head) / 2 - 1;
	cout << mid << endl;
	Node *head1 = head;
	Node *head2 = head;
	while (mid--)
		head2 = head2->next;
	Node *temp = head2->next;
	head2->next = nullptr;
	head2 = temp;
	printLL(head1);
	head2 = reverseLL(head2);
	printLL(head2);
	while (head1 != nullptr && head2 != nullptr)
	{
		if (head1->data != head2->data)
			return false;
		head1 = head1->next;
		head2 = head2->next;
	}
	return true;
}

Node *swapNodes(Node *head, int p, int q)
{
	Node *prevNodeA = head;
	Node *prevNodeB = head;
	if (p == 0 && q == 1)
	{
		Node *nodeA = prevNodeA;
		Node *nodeB = prevNodeB->next;
		nodeA->next = nodeB->next;
		nodeB->next = nodeA;
		head = nodeB;
		return head;
	}
	if (p == 0)
	{
		q--;
		while (q--)
			prevNodeB = prevNodeB->next;
		Node *nodeA = head;
		Node *nodeB = prevNodeB->next;
		Node *temp = head->next;
		head->next = nodeB->next;
		prevNodeB->next = head;
		nodeB->next = temp;
		head = nodeB;
		return head;
	}
	p--, q--;
	while (p--)
		prevNodeA = prevNodeA->next;
	while (q--)
		prevNodeB = prevNodeB->next;
	Node *nodeA = prevNodeA->next;
	Node *nodeB = prevNodeB->next;
	prevNodeA->next = nodeB;
	prevNodeB->next = nodeA;
	Node *temp = nodeA->next;
	nodeA->next = nodeB->next;
	nodeB->next = temp;
	return head;
}

int main()
{
	Node *head = takeInput();
	int p, q; cin >> p >> q;
	// cout << boolalpha << isPalindrome(head);
	Node *head1;
	head1 = swapNodes(head, p, q);
	printLL(head1);
}