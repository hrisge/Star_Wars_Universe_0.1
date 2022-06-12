#pragma once
#include <iostream>

template <typename T>
class MyVector
{
	T* vector;
	unsigned size;
	unsigned capacity;

	void free();
	void copyFrom(const MyVector<T>&);
	void resize();

public:
	MyVector();
	MyVector(const MyVector<T>&);
	MyVector(MyVector<T>&&);
	~MyVector();

	MyVector<T>& operator=(const MyVector<T>&);
	MyVector<T>& operator=(MyVector<T>&&);

	unsigned getSize() const;
	unsigned getCapacity() const;

	void addItem(const T&);
	void removeItem(unsigned);

	const T& getItemAtIndex(unsigned) const;
	const T& operator[](unsigned) const;
	T& operator[](unsigned);
};

template <typename T>
MyVector<T>::MyVector()
{
	vector = nullptr;
	size = 0;
	capacity = 0;
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& other)
{
	copyFrom(other);
}

template <typename T>
MyVector<T>::MyVector(MyVector<T>&& other)
{
	vector = other.vector;
	capacity = other.capacity;
	size = other.capacity;

	other.vector = nullptr;
	other.size = 0;
	other.capacity = 0;
}

template <typename T>
MyVector<T>::~MyVector()
{
	free();
}

template <typename T>
void MyVector<T>::free()
{
	delete[] vector;
	size = 0;
	capacity = 0;
}

template <typename T>
void MyVector<T>::copyFrom(const MyVector<T>& other)
{
	vector = new T[other.getCapacity()];
	capacity = other.getCapacity();
	size = other.getSize();
	for (size_t i = 0; i < size; ++i)
		vector[i] = other[i];
}

template <typename T>
void MyVector<T>::resize()
{
	capacity *= 2;
	T* buff = new T[capacity];
	for (size_t i = 0; i < size; ++i)
		buff[i] = vector[i];
	
	delete[] vector;
	vector = buff;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& other)
{
	if (this != &other)
	{
		delete[] vector;

		vector = other.vector;
		capacity = other.capacity;
		size = other.capacity;

		other.vector = nullptr;
		other.size = 0;
		other.capacity = 0;
	}
	return *this;
}

template <typename T>
unsigned MyVector<T>::getSize() const
{
	return size;
}

template <typename T>
unsigned MyVector<T>::getCapacity() const
{
	return capacity;
}

template <typename T>
void MyVector<T>::addItem(const T& item)
{
	if (getSize() == getCapacity())
		resize();

	vector[getSize()] = item;
	++size;
}

template <typename T>
void MyVector<T>::removeItem(unsigned index)
{
	delete vector[index];
	for (size_t i = index; i < size; ++i)
		vector[i] = vector[i + 1];
	size--;
}

template <typename T>
const T& MyVector<T>::getItemAtIndex(unsigned index) const
{
	return vector[index];
}

template <typename T>
const T& MyVector<T>::operator[](unsigned index) const
{
	return getItemAtIndex(index);
}

template <typename T>
T& MyVector<T>::operator[](unsigned index)
{
	return vector[index];
}