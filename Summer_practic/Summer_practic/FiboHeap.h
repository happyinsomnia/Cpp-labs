#pragma once
#include<string>
class FiboHeap
{
private:
	struct Node
	{
		Node* prev;
		Node* next;
		Node* child;
		Node* parent;
		int value;
		int degree;

		Node(int val);
	};
	Node* root;
	Node* merge(Node* n1, Node* n2);
	void linkNodes(Node* parent, Node* child);
	Node* extractMin(Node* n);
	void display(Node* n, const std::string& prefix) const;

public:
	FiboHeap();
	Node* insert(int val);
	void merge(FiboHeap& other);
	int getMin() const;
	int extractMin();
	void display() const;

};

