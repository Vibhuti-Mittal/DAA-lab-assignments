#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArraySum(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    int leftMax = maxSubArraySum(arr, l, m);
    int rightMax = maxSubArraySum(arr, m + 1, r);
    int crossMax = maxCrossingSum(arr, l, m, r);

    return max(leftMax, max(rightMax, crossMax));
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum is: "
         << maxSubArraySum(arr, 0, n - 1);

    return 0;
}
