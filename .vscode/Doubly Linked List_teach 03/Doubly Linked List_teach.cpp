#include "13104.h"
#include <algorithm>

void DoublyLinkedList::Insert(string str)
{
    Node *n = new Node(str);
    if (IsEmpty())
        head = tail = n;
    else
    {
        Node *tmp;
        for (tmp = head; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->data.length() > str.length())
            {
                if (tmp == head)
                {
                    head->prev = n;
                    n->next = head;
                    head = n;
                }
                else
                {
                    n->prev = tmp->prev;
                    n->next = tmp;
                    tmp->prev->next = n;
                    tmp->prev = n;
                }
                return;
            }
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
        return;
    }
}

void DoublyLinkedList::Delete(string str)
{
    Node *del = Find(str);
    if (del == nullptr)
        return;

    if (del == head && del == tail)
    {
        head = tail = nullptr;
        free(del);
    }
    else if (del == head)
    {
        head = head->next;
        head->prev = nullptr;
        free(del);
    }
    else if (del == tail)
    {
        tail = tail->prev;
        tail->next = nullptr;
        free(del);
    }
    else
    {
        del->prev->next = del->next;
        del->next->prev = del->prev;
    }
}

Node *DoublyLinkedList::Find(string str)
{
    Node *tmp;
    for (tmp = head; tmp != nullptr; tmp = tmp->next)
    {
        if (tmp->data == str)
            break;
    }
    return tmp;
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
int main()
{
    DoublyLinkedList list;

    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "insert")
        {
            string str;
            cin >> str;
            list.Insert(str);
        }
        else if (cmd == "delete")
        {
            string str;
            cin >> str;
            list.Delete(str);
        }
        else if (cmd == "find")
        {
            string str;
            cin >> str;
            Node *f = list.Find(str);
            if (f != nullptr)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (cmd == "print")
        {
            list.TraversalInOrder();
        }
        else if (cmd == "reverse")
        {
            list.TraversalInReverse();
        }

        /*
        else if (cmd == "ispalindrome")
        {
            if (list.IsPalindrome())
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        */
    }

    return 0;
}