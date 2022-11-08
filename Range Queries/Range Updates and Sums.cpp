#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef     long long    ll;
typedef     unsigned long long    ull;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define setpr(x) cout<<setprecision(x)<<fixed
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
template <typename T> inline void Int(T &a) {
	bool minus = false; a = 0; char ch = getchar();
	while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
	if (ch == '-') minus = true; else a = ch - '0';
	while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
	if (minus)a *= -1 ;
}
#ifdef LOCAL
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
#else
#define error(args...)
#endif

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
struct node {
	ll sum;
	ll setAll;
	ll increment;
	bool set_valid;
	node() {
		sum = 0;
		set_valid = 0;
		increment = 0;
	}
	void reset() {
		set_valid = increment = 0;
	}
};
class segtree {
	int n;
	vector<node>tree;
public:
	void build(vi &a) {
		n = a.size();
		tree.assign(4 * n, node());
		build_recur(a,0,n-1,0);
	}
	void build_recur(vi &a,int l,int r,int nod){
		 if(l==r){
		 	 if(l<a.size()) tree[nod].sum=a[l];
		 	 else tree[nod].sum=0;
		 	 return;
		 }
		 int mid=(l+r)/2;
		 build_recur(a,l,mid,2*nod+1);
		 build_recur(a,mid+1,r,2*nod+2);
		 tree[nod].sum=tree[2*nod+1].sum+tree[2*nod+2].sum;
	}
	void incUpdate(int nod,int l,int r,int L,int R,int x){
		 if(r<L||R<l||l>=n) return;
		 if(L<=l&&R>=r){
		 	 tree[nod].increment+=x;
		 	 return;
		 }
		 lazy_update(nod,l,r);
		 int mid=(l+r)/2;
		 incUpdate(2*nod+1,l,mid,L,R,x);
		 incUpdate(2*nod+2,mid+1,r,L,R,x);
		 lazy_update(2*nod+1,l,mid);
		 lazy_update(2*nod+2,mid+1,r);
		 tree[nod].sum=tree[2*nod+1].sum+tree[2*nod+2].sum;
	}
	void setUpdate(int nod,int l,int r,int L,int R,int x){
		 if(r<L||R<l||l>=n) return;
		 if(L<=l&&R>=r){
		 	tree[nod].set_valid=1;
		 	tree[nod].setAll=x;
		 	tree[nod].increment=0;
		 	return;
		 }
		 lazy_update(nod,l,r);
		 int mid=(l+r)/2;
		 setUpdate(2*nod+1,l,mid,L,R,x);
		 setUpdate(2*nod+2,mid+1,r,L,R,x);
		 lazy_update(2*nod+1,l,mid);
		 lazy_update(2*nod+2,mid+1,r);
		 tree[nod].sum=tree[2*nod+1].sum+tree[2*nod+2].sum;
	}
	void compos(int p,int nod){
		 if(tree[p].set_valid){
		 	 tree[nod].set_valid=1;
		 	 tree[nod].setAll=tree[p].setAll;
		 	 tree[nod].increment=tree[p].increment;
		 }else{
		 	 tree[nod].increment+=tree[p].increment;
		 }
	}
	void lazy_update(int nod,int l,int r){
		if(tree[nod].set_valid){
			 tree[nod].sum=(r-l+1)*tree[nod].setAll;
		}
		tree[nod].sum+=(r-l+1)*tree[nod].increment;
		if(l!=r){
            compos(nod,2*nod+1);
            compos(nod,2*nod+2);
		}
		tree[nod].reset();
	}
ll range_query_recur(int nod,int l,int r,int L,int R){
	 if(r<L||R<l||l>=n) return 0;
	  lazy_update(nod,l,r);
	  if(L<=l&&R>=r) return  tree[nod].sum;
	  int mid=(l+r)/2;
	   ll x=range_query_recur(2*nod+1,l,mid,L,R);
	   ll y=range_query_recur(2*nod+2,mid+1,r,L,R);
     return x+y;
 }
};
int main() {
	int test = 1, fac = 1;
	//cin>>test;
	while (test--) {
		int n, i, j, x, y, q;
		cin >> n >> q;
		vector<int>a(n);
		for (i = 0; i < n; i++) cin >> a[i];
	    segtree sg; 
        sg.build(a);
        while(q--){
        	 int t;
        	 cin>>t;
        	 if(t==1){
        	 	 int l,r;
        	 	 cin>>l>>r>>x;
        	 	 sg.incUpdate(0,0,n-1,l-1,r-1,x);
        	 }else if(t==2){
        	 	 int l,r;
        	 	 cin>>l>>r>>x;
        	 	 sg.setUpdate(0,0,n-1,l-1,r-1,x);
        	 }else{
        	 	 int l,r;
        	 	 cin>>l>>r;
        	 	 cout<<sg.range_query_recur(0,0,n-1,l-1,r-1)<<endl;
        	 }
        }
	}
	return 0;
}

