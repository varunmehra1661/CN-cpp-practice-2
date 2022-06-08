#include <bits/stdc++.h>
using namespace std;
// DP
int lcs(string s, string t)
{
    int m = s.size();
    int n = t.size();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n];
    }

    // fill 1st row
    for (int j = 0; j <= n; j++)
    {
        output[0][j] = 0;
    }

    // fill the 1st col
    for (int i = 0; i <= m; i++)
    {
        output[i][0] = 0;
    }

    // fill the entire matrix
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[m - i] == t[n - j])
            {
                output[i][j] = 1 + output[i - 1][j - 1];
            }
            else
            {
                int a = output[i - 1][j];
                int b = output[i - 1][j - 1];
                int c = output[i][j - 1];
                output[i][j] = max(a, max(b, c));
            }
        }
    }
    return output[m][n];
}

// memoisation
int lcs_memo_helper(string s, string t, int **output)
{
    int m = s.size();
    int n = t.size();
    if (s.size() == 0 or t.size() == 0)
    {
        return 0;
    }

    if (output[m][n] != -1)
    {
        return output[m][n];
    }
    int ans = INT_MIN;
    if (s[0] == t[0])
    {
        ans = 1 + lcs_memo_helper(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs_memo_helper(s, t.substr(1), output);
        int b = lcs_memo_helper(s.substr(1), t, output);
        int c = lcs_memo_helper(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    output[m][n] = ans;
    return output[m][n];
}

int lcs_memo(string s, string t)
{

    int **output = new int *[s.size() + 1];
    for (int i = 0; i <= s.size() + 1; i++)
    {
        output[i] = new int[t.size() + 1];
        for (int j = 0; j <= t.size() + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return lcs_memo_helper(s, t, output);
}

// brute
int lcs(string s, string t)
{
    // base case
    if (s.size() == 0 or t.size() == 0)
    {
        return 0;
    }

    // recursicve
    if (s[0] == t[0])
    {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else
    {
        int a = lcs(s, t.substr(1));
        int b = lcs(s.substr(1), t);
        int c = lcs(s.substr(1), t.substr(1));
        int output = max(a, max(b, c));
        return output;
    }
}

int main()
{
    string s, t;
    s = "xyz";
    t = "zxay";
    cout << "BRUTE FORCE :: " << lcs(s, t) << endl;
    cout << "MEMOISATION :: " << lcs_memo(s, t) << endl;
}