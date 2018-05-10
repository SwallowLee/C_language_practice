# include<iostream>
# include"MyStack.h"
# include"Coordinate.h"

template <class T>
MyStack<T>::MyStack()
{
	head=NULL;
	size=0;
}
template <class T>
MyStack<T>::~MyStack()
{
	if(head!=NULL)
		void pop();
}
template <class T>
void MyStack<T>::push(T& p)
{
	Node *one=new Node(p,head);
	head=one;
	size++;
}
template <class T>
void MyStack<T>::pop()
{
	MyStack::Node *cur=head;
	head=cur->next;
	delete cur;
	size--;
}
template <class T>
T& MyStack<T>::top()
{
	return head->value;
}
template <class T>
size_t MyStack<T>::getSize() const
{
	return size;
}
template <class T>
bool MyStack<T>::empty()const
{
	if(head==NULL)
		return true;
	else
		return false;
}
template <class T>
MyStack<T>::Node::Node(T& p,Node* one):
value(p),next(one)
{}
template class MyStack<int>;
template class MyStack<string>;
template class MyStack<char>;
template class MyStack<Coordinate>;
