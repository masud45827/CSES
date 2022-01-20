#include<bits/stdc++.h>
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
#define mp make_pair
#define     all(x)      x.begin() , x.end()
#define mod 1000000007
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
int n, m;
char A[1000][1000];
int dp[1000][1000];
int prev1[1000][1000];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string st = "URDL";
int main() {
  cin >> n >> m;
  int x,y,l,r;
  queue<pi> q;
  pi begin, end;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> A[i][j];
      if (A[i][j] == 'A') {
        begin = mp(i, j);
        x=i; y=j;
      } else if (A[i][j] == 'B') {
        end = mp(i, j);
        l=i; r=j;
      }
    }
  }
  q.push({x,y});
  dp[x][y] = 1;
 
  while (!q.empty()) {
    pi u = q.front(); q.pop();
    for (int i = 0; i < 4; i++) {
      pi v = mp(u.F + dx[i], u.S + dy[i]);
      if (v.F < 0 || v.F >= n || v.S < 0 || v.S >= m) continue;
      if (A[v.F][v.S] == '#') continue;
      if (dp[v.F][v.S]) continue;
      dp[v.F][v.S] = 1;
      prev1[v.F][v.S] = i;
      q.push(v);
    }
  }
  if (dp[l][r]) {
    cout << "YES" << endl;
    vector<int> steps;
    while (end != begin) {
      int p = prev1[end.F][end.S];
      steps.push_back(p);
      end = mp(end.F - dx[p], end.S - dy[p]);
    }
    //  while (l!=x&&r!=y) {
    //   int p = prev1[l][r];
    //   steps.push_back(p);
    //   //end = mp(end.f - dx[p], end.s - dy[p]);
    //   l-=dx[p]; r-=dy[p];
    // }
    reverse(steps.begin(), steps.end());
    cout << steps.size() << endl;
    for (char c : steps) {
      cout << st[c];
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
 
  return 0;
}
