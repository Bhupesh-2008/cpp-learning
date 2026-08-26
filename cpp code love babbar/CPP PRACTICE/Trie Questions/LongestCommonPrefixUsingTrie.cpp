#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        int childCount;
        bool isTerminal;

        TrieNode(char ch){
            data= ch;
            for(int i=0; i<26;i++){
                children[i]=NULL;
            }
            childCount=0;
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(char ch){
            root= new TrieNode(ch);
        }

        void insertUtil(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }
            
            int index= word[0]-'a';
            TrieNode* child;

            //present
            if(root->children[index]) child= root->children[index];
            else {
                child= new TrieNode(word[0]);
                root->childCount++;
                root->children[index]= child;
            }

            //Recursion
            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        void lcp(string str,string& ans){
            for(int i=0; i<str.length();i++){
                char ch= str[i];
                if(root->childCount==1){
                    ans.push_back(ch);
                    //aage badh jkaao
                    int index= ch-'a';
                    root= root->children[index];
                }
                else{
                    break;
                }
                if(root->isTerminal){
                    break;
                }
            }
        }
};

string longestCommonPrefix(vector<string>& strs) {
    Trie* t= new Trie('\0');

    //insert krdo all strings into trie
    for(int i=0; i<strs.size(); i++){
        t->insertWord(strs[i]);
    }

    string first= strs[0];
    string ans="";
    t->lcp(first,ans);
        
    return ans; // Return the final prefix
}

int main() {
    fast_io; 
    
    int n;
    cin >> n; // Number of strings in the array
    
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i]; // Input each string
    }
    string ans = longestCommonPrefix(strs);

    cout << ans << "\n";
    
    // }

    return 0;
}