#include<iostream>
using namespace std;
#define SIZE 10

class OBST
{
    int p[SIZE];    // Probabilities with which we search for an element
    int q[SIZE];   //Probabilities that an element is not found
    int a[SIZE];  //Elements from which OBST is to be built
    int w[SIZE][SIZE];  //Weight ‘w[i][j]’ of a tree having root
    //’r[i][j]’
    int c[SIZE][SIZE];   //Cost ‘c[i][j] of a tree having root ‘r[i][j]
    int r[SIZE][SIZE];  //represents root
    int n;             // number of nodes
    
    public:
    /* This function accepts the input data */
        void get_data()
        {
            int i;
            cout<<"\nOptimal Binary Search Tree \n";
            cout<<"\nEnter the number of nodes : ";
            cin>>n;
            
            cout<<"\nEnter the data as…\n";
            
            cout<<"\nInput Elements for OBST\n";
            for(i=1;i<=n;i++)
            {
                cout<<" a["<<i<<"] : ";
                cin>>a[i];
            }
            
            cout<<"\n\tProbabilitiy that Element is Found : \n";
            for(i=1;i<=n;i++)
            {
                cout<<"\t   p["<<i<<"] : ";
                cin>>p[i];
            }
            
            cout<<"\n\tProbaility that Element is NOT Found : \n";
            for(i=0;i<=n;i++)
            {
                cout<<"\t   q["<<i<<"] : ";
                cin>>q[i];
            }
        }
        
    /* This function returns a value in the range ‘r[i][j-1]’ to ‘r[i+1][j]’so
    that the cost ‘c[i][k-1]+c[k][j]’is minimum */
    int Min_Value(int i,int j)
    {
        int m,k;
        int minimum=32000;
        for(m=r[i][j-1];m<=r[i+1][j];m++)
        {
            if((c[i][m-1]+c[m][j])<minimum)
            {
                minimum=c[i][m-1]+c[m][j];
                k=m;
            }
        }
        return k;
    }
    
    /* This function builds the table from all the given probabilities It
    basically computes C,r,W values */
    void build_OBST()
    {
        int i,j,k,l,m;
        cout<<"\n\nCount | Weight | Root | Cost";
        for(i=0;i<n;i++)
        {
            //initialize
            w[i][i] = q[i];  //setting weight as q[i]
            //cout<<"\n\ni : "<<i<<" | q[i] : "<<q[i];
            
            r[i][i] = c[i][i]=0; //keeping root node and cost as 0
            //cout<<"\n\n\tr[i][i] : "<<r[i][i]<<" | c[i][i] : "<<c[i][i];
            
            //Optimal trees with one node
            //cout<<"\n\nAfter Operations : ";
            
            w[i][i+1] = q[i] + q[i+1] + p[i+1];
            //cout<<"\nw[i][i+1] : "<<w[i][i+1];
            cout<<"\n  "<<i <<"   |   "<<w[i][i+1];
            
            r[i][i+1] = i+1;
            //cout<<"\n\tr[i][i+1] : "<<r[i][i+1];
            cout<<"   |   "<<r[i][i+1];
            
            c[i][i+1] = q[i] + q[i+1] + p[i+1];
            //cout<<"\n\tc[i][i+1] : "<<c[i][i+1];
            cout<<"  |  "<<c[i][i+1];
            
        }
        w[n][n] = q[n];
        r[n][n] = c[n][n]=0;
        
        //Find optimal trees with ‘m’ nodes
        cout<<"\n\n\nFind optimal trees with ‘m’ nodes";
        cout<<"\n\n  | Weight  |   |   Cost  |   Root ";
        cout<<"\nj | w[i][j] | k | c[i][j] | r[i][j]";
        for(m=2;m<=n;m++)
        {
            for(i=0;i<=n-m;i++)
            {
                j=i+m;
                cout<<"\n"<<j;
                
                w[i][j] = w[i][j-1]+p[j]+q[j];
                //cout<<" | w[i][j] : " <<w[i][j];
                cout<<" |    " <<w[i][j];
                
                k=Min_Value(i,j);
                //cout<<"    | k : " <<k;
                cout<<"   | "<<k;
                
                c[i][j] = w[i][j]+c[i][k-1]+c[k][j];
                //cout<<" |   c[i][j] : " <<c[i][j];
                cout<<" |   " <<c[i][j];
                
                r[i][j] = k;
                //cout<<"  |   r[i][j] : " <<r[i][j];
                cout<<"    |     " <<r[i][j];
                
            }
        }
    }

    /* This function builds the tree from the tables made by the OBST function */
    void build_tree()
    {
        int i,j,k;
        int queue[20], front=-1, rear=-1;
        cout<<"\n\nThe Optimal Binary Search Tree For the Given Node Is…\n";
        cout<<"\n\nn : "<<n;
        cout<<"\n The Root of this OBST is :: "<<r[0][n];
        cout<<"\n The Cost of this OBST is :: "<<c[0][n];
        cout<<"\n\n\t NODE \t LEFT CHILD \t RIGHT CHILD ";
        cout<<"\n";
        queue[++rear]=0;
        queue[++rear]=n;
        while(front!=rear)
        {
            i=queue[++front];
            j=queue[++front];
            k=r[i][j];
            cout<<"\n\t  "<<k;
            if(r[i][k-1]!=0)
            {
                cout<<"\t\t"<<r[i][k-1];
                queue[++rear]=i;
                queue[++rear]=k-1;
            }
            else
            {
                cout<<"\t\t   ";
                if(r[k][j]!=0)
                {
                    cout<<"\t"<<r[k][j];
                    queue[++rear]=k;
                    queue[++rear]=j;
                }
                else
                    cout<<"\t";
            }//end of while
            cout<<"\n";
        }
    }
};//end of the class

/*This is the main function */
int main()
{
    OBST obj;
    obj.get_data();
    obj.build_OBST();
    obj.build_tree();
    return 0;
}
