#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    Node(string str) : data(str), next(nullptr), prev(nullptr) {}

    string data;
    Node *next, *prev;
};

class DoublyLinkedList
{
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void Insert(string str);
    void Delete(string str);
    Node *Find(string str);
    /*
    bool IsPalindrome();
    string StringInOrder();
    string StringInReverse();
    */

    // No need implement
    void TraversalInOrder()
    {
        if (!IsEmpty())
        {
            Node *tmp;
            for (tmp = head; tmp->next != nullptr; tmp = tmp->next)
            {
                cout << tmp->data << " ";
            }
            cout << tmp->data << endl;
        }
        else
            cout << "/* empty */" << endl;
    }

    void TraversalInReverse()
    {
        if (!IsEmpty())
        {
            Node *tmp;
            for (tmp = tail; tmp->prev != nullptr; tmp = tmp->prev)
            {
                cout << tmp->data << " ";
            }
            cout << tmp->data << endl;
        }
        else
            cout << "/* empty */" << endl;
    }

    bool IsEmpty()
    {
        if (head == nullptr && tail == nullptr)
        {
            return true;
        }
        else
            return false;
    }

    Node *head;
    Node *tail;
};

/* function.cpp */
/*
#include "function.h"
#include <algorithm>

void DoublyLinkedList::Insert(string str){

}

void DoublyLinkedList::Delete(string str){

}

Node *DoublyLinkedList::Find(string str){

}

/* 
bool DoublyLinkedList::IsPalindrome()
{
    if (IsEmpty())
        return false;

    string str = StringInOrder();
    string str_reverse = StringInReverse();
    return str == str_reverse;
}

string DoublyLinkedList::StringInOrder()
{
    string str = "";
    if (!IsEmpty())
    {
        Node *tmp;
        for (tmp = head; tmp != nullptr; tmp = tmp->next)
        {
            str += tmp->data;
        }
    }
    return str;
}

string DoublyLinkedList::StringInReverse()
{
    string str = "";
    if (!IsEmpty())
    {
        Node *tmp;
        for (tmp = tail; tmp != nullptr; tmp = tmp->prev)
        {
            string str_tmp = tmp->data;
            reverse(str_tmp.begin(), str_tmp.end());
            str += str_tmp;
        }
    }
    return str;
}
*/