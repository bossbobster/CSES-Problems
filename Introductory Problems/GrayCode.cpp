#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
 
vector<string> out;
void rec(int cur, vector<string> prev)
{
    out.clear();
    for(int i = 0; i < (int)prev.size(); i ++)
        out.push_back("0" + prev[i]);
    for(int i = (int)prev.size() - 1; i >= 0; i --)
        out.push_back("1" + prev[i]);
}
int main()
{
    int n;
    cin >> n;
    out.push_back("0"); out.push_back("1");
    for(int i = 2; i <= n; i ++)
        rec(i, out);
    for(int i = 0; i < out.size(); i ++)
        cout << out[i] << "\n";
}
