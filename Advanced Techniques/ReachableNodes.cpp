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
#include <valarray>
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
typedef long double ld;
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
#define input() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n, m, a, b, cur;
int in[50010];
vector<int> adj[50010];
bitset<50010> all[50010];
queue<int> nextInLine;
int main()
{
    input();
    cin >> n >> m;
    for(int i = 0; i < m; i ++)
    {
        cin >> a >> b; a--; b--;
        adj[b].push_back(a); in[a] ++;
    }
    for(int i = 0; i < n; i ++)
    {
        if(!in[i])
            nextInLine.push(i);
        all[i][i] = 1;
    }
    while(!nextInLine.empty())
    {
        cur = nextInLine.front();
        nextInLine.pop();
        for(auto it : adj[cur])
        {
            all[it] |= all[cur];
            in[it] --;
            if(!in[it])
                nextInLine.push(it);
        }
    }
    for(int i = 0; i < n; i ++)
        cout << all[i].count() << ((i==n-1)?"\n":" ");
}
