//һ���򵥵���ջѹջչʾ���Ͳ���ע���ˡ�
//Ψһע���һ������������ö�ٵ��ֶν�������г��������⣬֮ǰһֱʹ�ú��滻 
//��ô�ܲ���ͨ��ö�ٽ�����滻���������أ� 
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
