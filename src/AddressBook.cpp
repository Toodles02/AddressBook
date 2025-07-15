#include "AddressBook.h"

Node::Node(const Contact& c) : value(c), left(nullptr), right(nullptr) {}

Node::~Node() {
    left = nullptr;
    right = nullptr; 
}


AddressBook::AddressBook(const Contact& contact) { 
    root = new Node(contact); 
}

AddressBook::AddressBook() {
    root = nullptr; 
}


void AddressBook::insert(const Contact& contact) {
    root = insert(root, contact); 
}

Node* AddressBook::insert(Node* node, const Contact& contact) {
    if (!node) // If the node is null, assign the node
        return new Node(contact);
    if (contact < node->value)  // If the element is less than current node, go left
        node->left = insert(node->left, contact);
    else
        node->right = insert(node->right, contact); // Otherwise, go right 

    return node; // Update the parent nodes 
}

Contact* AddressBook::search(const std::string& name) const {
    Node* node = search(root, name); 
    return !node ? nullptr : &node->value; // return a nullptr if the node is invalid, or return the node's Contact value 
}

Node* AddressBook::search(Node* node, const std::string& name) const {
    if (!node)
        return nullptr; // Node is not found 

    if (Contact::compare(name, node->value.get_name())) // Node is found, case insensitive
        return node; 
    else if (Contact::str_less(name, node->value.get_name())) // Go left if the name is less than current node
        return search(node->left, name); 
    else
        return search(node->right, name); // Go right otherwise 
}

void AddressBook::remove(const Contact& contact) {
    if (!search(contact.get_name())) 
        throw std::invalid_argument("That contact does not exist!"); 
    root = remove(root, contact); 
}

Node* AddressBook::remove(Node* node, const Contact& contact) {
    if (!node) // Node not found, return
        return node;

    if (contact < node->value) // Go left if the value is less than current node 
        node->left = remove(node->left, contact);
    else if (contact > node->value) // Go right otherwise
        node->right = remove(node->right, contact);
    else { // You've arrived at the value to be deleted 

        if (!node->left && !node->right) { // Node is a leaf, has no subtrees
            delete node; 
            return nullptr; // Return to parent 
        } else if (!node->left) { // No left subtree, but has right subtree
            Node* right = node->right;
            delete node;
            return right; // Return to parent 
        } else if (!node-> right) { // No right subtree, but has left subtree
            Node* left = node->left;
            delete node;
            return left; // Return to parent  
        } else { // Final case: node has both subtrees, so replace with successor
            Node* s = successor(node); 
            node->value = s->value; // Copy successor's value into current node 
            node->right = remove(node->right, s->value); // Remove the successor node in right subtree 
        }
    }

    return node; // Return to parent 
}

Node* AddressBook::successor(Node* node) const {
    if (!node || !node->right) 
        return nullptr; // Node not found, or doesn't have successor

    Node* current = node->right; // Start at right subtree 
    while (current->left) { // Go left while a left node exists
        current = current->left; 
    }

    return current;
}

Node* AddressBook::predecessor(Node* node) const {
    if (!node || !node->left) 
        return nullptr; // Node not found, or doesn't have successor

    Node* current = node->left; // Start at left subtree
    while (current->right) { // Go right while a right node exists
        current = current->right; 
    }

    return current;
}

void AddressBook::delete_tree(Node* node) {
    if (!node) return;
    delete_tree(node->right);
    delete_tree(node->left);
    delete node; 
}

AddressBook::~AddressBook() {
    delete_tree(root); 
}






