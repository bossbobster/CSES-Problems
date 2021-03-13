#include <iostream>
#include <string.h>
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
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

vector<int> adj[100010];
int in[100010];
queue<int> nextInLine;
vector<int> ans;
int main()
{
    int n, m, one, two, cur;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two); in[two] ++;
    }
    for(int i = 0; i < n; i ++)
        if(in[i] == 0)
            nextInLine.push(i);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        ans.push_back(cur);
        for(auto it : adj[cur])
        {
            in[it] --;
            if(in[it] == 0)
                nextInLine.push(it);
        }
    }
    if(ans.size() < n) { cout << "IMPOSSIBLE\n"; return 0; }
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}
