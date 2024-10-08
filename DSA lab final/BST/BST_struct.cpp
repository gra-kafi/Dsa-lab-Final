#include <iostream>
using namespace std;

// Define the structure of a tree node
struct Node {
    int data;         // Data value stored in the node
    Node* left;       // Pointer to the left child
    Node* right;      // Pointer to the right child
    
    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a new node in a Binary Search Tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {  // If the tree is empty, create a new node
        return new Node(value);
    }
    
    // If the value is less than the root, insert in the left subtree
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    // If the value is greater, insert in the right subtree
    else {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// In-order Traversal: Left -> Root -> Right
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);      // Visit left subtree
        cout << root->data << " ";  // Visit node
        inOrder(root->right);     // Visit right subtree
    }
}

// Pre-order Traversal: Root -> Left -> Right
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit node
        preOrder(root->left);      // Visit left subtree
        preOrder(root->right);     // Visit right subtree
    }
}

// Post-order Traversal: Left -> Right -> Root
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);     // Visit left subtree
        postOrder(root->right);    // Visit right subtree
        cout << root->data << " ";  // Visit node
    }
}

// Function to search for a node in a BST
Node* search(Node* root, int value) {
    if (root == nullptr || root->data == value) {
        return root;  // Return the node if found or if tree is empty
    }
    
    // Search in the left or right subtree based on value
    if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

int main() {
    Node* root = nullptr;  // Initialize the tree as empty

    // Insert values into the tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Traverse the tree
    cout << "In-order Traversal: ";
    inOrder(root);  // Output: 20 30 40 50 60 70 80
    cout << endl;

    cout << "Pre-order Traversal: ";
    preOrder(root);  // Output: 50 30 20 40 70 60 80
    cout << endl;

    cout << "Post-order Traversal: ";
    postOrder(root);  // Output: 20 40 30 60 80 70 50
    cout << endl;

    // Search for a value in the tree
    int searchValue = 40;
    Node* foundNode = search(root, searchValue);
    if (foundNode != nullptr) {
        cout << "Node with value " << searchValue << " found in the tree.\n";
    } else {
        cout << "Node with value " << searchValue << " not found in the tree.\n";
    }

    return 0;
}
