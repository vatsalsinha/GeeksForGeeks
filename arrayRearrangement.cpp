#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	vector<int> nums;
	int n;
	cin>>n;
	nums.resize(n);
	for(int i = 0; i < nums.size(); i++){
		cin>>nums[i];
	}	
	for(int i = 0; i < n; i++){
		if(nums[i] >= 0){
			int index = nums[i], val = i;
			while(index != i){
				int tmp = nums[index];
				nums[index] = -(val+1);
				val = index;
				index = tmp;		
			}
			nums[index] = -(val + 1);
		}	
	}
	for(int i = 0; i < n; i++){
		nums[i] = -1 * nums[i] - 1;
	}
	for(int i = 0; i < n; i++)
		cout<<nums[i]<<" ";
	return 0;
}
