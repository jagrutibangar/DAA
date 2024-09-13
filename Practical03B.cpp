#include <bits/stdc++.h>
#include <stdbool.h>
using namespace std;

// Returns true if there is a sub of set[]
// with sum equal to given sum
bool Subset(int set[], int n, int sum)
{
    // The value of sub[i][j] will be true if
    // there is a sub of set[0..i-1] with sum
    // equal to j
    bool sub[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        sub[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        sub[0][i] = false;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                sub[i][j] = sub[i - 1][j];
            if (j >= set[i - 1])
                sub[i][j]
                    = sub[i - 1][j]
                      || sub[i - 1][j - set[i - 1]];
        }
    }

    return sub[n][sum];
}


int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    
    if (Subset(set, n, sum) == true)
        cout << "True";
    else
        cout << "False";

return 0;
}


