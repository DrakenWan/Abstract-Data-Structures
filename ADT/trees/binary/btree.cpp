/*
Note: this is not a btree.
binary tree : karry kaul
Maximum nodes at level n is 2^(n-1) if root node is at level 1
maximum nummber of nodes on root to leaf path =  2^(h-1) - 1
where h is height of tree

Maximum number of leaves:
     L <= 2^(l-1)
     l = log2(L) + 1
in a k-ary tree every node has either 0 or k children
L = (k-1)*I + 1
where L is leaf nodes and I is internal nodes

*/

#include<iostream>
#include "../../queue.h"
#define dtype_bt int //the key of the node of the type `dtype_bt`. It is better to use integer keys
// also keep the keys of the data type that can work with relational operators "<, >, >=, <=, =="

using namespace std;

struct node
{
    dtype_bt data;
    node* left;
    node* right;
};

class btree {
    node *root;
    int depth, branching=2;
    
    node* newNode(dtype_bt data)
    {
        node* n = new node;
        n->data = data;

        n->left= NULL;
        n->right= NULL;
        return n;
    }

    void insert(dtype_bt key, node* root);

    // traversals for displaying the tree
    void preorder(node*);
    void inorder(node*);
    void postorder(node*);
    void levelorder(node*, queue<node*>);
    void levelorder_helper(node*);

    public:

    btree() {
        this->root = NULL;
    }

    btree(dtype_bt data) {
        this->root = this->newNode(data);
    }

    
    void insert(dtype_bt key);
    int _branching_() {return this->branching;}
    //node* _root_() {return this->root;} //this is a threat to the tree as we are using pointers.

    void display(int);
};


void btree::insert(dtype_bt key) {
    /*
        Function for insertion
        accessible by user
    */
    if(this->root != NULL)
        insert(key, this->root);
    else 
        this->root = this->newNode(key);
} //user accessible insert method

void btree::insert(dtype_bt key, node *root){
    /*
        private insertion function    
    */

    if(key < root->data) {

        if(root->left != NULL)
            insert(key, root->left);
        else
            root->left = this->newNode(key);
    }
    else {
        if(root->right != NULL)
            insert(key, root->right);
        else
            root->right = this->newNode(key);
    }
} // private insert method

void btree::display(int choice=1) {
    /*
        Function to display contents of
        tree.

        uses inorder traversal by default
    
    */
    switch(choice) {
        case 0 :
            this->preorder(this->root);
            break;
        case 1 :
            this->inorder(this->root);
            break;
        case 2 :
            this->postorder(this->root);
            break;
        case 3 :
            this->levelorder_helper(this->root);
            break;
        default :
            cout<<"Wrong choice selected. select from 0,1,2.";
    }
}

void btree::levelorder_helper(node* root) {
    if(root != NULL) {
        queue<node*> q;
        q.enqueue(root);
        this->levelorder(root, q);
    } else {
        cout<<"Null tree.";
    }
}

void btree::levelorder(node *root, queue<node*> q) {
    
    while(!q.isEmpty()) {
        node* NODE  = q.dequeue();
        if(NODE != NULL) {
            cout<<NODE->data<<" ";
            q.enqueue(NODE->left);
            q.enqueue(NODE->right);
        }
    }
}

void btree::inorder(node *root) {
    if(root != NULL) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void btree::preorder(node *root) {
    if(root != NULL) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void btree::postorder(node *root) {
    if(root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int main()
{   
    btree buddy;
    
    buddy.insert(50);
    buddy.insert(23);
    buddy.insert(12);
    buddy.insert(53);
    buddy.insert(66);
    buddy.insert(78);
    buddy.display(3); //in order traversal.
    return 0;
}