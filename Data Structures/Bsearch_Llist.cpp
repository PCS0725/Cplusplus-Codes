/*
Program : Implementation of binary search algorithm on linked lists
Author : Prabhat Chand Sharma
Note : May fail on certain test cases, needs improvement
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
    node* start;
    node* last;
    void in_last(int);
    void srt();
    l_list();
    void display();
    friend int bsearch(node*,node*);
};
l_list::l_list()
{
    last=NULL;
    start=NULL;
}
void l_list::in_last(int c)  //Insertion at the last
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
    cout<<endl;
}
void l_list::srt()                                  //Sorting the list using bubble sort
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
struct node* find_mid(node* st,node* en)  //Using a fast pointer and a slow pointer, find the mid node
{
    node*t1;node*t2;
    t1=st;t2=st;
    while(t1!=en&&t1->next!=en)
    {
        t1=t1->next->next;             //the fast pointer
        t2=t2->next;                   //the slow pointer
    }
    return t2;
}
int bsearch(node* first,node* rear,int item)   //The binary search function
{
    if(first->data==item||rear->data==item)
        return 1;
    if((first->data)>(rear->data)||first->data==rear->data)
        return 0;
    else
    {
        node* mid=find_mid(first,rear);
        if(mid->data==item)
            return 1;
        else if(mid->data>item)
        {
           return (bsearch(first,mid,item));
        }
        else if(mid->data<item)
        {
            return (bsearch(mid->next,rear,item));
        }
        else
            return 0;
    }
}
int main()
{
    l_list l1;
    cout<<"Enter the elements(-1 to terminate the input) : "<<endl;
    while(1)
    {
        int x; cin>>x;
        if(x==-1)
            break;
        l1.in_last(x);
    }
    l1.srt();
    l1.display();
    int item;
    cout<<"Enter the element to be searched : "<<endl;
    cin>>item;
    if(bsearch(l1.start,l1.last,item))
        cout<<"Found !";
    else
        cout<<"Not found ! ";
    return 0;
}
