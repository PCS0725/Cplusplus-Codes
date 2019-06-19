/*
Program : TOWER OF HANOI PROBLEM
Author : Prabhat Chand Sharma
*/
#include<iostream>
using namespace std;
void t(int,char,char,char);
int main()
{
    int n;
    cout<<"Enter the no of discs : ";
    cin>>n;
    char a,b,c;
    a='A';b='B',c='C';
    t(n,a,b,c);          //A is source tower,C is the destination,B is the auxillary tower.
    return 0;
}
void t(int n,char beg,char aux,char last)
{
    if(n>=1)
    {
        t(n-1,beg,last,aux);                   //Move n-1 discs to auxillary tower
        cout<<" Move "<<beg<<" to "<<last<<endl; //move the last disc to destination tower.
        t(n-1,aux,beg,last);                      //Move the n-1 discs to the destination.
    }
}
