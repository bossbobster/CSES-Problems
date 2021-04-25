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
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int n, q, a, b, c, d, type;
bool board[1010][1010];
int bit[1010][1010];
void update(int x, int y, int val)
{
    x++; y++;
    for(int i = x; i <= n; i += (i & (-i)))
        for(int j = y; j <= n; j += (j & (-j)))
            bit[i][j] += val;
}
int sumUtil(int x, int y)
{
    int ans = 0; x++; y++;
    for(int i = x; i > 0; i -= (i & (-i)))
        for(int j = y; j > 0; j -= (j & (-j)))
            ans += bit[i][j];
    return ans;
}
int sum(int x1, int y1, int x2, int y2)
{
    return sumUtil(x2, y2) - sumUtil(x1-1, y2) - sumUtil(x2, y1-1) + sumUtil(x1-1, y1-1);
}
int main()
{
    cin >> n >> q;
    char ch;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> ch;
            if(ch == '*') { board[i][j] = true; update(i, j, 1); }
        }
    for(int i = 0; i < q; i ++)
    {
        cin >> type;
        if(type == 1)
        {
            cin >> a >> b; a--; b--;
            if(board[a][b]) { board[a][b] = false; update(a, b, -1); }
            else { board[a][b] = true; update(a, b, 1); }
        }
        else
        {
            cin >> a >> b >> c >> d; a--; b--; c--; d--;
            cout << sum(a, b, c, d) << "\n";
        }
    }
}
