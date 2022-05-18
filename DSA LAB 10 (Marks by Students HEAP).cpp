#include<iostream>
#define SIZE 100
using namespace std;

int heap[SIZE];
void create(int heap[], int n);
void buildheapmax(int heap[], int i);
void create1(int heap[], int n);
void buildheapmin(int heap[], int i);

int main()
{
    int n,i,j,k;
    
    cout<<"Enter the no of Students appeared For DSA Online Examination : ";
    cin>>n;
    heap[0]=n;
    
    //cout<<"\n\nheap[0] : "<<heap[0];
    cout<<"\nEnter the Marks of the students"<<endl;
    for(k=1;k<=n;k++)
    {
        cin>>heap[k];
    }
    
    create(heap,n);
        cout<<"\n\nDisplay Max Heap : \n";
        for(k=1;k<=n;k++)
        {
            cout<<heap[k]<<"  |  ";
        }
        cout<<"\n\nThe Maximum marks in the subject is : ";
        cout<<heap[1];
    
    create1(heap,n);
    {
        cout<<"\n\n\nDisplay Min Heap : \n";
        for(k=1;k<=n;k++)
        {
            cout<<heap[k]<<"  |  ";
        }
        cout<<"\n\nThe Minimum marks in the subject is : ";
        cout<<heap[1];
        return 0;
    }
    
    void create(int heap[],int n)
    {
        int i,k;
        for(i=n/2;i>=1;i--)
        {
            //cout<<"\n\ni : "<<i;
            buildheapmax(heap,i);
        }
    }
    
    void buildheapmax(int heap[],int i)
    {
        int j,temp,m;
        int q = 1;
        m = heap[0];
        while(2*i <= m && q == 1)
        {
            j=2*i;
            //cout<<"\n\nj : "<<j;
            //cout<<"\n\nheap[j+1] : "<<heap[j+1]<<" | heap[j] : "<<heap[j];
            if(j+1<=m && heap[j+1] > heap[j])
            {
                j=j+1;
                
            }
            
            if(heap[i]>heap[j])
            {
                //cout<<"\n\nheap[i] : "<<heap[i]<<" | heap[j] : "<<heap[j];
                q=0;
            }
            else
            {
                temp=heap[i];
                heap[i]=heap[j];
                heap[j]=temp;
                i=j;
            }
        }
    }

    void create1(int heap[],int n)
    {
        int i,k;
        for(i=n/2;i>=1;i--)
        {
            buildheapmin(heap,i);
        }
    }

    void buildheapmin(int heap[],int i)
    {
        int j,temp,m;
        int q=1;
        m=heap[0];
        while(2*i <= m && q == 1)
        {
            j=2*i;
            if(j+1 <= m && heap[j+1] < heap[j])
            {
                j=j+1;
                    
            }
            
            if(heap[i]<heap[j])
            {
                q=0;
                    
            }
            else
            {
                temp=heap[i];
                heap[i]=heap[j];
                heap[j]=temp;
                //i=j;
            }
        }
    }
