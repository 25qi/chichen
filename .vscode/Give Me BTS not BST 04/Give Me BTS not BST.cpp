#include "13105.h"
#include <vector>

void BinarySearchTree::Insert(int i)
{
    Node *n = new Node(i);
    Node *tmp = root, *tmp_prev = nullptr;
    if (root == nullptr)
    {
        root = n;
        return;
    }

    bool isLeft = false;s
    while (tmp != nullptr)
    {
        tmp_prev = tmp;
        if (i < tmp->data)
        {
            tmp = tmp->left;
            isLeft = true;
        }
        else if (i > tmp->data)
        {
            tmp = tmp->right;
            isLeft = false;
        }
        else
        {
            free(n);
            return;
        }
    }

    n->parent = tmp_prev;
    if (isLeft)
        tmp_prev->left = n;
    else
        tmp_prev->right = n;
}

Node *BinarySearchTree::FindNode(int i)
{
    Node *tmp = root;
    while (tmp != nullptr)
    {
        if (i < tmp->data)
            tmp = tmp->left;
        else if (i > tmp->data)
            tmp = tmp->right;
        else
            return tmp;
    }
    return nullptr;
}

Node *BinarySearchTree::FindMinNode(Node *r)
{
    if (r == nullptr)
        return nullptr;

    Node *n = r;
    while (n->left != nullptr)
        n = n->left;
    return n;
}

Node *BinarySearchTree::FindMaxNode(Node *r)
{
    if (r == nullptr)
        return nullptr;

    Node *n = r;
    while (n->right != nullptr)
        n = n->right;
    return n;
}

void BinarySearchTree::LevelOrderTraversal(Node *r)
{
    if (r == nullptr)
        return;

    vector<Node *> v;
    v.push_back(r);
    while (!v.empty())
    {
        cout << v.front()->data << endl;
        if (v.front()->left != NULL)
            v.push_back(v.front()->left);

        if (v.front()->right != NULL)
            v.push_back(v.front()->right);

        v.erase(v.begin());
    }
}

/*
void BinarySearchTree::Delete(int i)
{
    Node *del = FindNode(i);
    if (del == nullptr)
        return;

    if (del->left == nullptr || del->right == nullptr) // Has no any childNode
    {
        Node *child = (del->left != nullptr) ? del->left : del->right;

        if (del == root)
            root = child;
        else
        {
            if (del == del->parent->left)
                del->parent->left = child;
            else
                del->parent->right = child;
        }

        if (child != nullptr)
            child->parent = del->parent;

        free(del);
    }
    else // if (del->left && del->right) // Has both leftChildNode & rightChildNode
    {
        Node *origin = del;
        del = FindMinNode(del->right); // or del = FindMaxNode(del->left);
        int d = del->data;
        Delete(d); // // Since del is either 1.Has one rightChildNode 2.Has No any childNodes, it won't fall into infintie loop
        origin->data = d;
    }
}
*/

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
