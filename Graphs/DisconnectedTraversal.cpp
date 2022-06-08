#include <bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingV;
    pendingV.push(sv);
    visited[sv] = true;
    while (!pendingV.empty())
    {
        int currentV = pendingV.front();
        pendingV.pop();
        cout << currentV << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentV)
            {
                continue;
            }

            if (edges[currentV][i] == 1 && !visited[i])
            {
                pendingV.push(i);
                visited[i] = true;
            }
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}
void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

int main()
{
    int n; // vertices
    int e; // edges

    // creating a 2D matrix
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0; // initialise it with 0
        }
    }

    // sharing edges with
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    DFS(edges, n);
    cout << endl;
    BFS(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
}