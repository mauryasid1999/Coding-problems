
#include <iostream>
using namespace std;


#include<stack>
int countBracketReversals(char input[]){

   int j=0;
    while(input[j]!='\0')
    {
        j++;
    }
    if(j%2!=0)
    {return -1;}
    stack <char> s;
    for(int i=0;i<j;i++)
    {
        if(input[i]=='}' && !s.empty()){

            if(s.top()=='{'){
                s.pop();
            }
            else{
                s.push(input[i]);
            }
        }
        else{
            s.push(input[i]);
        }
    }

    int l=s.size();

    int n=0;
    while(!s.empty() && s.top()=='{')
    {
        s.pop();
        n++;
    }

    return (l/2+n%2);

}


int main() {
    char input[10000];
    cin >> input;
    cout << countBracketReversals(input) << endl;
}
