#include <iostream>
#include <vector>
using namespace std;

void findSubsets(vector<int>& nums) {
    int n = nums.size();

    // Sort the array manually to handle duplicates
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
    }

    cout << "{ ";
    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> subset;
        bool skip = false;

        for (int i = 0; i < n; i++) {
            // Check if the i-th bit is set
            if (mask & (1 << i)) {
                // Skip duplicates in the same subset
                if (i > 0 && (mask & (1 << (i - 1))) == 0 && nums[i] == nums[i - 1]) {
                    skip = true;
                    break;
                }
                subset.push_back(nums[i]);
            }
        }

        if (!skip) {
            cout << "{ ";
            for (int val : subset) cout << val << " ";
            cout << "} ";
        }
    }
    cout << "}" << endl;
}

int main() {
    vector<int> S = {1, 2, 2};
    findSubsets(S);
    return 0;
}
