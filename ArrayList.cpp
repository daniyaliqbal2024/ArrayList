#include "ArrayList.h"
#include <iostream>
#include <string>
using namespace std;


bool ArrayList::isEmpty()
{
	if (size1==0)
		{
		return true;
		}
	return false;
}

int ArrayList::size()
{
	return size1;
}

bool ArrayList::add(string value)
{
	insert(value, size1);
	return true;
}

string ArrayList::get(int atIndex)
{
	if (atIndex > size1)
	{
		return "";
	}
    return storage[atIndex];
}

bool ArrayList::insert(string value, int atIndex)
{
      if (atIndex > size1)
	{
		return false;
	}

     string* x= new string[size1+1];
     for (int i=0; i<size1; i++ )
     {
	 x[i]= storage[i];
     }
     delete[] storage;
     storage= x;
     for (int i= size1-1; i>=atIndex; i--)
     {
    	 storage[i+1]= storage[i];
     }
     storage[atIndex]= value;
     size1= size1 +1;
     return true;
}

string ArrayList::remove(int atIndex)
{
	if (atIndex>= size1)
	{
		return "";
	}
	else
	{
		string x= storage[atIndex];
		for (int i= atIndex; i<size1; i++)
		{
			storage[i]= storage[i+1];
		}
		size1= size1-1;
		return x;
    }
}

void ArrayList::clear()
{
	size1=0;
	for (int i=0; i<size1; i++)
	{
		storage[i]= "";
	}
}

string ArrayList::set(int atIndex, string value)
{
	string x= "";
	if (atIndex<size1)
	{
		x= storage[atIndex];
		storage[atIndex]= value;
		return x;
	}
	else
	{
	return "";
	}
}

bool ArrayList::contains(string value)
{
	for ( int i=0; i< size1; i++)
	{
		if (storage[i] == value)
		{
			return true;
		}
	}
	return false;
}

bool ArrayList::remove(string value)
{

	this -> remove(indexOf(value));
	return true;
}

int ArrayList::indexOf(string value)
{
	for (int i=0; i<size1; i++)
	{
		if (storage[i]== value)
		{
			return i;
		}
	}
	return -1;
}

int ArrayList::lastIndexOf(string value)
{
	for ( int i= size1-1; i>=0 ; i--)
	{
		if (storage[i]== value)
		{
			return i;
		}

	}
	return -1;
}
