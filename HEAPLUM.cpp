#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node *left,*right;
    string label;
    int priority;

    Node():left(NULL),right(NULL),priority(0)
    {}
    
};
struct treap
{
    struct Node   *roots;
    size_t tree_size;

    treap():tree_size(0)
    {
    }
    
    void insert(string &label,int &pri)
    {
        Node *temp = new Node();
        temp->label=label;
        temp->priority=pri;
        if(tree_size==0)
        {
            roots = temp;
            tree_size++;
            return;
        }

        Node *where = roots,*prev = NULL;
        while(where!=NULL and where->priority > temp->priority)
        {
            prev = where;
            if(temp->label < where->label)
                where = where->left;
            else
                where = where->right;
        }
        if(where==NULL)
        {
            if(temp->label < prev->label)
                prev->left = temp;
            else
                prev->right = temp;
        }
        else
        {
            if(prev==NULL)
            {
                roots = temp;
                if(where->label < roots->label)
                    roots->left = where;
                else
                    roots->right = where;
            }
            else
            {
                if(where->label < prev->label)
                    prev->left = temp;
                else
                    prev->right = temp;
                if(where->label < temp->label)
                    temp->left = where;
                else
                    temp->right = where;
                
            }
        }
        tree_size++;
    }

    void print(Node *trav)
    {
        if(trav == NULL)
            return;
        cout<<"(";
        print(trav->left);
        cout<<trav->label<<'/'<<trav->priority;
        print(trav->right);
        cout<<")";
    }
    void print()
    {
        print(roots);
    }
};
int main()
{
    int n;
    cin>>n;
    while(n)
    {
        treap a;
        string str;
        for(int i=0;i<n;i++)
        {
            cin>>str;
            int j=0;
            string label;
            int pri=0;
            while(str[j]!='/')
                label+=str[j],j++;
            j+=1;
            while(j<(int)str.size())
            {
                pri*=10;
                pri+= (str[j]-'0');
                j++;
            }
            a.insert(label,pri);
        }
        a.print();

        cout<<"\n";
        cin>>n;
    }
    return 0;
}