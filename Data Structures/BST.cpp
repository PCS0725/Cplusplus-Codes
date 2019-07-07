/*
Program : Implementation if binary search tree
Author : Prabhat Chand Sharma
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
};
class tree
{

public :
    node* root;
    void in(int);       //Insertion in the BST
    int srch(int);       //Searching at item in BST
    int srch1(int);     //Searching an item in BST
    void del(int);      //Deletion from BST(Not working
    void inorder();     //Non-recursive inorder traversal
    void inord(node*);
    void preord(node*);
    void postord(node*);
    struct node* FindMin(node*);
    struct node* Delete(struct node*,int);
    void preorder();                           //Non recursive preorder traversal
    struct node* srch_recursive(int,node*);
    tree()
    {
        root=NULL;
    }
};
void tree::in(int item)      //Insertion in binary search tree
{
    node* temp=root;
    node* newnode=new node;
    newnode->data=item;
    newnode->left=NULL;
    newnode->right=NULL;
    if(temp==NULL)
    {
        root=newnode;
        return;
    }
    while(temp!=NULL)
    {
        if(temp->data>item)  //if condition is modified to temp->data<item,,,then inorder traversal gives descending order.
        {
            if(temp->left!=NULL)
            {
                temp=temp->left;
                continue;
            }
            else
            {
                temp->left=newnode;
                return;
            }
        }
        else
        {
            if(temp->right!=NULL)
            {
                temp=temp->right;
                continue;           //Continue same process for right node.
            }
            else
            {
               temp->right=newnode;
               return;
            }
        }
    }
}
void tree ::inord(struct node* vertex)   //recursive inorder traversal
{
    if(vertex==NULL)
        return;
    inord(vertex->left);
    cout<<vertex->data<<" ";
    inord(vertex->right);
}
void tree::inorder()                 //NON-RECURSIVE PREORDER TRAVERSAL;
{
    node*temp=root;
    stack<struct node*> s;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            temp=temp->left;
        }
        if(s.empty()) return ;
        temp=s.top();
        cout<<temp->data<<" ";
        s.pop();
        temp=temp->right;
    }
    cout<<endl;
}
void tree::preorder()                 //NON-RECURSIVE PREORDER TRAVERSAL;
{
    node*temp=root;
    stack<struct node*> s;
    while(1)
    {
        while(temp!=NULL)
        {
            s.push(temp);
            cout<<temp->data<<" ";
            temp=temp->left;
        }
        if(s.empty()) return ;
        temp=s.top();
        s.pop();
        temp=temp->right;
    }
    cout<<endl;
}
void tree ::postord(struct node* vertex)  //Recursive postorder traversal
{
    if(vertex==NULL)
        return;
    postord(vertex->left);
    postord(vertex->right);
    cout<<vertex->data<<" ";
}
void tree ::preord(struct node* vertex)   //Recursive preorder traversal
{
    if(vertex==NULL)
        return;
    cout<<vertex->data<<" ";
    preord(vertex->left);
    preord(vertex->right);
}
int tree::srch(int item)     //Longer code for non-recursive search
{
    node* temp=root;
    if(root==NULL)
    {
        return 0;
    }
    else if(root->data==item)
    {
        return 1;
    }
    while(temp!=NULL)
    {
        if(temp->data>item)
        {
            if(temp->left!=NULL)
            {
                temp=temp->left;
                if(temp->data==item) return 1;
                continue;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if(temp->right!=NULL)
            {
                temp=temp->right;
                if(temp->data==item) return 1;
                continue;
            }
            else
            {
                return 0;
            }
        }
    }
}
int tree::srch1(int item)     //shorter code for non-recursive search
{
    node*temp=root;
    while(temp)
    {
        if(temp->data==item)
            return 1;
        else if(temp->data>item)
            temp=temp->left;
        else
            temp=temp->right;
    }
    return 0;
}
/*struct node* tree::srch_recursive(int key,node* vertex)//erroneous
{
   if(vertex==NULL)
    return vertex;
   if(root->data<key)
    root=srch_recursive(key,root->right);
   else
    root=srch_recursive(key,root->left);
}*/
struct node* tree:: FindMin(node* root)//erroneous
{
    node* curr=root;
    while(curr->left==NULL)
        curr=curr->left;
    return curr;
}
struct node* tree::Delete(node* root,int data)   //erroneous ,may not work.
{
    if(root==NULL)
    {
        return root;
    }
    else if(root->data>data)
        root->left=Delete(root->left,data);
    else if(root->data<data)
        root->right=Delete(root->right,data);
    else
    {
        if(root->left==NULL&&root->right==NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->left==NULL)
        {
            struct node* temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            struct node* temp=FindMin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    tree t;
    int a;
    do
    {
        int c;
        cout<<"Enter your choice : \n1.Insert\n 2.Delete node\n 3. Search\n 4.Inorder traversal\n 5. Preorder traversal\n 6.Postorder Traversal\n" ; cin>>c;
        if(c==1)
        {
            while(1)
            {
                int x; cin>>x;
                if(x==-1)
                    break;
                t.in(x);
            }
        }
        else if(c==2)
        {
            int x; cout<<"Enter the node you want to delete : \n "; cin>>x;
            t.Delete(t.root,x);
        }
        else if(c==3)
        {
            int x;
            cout<<"Enter the item to search for : \n"; cin>>x;
            t.srch1(x);
        }
        else if(c==4)
            t.inord();
        else if(c==5)
            t.preord();
        else if(c==6)
            t.postord();
    }
    return 0;
}
