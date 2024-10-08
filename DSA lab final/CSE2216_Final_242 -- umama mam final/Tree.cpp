#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int x){
        data = x;
        left = right = nullptr;
    }
};
class BST{
    node *root;
public:
    BST(){
        root = nullptr;
    }
    void Insert(int x){
        node *newnode = new node(x);
        //tree is empty
        if(root == nullptr ){
            root = newnode;
            return;
        }
        node * current = root, *parent = root;
        while ( current != nullptr ){
            parent = current;
            if(x < current->data ) current = current->left;
            else current = current->right;
        }
        if(parent->data > x ){
            parent->left = newnode;
        }else{
            parent->right = newnode;
        }
    }

    void printLeafNodes(){
        //add necessary codes here
        //you may add more functions inside the class if you want
        cout<<"Leaf nodes:";
    }

};
int main(){
    //insert the elements in the tree:
    //18, 9, 30, 25, 12, 10, 48, 40.
    BST bst;

    bst.Insert(18);
    bst.Insert(9);
    bst.Insert(30);
    bst.Insert(25);
    bst.Insert(12);
    bst.Insert(10);
    bst.Insert(48);
    bst.Insert(40);

    bst.printLeafNodes();


}

