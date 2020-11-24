#include "stack.h"
stack::stack(){
	top=-1;
}

bool stack::isempty()const{
	return top==-1;
}

bool stack::isfull()const{
	return top==SIZE-1;
}

bool stack::push(const elem &e){
	if(top<SIZE){
		a[++top]=e;
		return true;
	}
	else return false;
}

bool stack::pop(elem &e){
	if(top>=0){
		e=a[top--];
		return true;
	}
	else return false;
}


