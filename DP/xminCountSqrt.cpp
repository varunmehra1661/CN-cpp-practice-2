/*Given an integer N, find and return the count of minimum numbers,
 sum of whose squares is equal to N.That is, if N is 4,
  then we can represent it as :
   {1 ^ 2 + 1 ^ 2 + 1 ^ 2 + 1 ^ 2} and {2 ^ 2}.
   Output will be 1, as 1 is the minimum count of numbers required.Note : x ^ y represents x raise to the power y.
   Input Format : Integer N Output Format : Required minimum count Constraints : 1 <= N <= 1000 Sample Input 1 : 12 Sample Output 1 : 3 Sample Output 1 Explanation :
    12 can be represented as :
    1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1
    1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 2 ^ 2
    1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 1 ^ 1 + 2 ^ 2 + 2 ^ 2
    2 ^ 2 + 2 ^ 2 + 2 ^ 2
    As we can see, the output should be 3. Sample Input 2 : 9 Sample Output 2 : 1
*/
#include <bits/stdc++.h>
using namespace std;

// dynamic programming
int bottom_up(int n)
{
    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;

    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    for (int i = 4; i <= n; i++)
    {

        arr[i] = i;

        for (int x = 1; x <= ceil(sqrt(i)); x++)
        {
            int temp = x * x;
            if (temp > i)
                break;
            else
                arr[i] = min(arr[i], 1 + arr[i - temp]);
        }
    }
    return arr[n];
}

// memoization
int memo(int n, int *arr)
{

    if (sqrt(n) - floor(sqrt(n)) == 0)
    {
        arr[n] = 1;
        return arr[n];
    }
    if (n <= 3)
    {
        arr[n] = n;
        return n;
    }
    int ans = n;
    if (arr[n] != 0)
        return arr[n];
    for (int i = 1; i * i <= n; i++)
    {

        arr[n] = ans = min(ans, 1 + memo(n - i * i, arr));
    }

    return arr[n];
}

int memoMain(int n)
{
    int arr[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = 0;
    return memo(n, arr);
}

// brute force

int rec(int n)
{

    if (sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if (n <= 3)
        return n;
    int ans = n;
    for (int i = 1; i * i <= n; i++)
    {
        ans = min(ans, 1 + rec(n - i * i));
    }

    return ans;
}
int main()
{
    cout << "RECURSIVE :: " << rec(12) << endl;
    cout << "TOP-DOWN :: " << memoMain(12) << endl;
    cout << "DP :: " << bottom_up(12) << endl;
}
