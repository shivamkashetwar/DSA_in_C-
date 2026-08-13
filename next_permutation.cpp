#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int maxLimit) {
    int painter = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time + arr[i] <= maxLimit) {
            time += arr[i];
        } else {
            painter++;
            time = arr[i];
        }
    }

    return painter <= m;
}

int minimum(vector<int>& arr, int n, int m) {
    int sum = 0;
    int maxVal = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal;
    int end = sum;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {40, 30, 10, 20};
    int n = 4;
    int m = 2;

    cout << minimum(arr, n, m) << endl;

    return 0;
}