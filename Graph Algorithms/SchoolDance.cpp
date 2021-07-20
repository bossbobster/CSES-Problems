//FASTER ALGO

#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);
 
ifstream fin("cuplaj.in");
ofstream fout("cuplaj.out");
 
int n, m, k, a, b, ans = 0;
vector<int> adj[510];
bitset<510> visited;
int l[510], r[510];
bool good;
int pairUp(int x)
{
    if(visited[x]) return 0;
    visited[x] = 1;
    for(auto it : adj[x])
        if(!l[it])
        {
            l[r[x]] = 0, r[x] = it, l[it] = x;
            good = true;
            return 1;
        }
    for(auto it : adj[x])
        if(l[it] != x && pairUp(l[it]))
        {
            l[r[x]] = 0, r[x] = it, l[it] = x;
            good = true;
            return 1;
        }
    return 0;
}
int main()
{
    input();
    cin >> n >> m >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    do
    {
        good = false;
        visited.reset();
        for(int i = 1; i <= n; i ++)
            if(!r[i])
                pairUp(i);
    } while(good);
    for(int i = 1; i <= n; i ++)
        if(r[i])
            ans ++;
    cout << ans << "\n";
    for(int i = 1; i <= n; i ++)
        if(r[i])
            cout << i << " " << r[i] << "\n";
}





//SLOWER ALGO

/*#include <iostream>
#include <string.h>
#include <random>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

vector<int> adj[1010];
queue<int> nextInLine;
bitset<1010> visited;
int cur[1010][1010], lim[1010][1010], par[1010], match[1010];
vector<pii> v;
int main()
{
    input();
    int n, m, k, a, b, curN, curF, ans = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> a >> b; b += n;
        adj[a].push_back(b); adj[b].push_back(a);
        lim[a][b] ++;
    }
    for(int i = 1; i <= n; i ++) adj[0].push_back(i), adj[i].push_back(0), lim[0][i] ++;
    for(int i = n+1; i <= n+m; i ++) adj[i].push_back(n+m+1), adj[n+m+1].push_back(i), lim[i][n+m+1] ++;
    par[0] = -1;
    while(true)
    {
        nextInLine.push(0);
        visited.reset(); visited[0] = true;
        while(!nextInLine.empty())
        {
            curN = nextInLine.front();
            nextInLine.pop();
            if(curN == n+m+1) continue;
            for(auto it : adj[curN])
                if(cur[curN][it] != lim[curN][it] && !visited[it])
                {
                    nextInLine.push(it);
                    visited[it] = true;
                    par[it] = curN;
                }
        }
        if(!visited[n+m+1])
        {
            for(int i = 1; i <= n; i ++)
                for(int j = n+1; j <= n+m; j ++)
                    if(cur[i][j])
                    {
                        v.push_back({i, j-n});
                        break;
                    }
            break;
        }
        for(auto it : adj[n+m+1])
        {
            if(!visited[it] || cur[it][n+m+1] == lim[it][n+m+1]) continue;
            curF = 2000000000; par[n+m+1] = it; curN = n+m+1;
            while(curN != 0)
                curF = min(curF, lim[par[curN]][curN] - cur[par[curN]][curN]), curN = par[curN];
            curN = n+m+1;
            while(curN != 0)
                cur[par[curN]][curN] += curF, cur[curN][par[curN]] -= curF, curN = par[curN];
            ans += curF;
        }
    }
    cout << ans << "\n";
    for(int i = 0; i < v.size(); i ++)
        cout << v[i].f << " " << v[i].s << "\n";
}
*/
