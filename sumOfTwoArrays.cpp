//You are giventwo arrays and you have to sum them up like we add numbers
//EG: INPUT: array1={1,2,3,4} and array2={3,5,8}   OUTPUT: {1,5,9,2}
#include<iostream>
#include<vector>

using namespace std;

vector<int> reverse(vector<int>v){
    int s=0;
    int e= v.size()-1;

    while(s<e){
        swap(v[s++],v[e--]);
    }
    return v;

}

vector<int> findArraySum(vector<int>&a,int n, vector<int>&b,int m){
    int i=n-1, j=m-1;
    int carry=0;
    
    vector<int>ans;

    for(i,j;i>=0 && j>=0;i--,j--){
        int sum= a[i]+b[j]+carry;
        carry= sum/10;
        sum= sum%10;
        ans.push_back(sum);
    }
    while(i>=0){
        int sum= a[i]+carry;
        carry= sum/10;
        sum= sum%10;
        ans.push_back(sum);
        i--;
    }

    while(j>=0){
        int sum= b[j]+carry;
        carry= sum/10;
        sum= sum%10;
        ans.push_back(sum);
        j--;
    }

    while(carry!=0){
        int sum=carry;
        carry= sum/10;
        sum= sum%10;
        ans.push_back(sum);
    }
    return reverse(ans);
}

int main(){
    vector<int> v1={1,2,3,4};
    vector<int> v2={3,5,8};

    vector<int> result = findArraySum(v1,v1.size(),v2,v2.size());

    cout << "Result: ";
    for (int digit : result) {
        cout << digit << " ";
    }
    cout << endl;
    
    return 0;

}