#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"
#include <stdio.h>
template <class T>
class LinkedList
{
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    size = 0;
    /* TODO */
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
 if (obj.isEmpty()) {
        head = NULL;
        this->size = obj.getSize();
    }
    else {
        this->head = NULL;
        this->size =0;
        Node<T> *p = obj.getFirstNode();
        Node<T> *c = this->head;
        while(p->next != obj.getFirstNode()){
            append(p->data);
            p = p->next;
        } 
            append(p->data);
    }
}

template<class T>
LinkedList<T>::~LinkedList()
{
    removeAllNodes();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    /* TODO */
    if(this != &rhs){
        removeAllNodes();
        Node<T> *p = rhs.getFirstNode();
        this->head = NULL;
        if(rhs.isEmpty()){
            return *this;
        }
        else{   
                while(p->next != rhs.getFirstNode()){
                    append(p->data);
                    p = p->next;
                }
                append(p->data);
            } 
    }
    return *this;

}

template<class T>
int LinkedList<T>::getSize() const
{
    /* TODO */
    return this->size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    /* TODO */
    if(head == NULL){
        return true;
    }
    else{
        return false;
    }
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{
    /* TODO */
    if(isEmpty())
        return false;
    else{
        Node<T> *p = head;
        while(p->next != head){
            if(p->next == node)
                return true;
            p = p->next;
        }
        if(p->next == node)
            return true;
        return false;
    }
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    /* TODO */
    if(isEmpty()){
        return NULL;
    }else{
        return head;
    }
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    /* TODO */
    if(isEmpty()){
        return NULL;
    }else{
        return head->prev;
    }
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{
    /* TODO */
    if(isEmpty()){
        return NULL;
    }else{
        Node<T> *p = head;
        while(p->next != head){
            if(p->data == data){
                return p;
            }
            p = p->next;
        }
        if(p->data == data){
            return p;
        }
     return NULL;
    }
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
    /* TODO */
    if(isEmpty()){
        return NULL;
    }else{
        if(index >= size){
            return NULL;
        }
        if(index <0 ){
            return NULL;
        }
    Node<T> *p = head;
        for(int i=0; i<index; i++){
            p = p->next;            
        }
    return p;          
    }
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    /* TODO */
    if(isEmpty()){
        Node<T> *newNode = new Node<T>(data);
        newNode->next = newNode;
        newNode->prev = newNode;
        this->head = newNode;
        this->size=this->size + 1;
    }
    else{
        Node<T> *newNode = new Node<T>(data);
        Node<T> *p = head;
        p = p->prev; 
        newNode->prev = p;
        newNode->next = p->next;
        newNode->prev->next =newNode;
        newNode->next->prev =newNode; 
        this->size++;
    }
}

template<class T>
void LinkedList<T>::prepend(const T &data)
{
    /* TODO */
    if(isEmpty()){
        Node<T> *newNode = new Node<T>(data);
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        this->size++;
    }
    else{
        Node<T> *newNode = new Node<T>(data);
        Node<T> *p = head; //get head
        newNode->next=p;
        newNode->prev=p->prev;
        newNode->next->prev = newNode;
        newNode->prev->next =newNode;
        this->size++;
        head = newNode;
    }
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{
    /* TODO */
    bool find = false;
    if(head == NULL){
        return;
    }
    else{
        Node<T> *p = head; //get head
        if(containsNode(p)){
            Node<T> *newNode = new Node<T>(data);
            Node<T> *p = node; //get head
            newNode->next = p->next;
            newNode->prev = p;
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;
            this->size++;
            return;
        }
        else{
            return;
        }  
    }
}   

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{
    /* TODO */
    int indexCount = 0;
    bool inside = false;
    if(head == NULL){
        return;
    }
    else{
        if(index > size){
            return;
        }
        Node<T> *p = head; //get head
        while(p->next != head){
            if(indexCount == index){
                Node<T> *newNode = new Node<T>(data);
                p = p->prev;
                newNode->next = p->next;
                newNode->prev = p;
                newNode->next->prev = newNode;
                newNode->prev->next = newNode;
                this->size++;
                inside = true;
            }
            indexCount++;
            p = p->next;
        }
        if(indexCount == index && !inside){
            p = p->prev;
            Node<T> *newNode = new Node<T>(data);
            newNode->next = p->next;
            newNode->prev = p;
            newNode->next->prev = newNode;
            newNode->prev->next = newNode;
            this->size++;
        }
        return;
    }    
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    /* TODO */
    int index = 0;
    if(head == NULL){
        return -1;
    }
    else{
        Node<T> *p = head;
        while(p->next != head){
            if(p == node){
                return index;
            }
            index++;
            p = p->next;
        }
        if(p == node){
            //last node :)
            return index;
        }
        index = -1;
    }
    return index;    
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{ //will do
    /* TODO */
    if(isEmpty()){
    return;
    }
    if(currentIndex > size-1){
        return;
    }
    if(newIndex >= size){
        //node move the end
        if(currentIndex == 0){
            head = head->next;
        }else if(currentIndex == size-1){
            return;
        }
        else{
            Node<T> *c = getNodeAtIndex(currentIndex);
            Node<T> *p = getLastNode();
            Node<T> *c_next = c->next;
            Node<T> *c_prev = c->prev;
            c_next->prev = c_prev;
            c_prev->next = c_next;
            p->next = c;
            c->prev = p;
            c->next = head;
            head->prev = c;
        }
    }else{
        if(currentIndex == newIndex)
            return;
        else if(currentIndex < newIndex){
            if(currentIndex == 0 && newIndex == size-1){
                head = head->next;
                return;
            }
            Node<T> *c = getNodeAtIndex(currentIndex);
            Node<T> *p = getNodeAtIndex(newIndex);
            Node<T> *c_next = c->next;
            Node<T> *c_prev = c->prev;
            Node<T> *p_next = p->next;
            Node<T> *p_prev = p->prev;
    
            c_prev->next = c_next;
            c_next->prev = c_prev;
            p->next = c;
            p_next->prev = c;
            c->next = p_next;
            c->prev = p;
            if(currentIndex == 0)
                head = c_next;
            return;
        }else{
            
            if(newIndex == 0 && currentIndex == size -1){
                head = head->prev;
                return;
            }
            Node<T> *c = getNodeAtIndex(currentIndex);
            Node<T> *p = getNodeAtIndex(newIndex);
            Node<T> *c_next = c->next;
            Node<T> *c_prev = c->prev;
            Node<T> *p_next = p->next;
            Node<T> *p_prev = p->prev;

            c_prev->next = c_next;
            c_next->prev = c_prev;
            p->prev = c;
            p_prev->next = c;
            c->next = p;
            c->prev = p_prev;
            if(newIndex == 0)
                head = c;
            return;
        }
    }
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    /* TODO */
    Node<T> *p = head;
    if(isEmpty())
        return;
    else{
        if(p == node){ //head ise
            if(size == 1){
                this->size--;
                this->head =NULL;
                delete p;
                return;
            }else{
                head->next->prev =  head->prev;
                head->prev->next =  head->next;
                head = p->next;
                delete p;
                this->size--;
                return;
            }
        }else{ // not head
            while(p->next != head){
                if(p == node){
                    if(size == 2){
                        head->next = head;
                        head->prev = head;
                        delete p;
                        this->size--;
                        return;
                    }else{
                        p->prev->next = p->next;
                        p->next->prev = p->prev;
                        delete p;
                        this->size--;
                        return;
                    }
                }
                p = p->next;
            }
            //last shot p can be last unit
            if(p == node){
                p->prev->next = p->next;
                p->next->prev = p->prev;
                delete p;
                this->size--;
                return;
            }
        }
    }
}
template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    /* TODO */
    Node<T> *p = head;
    if(isEmpty()){
        return;
    }
        while(p->next != head){
            if(p->data == data){
                removeNode(p);
                p = head;
                if(p == NULL){
                    return;
                }
            }
            p = p->next;
        }
        if(p->data == data){removeNode(p);}

}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{
    /* TODO */
    Node<T> *p = head;
    if(isEmpty()){
        return;
    } 
    else{
        if(index > size){
            return;
        }
        for(int i =0; i<=index; i++){
            if(index == i){
                removeNode(p);
                return;
            }
            p = p->next;
        }
    }   
}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    /* TODO */
    Node<T> *p = head;
    if(isEmpty()){
        return;
    }
    else{
        while(head){
            removeNode(p);
            if(head){
                p = head;
            }
        }
    }
}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H
