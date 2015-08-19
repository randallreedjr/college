/**
 *  The DropOutStack class is a variant of the stack class included
 *  in the C++ STL.  The DropOutStack has a user defined capacity
 *	(default zero).  Once the capacity is reached, any subsequent
 *	pushes will cause the bottom item of the stack to be dropped
 *	and overwritten.  Otherwise, it functions very much like the
 *	standard stack class.  One other inportant addition is the
 *	requirement that the client include an "Item.h" header file,
 *	with a typedef of the Item they wish to store in
 *	the DropOutStack contained therein.
 *
 *  @author  Randall Reed, Jr. (rcrjr)
 *  @version 2005.02.21
 */

#include <iostream>
using namespace std;
#include "DropOutStack.h"
#include "Item.h"

/**
 * Create a new DropOutStack object.
 * The only parameter is capacity, controlling how many items can
	* be stored in the stack. If capacity is not defined by the user,
	* the default value is zero.
 *
 * @param capacity      number of items that may be stored in the drop out stack
 */
DropOutStack::DropOutStack(unsigned int capacity)	//Default Contructor
{
    stk = NULL;
    cap = capacity;				//Capacity is 0 by default if not given by user
    top = 0;
    usage = 0;
    LastError = NO_ERROR;
    stk=new Item [capacity];
}

/**
 * Create a copy of an existing DropOutStack object for functions that
	* require a DropOutStack to be passed by value.
 * The only parameter is source, the existing DropOutStack that is
	* to be copied, and it is passed by constant reference. This function
	* is only called implicitly, whenever a DropOutStack is a pass-by-value
	* parameter.
 *
 * @param source      original DropOutStack to be copied
 */
DropOutStack::DropOutStack(const DropOutStack& source)	//Copy Constructor
{
    unsigned int i;
    usage = source.usage;				//Copy all static data members
    cap = source.cap;
    top = source.top;
    LastError = source.LastError;
    
    stk = new Item [usage];			//Allocate memory equal to current usage
    for(i = 0 ; i < usage ; i++)				//Copy elements from source to "this"
        stk[i] = source.stk[i];
}

/**
 * Create a copy of an existing DropOutStack object when assignment is
	* invoked. The only parameter is rhs, the existing DropOutStack that is
	* on the right hand side of the equals sign, passed by constant reference.
	* This function is only called implicitly, wherever an equals sign is
	* sandwiched between two DropOutStacks.
 *
 * @param rhs      original DropOutStack to be copied
	* @return *this, reference to copy of rhs that was created
 */
DropOutStack& DropOutStack::operator=(const DropOutStack& rhs) //Assignment operator
{
    unsigned int i;
    if(this != &rhs)					//Check for self assignment
    {
        usage = rhs.usage;					//Copy static data members
        cap = rhs.cap;
        top = rhs.top;
        LastError = rhs.LastError;
        
        if(stk)
        {
            delete [] stk;
            stk = NULL;
        }
        
        stk = new Item [usage];
        for(i = 0 ; i < usage ; i++)				//Copy elements from source to "this"
            stk[i] = rhs.stk[i];
    }
    return *this;
}

/**
 * Push an item onto the drop out stack.
 * The item to be pushed is passed by constant reference.  Error
	* checking is performed then, if the operation is valid, the item is
	* insert at the index stored in top.
 *
 * @param elem		 Item to be inserted at index stored in top
	* @return true if push succeeded (capacity>0), false otherwise
 */
bool DropOutStack::push(const Item& elem)      //insert Elem at Top
{
    if(cap == 0)							//Trying to push when stack can hold zero items
    {
        LastError = STACK_OVERFLOW;
        return false;
    }
    
    stk[top] = elem;
    top++;
    if(top == cap)
        top = 0;
    if(usage < cap)
        usage++;
    LastError = NO_ERROR;
    return true;
}

/**
 * Pop an item off of the drop out stack.
 * An item is passed to the function by reference.  Error
	* checking is performed then, if the operation is valid, the top item from
	* the stack is stored in the parameter. After pop has executed, that
	* item is no longer accessible.  Ever.
 *
 * @param elem		 Item to store top element from stack
	* @return true if pop succeeded (usage>0), false otherwise
 */
bool DropOutStack::pop(Item& elem)          //remove top-most element and return it
{
    if(!usage)							//Trying to pop from empty stack
    {
        LastError = STACK_UNDERFLOW;
        return false;
    }
    
    LastError = NO_ERROR;
    if(top > 0)
        top--;							//Decrement index of next push to "remove" item (element not actually deleted)
    else
        top = cap-1;
    usage--;
    elem = stk[top];
    return true;
}

/**
 * Allow user to see top item on the stack without removing it.
	* This function returns a constant pointer to an Item object
	* which allows the user to see the value stored at the top of
	* the stack. This is a const function, so no change may be
	* made to the stack by calling this function.
 *
 * @return a constant pointer to an item object, pointing to
	*			the stack's top value in memory
 */
Item* const DropOutStack::peek() const      //provide access to top-most element
{
    Item* rv = NULL;
    if(usage > 0)
    {
        rv = new Item;
        if(top != 0)
            *rv = stk[top - 1];
        else
            *rv = stk[cap - 1];
    }
    return rv;
}

/**
 *  Clear the stack by reseting usage and top to zero,
	*  and reseting the error flag to no error
 */
void DropOutStack::clear()					//reset stack to empty state
{
    usage = 0;
    top = 0;
    LastError = NO_ERROR;
}

/**
 * Check to see if the stack is empty.
	* This is a const function, so no change may be
	* made to the stack by calling this function.
 *
 * @return true if no items are currently stored in the stack, false otherwise
 */
bool DropOutStack::isEmpty() const             //check for empty stack
{
    if(!usage)								//Stack is empty if no elements are stored
        return true;
    return false;
}

/**
 * Check to see what the last error message generated was.
	* This is a const function, so no change may be
	* made to the stack by calling this function.
 *
 * @return either NO_ERROR, STACK_OVERFLOW, or STACK_UNDERFLOW
 */
ErrorType DropOutStack::getError() const       //return error state
{
    return LastError;
}

/**
 * Check the capacity of a stack.
	* This is a const function, so no change may be
	* made to the stack by calling this function.
 *
 * @return capacity of the stack
 */
unsigned int DropOutStack::capacity() const	//Allows user read access to
{											//stack capacity
    return cap;
}

/**
 * Check the current usage of a stack.
	* This is a const function, so no change may be
	* made to the stack by calling this function.
 *
 * @return number of elements currently stored in the stack (0<=usage<=capacity)
 */
unsigned int DropOutStack::size() const        //report stack usage
{
    return usage;
}

/**
 * Display the contents of a drop out stack.
 * The only parameter is the ostream which the user wants
	* to employ to display the stack (e.g. cout).  The capacity
	* of the stack will be displayed first, followed by the index
	* tags of each element currently stored in the stack as well
	* as the values of the elements at those indices.
 *
 * @param out         output stream buffer used to display a stack
 */
void DropOutStack::display(ostream& out) const //display stack contents
{
    int i;
    int num = usage;
    out<<"Capacity: "<<cap<<endl;
    if(usage == 0)
        out<<setw(7)<<"S"<<"tack is empty"<<endl;
    else if(top<usage&&usage == cap)			//Number of times that push has been invoked is greater than capacity
        //causing circular storage
    {
        if(top > 0)						//Start at top and go backwards to element at index 0
        {
            for(i = top - 1 ; i >= 0 ; i--)
            {
                out<<setw(7)<<i<<": "<<stk[i]<<endl;
            }
        }
        //else
        //{
        
        //}
        i = cap - 1;
        while(i > top)
            //for(i = cap - 1 ; i >= top ; i--)			//Resume from max index until reaching starting point
        {
            out<<setw(7)<<i<<": "<<stk[i]<<endl;
            if(i>0)
                i--;
        }
        out<<setw(7)<<top<<": "<<stk[top]<<endl;
    }
    else if(top == usage)					//Capacity has not yet been exceeded
    {
        for(i = top - 1 ; i >= 0 ; i--)			//Start from last index filled and go backwards to zero
            out<<setw(7)<<i<<": "<<stk[i]<<endl;
    }
    else
    {
        if(top > 0)						//Capacity was exceeded, then some items popped off
        {
            for(i = top - 1 ; i >= 0 && num >0 ; i--)		//Start from last pushed index and decrement to zero
            {
                out<<setw(7)<<i<<": "<<stk[i]<<endl;
                num--;
            }
        }
        for(i=cap-1;num>0;i--)						//Display remaining elements
        {
            out<<setw(7)<<i<<": "<<stk[i]<<endl;
            num--;
        }
    }
}

/**
 *  Destructor, called whenever a DropOutStack object is destroyed.
	*  The destructor frees allocated memory and returns any
	*  private data members that are pointers to NULL.
 */
DropOutStack::~DropOutStack()	//Destructor
{
    if(stk)
        delete [] stk;
    stk = NULL;
}

//On my honor:
//
//- I have not discussed the C++ language code in my program with
//  anyone other than my instructor or the teaching assistants
//  assigned to this course.
//
//- I have not used C++ language code obtained from another student,
//  or any other unauthorized source, either modified or unmodified.
//
//- If any C++ language code or documentation used in my program 
//  was obtained from another source, such as a text book or course
//  notes, that has been clearly noted with a proper citation in
//  the comments of my program.
//
//- I have not designed this program in such a way as to defeat or
//  interfere with the normal operation of the Curator System.
//
//- I have neither given nor received unauthorized aid in the
//  completion of this assignment.
//
//      Randall Reed, rcrjr@vt.edu
