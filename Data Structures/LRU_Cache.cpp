/*
Program     : Implementation of Least Recently Used(LRU) Cache.
Description : Implement cache of size n. Methods :
              1.set(key,value) : Sets the key to value, if the current size of cache=n, then remove
              least recently used element and insert the new value.
              2.get(key) : Returns the value assosiated with key,if it exists, otherwise return null.
              Expected complexity : O(1) for all operations.
Author   :    Prabhat Chand Sharma
Approach :    Using hash map for storing and retrieving, and a doubly linked list for ordering the keys.
              Store key and address of node in hash map and value in nodes of doubly linked list.
              Reference : medium.com  ,geeksforgeeks.com
*/
#include<bits/stdc++.h>
using namespace std;
class cache
{
    list<int> dq;                                        //the doubly linked list to store values in the nodes
    unordered_map<int, list<int>::iterator>  hashmap;    //the hash map to store key and the address of node storing the value
    int msize;                                           //the maximum size of the cache
public :
    cache(int);
    void setkey(int,int);
    int getkey(int);
};
cache ::cache(int x)
{
    msize=x;
}
void cache::setkey(int key,int value)
{
    if(hashmap.find(key)==hashmap.end())           //if the key is not present in the map,insert it.
    {
        if(dq.size()==msize)               //if the cache is full, remove the least recently used item(the last node in the list)
        {
            int last=dq.back();
            cout<<"\nThe least recently used value : "<<last<<" is being removed ! ";
            dq.pop_back();
            //hashmap.erase(last);
        }
        dq.push_front(value);                 //insert the new node at the front of list
        hashmap[key]=dq.begin();             //the address of inserted node is pushed to the map
    }
    else
        cout<<"\nKey is already present";
}
int cache :: getkey(int key)
{
    if(hashmap.find(key)==hashmap.end())
    {
        cout<<"The key is not present in the cache !\n";
        return -1;
    }
    else                     //if the key is present, return the value and move the node to the front
    {
        list<int> ::iterator it=hashmap[key];
        int value=*it;
        dq.erase(hashmap[key]);                             //if the key is present in the cache, move it to the front of list
        dq.push_front(value);
        hashmap[key]=dq.begin();
        return value;
    }
}
int main()
{
    cout<<"Enter the size of cache : ";
    int n;cin>>n;
    cache c(n);
    int a=0;
    do
    {
        int ch;
        cout<<"\n Enter your choice : \n1. Set a key,value pair\n2.Get value of a key\n";
        cin>>ch;
        if(ch==1)
        {
            int k,v;
            cout<<"Enter the key-value pair : ";
            cin>>k>>v;
            c.setkey(k,v);
        }
        else if(ch==2)
        {
            int k;
            cout<<"Enter the key : ";
            cin>>k;
            c.getkey(k);
        }
        else
            cout<<"Wrong choice ! ";
        cout<<"\nWant to continue?(0 or 1) :";
        cin>>a;
    }while(a);
}
