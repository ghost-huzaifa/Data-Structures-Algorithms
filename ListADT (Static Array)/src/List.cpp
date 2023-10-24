#include <iostream>
#include "List.h"

using namespace std;

template <class T>
List<T>::List()    //Default Constructor
{
    size = 0;
}

template <class T>
List<T>::~List()   //Destructor
{
    /*Memory of List is freed automatically
    because it is a list with static array*/
}

template <class T>
List<T>::List(const List& other)   //Copy Constructor
{
    if (!other.empty())
    {
        size = other.length();

        for (int i = 0; i < size; i++)
        {
            head[i] = other.head[i];
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
        return head[0];
}

template <class T>
void List<T>::addHead(T newdata)    //Adds the element at head of list
{
    for (int i = size - 1; i >= 0; i--)
    {
        head[i + 1] = head[i];
    }
    head[0] = newdata;
    size++;
}

template <class T>
void List<T>::delHead()    //Overwrites the value of head to delete it
{
    if (empty())
        cout << "There is no element in list to remove! " << endl;
    else
    {
        for (int i = 0; i < size -1 ; i++)
        {
            head[i] = head[i+1];
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
            cout << head[i] << " ";
        }
        cout << "]" << endl;
    }
}
