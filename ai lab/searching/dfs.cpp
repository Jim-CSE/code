#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100];
bool visited[100];
int goal;
bool found = false;  // Flag to stop DFS after finding the goal

void dfs(int src)
{
    if (found) return;  // Stop if the goal has already been found
    cout << "Visiting node " << src << endl;
    visited[src] = true;

    if (src == goal)
    {
        cout << "Reached the goal\n";
        found = true;   // Set the flag when the goal is found
        return;
    }

    for (auto &x : graph[src])
    {
        if (!visited[x])
            dfs(x);
    }
}

int main()
{
    int number_of_nodes, num_of_edges;
    cout << "Enter number of nodes\n";
    cin >> number_of_nodes;
    cout << "Enter number of edges\n";
    cin >> num_of_edges;

    for (int i = 0; i < num_of_edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Enter goal\n";
    cin >> goal;
    dfs(1);
    return 0;
}
