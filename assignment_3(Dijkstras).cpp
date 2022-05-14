#include <bits/stdc++.h>
using namespace std;
void dijkstras(int source, vector<vector<pair<int, int>>> adj, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n, INT_MAX);

    distTo[source] = 0;
    pq.push(make_pair(0, source));

    while (!pq.empty())
    {
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (it = adj[prev].begin(); it != adj[prev].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }
    cout << "The distances from source, " << source << " are: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "Node " << i << ": " << distTo[i] << endl;
    }
    cout << '\n';
}

int main()
{
    int n, m, source; // n = number of nodes, m = number of edges, source = source node

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    // vector<pair<int, int>> adj[n]; // adjacency list for the graph
    vector<vector<pair<int, int>>> adj = vector<vector<pair<int, int>>>(n);

    int a, b, wt;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the edge " << i << " (<first_node> <second_node> <weight>): ";
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }
    cout << "Enter the source node: ";
    cin >> source;

    dijkstras(source, adj, n);
}