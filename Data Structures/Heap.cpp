/*
Program : Implementation of heap data structure
Author : Prabhat Chand Sharma
Note : The given implementation is very naive. Improved version is provided in the heap sort program
*/
#include<bits/stdc++.h>
using namespace std;
class heap
{
    int* arr;
    int max_size;
    int position;
public :
    heap(int x)
    {
        max_size=x;
        position =0;
        arr=new int[max_size];
    }
    void in_node(int);
    int l_child(int);
    int r_child(int);
    void display();
    int del_top();
};
void heap:: in_node(int x)  // Insertion of the node(integrated heapify function)
{
    if(position==0)
    {
        arr[position]=x;
        ++position;
        return;
    }
    arr[position]=x;
    int temp_pos=position;
    int parent=(temp_pos-1)/2;
    while(parent>=0)
    {
    if(parent<0)
        break;
    if(arr[parent]>arr[temp_pos])
    {
        int temp=arr[parent];
        arr[parent]=arr[temp_pos];
        arr[temp_pos]=temp;
        temp_pos=parent;
        parent=(temp_pos-1)/2;
    }
    else
        break;
    }
    ++position;
}
void heap::display()
{
    for(int i=0;i<position;++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int heap:: del_top()    //Retrieval and deletion of the top element(the min element)
{
    int S=arr[0];                      //copy the last element to the root of heap tree
    int last=arr[position-1];          //and delete delete the count by 1
    arr[0]=last;                       //heapify the tree starting from the root node
    position--;
    int i=0;
    while(i<position)
    {
            if((arr[i]>arr[2*i+1])&&(arr[i]>=arr[2*i+2]))     //if parent node is greater than both the children
            {
                int t=arr[i];
                arr[i]=arr[2*i+1];
                arr[2*i+1]=t;
                i=2*i+1;
            }
            else if((arr[i]>arr[2*i+1])&&(arr[i]<=arr[2*i+2]))
            {
                int t=arr[i];
                arr[i]=arr[2*i+1];
                arr[2*i+1]=t;
                i=2*i+1;
            }
            else if((arr[i]>arr[2*i+2])&&(arr[i]<=arr[2*i+2]))
            {
                int t=arr[i];
                arr[i]=arr[2*i+2];
                arr[2*i+2]=t;
                i=2*i+2;
            }
            else
                return S;
        }
    return S;
}
int main()
{
    int a=0;
    int b;
    cout<<"Enter the number of elements : "<<endl; cin>>b;
     heap h(b);
    cout<<"Enter the elements(-1 to terminate) : ";
        while(1)
        {
            int x;
            cin>>x;
            if(x==-1)
                break;
            h.in_node(x);
        }

    do
    {

        int c;
        cout<<"Enter your choice :  1.Retrieve the top element\n2.Display all the elements of the heap\n";
        cin>>c;
        if(c==1)
        {
            cout<<"Top element is : "<<h.del_top();
            cout<<endl;
        }
        else if(c==2)
        {
            cout<<"The heap elements are : ";
            h.display();

        }
        else
            cout<<"Wrong choice ! ";
        cout<<"  Want to continue (0 or 1)? ";
        cin>>a;

    }while(a);
    cout<<"Thank You ! ";
    return 0;
}
