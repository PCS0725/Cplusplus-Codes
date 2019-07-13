/*
Program : Tracking the maximum element in a stack efficiently.
Author : Prabhat Chand Sharma
Reference : geeksforgeeks.com
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> s1;  //The main stack
    stack<int> s2;  //auxillary stack to keep track of maximum element
    int a=0,f=0;
    do
    {
        int c;
        cout<<"Enter your choice : \n1.Push \n2.Pop\n3.Get maximum element \n";
        cin>>c;
        if(c==1)
        {
            int item;
            cout<<"\nEnter the element to be pushed : ";
            cin>>item;
            if(f==0)             //if it is the first element, push it to both the stacks
            {
                s1.push(item);
                s2.push(item);
                f=1;
            }
            else
            {
                s1.push(item);
                int el=s2.top();
                if(item>el)        //if the current element is greater than the max element, push it to s2.
                {
                    s2.push(item);
                }
                else               //else, push the top element of s2 back to s2
                    s2.push(el);
            }
        }
        else if(c==2)
        {
            if(s1.empty())
                cout<<"Underflow ! \n";
            else
            {
                cout<<s1.top()<<" has been popped ! \n";
                s1.pop();
                s2.pop();
            }
        }
        else if(c==3)
        {
            cout<<"The max element in the stack is : "<<s2.top();       //at any moment,top element of s2 is the maximum element.
        }
        cout<<"\nWant to continue ?(0 or 1) : ";
        cin>>a;
    }while(a);
}
