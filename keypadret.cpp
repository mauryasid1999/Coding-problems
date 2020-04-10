#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
 */  int p=num%10,c;
    string s;
    if(p==2){s="abc";}
    if(p==3){s="def";}
    if(p==4){s="ghi";}
    if(p==5){s="jkl";}
    if(p==6){s="mno";}
    if(p==7){s="pqrs";}
    if(p==8){s="tuv";}
    if(p==9){s="wxyz";}

    if(num==0 || num==1){
        output[0]="";
       return 1;
    }

    else{
       c=keypad(num/10,output);

    for(int i=0;i<c;i++){
      string temp= output[i];
        for(int j=0;j<s.size();j++){
            output[j*c+i]=temp+s[j];
        }
    }

return s.size()*c;
}

}

#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}










