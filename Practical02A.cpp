#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Helper function to determine if we can complete tasks within D days with the given maxWorkPerDay
bool canComplete(const vector<int>& tasks, int D, int maxWorkPerDay) {
    int days = 1;  // Start with the first day
    int currentWork = 0;  // Current amount of work done in the current day

    for (int task : tasks) {
        // If adding this task exceeds the max work per day, we start a new day
        if (currentWork + task > maxWorkPerDay) {
            days++;
            currentWork = task;  // Start the new day with this task
            if (days > D) {  // If the number of days exceeds D, return false
                return false;
            }
        } else {
            currentWork += task;  // Otherwise, continue adding tasks to the current day
        }
    }
    return true;  // If we fit all tasks within D days, return true
}


// Function to find the minimum possible maximum work per day using a greedy approach
int minWorkPerDay(const vector<int>& tasks, int D) {
    int low = *max_element(tasks.begin(), tasks.end());  // Minimum possible work per day
    int high = accumulate(tasks.begin(), tasks.end(), 0);  // Maximum possible work per day

    // Binary search between low and high to find the optimal solution
    while (low < high) {
        int mid = low + (high - low) / 2;  // Midpoint of the current range

        if (canComplete(tasks, D, mid)) {
            high = mid;  // If feasible, try for a lower maximum work per day
        } else {
            low = mid + 1;  // If not feasible, increase the minimum possible work per day
        }
    }
    return low;  // Low will be the minimum possible maximum work per day
}

int main() {
    vector<int> tasks = {7, 2, 5, 10, 8};
    int D = 2;

    cout << "Minimum possible maximum work per day: " << minWorkPerDay(tasks, D) << endl;

    return 0;
}
