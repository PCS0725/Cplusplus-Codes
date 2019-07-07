/*
Program : Implementation of queue data structure using a arrays.
Author  : Prabhat Chand Sharma
*/
#include<iostream>
#define max 100
using namespace std;
class qu
{
    int a[max];
    int head,tail;
public :
    qu();
    void add(int);
    void del();
    void srch(int);
    int len();
    void display();
};
qu::qu()    //the head and tail pointers point to first and last elements respectively
{
    head=0;
    tail=0;
}
void qu::add(int n)   //Insertion of a new element(at the front)
{
    if(head==max)
    {
        cout<<"Overflow !"<<endl;
        return;
    }
    a[head]=n;
    ++head;
}
void qu::del()         //Deletion of an element
{
    if(tail==head)
        cout<<"It is the last element !";
    int t=a[tail];
    cout<<t<<" has been deleted ! "<<endl;
    ++tail;
}
void qu:: display()
{
    for(int i=tail;i<head;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
void qu::srch(int n)    //searching an element
{
    for(int i=tail;i<head;++i)
    {
        if(a[i]==n)
        {
            cout<<"Found at "<<i<<"th position"<<endl;
            return;
        }
    }
        cout<<"NOt found !"<<endl;
}
int qu:: len()
{
    int cnt=0;
    for(int i=tail;i<head;++i)
        cnt++;
    return cnt;
}
main()
{
    qu q;
    int l;cin>>l;
    cout<<"Enter the data : ";
    int x;
    while(l--)
    {
        cin>>x;
        q.add(x);
    }
    int m=0;
    do
    {
    int c;
    cout<<"Enter your choice : \n 1.Add more\n 2.Delete\n 3.Search an element\n 4.Display\n 5.Find length"<<endl;
    cin>>c;
    if(c==1)
    {
    int y;
    int l1; cin>>l1;
    while(l1--)
    {
        cin>>y;
        q.add(y);
    }
    }
    else if(c==2)
        q.del();
    else if(c==3)
    {
        int b;
        cout<<"Enter the element to be searched : "<<endl; cin>>b;
        q.srch(b);
    }
    else if(c==4)
        q.display();
    else if(c==5)
        cout<<"Length is : "<<q.len();
    else
     cout<<"Wrong choice ! ";
    cout<<"Want to continue(0 or 1) : ";
    cin>>m;
    }while(m);
}
