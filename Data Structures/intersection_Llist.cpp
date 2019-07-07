/*
Program : Finding the intersection between two linked lists
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
};
class l_list
{
public:
    node* start;node* last;
    void in_last(int);
    void srt();
    friend struct node* intersect(node*,node*);
    l_list();
    void display();
};
l_list::l_list()
{
    last=NULL;
    start=NULL;
}
void l_list::in_last(int c)   //Insertion at the last
{
    node* temp=new node;
    temp->data=c;
    temp->next=NULL;
    if(last==NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        last=temp;
    }
}
void l_list:: display()
{
    node* temp=start;
    while(temp!=NULL)  //This will access the last element also.temp->next!=null will stop  before processing last element.
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void l_list::srt()       //Sorting the linked list using bubble sort
{
    node* curr,*ptr;
    int temp;
    for(curr=start;curr->next!=NULL;curr=curr->next)  // It finds the appropriate position
       {
           for(ptr=curr->next;ptr!=NULL;ptr=ptr->next)
             {
                if((curr->data)>(ptr->data))
                {
                    temp=curr->data;
                    curr->data=ptr->data;
                    ptr->data=temp;
                }
             }
      }
}
struct node* intersect(node* a,node* b)
{
    //Finds the intersection of two given lists
    //Approach : Similar to merging two sorted arrays
    //Input : The head nodes of both the lists
    //Output: The pointer to the intersection list
    l_list l3;
    while(a!=NULL&&b!=NULL)
    {
        if(a->data==b->data)
        {
            l3.in_last(a->data);
            a=a->next;
            b=b->next;
        }
        else if(a->data<b->data)
        {
            a=a->next;
        }
        else
            b=b->next;
    }
    return l3.start;
}
main()
{
    l_list l1,l2,l3;
    cout<<"Enter list 1(-1 to terminate the input) : "<<endl;
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1)
            break;
        l1.in_last(x);
    }
    l1.srt();
    l1.display();
    cout<<endl;
    cout<<"Enter list 2(-1 to terminate the input) : "<<endl;
    while(1)
    {
        int x;
        cin>>x;
        if(x==-1)
            break;
        l2.in_last(x);
    }
    l2.srt();
    l2.display();
    cout<<endl;
    l3.start=intersect(l1.start,l2.start);
    cout<<"Intersection of given lists : "<<endl;
    l3.display();
}
