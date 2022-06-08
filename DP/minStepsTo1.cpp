#include <bits/stdc++.h>
using namespace std;

// Brute-force : recursvie
int steps(int n)
{
    if (n <= 1)
    {
        return 0;
    }

    int x = steps(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
    {
        y = steps(n / 2);
    }
    if (n % 3 == 0)
    {
        z = steps(n / 3);
    }

    return min(x, min(y, z)) + 1;
}

// memo: top-down
int helper(int n, int *ans)
{
    if (n <= 1)
    {
        return 0;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int x = helper(n - 1, ans);
    int y = INT_MAX;
    int z = INT_MAX;
    if (n % 2 == 0)
    {
        y = helper(n / 2, ans);
    }
    if (n % 3 == 0)
    {
        z = helper(n / 3, ans);
    }

    int output = min(x, min(y, z)) + 1;
    ans[n] = output;
    return ans[n];
}

int steps_top_down(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    return helper(n, ans);
}

// DP-(bottom-up)
int steps_bottom_up(int n)
{
    int *ans = new int[n + 1];

    ans[1] = 0;
    ans[2] = 1;
    ans[3] = 1;
    int b = INT_MAX;
    int c = INT_MAX;
    for (int i = 4; i < n + 1; i++)
    {
        b = c = n;
        if (i % 2 == 0)
            b = ans[i / 2];
        if (i % 3 == 0)
            c = ans[i / 3];

        ans[i] = min(ans[i - 1], min(b, c)) + 1;
    }
    return ans[n];
}

int main()
{
    cout << "RECURSIVE :: " << steps(9) << endl;
    cout << "TOP-DOWN :: " << steps_top_down(9) << endl;
    cout << "DP :: " << steps_bottom_up(9) << endl;
}