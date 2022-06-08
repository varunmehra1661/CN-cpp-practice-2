#include <bits/stdc++.h>
using namespace std;
vector<int> removeDupes(int *arr, int size)
{
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i = 0; i < size; i++)
    {
        if (seen.count(arr[i]) > 0)
        {
            continue;
        }
        seen[arr[i]] = true;
        output.push_back(arr[i]);
    }
    return output;
}

int main()
{
    int arr[] = {1, 1, 1, 2, 2, 2, 4, 4, 5, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(int);
    vector<int> output = removeDupes(arr, n);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
}