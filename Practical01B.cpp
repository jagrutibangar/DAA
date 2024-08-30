#include <bits/stdc++.h>
using namespace std;

vector<int> moveZeros(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n); // Result vector
    
    // j: index for non-zeros 
    // count: Count of zeros
    int j = 0, count = 0; 

    // Move non-zeros to the result
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            res[j] = arr[i];
            j++;
        } else {
            count++;
        }
    }

    // Fill remaining positions with zeros
    for (int i = 0; i < count; i++) {
        res[j] = 0;
        j++;
    }

    return res;
}

int main() {
    vector<int> arr = {5, 6, 0, 4, 6, 0, 9, 0, 8};
    arr = moveZeros(arr);

    // Print the modified array
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}