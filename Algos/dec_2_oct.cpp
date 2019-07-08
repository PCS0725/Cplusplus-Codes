/*
Program : Decimal to octal conversion using stacks
Author : Prabhat Chand Sharma
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
void stac :: push(int n)
{
    node* temp=new node;
    temp->data=n;
    temp->next=top;
    top=temp;
}
void stac:: pop()
{
    if(top==NULL)
      cout<<" Underflow !";
    node*temp=top;
    top=temp->next;
    delete temp;
}
void stac:: display()
{
    node* temp=top;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
}
int main()
{
    int n;
    cout<<"Enter the decimal number :"; cin>>n;
    stac s;
    if(n==0)
    {
        s.push(0);
        exit;
    }
    while(n>0)
    {
        int rem=n%8;
        s.push(rem);
        n=n/8;
    }
    cout<<"The Number in octal is : "<<endl;
    s.display();
    return 0;
}
