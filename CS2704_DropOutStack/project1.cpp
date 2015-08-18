//#include <iostream>
//#include "DropOutStack.h"
//using namespace std;
//
//void TestCopy(DropOutStack);
//
//int main()
//{
//	Item element;
//	Item *Iptr;
//	element = 0;
//	DropOutStack a(2);
//	DropOutStack b;
//	DropOutStack c;
//	DropOutStack d(3);
//	DropOutStack e;
//	DropOutStack empty(5);
//
//	DropOutStack spec(5);				//Test Deep Copy
//	cout<<"Test: Deep copy"<<endl;
//	spec.push(23);
//	spec.push(9);
//	spec.push(42);
//	spec.push(12);
//	spec.push(17);
//	spec.push(41);
//	spec.push(25);
//	cout<<*spec.peek()<<endl;
//	spec.display(cout);
//	TestCopy(spec);
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test: Capacity zero push"<<endl;
//	b.push(element);
//	if(b.getError()==STACK_OVERFLOW)
//	cout<<"Stack Overflow"<<endl;
//	
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test: Capacity function call"<<endl;
//	cout<<a.capacity()<<endl;
//	cout<<b.capacity()<<endl;
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test: Assignment Operator"<<endl;
//	cout<<c.capacity()<<endl;
//	c=a;
//	a.display(cout);
//	cout<<endl;
//	c.display(cout);
//	cout<<endl;
//	a=spec;
//	a.display(cout);
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test: Push/pop/peek/clear"<<endl;
//	d.push(0);
//	cout<<*d.peek()<<endl;
//	d.push(1);
//	d.display(cout);
//	cout<<*d.peek()<<endl;
//	d.push(2);
//	d.display(cout);
//	cout<<*d.peek()<<endl;
//	d.push(3);
//	d.display(cout);
//	cout<<*d.peek()<<endl;
//	d.pop(element);
//	cout<<element<<endl;
//	d.pop(element);
//	cout<<element<<endl;
//	d.pop(element);
//	cout<<element<<endl;
//	d.pop(element);
//	cout<<element<<endl;
//	if(d.getError()==STACK_UNDERFLOW)
//		cout<<"Stack Underflow"<<endl;
//	d.display(cout);
//	if(d.peek())
//	cout<<*d.peek()<<endl;
//	else
//		cout<<"NULL"<<endl;
//	d.push(4);
//	d.display(cout);
//	d.clear();
//	if(d.peek())
//	cout<<*d.peek()<<endl;
//	else
//		cout<<"NULL"<<endl;
//	d.display(cout);
//	d.push(-1);
//	d.push(-2);
//	d.push(-3);
//	d.display(cout);
//	d.push(-4);
//	d.display(cout);
//	d.pop(element);
//	d.pop(element);
//	d.display(cout);
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test isEmpty and size and capacity: "<<endl;
//	d.push(element);
//	d.push(1);
//	d.push(2);
//	d.push(3);
//	c=d;
//	d.pop(element);
//	cout<<element<<endl;
//	cout<<"Capacity of c is "<<c.capacity()<<" and capacity of d is "<<d.capacity()<<endl;
//
//	c.display(cout);
//	d.display(cout);
//	
//
//	cout<<"Size of c is "<<c.size()<<" and size of d is "<<d.size()<<endl;
//	d.clear();
//	cout<<"d was cleared. Now size of d is "<<d.size()<<endl;
//
//	cout<<"Is c empty? "<<c.isEmpty()<<endl;
//	cout<<"Is d empty? "<<d.isEmpty()<<endl;
//	d.display(cout);
//
//	cout<<"--------------------------------------------------------------------------------";
//	cout<<"Test Big Stack: "<<endl;
//	DropOutStack big(10);
//
//	big.push(0);
//	big.push(1);
//	big.push(2);
//	big.push(3);
//	big.push(4);
//	big.push(5);
//	big.push(6);
//	big.push(7);
//	big.push(8);
//	big.push(9);
//	big.push(10);
//	big.push(11);
//	big.display(cout);
//	big.pop(element);
//	big.pop(element);
//	big.pop(element);
//	big.display(cout);
//	big.clear();
//	big.push(12);
//	big.display(cout);
//
//	cout<<"--------------------------------------------------------------------------------";
//
//
//	return 0;	
//}
//
//void TestCopy(DropOutStack stack)
//{
//	Item el;
//	DropOutStack b;
//	b=stack;
//	b.pop(el);
//	cout<<el<<endl;
//	cout<<*b.peek()<<endl;
//	b.display(cout);
//}