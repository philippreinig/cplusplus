#pragma once

#include <cstdint>
#include <utility>
#include <iostream>

/*
 * ToDo:
 *   * Make a template out of ForwardList. What template parameter(s) do you
 *     need?
 *   * Add data members to the classes if necessary
 *   * Implement all functions
 *   * Test your solution in main.cpp
 */

namespace a08{
/**
 * This class represents a linked list. It supports constant time insertion and
 * removal of elements anywhere in the list.
 */
template<typename T>
class ForwardList
{
    /**
     * This internal class represents a node of the linked list holding a data
     * member and a pointer to the next element. It is in the private part of
     * the class because it is an implementation detail that is not part of the
     * class's public interface.
     */
    struct Node
    {
        /// Constructs a Node from a data value and a link to the next element.
        Node(const T& data, Node* next) : data{data}, next{next} {}

        /// A Node owns all nodes after it, so it deletes them on destruction
        ~Node(){ delete next;}

        /**
        * Performs a deep copy of the Node and all Nodes after it. Note that
        * this function returns an (owning) raw pointer to storage that was
        * allocated using new inside the function. Usually, this is bad
        * practice, as the calling code must not forget to call delete on the
        * pointer. In this case, it is sort of fine, because the Node class is
        * private and can only be used from within the ForwardList class. This
        * means that if we do not make any mistakes while implementing
        * ForwardList, no one else can make mistakes with this either. A better
        * approach would be to use a smart pointer (such as std::unique_ptr) to
        * hold the next node, but we have not learned about that in the lecture
        * yet.
        */
        Node* clone() const
        {
            if(next == nullptr)
            {
                return new Node{data, nullptr};
            }
            else
            {
                return new Node{data, next->clone()};
            }
        }

        T data;
        Node* next;
    };
public:
    /**
     * This class represents an iterator on the ForwardList. It implements the
     * basic operations needed for an iterator, namely incrementation,
     * dereferencing and comparison. Note that to conform to the requirements
     * the STL has for iterators we would also have to provide some special
     * member typedefs. However, our Iterator is sufficient to work with a range
     * for loop.
     */
    class Iterator
    {
    public:
        /**
         * Dereference the iterator. Returns a reference to the data element
         * stored at the current position in the list. If the iterator does not
         * point to a valid node, the behavior is undefined.
         * 
         */
        
        T operator*(){
            return this->current_node->data;
        }

        /**
        Pre-increment (++it). Advances the iterator to the next element 
        and returns the modified iterator. If the iterator does not
         point to a valid node, the behavior is undefined.
         */
        Iterator operator++(){
            this->current_node = this->current_node->next;
            return *this;
        }

        /// Post-increment (it++). Advances the iterator to the next element
        /// and returns a copy of the previous iterator. If the iterator does not
        /// point to a valid node, the behavior is undefined.
        Iterator operator++(int) {
            Iterator copy(this->current_node);
            current_node = current_node->next;
            return copy;
        }

        /// Returns true if two iterators refer to the same elements in the list.
        bool operator==(const Iterator& other) const{
            return this->current_node == other.current_node;
        }

        /// Returns true if two iterators do not refer to the same element.
        bool operator!=(const Iterator& other) const{
            return this->current_node != other.current_node;
         }
    private:
        /// The constructor of iterator is private and ForwardList is listed
        /// as a friend. This means that only ForwardList can construct new
        /// instances of its Iterator class and users of ForwardList can not
        /// create iterators to random locations.
        friend class ForwardList;
        Iterator(Node* node) : current_node(node){}
        Node* current_node;
    };

    /// Default constructor creates an empty list
    ForwardList() : head(nullptr){
    }

    ForwardList(const ForwardList& other) : head(other.head->clone()){}

    /// Destructor makes sure that all Nodes are correctly destroyed
    ~ForwardList(){
        delete head;
    }

    /// Copy assignment operator uses the copy-and-swap idiom to make a safe
    /// assignment
    ForwardList& operator=(ForwardList other)
    {
        ForwardList tmp(other);
        swap(*this, tmp);
        return *this;
    }

    /// Return an iterator to the first element of the list
    Iterator begin(){
        return Iterator(this->head);
    }

    /// Return an iterator to one-past-the-end of the list. A common trick for
    /// non-contiguous containers like this to represent a one-past-the-end
    /// iterator is to return an iterator holding a nullptr internally.
    /// Dereferencing or incrementing the iterator returned by end() is undefined
    /// behavior.
    Iterator end(){
        return Iterator(nullptr);
    }

    /// Add an element to the front of the list.
    void push_front(const T& value){
        this->head = new Node(value, this->head);
     }

    /// Remove the first element of the list. Calling this function on an empty
    /// list is undefined behavior. When implementing this function, be careful
    /// to delete the one and only the one element that is removed.
    void pop_front()
    {
        Node* tmp = this->head;
        this->head = this->head->next;
        tmp->next = nullptr;
        delete tmp;
    }

    /// Get a reference to the first element of the list 
    /// (const and non-const version)
    T& front()
    { 
        return this -> head -> data;
    }
    const T& front() const
    {
         return this -> head -> data; 
    }

    /// Return true is the list is empty
    bool empty() const
    {
        return this->head == nullptr;
    }

    /// Return the number of elements stored in the list.
    std::size_t size() const{
        Node* tmp_node = this->head;
        std::size_t counter = 0;
        while(tmp_node != nullptr){
            counter++;
            tmp_node = tmp_node -> next;
        }    
        return counter;
    }

    /// Insert a new element after the one pointed to by the given Iterator.
    /// Returns an Iterator to the newly inserted element
    Iterator insert_after(Iterator pos, T& value){
        Node* new_node = new Node(value, pos.node->next);
        pos.node->next = new_node;
        return ++pos;
    }

    /// Swaps the contents of two ForwardLists without making any deep copies!
    /// This is a commonly implemented function that makes it possible to
    /// cheaply swap two objects of the same class, and that aids in
    /// implementing the assignment operator using the copy-and-swap idiom.
    friend void swap(ForwardList& l, ForwardList& r){
        Node* temp = l.head;
        l.head = r.head;
        r.head = temp;
    }

private:
    Node* head;
    
}; //forwardList

} // namespace a08
