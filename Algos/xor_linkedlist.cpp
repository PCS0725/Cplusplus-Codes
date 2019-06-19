//Problem : Implementation of a memory efficient doubly linked list
//Author : Prabhat Chand Sharma
//Solution : Instead of storing next and previous pointers,store their XOR
//Issue : XOR of pointers is not supported by C++
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    uintptr_t npx;
};
node* startNode=NULL;
node*endNode=NULL;
void in_beg(int x)
{
    node* temp=new node;
    temp->data=x;
    if(startNode==NULL)
    {
        temp->npx = NULL;
        startNode = temp;
        endNode = temp;
    }
    else
    {
        temp->npx=endNode;
        endNode=temp;
    }
}
void seedha() //forward traversal
{
    if(startNode==NULL)
        return;
    uintptr_t temp=(uintptr_t)startNode;
    uintptr_t prev=(uintptr_t)NULL;
    while((node*)temp!=endNode)
    {
        cout<<(node*)temp->data<<" ";
        uintptr_t t2=temp;
        temp=(uintptr_t)((node*)temp->npx)^(uintptr_t)prev;// this implementation is not supported in c++
        prev=t2;
    }
    cout<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        in_beg(x);
    }
   // cout<<"Forward traversal of the list : "<<seedha();
}
