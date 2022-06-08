/*
Coding Problem
Problem Statement: Maximum Frequency Number
Problem Level: EASY
Problem Description:
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains most frequent element in the given array.

Constraints:
0 <= N <= 10^8
Time Limit: 1 sec

Sample Input 1 :
13
2 12 2 11 12 2 1 2 2 11 12 2 6

Sample Output 1 :
2

Sample Input 2 :
3
1 4 5

Sample Output 2 :
1

*/
/*****************************************************************************************************************/
#include <bits/stdc++.h>
using namespace std;
int highestFrequency(int *input, int n)
{

    map<int, int> max;
    for (int i = 0; i < n; i++)
    {
        max[input[i]]++;
    }

    int key = 0;
    int value = 0;

    for (int i = 0; i < n; i++)
    {
        if (max[input[i]] > value)
        {
            key = input[i];
            value = max[input[i]];
        }
    }
    return key;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 2, 4, 4, 5, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    cout << highestFrequency(arr, n);
}