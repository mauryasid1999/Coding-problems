#include <iostream>
using namespace std;
#include<stack>

bool checkBalanced(char *exp) {
	// Write your code here

    stack<char>s;
    char x;
    int j=0;
    while(exp[j]!='\0')
    {
        j++;
    }

    for(int i=0;i<j;i++)
    {
        if(exp[i]=='(' || exp[i]=='{'  || exp[i]=='[')
        {
            s.push(exp[i]);
            continue;
        }

    switch(exp[i])
    {

        case ')':
            if(s.empty())
     return false;
            x=s.top();
            s.pop();

            if(x=='{' || x=='[' )
            {
                return false;
            }

           break;

        case '}':
            if(s.empty())
     return false;
            x=s.top();
            s.pop();

               if(x=='(' || x=='[' )
            {
                return false;
            }

            break;

        case ']':
            if(s.empty())
     return false;

            x=s.top();
            s.pop();
               if(x=='{' || x=='(')
            {
                return false;
            }

            break;
    }
}

return (s.empty()); //empty
}

int main() {
    char input[100000];
    cin.getline(input, 100000);
//    cin >> input;
    if(checkBalanced(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
