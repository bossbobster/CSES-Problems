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
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

ll dist[510][510];
int main()
{
    ll n, m, q, one, two, three;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            dist[i][j] = 200000000000000000;
    for(int i = 0; i < n; i ++) dist[i][i] = 0;
    for(int i = 0; i < m; i ++)
    {
        cin >> one >> two >> three;
        dist[one - 1][two - 1] = min(dist[one - 1][two - 1], three);
        dist[two - 1][one - 1] = min(dist[two - 1][one - 1], three);
    }
    for(int k = 0; k < n; k ++)
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < q; i ++)
    {
        cin >> one >> two;
        if(dist[one - 1][two - 1] == 200000000000000000) cout << -1 << "\n";
        else cout << dist[one - 1][two - 1] << "\n";
    }
}
