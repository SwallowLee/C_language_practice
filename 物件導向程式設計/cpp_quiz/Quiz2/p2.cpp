#include "p2.hpp"
#include<iostream>

namespace oop{

	Node* push(Node *top,int n){
	  struct Node *re=new struct Node[1];
	  re->num=n;
	  re->next=top;
	  return re;
	}
    Node* pop(Node *top){
	  struct Node *cur;
	  cur=top;
	  top=cur->next;
	  delete(cur);
	  return top;
	}
    void print(Node *top ){ 
	while(top!=NULL)
	{
	  std::cout<<top->num<<" ";
          struct Node *cur;
	  cur=top;
	  top=cur->next;
	  delete(cur);
	}
     //Output specification: top->space->top->space->¡K¡K 
     //std::cout<<top<<" "; //show example

    } 
}
