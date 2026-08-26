#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";

        //for traversing all characters of first string
        for(int i=0; i<strs[0].length();i++){
            char ch= strs[0][i];
            bool match= true;

            //for comparing ch with rest of the strings
            for(int j=1;j<strs.size();j++){
                //not match
                if(i>strs[j].length() || ch!=strs[j][i]){
                    match=false;
                    break;
                }
            }

            if (!match) break;
            else ans.push_back(ch);
        }
        
        return ans; // Return the final prefix
    }
};

int main() {
    fast_io; 
    int n;
    cin >> n; // Number of strings in the array
    
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i]; // Input each string
    }

    Solution obj;
    string ans = obj.longestCommonPrefix(strs);

    cout << "Longest common prefix string is: "<<ans << "\n";
    
    // }

    return 0;
}