#include <iostream>
using namespace std;

int maximizeProfit(int arr[], int n) {
    int profit = 0;

    // Traverse the array
    for (int i = 1; i < n; i++) {
        // If today's price is higher than yesterday's price, sell!
        if (arr[i] > arr[i - 1]) {
            profit += (arr[i] - arr[i - 1]);
        }
    }

    return profit;
}

int main() {
    int arr[] = {2, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum profit: " << maximizeProfit(arr, n) << endl;
    return 0;
}
