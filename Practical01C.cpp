#include<iostream>
using namespace std;

int trails(int x){
    int cnt = 0;
    while (x>=5){
        x = x/5;
        cnt = cnt + x;  
    }
    return cnt;
}

int leastTrail(int n){
    int low = 0;
    int high = 6*n;

    if (n==1){
        return 5;
    }

    while (low<high)
    {
        int mid = (low + high) >> 1;
        cout<<low<<' '<<high<<' '<<mid<<" "<<trails(mid)<<endl;
        if (trails(mid)< n){
            low = mid + 1;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main(){
    int n;
    cin>>n;
    cout<< leastTrail(n);
    return 0;
}
