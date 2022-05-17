#include <bits/stdc++.h>
using namespace std;

void BFS(int n, vector<int> adj[])
{
    vector<int> ans;
    vector<int> visited(n + 1, 0);

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (auto it : adj[curr])
        {
            if (visited[it] == 0)
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
   cout<<endl;  
}

void DFS(int node, vector<int> &ans, vector<int> &visited, vector<int> adj[])
{
    ans.push_back(node);
    visited[node] = 1;
    for (auto it : adj[node])
    {
        if (visited[it] == 0)
        {
            DFS(it, ans, visited, adj);
        }
    }
}

void dfs(int n, vector<int> adj[])
{
    vector<int> ans;
    vector<int> vis(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            DFS(i, ans, vis, adj);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
   cout<<endl; 
}

int main()
{

    int n, m;
    
    cout << "Enter Number of Vertices : ";
    cin >> n;
    cout << "Enter Number of Edges : ";
    cin >> m;
    
    vector<int> adj[n];
    
    cout<<"Enter the two Joining vertex : \n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);   //inserting new element into the vector
        adj[v].push_back(u);  //inserting new element into the vector
    }

    int choice;
    cout << "Type of Traversal :-\n";
    cout << "1)Breadth First Search\n2)Depth First Search\n3)Exit\n";
    do
    {
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "The Breadth First Search is :\n";
            BFS(n, adj);
            break;

        case 2:
            cout << "The Depth First Search is :\n";
            dfs(n, adj);
            break;

        case 3:
            cout << "END\n";
            exit(0);
        }
    } while (choice != 3);
}
