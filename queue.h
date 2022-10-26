//This interface exports a template version of the Queue class.
#ifndef _queue_h
#define _queue_h
#include "error.h"

//This class implements a queue of the specified value type
template <typename ValueType>
class Queue { 
public:
	//constructor
	Queue(); //intialize a new empty queue
	//destructor
	~Queue(); //frees any heap storage associated with the queue
	int size() const;//Returns the number of values in the queue
	bool isEmpty() const; //returns true if the queue contains no elements
	void clear(); //removes all elements from the queue
	void enqueue(ValueType value); //adds value to the end of the queue
	ValueType dequeue(); //removes & returns the first item in the queue. This method signals an error if called on an  empty queue.
	int peek() const; //returns the 1st value in the queue without removing it. This mehtod signals an error if called on an empty queue.
	Queue(const Queue<int>& src);
	Queue<int>& operator=(const Queue<int>& src);
private: //640
    static const int INTERNAL_CAPACITY = 10;
    /* Instance Variables */
    ValueType *array; //A dynamic array of the elements
    int capacity; //The allocated size of the array
    int head; //The index of the head element
    int tail; //The index of the tail element
    //Private method prototypes
    void deepCopy(const Queue<ValueType>& src);
    void expandCapacity();
};
/* Implementation of the array-based queue */
//Queue constructor allocates the array storage and initializes the fields
template <typename ValueType>
Queue<ValueType>::Queue() {
    capacity = INTERNAL_CAPACITY;
    array = new ValueType[capacity];
    head = 0;
    tail = 0;
}
//Size calculated from head and tail using modular arithmetic
template <typename ValueType>
int Queue<ValueType>::size() const {
    return (tail + capacity - head) % capacity;
}
//The queue is empty whenever the head and tail pointers are equal. This 
//interpretation means that the queue must always leave one unused space.
template <typename ValueType>
bool Queue<ValueType>::isEmpty() const {
    return head == tail;
}
//Clear method simply resets the head and tail indices
template <typename ValueType>
void Queue<ValueType>::clear() {
    head = tail = 0;
}
//Postcondition: Checks if there's enough room for the element and then 
//expands the array storage if necessay. 
template <typename ValueType>
void Queue<ValueType>::enqueue(ValueType value) {
    if(size()==capacity-1) expandCapacity();
    array[tail] = value;
    tail = (tail + 1) % capacity;
}
//These functions check for an empty queue and report an error if there
// is no first element
template<typename ValueType>
ValueType Queue<ValueType>::dequeue() {
    if(isEmpty()) error("dequeue: Attempting to dequeue an empty queue");
    ValueType result = array[head];
    head = (head + 1) % capacity;
    return result;
}

#endif

