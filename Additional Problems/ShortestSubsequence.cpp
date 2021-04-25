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
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int hsh(char c)
{
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    return 3;
}
bool used[4];
int main()
{
    int n;
    string st, ans = ""; ans.reserve(1000000);
    cin >> st; n = (int)st.length();
    for(int i = 0; i < n; i ++)
    {
        while(!used[0] || !used[1] || !used[2] || !used[3])
        {
            if(i >= n) break;
            used[hsh(st[i])] = true;
            if(used[0] && used[1] && used[2] && used[3])
            {
                ans += st[i];
                memset(used, false, sizeof(used));
                break;
            }
            i ++;
        }
    }
    if(!used[0]) ans += "A";
    else if(!used[1]) ans += "C";
    else if(!used[2]) ans += "G";
    else if(!used[3]) ans += "T";
    else ans += "AA";
    cout << ans << "\n";
}
