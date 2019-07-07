/*
Program : Implementation of stack data structure using a arrays.
Author  : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
#define m 10
class stac
{
    int a[m];
    int top;
public :
    void push(int);
    void pop();
    void display();
    stac();
};
void stac::push(int c)    //Insertion into the stack
{
    if(top==m)
         cout<<"Stack overflow !"<<endl;
    ++top;
    a[top]=c;
}
stac::stac()              //Initializing the top pointer to -1
{
    top=-1;
}
void stac::pop()
{
    if(top==-1)
     cout<<"Stack underflow"<<endl;
    else
     --top;
}
void stac::display()
{
    int x=0;
    while(x<=top)
    {
       cout<<a[x]<<" ";
       ++x;
    }
    cout<<endl;
}

int main()
{
    stac s; int a;
    do{
            int c;
            cout<<"Enter your choice :\n1. Push elements\n2. Pop elements\n3. Display"<<endl;
            cin>>c;
            if(c==1)
                {int n;
                cout<<"Enter the number of elements : "<<endl;
                cin>>n;
                cout<<"Enter the elements : "<<endl;
                for(int i=0;i<n;++i)
                {
                    int x; cin>>x;
                    s.push(x);
                }
                }
            else if(c==2)
            {
                s.pop();
            }
            else if(c==3)
                s.display();
            else
                cout<<"Wrong choice !"<<endl;
            cout<<"Want to continue ? (0 or 1)"<<endl; cin>>a;
    }while(a);
    return 0;
}
