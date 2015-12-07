#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

template <typename T>
class DynamicArray
{
	private:
		const int GROW_SHRINK_SIZE = 5;

		T *mData;
		int mArraySize, numIndexesFilled;
		
		void copyArray(const T* array1, T* array2, int size1, int size2);
		void contractArray();
		void expandArray();

	public:
		DynamicArray();
		DynamicArray(int size);
		~DynamicArray();
		
		int count() const;

		void clear();
		void insert(const T& item);
		bool remove(const T& item);
		bool removeAt(int index);

		DynamicArray<T> operator= (DynamicArray<T>& otherArray);
		DynamicArray<T> operator= (const DynamicArray<T>& otherArray);
		bool operator== (DynamicArray<T>& otherArray);
		T& operator[] (int index);
};


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
template <typename T>
void DynamicArray<T>::copyArray(const T* array1, T* array2, int size1, int size2)
{
	if (size2 < size1)
		size1 = size2;

	int i;
	for (i = 0; i < size1; i++)
		array2[i] = array1[i];

	for (; i < size2; i++)
		array2[i] = T();
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
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
* Purpose:
*     Pre:
*	 Post:
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
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
template <typename T>
DynamicArray<T>::DynamicArray()
{
	mData = new T[GROW_SHRINK_SIZE];

	mArraySize = GROW_SHRINK_SIZE;
	numIndexesFilled = 0;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
template <typename T>
DynamicArray<T>::DynamicArray(int size)
{
	mData = new T[size];

	mArraySize = size;
	numIndexesFilled = 0;
}


/*********************************************************************************************
* Purpose: 
*     Pre: 
*	 Post: 
*********************************************************************************************/
template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] mData;
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
template <typename T>
int DynamicArray<T>::count() const
{
	return numIndexesFilled;
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
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
* Purpose: 
*     Pre: 
*	 Post: 
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
* Purpose: 
*     Pre: 
*	 Post: 
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
* Purpose: 
*     Pre: 
*	 Post: 
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
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
template <typename T>
DynamicArray<T> DynamicArray<T>::operator= (DynamicArray<T>& otherArray)
{
	this->clear();

	while (this->mArraySize < otherArray.mArraySize)
		this->expandArray();

	for (this->numIndexesFilled = 0; i < otherArray.numIndexesFilled; numIndexesFilled++)
		this->mData[i] = otherArray.mData[i];
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
template <typename T>
DynamicArray<T> DynamicArray<T>::operator= (const DynamicArray<T>& otherArray)
{
	this->clear();

	while (this->mArraySize < otherArray.mArraySize)
		this->expandArray();

	for (this->numIndexesFilled = 0; i < otherArray.numIndexesFilled; numIndexesFilled++)
		this->mData[i] = otherArray.mData[i];
}


/*********************************************************************************************
* Purpose:
*     Pre:
*	 Post:
*********************************************************************************************/
template <typename T>
bool DynamicArray<T>::operator== (DynamicArray<T>& otherArray)
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
* Purpose: 
*     Pre: 
*	 Post: Return the item at the index. Throws exception (std::out_of_range) if out of range.
*********************************************************************************************/
template <typename T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index >= numIndexesFilled)
		throw std::out_of_range("DynamicArray<T> access out of range");

	return mData[index];
}

#endif