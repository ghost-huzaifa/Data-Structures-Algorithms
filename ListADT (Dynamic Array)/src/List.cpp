#include <iostream>
#include "List.h"

using namespace std;

template <class T>
List<T>::List()    //Default Constructor
{
    size = 0;
    list_elements = new T[10];
}

template <class T>
List<T>::~List()   //Destructor
{
    delete(list_elements);
    /*Memory of List is freed by using delete
    because it is a list with dynamic array*/
}

template <class T>
List<T>::List(const List& other)   //Copy Constructor
{
    if (!other.empty())
    {
        size = other.length();
        list_elements = new T[1s0];

        for (int i = 0; i < size; i++)
        {
            list_elements[i] = other.list_elements[i];
        }
    }
}

template <class T>
bool List<T>::empty() const    //Checks if the list is empty
{
    if (size == 0)
        return 1;
    else
        return 0;
}

template <class T>
T List<T>::headElement() const    //Gets the first element of list
{
    if (empty())
        return NULL;
    else
        return list_elements[0];
}

template <class T>
void List<T>::addHead(T newdata)    //Adds the element at list_elements of list
{
    for (int i = size - 1; i >= 0; i--)
    {
        list_elements[i + 1] = list_elements[i];
    }
    list_elements[0] = newdata;
    size++;
}

template <class T>
void List<T>::delHead()    //Overwrites the value of list_elements to delete it
{
    if (empty())
        cout << "There is no element in list to remove! " << endl;
    else
    {
        for (int i = 0; i < size -1 ; i++)
        {
            list_elements[i] = list_elements[i+1];
        }
        size--;
    }
}

template <class T>
int List<T>::length() const    //Get no. of elements in list
{
    return size;
}

template <class T>
void List<T>::print() const
{
    if (empty())
        cout << "The List is empty!" << endl;
    else
    {
        cout << "List = [ ";
        for (int i = 0; i < size; i++)
        {
            cout << list_elements[i] << " ";
        }
        cout << "]" << endl;
    }
}
