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
 * Last Updated: 9/26/16 
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

	// Utility Functions:
	inline unsigned int size() const { return size_; }
	inline bool empty() const { return ( head_ == NULL ); }
	void clear() { this->deleteList(); }

	// Adding/Removing Elements:
	void push_front( const T& obj );
	void pop_front();
	void push_back( const T& obj ); 
	void pop_back();
	
	// Iterator Support:
	typedef ListIterator<T> iterator;
	iterator erase( iterator itr );
	iterator insert( iterator itr, T const& value );
	inline iterator begin() { return iterator( head_ ); }
	inline iterator end() { return iterator( NULL ); }

private:
	// Helper functions to copy and delete the list safely:
	void copyList( const List<T>& rhs );
	void deleteList(); 

	// Pointer to the head node:
	Node< T > *head_; 
	// Pointer to the tail node:
	Node< T > *tail_; 

	// Length of this list:
	unsigned int size_;
};

// Implementation of assignment operator=:
template <class T> List<T>& List<T>::operator=( const List<T>& rhs )
{
	if( &rhs != this )
	{
		this->deleteList();
		this->copyList();
	}

	return *this;
}

// Push Back/Push Front:
template <class T> void List<T>::push_back( const T& value )
{
	// Check if the head is NULL:
	if( head_ == NULL )
	{
		// Create a new node and make that the head:  
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = NULL;
		n->prev = NULL;
		head_ = n;
		tail_ = n;
		size_++;
	}
	else
	{
		// Walk through the existing list and append the new node at the end:
		Node<T> *head = head_;
		for( ; head->next != NULL; head = head->next );

		// Create the new node:
		Node<T> *n = new Node<T>;
		n->value = value;
		n->next = NULL;
		n->prev = head;
		
		head->next = n;	
		tail_ = n;
		size_++; 
	}
}

// Function to go through the linked list and copy all objects:
template <class T> void List<T>::copyList( const List<T>& rhs )
{
}

// Function to go through the linked list and delete all objects safely:
template <class T> void List<T>::deleteList()
{
	
}
     

#endif
