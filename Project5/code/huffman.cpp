#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
const int maxn=400;
const int INF=2147483647;
int n,m,length;
char c[maxn];//store the character
int f[maxn];//store the frequency (also the weight)
typedef struct Treenode* HuffmanTree; //structure
struct Treenode
{
    int val;
    HuffmanTree left;
    HuffmanTree right;
};
struct cmp//used for priority queue 
{
    bool operator()(HuffmanTree A, HuffmanTree B)
    {
        return A->val>B->val;//put the node with smallest key value to top
    } 
};
HuffmanTree create_tree()//tree node initialize
{
    HuffmanTree T = (HuffmanTree)malloc(sizeof(Treenode));
    T->left=NULL;
    T->right=NULL;
    T->val=0;
    return T;
}
priority_queue<HuffmanTree,vector<HuffmanTree>,cmp> heap;//declare of the priority queue, replace the heap

/////////////////////////////////////////////////
// build():
// We select 2 Huffman Tree with the least frequency, 
// and build a binary tree, then insert the new tree into the priority queue. 
// Repeat this operation for N-1 times (N elements in total).
/////////////////////////////////////////////////
HuffmanTree build()
{
    HuffmanTree T;
    for(int i=1;i<n;i++)
    {
        T=create_tree();
        T->left=heap.top();
        heap.pop();
        T->right=heap.top();
        heap.pop();
        T->val=T->left->val+T->right->val;
        // the key value is the left subtree value plus right subtree value
        heap.push(T);
    }
    T=heap.top();
    heap.pop();
    return T;
} 
int WPL(HuffmanTree root, int depth)
{
    if(root->left||root->right)//Not leaf
    return WPL(root->left,depth+1)+WPL(root->right,depth+1);
    else return root->val*depth;//reach leaf, return the weight multiply depth
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c[i]>>f[i];
        HuffmanTree T=create_tree();
        T->val=f[i];
        heap.push(T);
        //Huffman Tree list initialize
    }
    HuffmanTree ans=build();
    int length=WPL(ans,0);
    cin>>m;
    for(int i=0;i<m;i++)
    {
        char ch;
        int flag=0;
        char str[70][70];
        int wgh=0;
        for(int j=0;j<n;j++)
        {
            cin>>ch>>str[j];
            wgh+=strlen(str[j])*f[j];
            //input the code list and calculate the WPL at the same time
        }
        if(wgh!=length)
        {
            cout<<"No"<<endl;
            continue;
        }
        for(int j=0;j<n;j++)
        for(int k=j+1;k<n;k++)
        {
            int flag2=0;
            int len1=strlen(str[j]);
            int len2=strlen(str[k]);
            //str[j],str[k]:the chosen two code to compare
            for(int l=0;l<len1&&l<len2;l++)
            if(str[j][l]!=str[k][l]){flag2=1;break;}//if there exist one bit distinct, it's legal; else it's prefix code
            if(!flag2)flag=1;
        }
        if(flag)cout<<"No"<<endl;//if exist prefix code, it's not legal
        else cout<<"Yes"<<endl;
    }
    /*
    //the following code is the prefix code check completed by the firsy way, mentioned in report
    for(int i=0;i<m;i++)
    {
        char ch;
        char str[70];
        bool flag=0;
        int test_WPL=0;
        HuffmanTree test=create_tree();
        for(int l=0;l<n;l++)
        {
            cin>>ch>>str;
            HuffmanTree branch=test;
            int weight;
            int len=strlen(str);
            if(len>n){flag=1;break;}
            for(int k=0;k<len;k++)
            {
                if(str[k]=='0')
                {
                    if(!branch->left)branch->left=create_tree();
                    branch=branch->left;
                }
                else if(str[k]=='1')
                {
                    if(!branch->right)branch->right=create_tree();
                    branch=branch->right;
                }
                if(branch->val)
                {
                    flag=1;
                    break;
                }
            }
            if(branch->left||branch->right)flag=1;
            if(flag)break;
            branch->val=f[l];
            test_WPL+=f[l]*len;
        }
        if(!flag&&test_WPL==length)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }*/
    system("pause"); 
    return 0;
}
