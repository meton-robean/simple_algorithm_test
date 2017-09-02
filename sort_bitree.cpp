#include <stdio.h>
#include <string.h>

using namespace std;
int loc;
struct Node{
    Node *lchild;
    Node *rchild;
    int c;

}tree[100];

void preOrder(Node *T)
{
    printf("%c",T->c);
    if(T->lchild!=NULL)
    {
        preOrder(T->lchild);
    }
    if(T->rchild!=NULL)
    {
        preOrder(T->rchild);
    }
}

void inOrder(Node *T)
{
    if(T->lchild!=NULL)
    {
        inOrder(T->lchild);
    }
    printf("%c",T->c);
    if(T->rchild!=NULL)
    {
        inOrder(T->rchild);
    }

}

void postOrder(Node *T)
{
    if(T->lchild!=NULL)
    {
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL)
    {
        postOrder(T->rchild);
    }
    printf("%c",T->c);
}

//node init
Node *create()
{
    tree[loc].lchild=tree[loc].rchild=NULL;
    return &tree[loc++];

}

Node *Insert(Node *T,int x)
{
    if(T==NULL)
    {
        T=create();
        T->c=x;
        return T;
    }
    else if(x<T->c)
    {
        T->lchild=Insert(T->lchild,x);
    }
    else if(x>T->c){
        T->rchild=Insert(T->rchild,x);
    }

    return T;
}


int main()
{
    int n;
    while(scanf("%s",&n)!=EOF)
    {
        loc=0;
        Node *T=NULL;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            T=Insert(T,x);
        }
        preOrder(T);
        printf("\n");
        inOrder(T);
        printf("\n");
        postOrder(T);
        printf("\n");
    }    
    return 0;
}