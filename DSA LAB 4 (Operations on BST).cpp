#include <iostream>
using namespace std;

struct Node // creating a class node
{
    int key;
    Node *ln, *rn; // Node *ln and Node *rn represent node pointer for left node and right node
} * root;

class tree
{
public:
    Node *root;               // root is the pointer object of the Node class
    Node *createtree(int key) // for the very first Node in the tree
    {
        root = new Node(); /*new function will allocate a memory for the newly created node and
        the starting address will be stored in the root variable */
        root->key = key;
        root->ln = NULL;
        root->rn = NULL;
        return root; // root is return means the address is now known to whoever calls this function
    }
    
    void insertnode(int key, Node *root) // key value which we want to add and root node
    {
        Node *node = new Node(); /* New node is created named (node) and its address stored in Node* class */
        node->key = key;         // we add value of key ie. user entered value in the newly (node) created
        if (root->key > key)     /* as key value is less than root value then it will go to left side
             or left subtree and so on */
        {
            if (root->ln == NULL) // to check if left subtree is empty / null not
            {
                root->ln = node; // node along with its key value is entered in the left subtree
            }
            else
            {
                insertnode(key, root->ln); /* if subtree is not null then the root value changes
                 to the value present to the non empty subtree */
                /* again calling the insertnode function but change the
                root to ln(left subtree value present)*/
            }
        }
        
        else if (root->key < key) /* as key value is greater than root value then it will go to right
         side or right subtree and so on */
        {
            if (root->rn == NULL) // to check if right subtree is empty / null or not
            {
                root->rn = node; // node along with its key value is entered in the right subtree
            }
            else
            {
                insertnode(key, root->rn); /* if subtree is not null then the root value changes
                  to the value present at the non empty subtree */
                /* again calling the insertnode function but change the
                root to rn(right subtree value present)*/
            }
        }
        else
        {
            cout << "Duplicate Keys are not allowed... ";
        }
    }
    
    void displayInorder(Node *root) // display in INORDER traversal
    {
        if (root != NULL) // below is the algorithm of inorder traversal of Binary tree
        {
            displayInorder(root->ln);   // got to left subtree and print key value in node
            cout << "\n " << root->key; // print key value of root node
            displayInorder(root->rn);   // go to right node
        }
    }
    
    void search(Node *root, int searchkey) // serch if the given number/key is present in the tree
    {
        if (searchkey < root->key) /* search for left subtree
            comparing entered value ie.searchkey with the value in root node */
        {
            if (root->ln == NULL)
            {
                cout << "\nEntered Number NOT FOUND in the Tree";
            }
            else
            {
                search(root->ln, searchkey); /*changing value of root to value present in left
                  subtree node and executing the search function again*/
            }
        }
        else if (searchkey > root->key) // Search for right subtree
        {
            if (root->rn == NULL)
            {
                cout << "\nEntered Number NOT FOUND in the Tree";
            }
            else
            {
                search(root->rn, searchkey);
            }
        }
        else if (searchkey == (root->key)) // entered value matches the value present in the root node
        {
            cout << "Entered Number Found in the Tree...";
        }
    }
    
    void displaymini(Node *root) // function to display minimum/lowest value in the tree
    {
        while (root->ln != NULL) // if value of left sub tree is not null then keep going to
        // the left most subtree until the left subtree becomes null
        {
            root = root->ln; // changing value to root to the key value present in left subtree as it is not null
        }
        cout << "\nThe Minnimum number present in the Tree is:- " << root->key;
    }
    
    void displaymax(Node *root) // function to display maximum/highest value in the tree
    {
        while (root->rn != NULL)
        {
            root = root->rn;
        }
        cout << "\nThe Maximum number present in the tree is:-" << root->key;
    }

    int longestpath(Node *root)
    {
        if (root == NULL)
        {
            return 0; // return 0 means it will go to the previous node
        }
        int lstree = longestpath(root->ln);
        int rstree = longestpath(root->rn);
        if (lstree > rstree)
        {
            return (lstree + 1);
        }
        else
        {
            return (rstree + 1);
        }
    }
    
    Node *swapnode(Node *root)
    {
        Node *temp;
        if (root == NULL)
            return NULL;

        // below is the general swaping operation
        temp = root->ln;
        root->ln = root->rn;
        root->rn = temp;
        swapnode(root->ln); // performing swapnode function again but taking left subtree as root
        swapnode(root->rn); // performing swapnode function again but taking right subtree as root
        return temp;
    }
};

int main()
{
    int choice, flag = 0;
    int key, searchkey;
    tree t1; // making oject t1 of class tree
    // Node *root; /*making object pointer (root) of class Node to get the memory location / address
    //  wherever the object is created */
    cout << "\n-------------------MENU-------------------";
    cout << "\n1.Enter a number(New node value)";
    cout << "\n2.Display Tree(Inorder Traversal)";
    cout << "\n3.Display Minimum Data Value Present in the Tree";
    cout << "\n4.Display Maximum Data Value Present in the Tree";
    cout << "\n5.Display no. of nodes in longest path";
    cout << "\n6.Swap left and right nodes";
    cout << "\n7.Search for a value in the Binary Tree ";
    cout << "\n8.Exit";
    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter Number:- ";
            cin >> key;
            if (flag == 0) // flag=0 means not node is present (ie. no tree present or created)
            {
                root = t1.createtree(key); // create tree TODO: only one tree can be created hence flag 1 is executed
                flag = 1;                  /*flag=1 means when we chose case 1 again in the same execution it will
                                    directly go to the else statement (i.e the insertnode function to
                                    insert node instead of main root)instead of executing the above command */
            }
            else
            {
                t1.insertnode(key, root);
            }
            cout << "\nNode inserted into the tree";
            break;
        case 2:
            cout << "Display in In-order treversal:- \n";
            t1.displayInorder(root);
            cout << "\n";
            break;
        case 3:
            t1.displaymini(root);
            cout << "\n";
            break;
        case 4:
            t1.displaymax(root);
            cout << "\n";
            break;
        case 5:
            cout << "the numer of Node's in the longest path is:- " << t1.longestpath(root);
            cout << "\n";
            break;
        case 6:
            t1.swapnode(root);
            cout << "\nThe valuse in the tree has been seapped \n The new swapped List is:- \n";
            t1.displayInorder(root);
            cout << "\n";
            break;

        case 7:
            cout << "\nEnter the Value to be searched in the List/Tree:- ";
            cin >> searchkey;
            t1.search(root, searchkey);
            cout << "\n";
            break;
        case 8:
            cout << "\nEnd";
            exit(0);
        }
    } while (choice != 8);
    {
        return 0;
    }
}

