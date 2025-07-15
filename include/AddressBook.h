#pragma once

#include "Contact.h"
#include <stdexcept>


/**
 * @struct Node
 * @brief Node to hold Contact in BST 
 * 
 */
struct Node {
    Contact value; 
    Node* left;
    Node* right; 

    Node(const Contact &c);
    ~Node(); 
};

/**
 * @class AddressBook
 * @brief Holds multiple Contact objects in a BST 
 * 
 */
class AddressBook {
    public:

        /**
         * @brief Construct a new Address Book object
         * 
         * @param contact The Contact starting as the root 
         */
        AddressBook(const Contact& contact); 

        /**
         * @brief Construct an empty Address Book object 
         * 
         */
        AddressBook(); 

        /**
         * @brief Add a contact to the Address Book
         * 
         * @param contact The Contact to be added 
         */
        void insert(const Contact& contact); 

        /**
         * @brief Find a contact in the address book by name
         * 
         * @param name A string name of the person to be searched 
         * @return Contact* Returns a pointer to the Contact that is found, nullptr if not found 
         */
        Contact* search(const std::string& name) const;

        /**
         * @brief Removes a contact in the address book
         * 
         * @param contact The Contact to be removed 
         * @throw std::invalid_argument If the Contact is not found
         */
        void remove(const Contact& contact); 
        ~AddressBook();
    private:

        /**
         * @brief The recursive helper function to insert a new Node 
         * 
         * @param node The current Node 
         * @param c The original Contact object to be inserted 
         * @return Node* The next Node 
         */
        Node* insert(Node* node, const Contact& c); 

        /**
         * @brief The recusrive search function to search a Node 
         * 
         * @param node The current Node
         * @param name The name used to search the Nodes
         * @return Node* The next Node
         */
        Node* search(Node* node, const std::string& name) const; 

        /**
         * @brief The recursive remove function to remove a Node
         * 
         * @param node The current Node
         * @param contact The Contact to find the Node to remove 
         * @return Node* The next Node 
         */
        Node* remove(Node* node, const Contact& contact);
        
        /**
         * @brief Finds a Node's predecessor 
         * 
         * @param node The Node to find the predecessor of
         * @return Node* The rightmost Node in the left subtree 
         */
        Node* predecessor(Node* node) const; 

        /**
         * @brief Finds a Node's successor
         *  
         * @param node The Node to find the successor of 
         * @return Node* The leftmost Node in the right subtree 
         */
        Node* successor(Node* node) const; 

        /**
         * @brief Recursive helper function to cleanup memory and delete trees 
         * 
         * @param node The Node to be deleted 
         */
        void delete_tree(Node* node); 

        /**
         * @brief The root node at the top of the BST
         * 
         */
        Node* root;

};

