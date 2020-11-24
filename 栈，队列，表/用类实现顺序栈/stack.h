#ifndef	STACK_H_
#define STACK_H_
#include<iostream>
//#define SIZE 10 
#define elem int     

class stack{
	private:
		enum {SIZE=10};				//用枚举替代宏定义 
		elem a[SIZE];
		int top;
	public:
		stack();
		bool isempty() const;
		bool isfull() const;
		bool push(const elem &e);
		bool pop(elem &e);
}; 

#endif
