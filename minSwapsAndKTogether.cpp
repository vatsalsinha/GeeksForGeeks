// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    // Complet the function
    int countLegal = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] <= k)
            countLegal++;
    }
    int count = 0;
    for(int i = 0; i < countLegal; i++)
        if(arr[i] <= k)
            count++;
    int maxCount = count;
    for(int i = countLegal; i < n; i++){
        if(arr[i-countLegal] <= k)
            count--;
        if(arr[i] <= k)
            count++;
        maxCount = max(maxCount, count);
    }
    return countLegal - maxCount;
}

