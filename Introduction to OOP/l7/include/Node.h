#pragma once

class Node {
    /**Single node used by TwoWayList to store data*/
    
    private:
        Node *prev;     //pointer to previous node
        Node *next;     //pointer to next node
        char *data;     //data in format of string from c language
        
    public:
    
        Node *getPrev() const;
        /** Returns pointer to previous Node */
          
        Node *getNext() const;
        /** Returns pointer to next Node */
        
        char *getData() const;
        /** Returns data in cstring format*/
        
        void setPrev(const Node *new_prev);
        /** Sets prev (previous) pointer to new_prev */
        
        void setNext(const Node *new_next);
        /** Sets next pointer to new_next */
        
        void setData(const char *new_data);
        /** Allocates memory for new_data and sets data to new_data */
};
