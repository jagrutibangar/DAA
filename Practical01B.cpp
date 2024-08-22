#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void arrayInput(int n, vector <int> &b){
    int num;
    for(int i = 0; i < n; i++){
        cin>>num;
        b.push_back(num);
    }
}

int countZero(vector <int> b, int n){
    int low = 0;
    int high = n-1;
    int mid = (high + low)/2;
    while(low < high){
        mid = (high + low)/2;
        if (b[mid]==1){
            low = mid + 1;
        }
        else if (b[mid]==0){
           high = mid;

        } 
    }
    return n - high;
}

int main(){
    vector <int> b;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    arrayInput(n,b);
    cout << countZero(b,n);

    return 0;
}
