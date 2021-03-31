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

string st;
int n;
ll mod = 1000000007, p = 7;
ll pw[1000010];
ll hsh[1000010];
vector<int> ans;
void hshs()
{
    hsh[0] = 1;
    for(int i = 0; i < (int)st.length(); i ++)
        hsh[i + 1] = ((hsh[i] * p) % mod + (ll)st[i]) % mod;
}
ll get(int a, int b)
{
    return (hsh[b + 1] - (hsh[a] * pw[b - a + 1]) % mod + mod) % mod;
}
int main()
{
    st.reserve(1000000);
    cin >> st;
    n = (int)st.length();
    pw[0] = 1;
    for(int i = 1; i <= st.length(); i ++)
        pw[i] = (pw[i - 1] * p) % mod;
    hshs();
    for(int i = 0; i < n - 1; i ++)
        if(get(0, i) == get(n - i - 1, n - 1))
            ans.push_back(i + 1);
    for(int i = 0; i < ans.size(); i ++)
        cout << ans[i] << " ";
    cout << "\n";
}
