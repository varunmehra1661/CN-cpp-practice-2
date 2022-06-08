#include <bits/stdc++.h>
using namespace std;

// recursive
int fibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}

// Memoization-top-down
int fibo_helper(int n, int *ans)
{
    if (n <= 1)
    {
        return n;
    }

    if (ans[n] != -1)
    {
        return ans[n];
    }

    int a = fibo_helper(n - 1, ans);
    int b = fibo_helper(n - 2, ans);

    ans[n] = a + b;
    return ans[n];
}

int fibo_top_down(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }

    return fibo_helper(n, ans);
}

// DP-bottom-up
int fibo_bottom_up(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i < n + 1; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2];
    }

    return ans[n];
}

int main()
{
    cout << "RECURSIVE :: " << fibo(6);
    cout << endl;
    cout << "TOP DOWN:: " << fibo_top_down(6);
    cout << endl;
    cout << "BOTTOM UP :: " << fibo_bottom_up(6);
}