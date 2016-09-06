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
 * Last Updated: 9/5/16 
 */
#ifndef _LIST_H_
#define _LIST_H_

/*
 * This class represents a single node in a 
 * doubly-linked list.   
 */
template <class T> class Node
{
public:
	// Constructor:
	Node( const T& obj, Node *n, Node *p ) :
	    object( obj ), next( n ), prev( p ) {}

	// The object T stored in this Node:
	T object;
	Node* next;
	Node* prev;
};

template <class T> class List
{

public:
	List();
	List( const List& rhs );
	~List();
	List& operator=( const List& rhs );

private:
	// Length of this list:
	unsigned int size_;

	// Pointer to the head node:
	Node< T > *headNode; 

};

#endif
