// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void towerOfHanoi(int n, int s, int d, int a, vector<vector<int>>& ans){
        if(n == 1){
            ans.push_back({s,d});
            return;
        }
        towerOfHanoi(n-1, s, a, d, ans);
        ans.push_back({s,d});
        towerOfHanoi(n-1, a, d, s, ans);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        vector<vector<int>> ans;
        int src = 1, dst = 3, aux = 2;
        towerOfHanoi(N, src, dst, aux, ans);
        return ans[n-1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends
