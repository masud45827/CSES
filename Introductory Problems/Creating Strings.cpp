#include <bits/stdc++.h> 
using namespace std; 
 
 set<string>s; 
void permute(string a, int l, int r) 
{ 
    
    if (l == r) 
       s.insert(a);
    else
    { 
       
        for (int i = l; i <= r; i++) 
        { 
            swap(a[l], a[i]); 
            permute(a, l+1, r); 
            swap(a[l], a[i]); 
        } 
    } 
} 
int main() 
{ 
    string str;
    cin>>str; 
    int n = str.size(); 
    permute(str, 0, n-1); 
    cout<<s.size()<<endl;
    for( string s1:s) cout<<s1<<endl;
    return 0; 
}
