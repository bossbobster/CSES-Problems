#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <bitset>
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
 
vector<int> sets[2];
bool in[1000010];
int main()
{
    ll n, sum = 0;
    cin >> n;
    if(n <= 2) { cout << "NO\n"; return 0; }
    if(n % 4 == 0)
    {
        cout << "YES\n";
        for(int i = 0; i < n / 2; i ++)
        { sets[i % 2].push_back(i + 1); sets[i % 2].push_back(n - i); }
    }
    else if(n % 4 == 2 || n % 4 == 1) { cout << "NO\n"; return 0; }
    else
    {
        for(int i = n; i >= 1; i --)
        {
            sum += i;
            sets[0].push_back(i);
            in[i] = true;
            if(sum + (i - 1) >= (n * (n + 1) / 4))
                break;
        }
        if(sum != (n * (n + 1) / 4))
        {
            sets[0].push_back((n * (n + 1) / 4) - sum);
            in[(n * (n + 1) / 4) - sum] = true;
        }
        for(int i = 1; i <= n; i ++)
            if(!in[i])
                sets[1].push_back(i);
        cout << "YES\n";
    }
    sort(sets[0].begin(), sets[0].end()); sort(sets[1].begin(), sets[1].end());
    cout << sets[0].size() << "\n";
    for(int i = 0; i < sets[0].size(); i ++)
        cout << sets[0][i] << " ";
    cout << "\n" << sets[1].size() << "\n";
    for(int i = 0; i < sets[1].size(); i ++)
        cout << sets[1][i] << " ";
    cout << "\n";
}
