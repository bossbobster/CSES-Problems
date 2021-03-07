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
typedef pair<pii, int> piii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define max(n, m) ((n>m)?n:m)
#define min(n, m) ((n<m)?n:m)
#define f first
#define s second

int board[1010][1010];
int col[1010][1010];
int pre[1010][1010];
int getsum(int x1, int y1, int x2, int y2)
{
    int all = pre[x2][y2];
    int subX = 0, subY = 0, add = 0;
    if(y1 != 0) subX = pre[x2][y1 - 1];
    if(x1 != 0) subY = pre[x1 - 1][y2];
    if(x1 != 0 && y1 != 0) add = pre[x1 - 1][y1 - 1];
    return all - subX - subY + add;
}
int main()
{
    int n, q, a, b, c, d;
    string cur;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> cur;
        for(int j = 0; j < n; j ++)
            board[i][j] = ((cur[j]=='.')?0:1);
    }
    for(int i = 0; i < n; i ++)
        col[i][0] = board[i][0];
    for(int i = 0; i < n; i ++)
        for(int j = 1; j < n; j ++)
            col[i][j] = col[i][j - 1] + board[i][j];
    for(int i = 0; i < n; i ++)
        pre[0][i] = col[0][i];
    for(int i = 1; i < n; i ++)
        for(int j = 0; j < n; j ++)
            pre[i][j] = pre[i - 1][j] + col[i][j];
    for(int i = 0; i < q; i ++)
    {
        cin >> a >> b >> c >> d;
        if(a > c) swap(a, c);
        if(b > d) swap(b, d);
        cout << getsum(a - 1, b - 1, c - 1, d - 1) << "\n";
    }
}
