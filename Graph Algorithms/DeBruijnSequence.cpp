#include <iostream>
#include <string.h>
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

int n;
vector<int> adj[40010];
string arr[40010];
bitset<40010> visited;
int tmp, cnt = 0;
void findAll(int cur, string &st)
{
    if(cur == n)
    {
        arr[cnt++] = st;
        return;
    }
    st[cur] = '0';
    findAll(cur + 1, st);
    st[cur] = '1';
    findAll(cur + 1, st);
}
int main()
{
    input();
    int cur = 1;
    string str, ans;
    cin >> n;
    ans.reserve((1<<n)+n);
    for(int i = 0; i < n; i ++)
        str += "0";
    findAll(0, str);
    for(int i = 0; i < (1<<n); i ++)
    {
        if(((i<<1)&((1<<n)-1)) != i) adj[i].push_back(((i<<1)&((1<<n)-1)));
        if(((i<<1)&((1<<n)-1))+1 != i) adj[i].push_back(((i<<1)&((1<<n)-1))+1);
    }
    ans = arr[0] + "1"; visited[0] = 1;
    while(!visited[cur])
    {
        visited[cur] = true;
        if(visited[adj[cur][1]])
        {
            ans += "0";
            cur = adj[cur][0];
        }
        else
        {
            ans += "1";
            cur = adj[cur][1];
        }
    }
    cout << ans.substr(0, ans.length()-1) << "\n";
}
