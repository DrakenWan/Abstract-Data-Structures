//binary tree : karry kaul
//Maximum nodes at level n is 2^(n-1) if root node is at level 1
// maximum nummber of nodes on root to leaf path =  2^(h-1) - 1
// where h is height of tree

//Maximum number of leaves:
//      L <= 2^(l-1)
//      l = log2(L) + 1
// in a k-ary tree every node has either 0 or k children
// L = (k-1)*I + 1
// where L is leaf nodes and I is internal nodes
//
#include<iostream>

struct node
{
    int data;
    node* left;
    node* right;
};

class btree {

}
node* newNode(int data)
{
    node* n = new node;
    n->data = data;

    n->left= NULL;
    n->right= NULL;
    return n;
}

int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left = newNode(4);
    return 0;
}