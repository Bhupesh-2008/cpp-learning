#include <iostream>
#include <vector>
#include <queue> // Typically needed for the optimal Min-Heap approach

using namespace std;

class node{
    public:
        int data;
        int i; 
        int j;

        node(int data,int row,int column){
            this->data= data;
            this->i= row;
            this->j= column;
        }
};

class compare{
    public:
        bool operator()(node* a, node*b){
            return a->data>b->data;
        }
};

// Function to merge K sorted arrays
vector<int> mergeKSortedArrays(vector<vector<int>>& arr,int k) {
    priority_queue<node*,vector<node*>,compare> minHeap;
    for(int i=0; i<k; i++){
        node* temp= new node(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int> ans;

    while(minHeap.size()>0){
        node* temp= minHeap.top();
        ans.push_back(temp->data);
        minHeap.pop();
        int i= temp->i;
        int j= temp->j;

        if(j+1< arr[i].size()){
            node* next= new node(arr[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    

    return ans; 
}

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    // Read the number of arrays
    cin >> k;

    vector<vector<int>> arrays(k);
    for (int i = 0; i < k; i++) {
        int n;
        // Read the size of the current array
        cin >> n;
        
        arrays[i].resize(n);
        // Read the elements of the current array
        for (int j = 0; j < n; j++) {
            cin >> arrays[i][j];
        }
    }

    // Call your function
    vector<int> result = mergeKSortedArrays(arrays,k);
    
    // Print the final merged array
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}