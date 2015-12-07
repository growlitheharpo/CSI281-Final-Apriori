/*
Author:           James Keats
Class:            CSI-281-02
Assignment:       PA7
Date Assigned:    11/05/2015
Due Date:         11/12/2015 @ 9:30AM

Description:
An implementation of a Binary Search Tree

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references
to the work of others. I understand the definition and consequences of plagiarism and acknowledge
that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then
retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
#ifndef SIMPLE_QUEUE_H
#define SIMPLE_QUEUE_H

template <typename T>
class SimpleQueue
{
private:
	template <typename T>
	struct Node
	{
		T mData;
		Node *mNext;

		Node(T d)
		{
			this->mData = d;
			this->mNext = NULL;
		}
	};

	Node<T> *mHead, *mTail;
	int mCount;

public:
	SimpleQueue();
	~SimpleQueue();

	T dequeue();
	void enqueue(T data);
	int getCount();
};

#endif

/*********************************************************************************************
*  Purpose: Simple constructor
*      Pre: None
*	  Post: None
*********************************************************************************************/
template <typename T>
SimpleQueue<T>::SimpleQueue()
{
	this->mHead = NULL;
	this->mTail = NULL;
	this->mCount = 0;
}

/*********************************************************************************************
*  Purpose: Destructor
*      Pre: None
*	  Post: All memory is released.
*********************************************************************************************/
template <typename T>
SimpleQueue<T>::~SimpleQueue()
{
	Node<T> *deleteMe = mHead, *tmp = mHead;

	while (tmp != NULL)
	{
		tmp = tmp->mNext;

		delete deleteMe;
		deleteMe = tmp;
	}
}

/*********************************************************************************************
*  Purpose: Remove and return an item from the front of the queue.
*      Pre: None
*	  Post: Returns the first item in the queue, or a default object of type T.
*********************************************************************************************/
template <typename T>
T SimpleQueue<T>::dequeue()
{
	Node<T> *deleteMe = mHead;
	T val = T();

	if (mHead != NULL)
	{
		val = mHead->mData;

		mHead = mHead->mNext;
		delete deleteMe;
		mCount--;
	}

	return val;
}

/*********************************************************************************************
*  Purpose: Add a new item to the end of the queue.
*      Pre: Handed the item to create.
*	  Post: Object is added to queue.
*********************************************************************************************/
template <typename T>
void SimpleQueue<T>::enqueue(T data)
{
	Node<T> *newNode = new Node<T>(data);

	if (newNode != NULL)
	{
		if (mCount == 0)
			mHead = newNode;
		else
			mTail->mNext = newNode;

		mTail = newNode;
		mCount++;
	}
}

/*********************************************************************************************
*  Purpose: Get the number of items in the queue.
*      Pre: Object is initialized.
*	  Post: Returns the count of items in the queue.
*********************************************************************************************/
template <typename T>
int SimpleQueue<T>::getCount()
{
	return mCount;
}
