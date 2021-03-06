#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

vector<int> adj[100010];
queue<int> nextInLine;
int cc[100010];
vector<int> each[100010];
vector<pii> ansL;
int main()
{
    int n, m, one, two, curCC = 0, cur, idx = 2, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two); adj[two].push_back(one);
    }
    for(int i = 0; i < n; i ++)
    {
        if(cc[i]) continue;
        curCC ++;
        nextInLine.push(i);
        while(!nextInLine.empty())
        {
            cur = nextInLine.front();
            nextInLine.pop();
            if(cc[cur]) continue;
            cc[cur] = curCC;
            each[curCC].push_back(cur);
            for(auto i : adj[cur])
                nextInLine.push(i);
        }
    }
    while(!each[idx].empty())
    {
        ans ++;
        ansL.push_back({each[idx - 1][0], each[idx][0]});
        idx ++;
    }
    cout << ans << "\n";
    for(int i = 0; i < ansL.size(); i ++)
        cout << ansL[i].f + 1 << " " << ansL[i].s + 1 << "\n";
}
