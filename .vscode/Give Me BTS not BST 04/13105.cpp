#include "13105.h"

int main()
{
    BinarySearchTree bst;

    string cmd;
    while (cin >> cmd)
    {
        if (cmd == "insert")
        {
            int i;
            cin >> i;
            bst.Insert(i);
        }
        else if (cmd == "find")
        {
            int i;
            cin >> i;
            Node *f = bst.FindNode(i);
            if (f != nullptr)
                cout << "true" << endl;
            else
                cout << "false" << endl;
        }
        else if (cmd == "print")
        {
            if (bst.root == nullptr)
                cout << "/* empty */" << endl;
            else
                bst.InOrderTraversal(bst.root);
        }
        else if (cmd == "level")
        {
            if (bst.root == nullptr)
                cout << "/* empty */" << endl;
            else
                bst.LevelOrderTraversal(bst.root);
        }
        else if (cmd == "min")
        {
            if (bst.root == nullptr)
                cout << "/* empty */" << endl;
            else
            {
                Node *tmp = bst.FindMinNode(bst.root);
                cout << "min: " << tmp->data << endl;
            }
        }
        else if (cmd == "max")
        {
            if (bst.root == nullptr)
                cout << "/* empty */" << endl;
            else
            {
                Node *tmp = bst.FindMaxNode(bst.root);
                cout << "max: " << tmp->data << endl;
            }
        }
        /*
        else if (cmd == "delete")
        {
            int i;
            cin >> i;
            bst.Delete(i);
        }
        */
    }
    return 0;
}