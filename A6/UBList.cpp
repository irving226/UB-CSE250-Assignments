// ============================================================================ 
// UBList.cpp
// ~~~~~~~~~~
// James Droste <james@droste.im>
// - implement the UBList interface
// ============================================================================ 

#include <cstddef> // this header defines NULL
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "UBList.h"

using namespace std; // BAD PRACTICE

// ============================================================================ 
// DO NOT MODIFY THIS SECTION
// ============================================================================ 
UBList::UBList(Node* h, size_t n) : head(h), numNodes(n)
{
}

UBList::UBList(const UBList& theOther)
{
    Node* cur;
    head = NULL;
    numNodes = 0;
    Node* ptr = theOther.head;
    while (ptr != NULL) {
        numNodes++;
        if (head == NULL) {
            cur = head = new Node(ptr->key);
        } else {
            cur->next = new Node(ptr->key);
            cur = cur->next;
        }
        ptr = ptr->next;
    }
}

void UBList::swap(UBList& theOther)
{
    std::swap(numNodes, theOther.numNodes);
    std::swap(head, theOther.head);
}

UBList& UBList::operator=(const UBList& theOther)
{
    UBList temp(theOther); // deep copy
    swap(temp);
    return *this;
}

UBList::~UBList() 
{
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;        
        delete temp;
    }
}

void UBList::insert(int x)
{
    head = new Node(x, head);
    numNodes++;
}

string UBList::toString()
{
    ostringstream oss;
    oss << "[" << numNodes << " NODES] : ";
    Node* ptr = head;
    while (ptr != NULL) {
        oss << ptr->key << " ";
        ptr = ptr->next;
    }
    return oss.str();
}

bool UBList::isSorted()
{
    for (Node* ptr = head; ptr != NULL && ptr->next != NULL; ptr = ptr->next)
        if (ptr->key > ptr->next->key) 
            return false;
    return true;
}

// ============================================================================ 
// START MODIFYING FROM HERE. DO NOT ADD ANY HELPER FUNCTION, JUST IMPLEMENT
// THE FUNCTIONS THAT HAVE TODO: YOUR CODE GOES HERE IN THEM
// ============================================================================ 
void UBList::merge(UBList& theOther)
{
    if (!this->isSorted() || !theOther.isSorted())
        throw runtime_error("Give give me sorted lists to merge");
        
    // Pointers OH MY!
    Node* a = head;
    Node* b = theOther.head;
    
    // Head stuff
    if ( a->key > b->key ) {
        head = b;
        b = b->next;
    } else {
        a = a->next;
    }
    
    // Merge the rest
    for ( 
        Node* ptr = head; 
        ptr != NULL && !(a == NULL && b == NULL); 
        ptr = ptr->next 
    ) {
        if ( a == NULL && b != NULL ) {
            ptr->next = b;
            b = b->next;
        } else if ( a != NULL && b == NULL ) {
            ptr->next = a;
            a = a->next;
        } else if ( a->key > b->key ) {
            ptr->next = b;
            b = b->next;
        } else {
            ptr->next = a;
            a = a->next;
        }
    }
    
    // Update our head/nodes
    numNodes = numNodes + theOther.numNodes;
    
    // Update the other head/nodes
    theOther.head = NULL;
    theOther.numNodes = 0;
}

void UBList::remove(int x)
{
    Node* prevPtr = NULL;
    
    for ( Node* ptr = head; ptr != NULL; ptr = ptr->next ) {
        if ( ptr->key == x ) {
            // Change the head
            if ( prevPtr == NULL ) {
                head = ptr->next;
            } else {
                prevPtr->next = ptr->next;
            }
            
            // Actually delete pointer + deinc
            delete ptr;
            numNodes--;
        } else {
            prevPtr = ptr;
        }
    }
}

void UBList::sort()
{
    if ( numNodes == 0 || numNodes == 1 ) return;
    
    // Get the middle
    size_t m = (numNodes/2);
    Node* mid = head;
    Node* mid_prev = head;
    for ( size_t i=0; i < m; i++ ) {
        mid_prev = mid;
        mid = mid->next;
    }
    mid_prev->next = NULL; // Break the heads
    
    // Create left + right
    UBList left(head, m);
    UBList right(mid, numNodes-m);
    
    // Sort
    left.sort();
    right.sort();
    
    // Actually sort
    // Left
    Node* newLeftHead = left.head;
    for ( size_t i=0; i < left.numNodes; i++ ) {
        Node* prev = newLeftHead;
        Node* ptr = prev->next;
        
        for ( size_t j=1; j < left.numNodes; j++ ) {            
            if ( prev->key > ptr->key ) {
                Node* tmp = prev;
                
                prev = ptr;
                ptr->next = tmp;
            }
            
            prev = ptr;
            ptr = ptr->next;
        }
    }
    left.head = newLeftHead;
    
    // Right
    Node* newRightHead = right.head;
    for ( size_t i=0; i < right.numNodes; i++ ) {
        Node* prev = newRightHead;
        Node* ptr = prev->next;
        
        for ( size_t j=1; j < right.numNodes; j++ ) {
            if ( prev->key > ptr->key ) {
                Node* tmp = prev;
                
                prev = ptr;
                ptr->next = tmp;
            }
            
            prev = ptr;
            ptr = ptr->next;
        }
    }
    right.head = newRightHead;
    
    // Merge
    left.merge(right);
    
    // Reset + Swap
    head = NULL;
    numNodes = 0;
    swap(left);
}
