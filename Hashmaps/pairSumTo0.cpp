/*
Coding Problem
Problem Statement: Pair sum to 0
Problem Level: MEDIUM
Problem Description:
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.
Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.

Constraints :
0 <= N <= 10^4
Time Limit: 1 sec

Sample Input 1:
5
2 1 -2 2 3

Sample Output 1:
2
*/
/***********************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
#include <map>
void PairSum(int *input, int n)
{

    map<int, int> m;

    for (int i = 0; i < n; i++)
        m[input[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (m[-input[i]] > 0)
        {
            int x = m[-input[i]];
            while (x > 0)
            {
                if (input[i] > -input[i])
                    cout << -input[i] << " " << input[i] << endl;
                else
                    cout << input[i] << " " << -input[i] << endl;
                x--;
            }

            m[input[i]]--;
        }
    }
}
int main()
{
    int arr[] = {};
    int n = sizeof(arr) / sizeof(int);
    PairSum(arr, n);
}