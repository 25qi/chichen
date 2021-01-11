#include <iostream>

using namespace std;

class Node
{
public:
    Node(int d) : data(d), left(nullptr), right(nullptr), parent(nullptr) {}

    int data;
    Node *left, *right, *parent;
};

class BinarySearchTree
{
public:
    BinarySearchTree() : root(nullptr) {}

    void Insert(int i);
    // void Delete(int i); // too hard to implement
    Node *FindNode(int i);
    Node *FindMinNode(Node *r);
    Node *FindMaxNode(Node *r);
    void LevelOrderTraversal(Node *r);

    // No need implment
    void InOrderTraversal(Node *r)
    {
        if (r == nullptr)
            return;

        InOrderTraversal(r->left);
        cout << r->data << endl;
        InOrderTraversal(r->right);
    }

    Node *root;
};

/* function.cpp */
/*
#include "function.h"
#include <vector>

void BinarySearchTree::Insert(int i){
    
}

Node *BinarySearchTree::FindNode(int i){
    
}

Node *BinarySearchTree::FindMinNode(Node *r){

}

Node *BinarySearchTree::FindMaxNode(Node *r){

}

void BinarySearchTree::LevelOrderTraversal(Node *r){
    
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
