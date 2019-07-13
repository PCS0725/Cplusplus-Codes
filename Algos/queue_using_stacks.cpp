/*
Program : Implementation of queue using two stacks.
Author : Prabhat Chand Sharma
Complexity : Enqueue - O(1), Dequeue - O(n).
*/
#include<bits/stdc++.h>
using namespace std;

void enqueue(stack<int> &s1,int x)
{
    s1.push(x);
}
int dequeue(stack<int> &s1,stack<int> &s2)
{
    if(s2.empty()==false)
    {
        int val=s2.top();
        s2.pop();
        return val;
    }
    else
    {
        if(s1.empty()&&s2.empty())
        {
            cout<<"Queue is empty! ";
            return 0;
        }
        while(!s1.empty())
        {
            int val=s1.top();
            s1.pop();
            s2.push(val);
        }
        int val2=s2.top();
        s2.pop();
        return val2;
    }
}
int main()
{
    stack<int> s1;
    stack<int> s2;
    int a=0;
    do
    {
        int c;
        cout<<"\nEnter your choice : 1.Enqueue \n2.Dequeue  ";
        cin>>c;
        if(c==1)
        {
            int item;
            cout<<"\nEnter the value to be inserted : ";
            cin>>item;
            enqueue(s1,item);
        }
        else if(c==2)
        {
            cout<<"\nThe value removed is : "<<dequeue(s1,s2);
        }
        else
            cout<<"\nWrong choice !";
        cout<<"Want to continue?(0 or 1) : ";
        cin>>a;
    }while(a);
    cout<<"\nThank you !";
}
