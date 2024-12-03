#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void findSubsets(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> uniqueSubsets; // To avoid duplicates
    
    // Sort the array to ensure subsets are in order
    sort(nums.begin(), nums.end());
    
    // Generate all subsets using bit masking
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set in the mask
            if (mask & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        uniqueSubsets.insert(subset);
    }
    
    // Print all unique subsets
    cout << "{ ";
    for (auto subset : uniqueSubsets) {
        cout << "{";
        for (int val : subset) cout << val << " ";
        cout << "} ";
    }
    cout << "}" << endl;
}

int main() {
    vector<int> S = {1, 2, 2};
    findSubsets(S);
    return 0;
}
