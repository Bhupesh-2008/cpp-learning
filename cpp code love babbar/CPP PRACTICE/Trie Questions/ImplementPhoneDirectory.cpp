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
            data=ch;
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
            childCount=0;
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root= new TrieNode('\0');
        }

        void insertUtil(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal= true;
                return;
            }

            int index= word[0]-'a';
            TrieNode* child;

            if(root->children[index]){
                child=root->children[index];
            }else{
                TrieNode* child= new TrieNode(word[0]);
                root->childCount++;
                root->children[index]=child;
            }

            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        void printSuggestions(TrieNode* curr,vector<string>&temp,string prefix){
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            for(char ch='a'; ch<='z'; ch++){
                TrieNode* next= curr->children[ch-'a'];
                if(next!=NULL){
                    prefix.push_back(ch);
                    printSuggestions(next,temp,prefix);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev= root;
            vector<vector<string>> output;
            string prefix="";

            for(int i=0;i<str.length();i++){
                char lastch= str[i];
                prefix.push_back(lastch);

                // check for lastcharacter
                TrieNode* curr= prev->children[lastch-'a'];

                //if not found
                if(curr==NULL) break;

                //if found
                vector<string>temp;
                printSuggestions(curr,temp,prefix);
                output.push_back(temp);
                temp.clear();
                prev=curr;
            }
            return output;
        }
};

vector<vector<string>> displayContacts(int n, vector<string>& contact, string s) {
    Trie* t= new Trie();
    for(int i=0; i<contact.size();i++){
        string str= contact[i];
        t->insertWord(str);
    }
        
    return t->getSuggestions(s);
}


int main() {
    fast_io; 

    int t;
    cin >> t; // Number of test cases (agar test cases nahi hain toh ise hata dena)
    while (t--) {
        int n;
        cin >> n; // Number of contacts in the directory
        
        vector<string> contact(n);
        for (int i = 0; i < n; i++) {
            cin >> contact[i]; // Input each contact
        }
        
        string s;
        cin >> s; 
        vector<vector<string>> ans = displayContacts(n, contact, s);
        
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].empty()) {
                cout << "0\n";
            } else {
                for (int j = 0; j < ans[i].size(); j++) {
                    cout << ans[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }

    return 0;
}