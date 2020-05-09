#include <iostream>
#include <stack>
using namespace std;


int main() {
    stack<int> s1, s2;
    int size;
    cin >> size;

    int val;
    for(int i = 0; i < size; i++) {
    	cin >> val;
    	s1.push(val);
    }
    reverseStack(s1, s2);
    while(!s1.empty()) {
    	cout << s1.top() << " ";
    	s1.pop();
    }
}


void reverseStack(stack<int> &input, stack<int> &extra) {


    int d;
 if(input.empty())
 {
     return ;
 }
    if(input.size()==1)
    {
        return;
    }
    int x=input.top();
    input.pop();
    reverseStack(input,extra);

    while(!input.empty()){
    d= input.top();
    input.pop();
    extra.push(d);
    }
    int e;
    input.push(x);
    while(!extra.empty()){
        e=extra.top();
    extra.pop();
    input.push(e);
    }

}
