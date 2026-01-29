#include <iostream>
using namespace std;
int binarySearch(int arr[], int low, int high, int x)
{
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(arr[mid] == x)
        return mid;
        else if(arr[mid] > x) return binarySearch(arr, low, mid-1, x);
        else return binarySearch(arr, mid+1, high, x);
    }
    return -1;
}
int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int ele;
    cout << "Enter element to search for: " << endl;
    cin >> ele;
    int index = binarySearch(arr, 0, (sizeof(arr)/sizeof(arr[0]))-1, ele);
    if(index == -1) cout << "Element not found" << endl;
    else 
    cout << "Element " << ele << " found at index " << index << endl;
    return 0;
}