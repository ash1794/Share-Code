#include<bits/stdc++.h>

using namespace std;

struct Node
{
    Node *left,*right;
    string label;
    int priority;

    Node():left(NULL),right(NULL),label(NULL),priority(0)
    {}
    ~Node()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
struct treap
{
    struct Node   *roots;
    size_t tree_size;

    treap():tree_size(0)
    {
    }
    ~treap()
    {
        if(roots)
            delete roots;
    }
    void insert(string label,int pri)
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
            if(temp->label < prev->label)
                prev->left = temp;
            else
                prev->right = temp;
            if(where->label < temp->label)
                temp->left = where;
            else
                temp->right = where;
        }
    }

    void print(Node *trav = roots)
    {
        if(trav == NULL)
            return;
        cout<<"(";
        print(trav->left);
        cout<<trav->label<<'/'<<trav->priority;
        print(trav->right);
        cout<<")";
    }
};
int main()
{
    return 0;
}