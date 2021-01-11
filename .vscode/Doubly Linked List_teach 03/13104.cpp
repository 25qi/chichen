#include "13104.h"

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