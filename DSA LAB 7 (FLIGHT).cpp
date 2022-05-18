#include <iostream>
using namespace std;

int adj_mat[50][50] = {0, 0};
int main()
{
    cout << "Enter no. of Cities : ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n\tEnter City Name for City " <<i+1 <<" : ";
        cin >> cities[i];
    }
    
    cout << "\n\n\tYour cities are: ";
    for (int i = 0; i < n; i++)
        cout << "\n\t\t\t  City " << i << ") : " << cities[i] << endl;
        
    cout<<"\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << "\n\t\tEnter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }
    
    cout<<"\n\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\t" << cities[i] << "\t";
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << "\n "<< cities[i];
        
        for (int j = 0; j < n; j++)
        {
            cout << "\t  " << adj_mat[i][j] << "\t  ";
        }
        cout << endl;
    }
    return 0;
}
