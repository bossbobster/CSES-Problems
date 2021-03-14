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
int len[100010];
int par[100010];
vector<int> arr;
bool visited[100010];
int dp[100010];
int main()
{
    int n, m, one, two, cur;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two; one --; two --;
        adj[one].push_back(two);
    }
    nextInLine.push(0);
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        for(auto it : adj[cur])
            nextInLine.push(it);
    }
    for(int i = 0; i < n; i ++)
        if(visited[i])
            for(auto it : adj[i])
                in[it] ++;
    nextInLine.push(0); dp[0] = 1;
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        for(auto it : adj[cur])
        {
            dp[it] = (dp[it] + dp[cur]) % 1000000007;
            in[it] --;
            if(in[it] == 0)
                nextInLine.push(it);
        }
    }
    cout << dp[n - 1] << "\n";
}
