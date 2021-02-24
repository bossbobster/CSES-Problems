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
 
int nums[21];
bool used[21];
int n, m;;
long long s1, s2, total = 0, ans = 20000000000000000;
string cur = "";
void printAll(int n1, int idx)
{
    if(n1 == 0)
    {
        s1 = s2 = 0;
        for(int i = 0; i < n; i ++)
            s1 += nums[cur[i] - '0'];
        s2 = total - s1;
        ans = min(ans, abs(s1 - s2));
        return;
    }
    for(int i = n - n1 + idx; i < m - n1 + 1; i ++)
    {
        if(used[i]) continue;
        cur[n - n1] = i + '0';
        used[i] = true;
        printAll(n1 - 1, idx);
        idx ++;
        used[i] = false;
    }
}
 
int main()
{
    cin >> m;
    for(int i = 0; i < m; i ++)
        cin >> nums[i];
    if(m == 1) { cout << nums[0]; return 0; }
    for(int i = 0; i < m; i ++) total += nums[i];
    for(int i = 0; i < m; i ++) cur += "0";
    for(int i = 1; i <= m / 2; i ++)
    {
        n = i;
        printAll(n, 0);
    }
    cout << ans << "\n";
}
