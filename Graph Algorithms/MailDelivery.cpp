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
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

set<int> adj[100010];
vector<int> ord;
stack<int> st;
int tmp;
int main()
{
    int n, m, a, b, cur;
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[a].insert(b); adj[b].insert(a);
    }
    for(int i = 0; i < n; i ++)
        if(adj[i].size() % 2 == 1)
        {
            cout << "IMPOSSIBLE\n"; return 0;
        }
    st.push(0);
    while(!st.empty())
    {
        cur = st.top();
        if(adj[cur].empty())
        {
            ord.push_back(cur);
            st.pop();
        }
        else
        {
            tmp = *adj[cur].begin(); adj[cur].erase(tmp); adj[tmp].erase(cur);
            st.push(tmp);
        }
    }
    for(int i = 0; i < n; i ++)
        if(adj[i].size() != 0)
        {
            cout << "IMPOSSIBLE\n"; return 0;
        }
    for(int i = 0; i < ord.size(); i ++)
        cout << ord[i]+1 << " ";
    cout << "\n";
}
