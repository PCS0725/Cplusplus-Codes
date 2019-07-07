/*
Program : Implementation of Tree and related algorithms
Author : Prabhat Chand Sharma
Note : Some functionalities are incomplete and may not work
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};
class tree
{
public :
    node* root;
    void inorder(struct node*);  //DFS
    void postorder(node*);       //DFS
    void preorder(struct node*); //DFS
    void BFS_queue(struct node*); //BFS traversal using a queue.
    void level_in(int);            //Insertion using BFS
    struct node* right_deep(struct node*);   //finding the deepest node in right of a given node
    void deletion(struct node*,int);       //May not work
    void del_last(struct node*);           //May not work
    void setNull(node*);           //May not work
    struct node* create(int);      //Creates a node and return its pointer.
    int count_node(struct node*);  //count total nodes
    int count_leaf(struct node*);  //count leaf nodes
    int height(struct node*);     //computes height of tree
    int srch(struct node*,int);  //Searches for a given element
    tree()
    {
        root=NULL;
    }
};
void tree ::inorder(struct node* vertex)
{
    if(vertex==NULL)
        return;
    inorder(vertex->left);
    cout<<vertex->data<<" ";
    inorder(vertex->right);
}
void tree ::postorder(struct node* vertex)
{
    if(vertex==NULL)
        return;
    postorder(vertex->left);
    postorder(vertex->right);
    cout<<vertex->data<<" ";
}
void tree ::preorder(struct node* vertex)
{
    if(vertex==NULL)
        return;
    cout<<vertex->data<<" ";
    preorder(vertex->left);
    preorder(vertex->right);
}
struct node* tree :: create(int n)
{
    node* temp=new node;
    temp->data=n;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
void tree::BFS_queue(struct node* vertex)
{
    if(vertex==NULL)
         return;
    queue<struct node*> q;
    q.push(vertex);
    while(q.empty()==false)
    {
        node* nod=q.front();
        cout<<nod->data<<" ";
        q.pop();
        if(nod->left!=NULL)
            q.push(nod->left);
        if(nod->right!=NULL)
            q.push(nod->right);
    }
}
void tree:: level_in(int n)   //level insertion
{
    if(root==NULL)
    {
        root=create(n);
        return;
    }
    queue<struct node*> q;
    q.push(root);
    while(q.empty()==false)
    {
        node* nod=q.front();
        if(nod->left!=NULL)   //if it is occupied,push it to queue.
        {
            q.push(nod->left);
        }
        else                   //else, copy temp to it;
        {
            nod->left=create(n);
            return;
        }
        if(nod->right!=NULL)
        {
            q.push(nod->right);
        }
        else
        {
            nod->right=create(n);
            return ;
        }
        q.pop();
    }
}
struct node* tree::right_deep(struct node* vertex)
{
    if(vertex==nullptr)
        return vertex;
    if(vertex->left==NULL&&vertex->right==NULL)
        return vertex;
    if(vertex->right!=NULL)
        return (right_deep(vertex->right));
    else
        return (right_deep(vertex->left));
}
/*void tree::del_last(struct node* vertex)
{
    if(vertex==NULL)
        return;
    setNull(vertex);
}*/
void tree::setNull(node* root)
{
    queue<node*> q;
    q.push(root);
    node* ll=new node;
    ll=right_deep(root);
    while(q.empty()==false)
    {
        node* temp=q.front();
        q.pop();
        if(temp->left=ll)
        {
            temp->left=NULL;
            break;
        }
        if(temp->right=ll)
        {
            temp->right=NULL;
            break;
        }
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}
void tree::deletion(struct node* vertex,int key)
{
    if(vertex==NULL)
        return;
    queue<struct node*> q;
    q.push(vertex);
    int flag=0;
    node* keyNode=NULL;
    while(q.empty()==false)
    {
        node* temp=q.front();
        q.pop();
        if(temp->data==key)
        {
            flag=1;
            keyNode=temp;
            break;
        }
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
            q.push(temp->right);
    }
    if(flag)
    {
        node* last=new node;
        last=right_deep(vertex);
        cout<<"Deleting "<<keyNode->data<<endl;
        keyNode->data=last->data;
        setNull(last);
        delete last;
    }
    else
        cout<<"Key not found !"<<endl;
}
int tree::count_node(struct node* vertex)
{
    if(vertex==NULL)
        return 0;
    else
        return (1+count_node(vertex->left)+count_node(vertex->right));
}
int tree::count_leaf(struct node* vertex)
{
    if(vertex==NULL)
        return 0;
    else if(vertex->left==NULL&&vertex->right==NULL)
        return 1;
    else
        return (count_leaf(vertex->left)+count_leaf(vertex->right));
}
int tree::height(struct node* vertex)
{
    int level=0;
    if(vertex==NULL)
         return 0;
    queue<struct node*> q;
    q.push(vertex);
    while(q.empty()==false)
    {
        level++;
        node* nod=q.front();
        q.pop();
        if(nod->left!=NULL&&nod->right!=NULL)
        {
            q.push(nod->left);
            q.push(nod->right);
        }
        else if(nod->left!=NULL&&nod->right==NULL)
        {
            q.push(nod->left);
        }
        else if(nod->left==NULL&&nod->right!=NULL)
        {
            q.push(nod->right);
        }
    }
        return level;
}
int tree::srch(struct node* vertex,int item)
{
    if(vertex==NULL)
        return 0;
    queue<struct node*>q;
    q.push(vertex);
    while(q.empty()==false)
    {
        node* nod=q.front();
        q.pop();
        if(nod->data==item)
        {
            return 1;
        }
        if(nod->left==NULL&&nod->right==NULL)
            break;
        q.push(nod->left);
        q.push(nod->right);
    }
    return 0;
}
main()
{
    tree t;
    int a,c;a=0;
    do
    {
    cout<<"Enter your choice :\n1. Insert in level order\n2. Traverse in BFS\n3. Traverse in DFS(inorder)\n4. Traverse in DFS(preorder)\n5. Traverse in DFS(postorder)\n6. Count the nodes\n7. Count leaf nodes\n8. Calculate Height\n9. Search an element"<<endl;
    cin>>c;
    if(c==1)
    {
        int x;
        cout<<"Enter the elements : (-1 to terminate)"<<endl;
        while(1)
        {
            cin>>x;
            if(x==-1)
                break;
            t.level_in(x);
        }
    }
    else if(c==2)
        t.BFS_queue(t.root);
    else if(c==3)
    {
        t.inorder(t.root);
        cout<<endl;
    }
    else if(c==4)
    {
        t.preorder(t.root);
        cout<<endl;
    }
    else if(c==5)
    {
        t.postorder(t.root);
        cout<<endl;
    }
    else if(c==6)
        cout<<"Number of nodes is : "<<t.count_node(t.root)<<endl;
    else if(c==7)
        cout<<"Number of leaf nodes is : "<<t.count_leaf(t.root)<<endl;
    else if(c==8)
        cout<<"The height is  : "<<t.height(t.root)<<endl;
    else if(c==9)
    {
        int x;
        cout<<"Enter the element : "<<endl; cin>>x;
        if(t.srch(t.root,x))
            cout<<"Found ! "<<endl;
        else
            cout<<"Not found ! "<<endl;
    }
    else if(c==10)
    {
        int x;
        cout<<"Enter the element to be deleted : "<<endl; cin>>x;
        if(t.srch(t.root,x))
        {
           t.deletion(t.root,x);
        }
        else
            cout<<"Element is not present in the tree !"<<endl;
    }
    else
        cout<<"Wrong choice !"<<endl;
    cout<<endl<<"Want to continue ?(0 or 1)"<<endl;
    cin>>a;
    }while(a);
}
