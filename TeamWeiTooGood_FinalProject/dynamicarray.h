/*
Author:           James Keats, David Horntvedt
Class:            CSI-281-02
Assignment:       Apriori
Due Date:         12/12/2015 @ 11:59 PM

Description:
Apriori. What else is there to say.

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully-documented references
to the work of others. I understand the definition and consequences of plagiarism and acknowledge
that the assessor of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may then
retain a copy of this assignment on its database for the purpose of future plagiarism checking)
*/
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray
{
private:
	const int GROW_SHRINK_SIZE = 1000;

	T *mData;
	int mArraySize, numIndexesFilled;

	void copyArray(const T* array1, T* array2, int size1, int size2);
	void contractArray();
	void expandArray();

public:
	DynamicArray();
	DynamicArray(int size);
	DynamicArray(const DynamicArray& other);
	~DynamicArray();

	int count() const;
	void display() const;

	void clear();
	void insert(const T& item);
	bool remove(const T& item);
	bool removeAt(int index);

	DynamicArray<T>& operator= (const DynamicArray<T>& otherArray);

	bool operator== (const DynamicArray<T>& otherArray) const;

	T& operator[] (int index);
	T operator[] (int index) const;
};


/*********************************************************************************************
* Purpose: Copy one array into another
*     Pre: Two initialized arrays and the sizes must be passed in
*	 Post:  One array is copied into another
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::copyArray(const T* array1, T* array2, int size1, int size2)
{
	if (size2 < size1)
		size1 = size2;

	int i;
	for (i = 0; i < size1; i++)
		array2[i] = array1[i];
}


/*********************************************************************************************
* Purpose: Change size of array
*     Pre: Array must be initialized
*	 Post:  Array is resized
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::contractArray()
{
	T *newData = new T[mArraySize - GROW_SHRINK_SIZE];
	copyArray(mData, newData, mArraySize, mArraySize - GROW_SHRINK_SIZE);

	mArraySize -= GROW_SHRINK_SIZE;

	delete[] mData;
	mData = newData;
}


/*********************************************************************************************
* Purpose:  Increase size of array
*     Pre: Array  must be initialized
*	 Post:  Array size is increased
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::expandArray()
{
	T *newData = new T[mArraySize + GROW_SHRINK_SIZE];
	copyArray(mData, newData, mArraySize, mArraySize + GROW_SHRINK_SIZE);

	mArraySize += GROW_SHRINK_SIZE;

	delete[] mData;
	mData = newData;
}


/*********************************************************************************************
* Purpose: Initialize dynamic array
*     Pre: None
*	 Post:  Initialize DynamicArray
*********************************************************************************************/
template <typename T>
DynamicArray<T>::DynamicArray()
{
	mData = new T[GROW_SHRINK_SIZE];

	mArraySize = GROW_SHRINK_SIZE;
	numIndexesFilled = 0;
}


/*********************************************************************************************
* Purpose: Initialize dynamic array
*     Pre: Size must be passed in
*	 Post:  Initialize DynamicArray
*********************************************************************************************/
template <typename T>
DynamicArray<T>::DynamicArray(int size)
{
	mData = new T[size];

	mArraySize = size;
	numIndexesFilled = 0;
}


/*********************************************************************************************
* Purpose: Initialize dynamic array
*     Pre: Another initialized and instantiated DynamicArray
*	 Post:  Initialize DynamicArray
*********************************************************************************************/
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	mData = new T[GROW_SHRINK_SIZE];
	mArraySize = GROW_SHRINK_SIZE;
	numIndexesFilled = 0;

	*this = other;
}


/*********************************************************************************************
* Purpose:  Destructor
*     Pre:  None
*	 Post:    None
*********************************************************************************************/
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] mData;
}


/*********************************************************************************************
* Purpose:  Return size of array
*     Pre:  Initialized array
*	 Post:    Size is returned
*********************************************************************************************/
template <typename T>
int DynamicArray<T>::count() const
{
	return numIndexesFilled;
}


/*********************************************************************************************
* Purpose: Display array on screen
*     Pre:  Initialized array
*	 Post:    array is displayed on screen
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::display() const
{
	for (int i = 0; i < numIndexesFilled; i++)
		cout << mData[i] << " ";

	cout << endl;
}


/*********************************************************************************************
* Purpose:  Clear array
*     Pre:  Initialized array
*	 Post:    Array is cleared
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::clear()
{
	delete[] mData;

	mData = new T[GROW_SHRINK_SIZE];

	mArraySize = GROW_SHRINK_SIZE;
	numIndexesFilled = 0;
}


/*********************************************************************************************
* Purpose:  Insert item into array
*     Pre:  Initialized array
*	 Post:    Item is inserted
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::insert(const T& item)
{
	mData[numIndexesFilled] = item;
	numIndexesFilled++;

	if (numIndexesFilled == mArraySize)
		expandArray();
}


/*********************************************************************************************
* Purpose:  Remove item fromarray
*     Pre:  Initialized array
*	 Post:    Item is removed
*********************************************************************************************/
template <typename T>
bool DynamicArray<T>::remove(const T& item)
{
	int index = -1;
	for (int i = 0; i < numIndexesFilled && index == -1; i++)
	{
		if (mData[i] == item)
			index = i;
	}

	//traversed entire list and item was not found
	if (index == -1)
		return false;

	//else
	return removeAt(index);
	return true;
}


/*********************************************************************************************
* Purpose:  Remove item from array at index
*     Pre:  Initialized array
*	 Post:    Item is removed
*********************************************************************************************/
template <typename T>
bool DynamicArray<T>::removeAt(int index)
{
	if (index < 0 || index >= numIndexesFilled)
		return false;

	for (int i = index; i < numIndexesFilled - 1; i++)
		mData[i] = mData[i + 1];

	numIndexesFilled--;

	if (mArraySize - GROW_SHRINK_SIZE - 2 > numIndexesFilled) //if we're removing a lot of items, shrink
		contractArray();

	return true;
}


/*********************************************************************************************
* Purpose:  Set DynamicArray equal to DynamicArray
*     Pre:  Arrays are initialized
*	 Post:    Dynamic array is assigned
*********************************************************************************************/
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& otherArray)
{
	this->clear();

	while (this->mArraySize < otherArray.mArraySize)
		this->expandArray();

	for (this->numIndexesFilled = 0; this->numIndexesFilled < otherArray.numIndexesFilled; numIndexesFilled++)
		this->mData[numIndexesFilled] = otherArray.mData[numIndexesFilled];

	return *this;
}


/*********************************************************************************************
* Purpose:  Compare arrays
*     Pre:  Arrays must be initialized
*	 Post:    Returns true if equal, false if not
*********************************************************************************************/
template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& otherArray) const
{
	if (this->numIndexesFilled != otherArray.numIndexesFilled)
		return false;

	for (int i = 0; i < numIndexesFilled; i++)
	{
		if (this->mData[i] != otherArray.mData[i])
			return false;
	}

	return true;
}


/*********************************************************************************************
* Purpose:  Get item at index
*     Pre:  Initialized array
*	 Post: Return the item at the index. Throws exception (std::out_of_range) if out of range.
*********************************************************************************************/
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= numIndexesFilled)
		throw std::out_of_range("DynamicArray<T> access out of range");

	return mData[index];
}


/*********************************************************************************************
* Purpose:  Get item at index
*     Pre:  Initialized array
*	 Post: Return the item at the index. Throws exception (std::out_of_range) if out of range.
*********************************************************************************************/
template <typename T>
T DynamicArray<T>::operator[](int index) const
{
	if (index < 0 || index >= numIndexesFilled)
		throw std::out_of_range("DynamicArray<T> access out of range");

	return mData[index];
}


#endif
