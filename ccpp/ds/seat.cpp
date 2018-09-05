#include <bits/stdc++.h>
using namespace std;

// Returns true if it is possible to arrange
// k elements of arr[0..n-1] with minimum distance
// given as mid.
bool isFeasible(int mid, int arr[], int n, int k)
{
    // Place first element at arr[0] position
    int pos = arr[0];

    // Initialize count of elements placed.
    int elements = 1;

    // Try placing k elements with minimum
    // distance mid.
    for (int i=1; i<n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            // Place next element if its
            // distance from the previously
            // placed element is greater
            // than current mid
            pos = arr[i];
            elements++;

            // Return if all elements are placed
            // successfully
            if (elements == k)
              return true;
        }
    }
    return 0;
}

// Returns largest minimum distance for k elements
// in arr[0..n-1]. If elements can't be placed,
// returns -1.
int largestMinDist(int arr[], int n, int k)
{
    // Sort the positions
    sort(arr,arr+n);

    // Initialize result.
    int res = -1;

    // Consider the maximum possible distance
    int left = arr[0], right = arr[n-1];

    // Do binary search for largest minimum distance
    while (left < right)
    {
        int mid = (left + right)/2;

        // If it is possible to place k elements
        // with minimum distance mid, search for
        // higher distance.
        if (isFeasible(mid, arr, n, k))
        {
            // Change value of variable max to mid iff
            // all elements can be successfully placed
            res = max(res, mid);
            left = mid + 1;
        }

        // If not possible to place k elements, search
        // for lower distance
        else
            right = mid;
    }

    return res;
}

// Driver code
int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << largestMinDist(arr, n, k);
    return 0;
}
