/*C++ Program To read details of a book consists of chapters,
 *chapters consist of sections and sections consist of
 *subsections. Construct a tree and print the nodes.
 *Find the time and space requirements of your method.
 **/
# include <iostream>
# include <cstdlib>
# include <string.h>
using namespace std;

/*
 * Node Declaration
 */
 
struct node
{
    char label[10];
    int ch_count;
    struct node *child[10];
}*root;

/*
 * Class Declaration
 */
class Book
{
    public:
        void create_tree();      //create_tree   function initialization
        void display(node *r1);  //display function initialization
     
        Book()  //constructor
        {
            root = NULL;
        }
};


void Book::create_tree()
{
    int tbooks, tchapters,i,j,k;
    root = new node;
    cout<<"\nEnter Name of Book : ";
    cin>>root->label;
    cout<<"\n\n\tEnter No. of Chapters in Book : ";
    cin>>tchapters; 
    root->ch_count = tchapters;
 
    for(i=0; i<tchapters; i++)
    {
        root->child[i] = new node;
        cout<<"\n\tEnter Chapter " <<i+1 <<" Name : ";
        cin>>root->child[i]->label;   
        
        cout<<"\n\t\tEnter No. of Sections in Chapter '"<<root->child[i]->label<<"' : ";
        cin>>root->child[i]->ch_count;
  
        for(j=0; j<root->child[i]->ch_count; j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"\t\t\tEnter Section "<<j+1<<" Name : ";
            cin>>root->child[i]->child[j]->label;   
            cout<<"\n";
            //cout<<"Enter no. of subsections in "<<r1->child[i]->child[j]->label;
            //cin>>r1->child[i]->ch_count;
        }  
    }
}


void Book::display(node * r1)
{
    int i,j,k,tchapters;
    if(r1 != NULL)
    { 
        cout<<"\n\n-----Book Hierarchy---\n";
        cout<<"\n Book Title : "<<r1->label;
        tchapters = r1->ch_count;
        for(i=0;i<tchapters;i++)
        {
            cout<<"\n\n\tChapter "<<i+1<<" : ";
            cout<<" "<<r1->child[i]->label;   
            cout<<"\n\n\t\tSections : \n";
            for(j=0;j<r1->child[i]->ch_count;j++)
            {
                //cin>>r1->child[i]->child[j]->label;   
                cout<<"\t\t\t" <<j <<") " <<r1->child[i]->child[j]->label<<"\n\n";
            }  
        }
    }
}


/*
 * Main Contains Menu
 */
int main()
{
    int choice;
    Book book;
    while (1)
    {
        cout<<"------------------------"<<endl;
        cout<<"  Book Tree Creation"<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1) Create"<<endl;
        cout<<"2) Display"<<endl;
        cout<<"3) Quit"<<endl;
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                book.create_tree();
            break;
                  
            case 2:
                book.display(root);
            break;
                
            case 3:
                exit(1);
                
            default:
                cout<<"Wrong choice"<<endl;
        }
    }
}


