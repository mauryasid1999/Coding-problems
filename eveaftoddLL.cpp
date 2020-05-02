#include <iostream>
node* arrange_LinkedList(node* head)
{
    //write your code here

    node* oddhead=NULL;
    node* oddtail=NULL;
    node* evenhead=NULL;
    node* eventail=NULL;

    node* temp=head;

    while(temp!=NULL)
    {
        if((temp->data)%2!=0){

        if(oddhead==NULL){
            oddhead=oddtail=temp;
        }
            else{
                oddtail->next=temp;
                oddtail=oddtail->next;
            }
        }
        else

        {
            if(evenhead==NULL)
            {
                evenhead=eventail=temp;
            }
            else{
            eventail->next=temp;
            eventail=eventail->next;
        }

    }

    temp=temp->next;
}

    if(oddhead){
        head=oddhead;
     oddtail->next=evenhead;
    }
    if(evenhead)
    {
        eventail->next=NULL;
    }
    return head;
}




class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
#include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node*head=takeinput();
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}

