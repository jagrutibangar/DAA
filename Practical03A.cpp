#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int>& coins, int sum) {
    // Create a dp array of size (sum + 1) and initialize with 0
    vector<int> dp(sum + 1, 0);
    
    // There's 1 way to make sum 0 (by using no coins)
    dp[0] = 1;
    
    // Iterate over each coin
    for (int coin : coins) {
        // Update the dp array for all sums from the current coin to the target sum
        for (int i = coin; i <= sum; i++) {
            dp[i] += dp[i - coin];
        }
    }
    
    // Return the number of ways to make the target sum
    return dp[sum];
}

int main() {
    
    vector<int> coins2 = {2, 5, 3, 6};
    int sum2 = 10;
    cout << "Number of ways to make sum " << sum2 << " is: " << coinChange(coins2, sum2) << endl; // Output: 5

    return 0;
}
