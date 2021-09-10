// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
#define mod 1000000007
class Solution{   
public:
    long long subarraySum(long long a[], long long n)
    {
        // Your code goes here
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long tmp = ((i+1)%(mod))*((n-i)%(mod))*(a[i]%(mod));
            tmp = tmp%(mod);
            ans = (ans%(mod) + tmp%(mod))%(mod);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
     long long t; 
     cin>>t;
     while(t--)
     {
         long long n; cin>>n;
         long long a[n+5];
         for(long long i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.subarraySum(a, n)<<endl;
     }
    return 0;
}
  // } Driver Code Ends
