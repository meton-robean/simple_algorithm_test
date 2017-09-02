#include <stdio.h>
#include <string.h>

using namespace std;
int loc; //global var
char str1[30]; //保存前序结果
char str2[30]; //保存中序结果
struct Node{
    Node *lchild;
    Node *rchild;
    char c;
}tree[50];

//node init
Node *creat()
{
    tree[loc].lchild=tree[loc].rchild=NULL;
    return &tree[loc++];

}

//后序遍历
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

//build the trees
Node *build_trees(int s1,int e1,int s2, int e2)
{
    Node *ret=creat();
    ret->c=str1[s1]; //get root node char
    int rootindex;
    for(int i=s2;i<=e2;i++)
    {
        if(str1[s1]==str2[i]){
            rootindex=i;
            break;
        }
    }
    if(rootindex!=s2) //have no left trees
    {
        ret->lchild=build_trees(s1+1,s1+(rootindex-s2),s2,rootindex-1);
    }
    if(rootindex!=e2) //have no rigth trees
    {
        ret->rchild=build_trees(s1+1+(rootindex-s2),e1, rootindex+1,e2 );
    }
    return ret;// return root Node
}


int main(){
    while(scanf("%s",str1)!=EOF)
    {
        scanf("%s",str2);
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node *T=build_trees(0,L1-1,0,L2-1);
        postOrder(T);
        printf("\n");
    }

    return 0;
}
