#include "IntegerArray.h"
#include <iostream>

IntegerArray::IntegerArray(int len) : _len{ len }
{
	try 
	{
		if (len<=0) throw BadLength(len);
		data = new int[len] {0}; 
	}
	catch (BadLength& bad_length) { bad_length.what(); }
};

int IntegerArray::getSize()
{
	return _len;
}

int* IntegerArray::copy()
{
	int* data_tmp = new int[this->_len] {0};
	for (int i = 0; i < this->_len; i++) data_tmp[i] = this->data[i];
	return data_tmp;
}

int IntegerArray::find(int idx)
{
	return this->data[idx];
}

void IntegerArray::insert(int x, int newLen)
{
	
	try
	{
		if (newLen < 0) throw BadRange(newLen);
		int* data_tmp = new int[this->_len + newLen]{ 0 };
		for (int i = 0; i < this->_len; i++) data_tmp[i] = this->data[i];
		for (int i = this->_len; i < this->_len + newLen; i++) data_tmp[i] = x;

		this->data = data_tmp;
		this->_len = this->getSize() + newLen;
	}
	catch (BadRange bad_range) { bad_range.what(); }

}

void IntegerArray::remove(int newLen)
{
	try
	{
		if (newLen < 0) throw BadRange(newLen);
		int* data_tmp = new int[this->_len - newLen] {0};

		for (int i = 0; i < this->_len - newLen; i++) data_tmp[i] = this->data[i];

		this->data = data_tmp;
		this->_len = this->getSize() - newLen;
	}
	catch (BadRange bad_range) { bad_range.what(); }

}

void IntegerArray::changeSize(int len)
{
	if (len < this->_len) this->remove(len);
	else this->insert(len);
}

IntegerArray::~IntegerArray()
{
	delete[] data;
}

//=============================

BadLength::BadLength(int len) : _len(len) {}

void BadLength::what() { std::cout << "Неправильный размер контейнера" << std::endl; }

//=============================

BadRange::BadRange(int len) : _len(len) {}

void BadRange::what() { std::cout << "выход за пределы размера контейнера" << std::endl; }

