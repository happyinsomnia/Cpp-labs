#include "FiboHeap.h"

FiboHeap::Node::Node(int val)
{
	value = val;
	prev = next = this;
	degree = 0;
	child = nullptr;
	parent = nullptr;
}

FiboHeap::FiboHeap(): root(nullptr){}


