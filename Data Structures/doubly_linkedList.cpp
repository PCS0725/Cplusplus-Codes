/*
Program : Implementation of doubly linked list and its functions
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
class l_list
{
    node* start;
    node* last;
public:
    void in_start(int);   //insertion at the start
    void in_last(int);    //insertion at the end
    void del_start();     //deletion from the start
    void del_last();      //deletion from the end
    void display();       //traversal
    l_list();
    void search(int);     //searching an element in the list
    void in_pos(int,int);  //insertion at a given position
    void del_pos(int);     //deletion from a given position
    void srt();            //sorting a given linked list
    int f_length();        //returns the length of given linked list
    void find_mid();       // finding the mid element
};
l_list::l_list()
{
    last=NULL;
    start=NULL;
}
void l_list::in_last(int c)
{
    node* temp=new node;
    temp->data=c;
    temp->next=NULL;
    temp->prev=NULL;
    if(last==NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        last->next=temp;
        temp->prev=last;
        last=temp;
    }
}
void l_list::in_start(int c)
{
    node* temp=new node;
    temp->data=c;
    if(start==NULL)
    {
        temp->next=NULL;
        temp->prev=nullptr;
        start=temp;
        last=temp;
    }
    else
    {
        temp->next=start;
        temp->prev=NULL;
        start=temp;
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
void l_list:: del_start()
{
    if(start==NULL)
        cout<<" List is Empty!";
    node* temp=start;
    start=start->next;
    start->prev=nullptr;
    if(start==NULL)
        last=NULL;
    delete temp;
}
void l_list::del_last()
{
    node* temp=last;
    last=last->prev;
    last->next=NULL;
    delete temp;
}
void l_list::search(int x)
{
    node* temp=start;
    node* loc=NULL;
    int cnt;
    cnt=1;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            loc=temp;
            break;
        }
        else
        {
            temp=temp->next;
            cnt++;
        }

    }
    if(loc!=NULL)
        cout<<"Element found at position :"<<cnt<<" from the start"<<endl;
    else
        cout<<"Element not found!"<<endl;
}
void l_list::in_pos(int item,int pos)
{
    node* curr=start;
    node* prevs;
    node*temp=new node;
    temp->data=item;
    temp->next==NULL;
    temp->prev=NULL;
    if(pos==1)
    {
        in_start(item);
        return ;
    }
    int i=1;
    while(i<pos)
    {
        prevs=curr;
        curr=curr->next;
        i+=1;
    }
    temp->prev=prevs;
    prevs->next=temp;
    temp->next=curr;
}
void l_list::del_pos(int pos)
{
    int i=1;
    if(pos==1)
    {
        del_start();
        return;
    }
    node* temp=start;
    node* prevs;
    while(i<pos)
    {
        prevs=temp;
        temp=temp->next;
        ++i;
    }
    temp->prev=prevs;
    prevs->next=temp->next;
    delete temp;
}
void l_list::srt()
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

void l_list::find_mid()
{
    node* ptr1;node* ptr2;
    ptr2=start;
    ptr1=ptr2;
    while(ptr2!=nullptr&&ptr2->next!=nullptr)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }
    cout<<"The mid element is : "<<ptr1->data<<endl;
}
//function to find the length of the list
int l_list::f_length()
{
    int c=0;
    node* ptr=start;
    while(ptr!=nullptr)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
main()
{
    l_list l1;
    int a;
    do
    {
        int c;
        cout<<" Enter your choice :\n 1.Insert at start\n 2.Insert at last\n 3.Display all elements\n 4.Delete from start\n 5.Delete from last\n 6.Search an element\n 7.Insert at a given position\n 8. Delete a given position\n 9.Sort the list\n 11.Find the mid\n 12.Find Length"<<endl;
        cin>>c;
        if(c==1)
        {
            int x;
            cout<<" Enter the element(s) :"<<endl;
            while(1)
            {
                cin>>x;
                if(x==-1)
                    break;
                l1.in_start(x);
            }
            int y=0;
            cout<<"  Want to display ? "; cin>>y;
            if(y)
                l1.display();

        }
        else if(c==2)
        {
            int x;
            cout<<" Enter the element(s) :"<<endl;
            while(1)
            {
                cin>>x;
                if(x==-1)
                    break;
                l1.in_last(x);
            }
            int y=0;
            cout<<"  Want to display ? "; cin>>y;
            if(y)
                l1.display();
        }
        else if(c==3)
            l1.display();
        else if(c==4)
        {
            int x;
            cout<<"How many elements to delete? : ";
            cin>>x;
            while(x--)
              l1.del_start();
            int y=0;
            cout<<"  Want to display ? "; cin>>y;
            if(y)
                l1.display();
        }
        else if(c==5)
        {
            int x;int y=0;
            cout<<"How many elements to delete? : ";
            cin>>x;
            while(x--)
              l1.del_last();
            cout<<" Want to display ? ";cin>>y;
            if(y)
                l1.display();
        }
        else if(c==6)
        {
            int x;
            cout<<"Enter the element : "; cin>>x;
            l1.search(x);
        }
        else if(c==7)
        {
            int item,pos;int x=0;
            cout<<"Enter the data and position : ";cin>>item>>pos;
            l1.in_pos(item,pos);
            cout<<" Want to display ? ";cin>>x;
            if(x)
                l1.display();
        }
        else if(c==8)
        {
            int pos;int x=0;
            cout<<"Enter the position : "; cin>>pos;
            l1.del_pos(pos);
            cout<<" Want to display ? ";cin>>x;
            if(x)
                l1.display();
        }
        else if(c==9)
        {
            l1.srt();int x=0;
            cout<<"  Want to display ? "; cin>>x;
            if(x)
                l1.display();
        }
        else if(c==11)
            l1.find_mid();
        else if(c==12)
            cout<<l1.f_length();
        else
            cout<<" Wrong choice !";
        cout<<" Want to continue ? 1. Yes  2. No :  ";
        cin>>a;
    }while(a==1);
}


