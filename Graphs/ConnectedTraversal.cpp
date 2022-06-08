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

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingV;
    bool *visit = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visit[i] = false;
    }
    pendingV.push(sv);
    visit[sv] = true;
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

            if (edges[currentV][i] == 1 && !visit[i])
            {
                pendingV.push(i);
                visit[i] = true;
            }
        }
    }
    delete[] visit;
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
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // printDFS(edges, n, 0, visited);
    // cout << endl;
    // printBFS(edges, n, 0);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
}