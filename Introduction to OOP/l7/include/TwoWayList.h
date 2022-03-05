#pragma once
#include "Node.h"

class TwoWayList {
    /** double-linked list */

    private:
        Node *head;     //contains 1st element in list or nullptr if list is empty
        Node *tail;     //contains last element in list or nullptr if list is empty
    
    public:
        void prepare();
        /** sets head and tail to nullptr. It is required to use this method
            before calling any other method on an object. Behaviour of other methods
            is undefined if .prepare() has not been used*/
    
        void prepend(const char *data);
        /** adds data at the beginning of the list */
    
        void append(const char *data);
        /** adds data at the end of the list */
    
        bool empty() const;
        /** Returns true if list is empty and false otherwise */
    
        void dump() const;
        /** Prints entire list starting from first element */
    
        void dumpBack() const;
        /** Prints enitre list starting from last element */
    
        void clear();
        /** deletes all items stored in list and frees memory used by the list.
            This method should be called on every TwoWayList that had any data appended
            before object disappears */
    
        Node *getHead() const;
        /** Returns pointer to first node in list or nullptr if list is empty */
    
        Node *getTail() const;
        /** Returns pointer to last node in list or nullptr if list is empty */
};
