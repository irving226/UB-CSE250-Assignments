// ============================================================================
// BinaryTree.cpp
// ~~~~~~~~~~~~~~
// hqn & James Droste <james@droste.im>
// - Implementation of a Very Basic Binary Tree Class
// - Illustration of how to use deque
// - Common traversal order
// ============================================================================

#include <algorithm> // for sort()
#include <stdexcept>
#include <deque>
#include <map>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "BinaryTree.h"
#include "term_control.h"

using namespace std; // BAD PRACTICE

BinaryTree::BinaryTree()
{
    root_ = NULL;
}

BinaryTree::BinaryTree(vector<string>& a, vector<string>& b)
{
    root_ = NULL;
    setTree(a, b);
}

BinaryTree::~BinaryTree()
{
    clearTree(root_);
    root_ = NULL;
}

void BinaryTree::clearTree(Node* node) 
{
    if (node != NULL) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}


bool BinaryTree::isEmpty() const
{
    return root_ == NULL;
}

string BinaryTree::levelOrderSequence()
{
    ostringstream oss;
    if (root_ != NULL) {
        deque<Node*> nodeQ;
        nodeQ.push_front(root_);
        while (!nodeQ.empty()) {
            Node* cur = nodeQ.back();
            nodeQ.pop_back();
            if (cur->left != NULL) 
                nodeQ.push_front(cur->left);
            if (cur->right != NULL) 
                nodeQ.push_front(cur->right);
            oss << cur->payload << " ";
        }
    }
    return oss.str();
}

string BinaryTree::inOrderSequence()
{
    return inOrderSequence(root_);
}

string BinaryTree::preOrderSequence()
{
    return preOrderSequence(root_);
}

string BinaryTree::postOrderSequence()
{
    return postOrderSequence(root_);
}

string BinaryTree::inOrderSequence(Node* node) 
{
    ostringstream oss;
    if (node != NULL) {
        oss << inOrderSequence(node->left) 
            << node->payload << " "
            << inOrderSequence(node->right);
    }
    return oss.str();
}

string BinaryTree::postOrderSequence(Node* node) 
{
    ostringstream oss;
    if (node != NULL) {
        oss << postOrderSequence(node->left)
            << postOrderSequence(node->right)
            << node->payload << " ";
    }
    return oss.str();
}

string BinaryTree::preOrderSequence(Node* node) 
{
    ostringstream oss;
    if (node != NULL) {
        oss << node->payload << " "
            << preOrderSequence(node->left)
            << preOrderSequence(node->right);
    }
    return oss.str();
}

bool BinaryTree::setTree(vector<string>& a, vector<string>& b)
{
    if (!isPermutation(a,b))
        return false;
    this->~BinaryTree();
    root_ = constructTree(a, 0, b, 0, a.size());
    return true;
}

BinaryTree::Node* BinaryTree::constructTree(
        vector<string>& a, size_t a_start, 
        vector<string>& b, size_t b_start, 
        size_t len)
{
    if (len == 0) 
        return NULL;

    Node* node = new Node(a[a_start]); // root_ of new tree

    size_t i;
    for (i=0; i<len; i++) {
        if (b[b_start+i].compare(a[a_start]) == 0) 
            break;
    }

    node->left  = constructTree(a, a_start+1, b, b_start, i);
    node->right = constructTree(a, a_start+i+1, b, b_start+i+1, len-i-1);

    return node;
}

bool BinaryTree::isPermutation(vector<string> a, vector<string> b) 
{
    if (a.size() != b.size()) 
        return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (size_t i=0; i<a.size(); i++)
        if (a[i].compare(b[i]) != 0) 
            return false;

    return true;
}

// Use: Level-Order
string BinaryTree::vertical()
{
    ostringstream oss;
    bool running = true;
    
    Node* left  = _root->left;
    Node* right = _root->right;
    
    while ( running ) {
        if ( left != NULL ) {
            oss << "LEFT: " << left->payload;
        }
        
        if ( right != NULL ) {
            oss << "RIGHT: " << right->payload;
        }
    }
    
    return oss.str();
}

// Use: ??
string BinaryTree::horizontal()
{
    // TODO: YOUR CODE GOES HERE
    ostringstream oss;
    oss << "HORIZONTAL TREE" << endl;
    return oss.str();
}

// Use: Pre-Order
string BinaryTree::symmetric()
{
    // TODO: YOUR CODE GOES HERE
    ostringstream oss;
    oss << "BEAUTIFUL TREE" << endl;
    return oss.str();
}
