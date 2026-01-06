// You ar given with an array and you have to check that whether that array is sorted and rotated after a number of indexes or not.
// Eg: nums={4,5,1,2,3} output=true
//Eg: nums= {2,1,3,4} output=false
#include<iostream>
#include<vector>

using namespace std;

bool check( vector<int>&nums){
    int n= nums.size();
    int count=0;

    for(int i=1;i<n;i++){
        if (nums[i-1]>nums[i]){
            count++;
        }
    }
    if(nums[n-1]>nums[0]){
        count++;
    }
    return count<=1; 
}

int main(){
    vector<int> nums={1,1,1,1};

    cout<<check(nums);

    return 0;
}