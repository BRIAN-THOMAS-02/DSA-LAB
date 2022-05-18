#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *ln, *rn;
} * root;

class tree
{
public:

    Node *root;
    Node *createtree(int key)
    {
        root = new Node();
        root->key = key;
        cout<<"\n\t\tRoot : "<<key;
        root->ln = NULL;
        root->rn = NULL;
        return root;
    }
    
    void insertnode(int key, Node *root)
    {
        Node *node = new Node();
        node->key = key;
        //cout<<"\n\nkey : "<<key;
        
        
        //cout<<"\n\n";
        //cout<<root->key<<" > " <<key;
        if (root->key > key)
        {
            cout<<"\n";
            cout<<"\t\t"<<root->key<<" > " <<key;
            if (root->ln == NULL)
            {
                root->ln = node;
                cout<<"\n\t\tLeft Node : " <<root->ln->key;
                cout <<"\n\t\tNode inserted into the tree\n";
            }
            else
            {
                insertnode(key, root->ln);
            }
        }
        
        else if (root->key < key)
        {
            cout<<"\n";
            cout<<"\t\t"<<root->key<<" < " <<key;
            if (root->rn == NULL)
            {
                root->rn = node;
                cout<<"\n\t\tRight Node : " <<root->rn->key;
                cout << "\n\t\tNode inserted into the tree\n";
            }
            else
            {
                insertnode(key, root->rn);
            }
        }
        else
        {
            cout << "\nDuplicate Keys are not allowed.";
        }
    }

    void displayPreorder(Node *root)
    {
        vector<int> preorder;
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->ln == NULL)
            {
                preorder.push_back(curr->key);
                //cout<<"\n\npreorder : "<<preorder;
                curr = curr->rn;
                //cout<<"\n\t\t curr : "<<curr->key<<endl;
            }
            
            else
            {
                Node *next = curr->ln; //storing the value of current left in 'next'
                //cout<<"\n\n\tcurr->ln->key : "<<curr->ln->key;
                //cout<<"\tnext->rn : " <<next->rn->key;
                
                //traversing from left node to right node
                while (next->rn != NULL && next->rn != curr)  //checking if the value of Right Node is Null or equal to current right node
                {
                    next = next->rn;                  //setting next as latest right node
                    //cout<<"\n\n\tnext : "<<next->key;
                }
                if (next->rn == NULL)
                {
                    next->rn = curr;
                    preorder.push_back(curr->key);
                    curr = curr->ln;
                }
                else
                {
                    next->rn = NULL;
                    curr = curr->rn;
                }
            }
        }
        for (int i = 0; i < preorder.size(); i++)
        {
            cout << preorder[i] << " ";
        }
    }

    void displayInorder(Node *root)
    {
        vector<int> inorder;
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->ln == NULL)
            {
                inorder.push_back(curr->key);  //inserting new element at the end of the vector
                curr = curr->rn;
            }
            else
            {
                Node *next = curr->ln;
                while (next->rn != NULL && next->rn != curr)
                {
                    next = next->rn;
                }
                if (next->rn == NULL)
                {
                    next->rn = curr;
                    curr = curr->ln;
                }
                else
                {
                    next->rn = NULL;
                    inorder.push_back(curr->key);
                    curr = curr->rn;
                }
            }
        }
        for (int i = 0; i < inorder.size(); i++)
        {
            cout << inorder[i] << " ";
        }
    }

    void displayPostorder(Node *root)
    {
        vector<int> postorder;
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->rn == NULL)
            {
                postorder.push_back(curr->key);
                curr = curr->ln;
            }
            else
            {
                Node *next = curr->rn;
                while (next->ln != NULL && next->ln != curr)
                {
                    next = next->ln;
                }
                if (next->ln == NULL)
                {
                    next->ln = curr;
                    postorder.push_back(curr->key);
                    curr = curr->rn;
                }
                else
                {
                    next->ln = NULL;
                    curr = curr->ln;
                }
            }
        }
        reverse(postorder.begin(), postorder.end());
        for (int i = 0; i < postorder.size(); i++)
        {
            cout << postorder[i] << " ";
        }
    }
};

int main()
{
    int choice, flag = 0;
    int key;
    tree t1;
    cout << "\n-------------------MENU-------------------";
    cout << "\n1) Enter a number(New node keyue)";
    cout << "\n2) Display PreOrder Traversal";
    cout << "\n3) Display InOrder Traversal";
    cout << "\n4) Display PostOrder Traversal";
    cout << "\n5) Exit";
    do
    {
        cout << "\n\n  Enter your choice : ";
        cin >> choice;
        
        switch (choice)
        {
            
        case 1:
            cout << "\n\tEnter Number to add to Tree : ";
            cin >> key;
            if (flag == 0)
            {
                root = t1.createtree(key);
                flag = 1;
            }
            
            else
            {
                t1.insertnode(key, root);
            }
            break;
            
        case 2:
            cout << "\n\tDisplay in Pre-Order treversal:- \n";
            t1.displayPreorder(root);
            cout << "\n";
            break;
            
        case 3:
            cout << "\n\tDisplay in In-Order treversal:- \n";
            t1.displayInorder(root);
            cout << "\n";
            break;
            
        case 4:
            cout << "\n\tDisplay in Post-Order treversal:- \n";
            t1.displayPostorder(root);
            cout << "\n";
            break;
            
        case 5:
            cout << "\nEnd";
            exit(0);
            
        }
        
    } while (choice != 5);
    {
        return 0;
    }
}



