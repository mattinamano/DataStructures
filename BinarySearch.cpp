#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main(void)
{
    int x;//element to be found
    int arr[] = { 2, 3, 4, 10, 40 };
    cout<<"please enter the element to be searched"<<endl;
    cin>>x;
    int n = sizeof(arr) / sizeof(arr[0]);
    int r = binarySearch(arr, 0, n - 1, x);
    if(r == -1)
        cout << "Element is not present in array";
    else
        cout << "Element is present at index " << r;
    return 0;
}
