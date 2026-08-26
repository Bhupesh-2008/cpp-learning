#include<iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main(){
    //creation
    map<string,int>m;

    //insertion
    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);
    pair<string,int> p2("love",2);
    m.insert(p2);

    m["mera"]=1;
    m["mera"]=2;

    //search
    cout<<m["mera"]<<endl;                
    cout<<m.at("babbar")<<endl;
   // cout<<m.at("unknownkey")<<endl;
    cout<<m["unknownkey"]<<endl;

    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("love")<<endl;

    //erase
    m.erase("love");
    cout<<m.size()<<endl;

    //iterator
    map<string,int> ::iterator it= m.begin();
    while(it!=m.end()){
        cout<< it->first<< " "<<it->second<<endl;
        it++;
    }

    return 0;
}