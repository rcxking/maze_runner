/*
 * list.h
 *
 * This is an implementation of a linked list class
 * for the 3pi robot.  AVR does not currently have a linked
 * list class so I have to create my own.
 *
 * Bryant Pong
 * 9/4/16
 *
 * Last Updated: 9/25/16 
 */
#ifndef _LIST_H_
#define _LIST_H_

// STL Includes:
#include <cstddef> // For NULL definition

/*
 * This class represents a single node in a 
 * doubly-linked list.   
 */
template <class T> class Node
{
public:
	// Default Node Constructor:
	Node() : next( NULL ), prev( NULL ) {}


	Node( const T& obj, Node *n, Node *p ) :
	      value( obj ), next( n ), prev( p ) {}

	// The object T stored in this Node:
	T value;
	Node<T>* next;
	Node<T>* prev;
};

// Forward declaration of the List class (for the iterator):
template< class T > class List;

/*
 * This is an iterator class for the doubly-linked list
 * object.  
 */
template <class T> class ListIterator
{
public:
	// Default Constructor:
	ListIterator() : node( NULL ) {}	

	// Constructor given the node to point to:
	ListIterator( Node<T>* n ) : node( n ) {}

	// Copy Constructor:
	ListIterator( const ListIterator<T>& rhs ) : node( rhs.node ) {}  

	// Destructor:
	~ListIterator() {}

	// Assignment operator=:
	inline ListIterator<T>& operator=( const ListIterator<T>& rhs )
	{
		node = rhs.node;
		return *this;
	}

	// Deferencing operator gives the object that the node pointer is pointing to:
	inline T& operator*() { return node->value; }

	// Increment/Decrement operators:
	inline ListIterator<T>& operator++() // Pre-increment (++iter)
	{
		node = node->next;
		return *this;
	}

	inline ListIterator<T>& operator++(int) // Post-increment (iter++)
	{
		// Create a copy of this iterator:
		ListIterator<T> temp( *this ); 
		// Move the node pointer to the next object:
		node = node->next;
		return temp;	
	}

	inline ListIterator<T>& operator--() // Pre-decrement (--iter)
	{
		node = node->prev;
		return *this;
	}

	inline ListIterator<T>& operator--(int) // Post-decrement (iter++)
	{
		// Create a copy of this iterator:
		ListIterator<T> temp( *this );
		// Move the node pointer to the previous object:
		node = node->prev;
		return temp;
	}

	// Comparison operators.  Need to declare the List class as a friend class:
	friend class List<T>;

	inline friend bool operator==( const ListIterator<T>& lhs,
	                               const ListIterator<T>& rhs )
	{
		return lhs.node == rhs.node;
	}

	inline friend bool operator!=( const ListIterator<T>& lhs,
	                               const ListIterator<T>& rhs )
	{
		return lhs.node != rhs.node;
	}

private:
	// The node that this iterator is currently pointing to:
	Node<T>* node;
};

/*
 * This is the templated class declaration for a doubly-linked
 * list class.  
 */ 
template <class T> class List
{

public:
	// Default Constructor:
	List() : head_( NULL ), tail_( NULL ), size_( 0 ) {}

	// Copy Constructor:
	List( const List<T>& rhs );
	// Destructor:
	~List() { this->deleteList(); }
	List& operator=( const List& rhs );

	void push_front( const T& obj );
	void push_back( const T& obj ); 

private:
	// Helper functions to copy and delete the list safely:
	void copyList();
	void deleteList(); 

	// Length of this list:
	unsigned int size_;

	// Pointer to the head node:
	Node< T > *head_; 
	// Pointer to the tail node:
	Node< T > *tail_; 
};

// Function to go through the linked list and delete all objects safely:
template <class T> void List<T>::deleteList()
{
	
}

#endif
