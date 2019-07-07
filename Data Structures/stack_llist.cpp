/*
Program : Implementation of stack data structure using a linked list
Author  : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
class stac
{
    node* top;
public :
    void push(int);
    void pop();
    void display();
    stac();
};
stac::stac()
{
    top=NULL;//space is not yet allocated to top ptr
}
void stac :: push(int n)   //Insertion at the top
{
    node* temp=new node;
    temp->data=n;
    temp->next=top;
    top=temp;
}
void stac:: pop()           //Deletion at the top(Most recently inserted node)
{
    if(top==NULL)
      cout<<" Underflow !";
    node*temp=top;
    top=temp->next;
    delete temp;
}
void stac:: display()       //Traversal of the list
{
    node* temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main()
{
    stac s;
    int a=0;
    do
    {
        int c;
        cout<<"Enter your choice : \n1. Push\n2. Pop\n3. Display "<<endl;
        cin>>c;
        if(c==1)
        {
            cout<<"Enter the elements : ";
        while(1)
        {
           int c;
           cin>>c;
           if(c==-1)
             break;
           s.push(c);
        }
        }
        else if(c==2)
        {
            int x;
            cout<<"How many elements to pop ? ";
            cin>>x;
            for(int i=0;i<x;++i)
                s.pop();
        }
        else if(c==3)
            s.display();
        else
            cout<<endl<<" Wrong choice!"<<endl;
        cout<<"Want to continue ? ";cin>>a;
    }while(a);
    return 0;
}
