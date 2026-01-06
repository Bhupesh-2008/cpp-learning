// You are given with an array and you have to rotate the array in such a way that all the elements shift with a certain number of indexes in a cyclic order.
#include<iostream>
#include<vector>

using namespace std;

void rotate( vector<int>&nums ,int k){

vector<int>temp(nums.size());
    for(int i=0; i<nums.size();i++){
        temp[(i+k)%nums.size()]=nums[i];
    }

    nums= temp;
}

void print(vector<int>& nums, int size){

    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    int k=3;

    rotate(v,k);

    print(v,7);
}