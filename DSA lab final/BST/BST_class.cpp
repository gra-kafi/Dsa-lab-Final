#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Search Tree Class
class BST {
public:
    Node* root;

    // Constructor to initialize an empty tree
    BST() {
        root = nullptr;
    }

    // Function declarations
    Node* insert(Node* node, int value);
    Node* search(Node* node, int value);
    Node* deleteNode(Node* node, int value);
    Node* findMin(Node* node);
    Node* findMax(Node* node);

    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
};

// Insert function for the Binary Search Tree
Node* BST::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);  // If the tree is empty, create a new node
    }

    if (value < node->data) {
        node->left = insert(node->left, value);  // Insert in the left subtree
    } else {
        node->right = insert(node->right, value);  // Insert in the right subtree
    }

    return node;  // Return the updated root
}

// Search function to find a value in the BST
Node* BST::search(Node* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;  // Return the node if found or if the tree is empty
    }

    if (value < node->data) {
        return search(node->left, value);  // Search in the left subtree
    } else {
        return search(node->right, value);  // Search in the right subtree
    }
}

// Function to find the minimum node in a tree (used in deletion)
Node* BST::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;  // Go as far left as possible
    }
    return node;
}

// Delete function to remove a node from the BST
Node* BST::deleteNode(Node* node, int value) {
    if (node == nullptr) {
        return node;  // Base case: If the tree is empty
    }

    if (value < node->data) {
        node->left = deleteNode(node->left, value);  // Search in the left subtree
    } else if (value > node->data) {
        node->right = deleteNode(node->right, value);  // Search in the right subtree
    } else {
        // Node found; handle the 3 deletion cases

        // Case 1: Node with only one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 2: Node with two children
        Node* temp = findMin(node->right);  // Find the in-order successor
        node->data = temp->data;  // Replace the data with the successor
        node->right = deleteNode(node->right, temp->data);  // Delete the successor
    }

    return node;
}

// In-order traversal: Left, Root, Right
void BST::inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

// Pre-order traversal: Root, Left, Right
void BST::preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// Post-order traversal: Left, Right, Root
void BST::postOrder(Node* node) {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

// Function to find the maximum node in a tree
Node* BST::findMax(Node* node) {
    while (node->right != nullptr) {
        node = node->right;  // Go as far right as possible
    }
    return node;
}

int main() {
    BST tree;  // Create an instance of the BST

    // Insert values into the tree
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);

    // Perform in-order traversal
    cout << "In-order Traversal: ";
    tree.inOrder(tree.root);  // Output: 20 30 40 50 60 70 80
    cout << endl;

    // Perform pre-order traversal
    cout << "Pre-order Traversal: ";
    tree.preOrder(tree.root);  // Output: 50 30 20 40 70 60 80
    cout << endl;

    // Perform post-order traversal
    cout << "Post-order Traversal: ";
    tree.postOrder(tree.root);  // Output: 20 40 30 60 80 70 50
    cout << endl;

    // Search for a node
    Node* searchResult = tree.search(tree.root, 40);
    if (searchResult != nullptr) {
        cout << "Node 40 found in the tree.\n";
    } else {
        cout << "Node 40 not found in the tree.\n";
    }

    // Find minimum and maximum nodes
    cout << "Minimum value in the tree: " << tree.findMin(tree.root)->data << endl;
    cout << "Maximum value in the tree: " << tree.findMax(tree.root)->data << endl;

    // Delete a node and perform in-order traversal again
    tree.root = tree.deleteNode(tree.root, 50);
    cout << "In-order Traversal after deleting 50: ";
    tree.inOrder(tree.root);  // Output: 20 30 40 60 70 80
    cout << endl;

    return 0;
}
