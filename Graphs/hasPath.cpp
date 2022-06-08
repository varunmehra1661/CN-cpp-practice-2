#include <bits/stdc++.h>
using namespace std;

bool haspath(int **edges, int v, bool *visited, int s, int e)
{
    if (edges[s][e] == 1)
        return true;

    visited[s] = true;

    bool res = false;

    for (int i = 0; i < v; i++)
    {
        if (i == s)
        {
            continue;
        }

        if (!visited[i] && edges[s][i] == 1)
            res = haspath(edges, v, visited, i, e);
        if (res == true)
            return true;
    }

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int **edges = new int *[V];

    for (int i = 0; i < V; i++)
    {
        edges[i] = new int[V];
        for (int j = 0; j < V; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < E; i++)
    {
        int x, y;
        cin >> x >> y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[V] = false;
    int s, e;

    cin >> s >> e;

    if (haspath(edges, V, visited, s, e))
        cout << "true";
    else
        cout << "false";

    delete[] visited;
    for (int i = 0; i < V; i++)
        delete[] edges[i];

    delete[] edges;

    return 0;
}