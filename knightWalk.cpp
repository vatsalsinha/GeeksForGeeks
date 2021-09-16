// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:
    struct cell{
        int row, col, dist;
    };
    cell createNode(int r, int c, int d){
        cell a;
        a.row = r;
        a.col = c;
        a.dist = d;
        return a;
    }
    bool isValid(cell c, int n){
        return c.row >= 1 && c.row <= n && c.col >= 1 && c.col <= n;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    vector<pair<int, int>> directions = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
	    queue<cell> q;
	    int visited[N+1][N+1] = {0};
	    pair<int, int> src, dst;
	    src.first = KnightPos[0];
	    src.second = KnightPos[1];
	    dst.first = TargetPos[0];
	    dst.second = TargetPos[1];
	    visited[src.first][src.second] = 1;
	    q.push(createNode(src.first, src.second, 0));
	    while(!q.empty()){
	        cell x = q.front();
	        q.pop();
	        if(x.row == dst.first && x.col == dst.second)
	            return x.dist;
	        for(int i = 0; i < directions.size(); i++){
	            cell adj = createNode(x.row + directions[i].first, x.col + directions[i].second, x.dist + 1);
	            if(isValid(adj, N) && !visited[adj.row][adj.col]){
	                visited[adj.row][adj.col] = 1;
	                q.push(adj);
	            }
	        }
	    }
	    //return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
