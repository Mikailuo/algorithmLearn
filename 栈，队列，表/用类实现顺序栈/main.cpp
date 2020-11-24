//一个简单的入栈压栈展示，就不打注释了。
//唯一注意的一点就是这里采用枚举的手段解决类域中常量的问题，之前一直使用宏替换 
//那么能不能通过枚举解决宏替换数据类型呢？ 
#include <iostream>
#include <cstdlib>
#include "stack.h"

using namespace std;

int main(void){
	stack st;
	char ch;
	int suzi;
	while(cin>>ch&&ch!='#'){
		suzi=atoi(&ch);
		st.push(suzi);
		if(st.isfull()){
			cout<<"stack has been full;"<<endl;
			break;
		}
	}
	
	cout<<"pop stack:";
	while(!st.isempty()){
		st.pop(suzi);
		cout<<suzi<<" ";
	}
	cout<<endl;
	return 0;
}
