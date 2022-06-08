#include <bits/stdc++.h>
using namespace std;

// DP
int minCost_dp(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
    }

    // fill the last cell
    output[m - 1][n - 1] = input[m - 1][n - 1];

    // fill the last row
    for (int j = m - 2; j >= 0; j--)
    {
        output[m - 1][j] = input[m - 1][j] + output[m - 1][j + 1];
    }

    // fill the last column
    for (int i = m - 2; i >= 0; i--)
    {
        output[i][n - 1] = input[i][n - 1] + output[i + 1][n - 1];
    }

    // fill the remaining
    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = n - 2; j >= 0; j--)
        {
            output[i][j] = min(output[i][j + 1], min(output[i + 1][j], output[i + 1][j + 1])) + input[i][j];
        }
    }

    return output[0][0];
}

// memo
int minCostPath_memo_helper(int **input, int m, int n, int i, int j, int **output)
{

    if (i == m - 1 and j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m - 1 or j >= n - 1)
    {
        return INT_MAX;
    }
    if (output[i][j] != -1)
    {
        return output[i][j];
    }

    int x = minCostPath_memo_helper(input, m, n, i, j + 1, output);
    int y = minCostPath_memo_helper(input, m, n, i + 1, j, output);
    int z = minCostPath_memo_helper(input, m, n, i + 1, j + 1, output);

    int a = min(x, min(y, z)) + input[i][j];
    output[i][j] = a;
    return output[i][j];
}
int minCostPath_memo(int **input, int m, int n)
{
    int **output = new int *[m];
    for (int i = 0; i < m; i++)
    {
        output[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            output[i][j] = -1;
        }
    }
    return minCostPath_memo_helper(input, m, n, 0, 0, output);
}

// brute-force
int minCostPath(int **input, int m, int n, int i, int j)
{

    if (i == m - 1 and j == n - 1)
    {
        return input[i][j];
    }

    if (i >= m - 1 or j >= n - 1)
    {
        return INT_MAX;
    }

    int x = minCostPath(input, m, n, i, j + 1);
    int y = minCostPath(input, m, n, i + 1, j);
    int z = minCostPath(input, m, n, i + 1, j + 1);

    int output = min(x, min(y, z)) + input[i][j];
    return output;
}
int minCost(int **input, int m, int n)
{
    return minCostPath(input, m, n, 0, 0);
}
int main()
{
    int m, n;
    cin >> m >> n;
    int **input = new int *[m];
    for (int i = 0; i < m; i++)
    {
        input[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> input[i][j];
        }
    }

    cout << "BRUTE FORCE :: " << minCost(input, m, n) << endl;
    cout << "MOMOISATION :: " << minCostPath_memo(input, m, n);
}