// ============================================================================ 
// UBHeap.cpp
// ~~~~~~~~~~
// James Droste <james@droste.im>
// - implement the UBHeap interface
// ============================================================================ 

#include <cstddef> // this header defines NULL
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "UBHeap.h"

using namespace std; // BAD PRACTICE

// PUBLIC
UBHeap::UBHeap(const vector<int>& a)
{
    for ( size_t i=0; i < a.size(); i ++ ) {
        heap_.push_back(a[i]);
    }

    heapify();
}

UBHeap& UBHeap::operator=(const UBHeap& theOther)
{
    heap_ = theOther.heap_;

    return *this;
}

string UBHeap::toString()
{
    ostringstream oss;

    for ( size_t i=0; i < heap_.size(); i++ ) {
        oss << heap_[i] << " ";
    }

    return oss.str();
}

void UBHeap::push(int a)
{
    heap_.push_back(a);
    heapify();
}

void UBHeap::pop()
{
    if ( empty() ) throw runtime_error("Heap is empty");

    heap_.erase(heap_.begin());
    heapify();
}

int UBHeap::top()
{
    if ( empty() ) throw runtime_error("Heap is empty");

    return heap_[0];
}

bool UBHeap::empty()
{
    return heap_.empty();
}

// PRIVATE
void UBHeap::heapify()
{
    if ( empty() ) return;

    for (int i=heap_.size()/2; i >= 0; i--) {
        sink(i);
    }
}

void UBHeap::sink(size_t i)
{
    if ( i > heap_.size() ) return;
    size_t left, right, my_pick, size;

    size = heap_.size();

    while ((left = 2*i+1) < size) {
        right = left + 1;
        
        my_pick = right >= size ? left : (heap_[right] > heap_[left] ? right : left);

        if (heap_[i] >= heap_[my_pick]) break;

        swap(heap_[i], heap_[my_pick]);

        i = my_pick;
    }
}

void UBHeap::floatUp(size_t i)
{
    if ( i > heap_.size() ) return;
    size_t left, right, my_pick, size;

    size = heap_.size();

    while ((left = 2*i+1) < size) {
        right = left + 1;
        
        my_pick = right >= size ? left : (heap_[right] < heap_[left] ? right : left);

        if (heap_[i] >= heap_[my_pick]) break;

        swap(heap_[i], heap_[my_pick]);

        i = my_pick;
    }
}
