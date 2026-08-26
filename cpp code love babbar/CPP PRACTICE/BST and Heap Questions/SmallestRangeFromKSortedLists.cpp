#include <bits/stdc++.h>
using namespace std;

// Shorthand for common types and containers
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) ((int)(x).size())

class Node{
    public:
        int data;
        int row;
        int col;
        Node(int data,int row, int col){
            this->data=data;
            this->row= row;
            this->col= col;
        }
};

class compare{ 
    public:
        bool operator()(Node* a,Node* b){
            return a->data>b->data;
        }
};

class Solution {
    public:

        int smallestRange(vector<vector<int>>& a,int k,int n) {
            int mini= INT_MAX,maxi=INT_MIN;
            priority_queue<Node*,vector<Node*>,compare> minHeap;

            // step1: create a min heap and tracking mini/maxi value
            for(int i=0; i<k ;i++){
                int element= a[i][0];
                maxi= max(maxi,element);
                mini= min(mini,element);
                minHeap.push(new Node(element,i,0));
            }

            int start= mini,end= maxi;

            //processs ranges
            while(!minHeap.empty()){
                //mini fetch ho raha
                Node* temp= minHeap.top();
                minHeap.pop();
                mini= temp->data;

                //right answer or updation
                if(maxi-mini<start-end){
                    start= mini;
                    end= maxi;
                }

                //next element exists or not
                if(temp->col<n){
                    maxi= max(maxi,a[temp->row][temp->col+1]);
                    minHeap.push(new Node(a[temp->row][temp->col+1],temp->row,temp->col+1));
                }else break; // next element does not exist
            }

            return (end-start+1);
        }
};

int main() {
    fast_io; // Optimization for competitive programming

    // Standard LeetCode testcase for debugging
    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    int n=nums[0].size();
    int k= nums.size();

    Solution obj;
    int result = obj.smallestRange(nums,k,n);

    // If your logic is correct, this should output: [20, 24]
    cout << "Smallest Range:" << result <<"\n";

    return 0;
}