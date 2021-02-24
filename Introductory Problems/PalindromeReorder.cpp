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
 
int cnt[26];
int main()
{
    string st, ans;
    int idx = 0, bad = 0;
    cin >> st;
    for(int i = 0; i < st.length(); i ++)
        cnt[st[i] - 'A'] ++;
    ans.reserve(st.length());
    for(int i = 0; i < st.length(); i ++)
        ans += "A";
    for(int i = 0; i < 26; i ++)
    {
        if(cnt[i] % 2 == 1) { bad ++; ans[st.length() / 2] = i + 'A'; }
        for(int j = 0; j < cnt[i] / 2; j ++)
        {
            ans[idx] = ans[st.length() - idx - 1] = i + 'A';
            idx ++;
        }
    }
    if(bad > 1) { cout << "NO SOLUTION\n"; return 0; }
    cout << ans << "\n";
}
