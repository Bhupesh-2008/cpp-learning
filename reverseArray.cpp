#include <iostream>
#include <array>
#include <vector>

using namespace std;

//*********************************************** USING ARRAYS **********************************************************************************
// int main(){
//     int arr[6]={7,85,36,24,65,1};
//     cout<<"Your reversed array is : ";

//     int s=0;
//     int e= (sizeof(arr)/ sizeof(int))-1;

//     while(s<e){
//         swap(arr[s],arr[e]);
//         s++;
//         e--;
//     }
    
//     int size = sizeof(arr) / sizeof(int);
//     for(int i=0;i<size; i++){
//         cout<<arr[i]<<" ";
//     }

//     return 0;
// }




//**************************************************** USING VECTORS**************************************************************

vector<int>reverse(vector<int> v){
    int s=0;
    int e= v.size()-1;

    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }

    return v;
}

void print(vector<int> v){
for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int main(){
    vector<int> v;

    v.push_back(7);
    v.push_back(85);
    v.push_back(36);
    v.push_back(24);
    v.push_back(65);
    v.push_back(1);

    vector<int> ans= reverse(v);

    print(ans);
    return 0;
}