#include <iostream>
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

struct st
{
    int r, c, d, pr, pc;
};

string board[1010];
queue<st> nextInLine;
bool visited[1010][1010];
int len[1010][1010];
pii par[1010][1010];
int main()
{
    int n, m, r1, c1, r, c, d, pr, pc;
    cin >> n >> m;
    string ans = ""; ans.reserve(1000010);
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(board[i][j] == 'M') nextInLine.push({i, j, 0, 0, 0});
            if(board[i][j] == 'A') { r1 = i; c1 = j; }
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
            len[i][j] = 2000000000;
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r; c = nextInLine.front().c; d = nextInLine.front().d;
        nextInLine.pop();
        if(visited[r][c]) continue;
        visited[r][c] = true; len[r][c] = d;
        if(r + 1 < n && !visited[r + 1][c] && board[r + 1][c] != '#') nextInLine.push({r + 1, c, d + 1});
        if(r - 1 >= 0 && !visited[r - 1][c] && board[r - 1][c] != '#') nextInLine.push({r - 1, c, d + 1});
        if(c + 1 < m && !visited[r][c + 1] && board[r][c + 1] != '#') nextInLine.push({r, c + 1, d + 1});
        if(c - 1 >= 0 && !visited[r][c - 1] && board[r][c - 1] != '#') nextInLine.push({r, c - 1, d + 1});
    }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            visited[i][j] = false;
            par[i][j] = {-1, -1};
        }
    nextInLine.push({r1, c1, 0, -1, -1});
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r; c = nextInLine.front().c; d = nextInLine.front().d; pr = nextInLine.front().pr; pc = nextInLine.front().pc;
        nextInLine.pop();
        if(visited[r][c] || len[r][c] <= d) continue;
        par[r][c] = {pr, pc};
        if(r == 0 || c == 0 || r == n - 1 || c == m - 1)
        {
            while(r != -1)
            {
                pr = par[r][c].f; pc = par[r][c].s;
                if(pr == -1) break;
                if(pr < r) ans += "D";
                if(pr > r) ans += "U";
                if(pc < c) ans += "R";
                if(pc > c) ans += "L";
                r = pr; c = pc;
            }
            for(int i = 0; i < ans.length() / 2; i ++) swap(ans[i], ans[ans.length() - i - 1]);
            cout << "YES\n" << ans.length() << "\n" << ans << "\n";
            return 0;
        }
        visited[r][c] = true;
        if(r + 1 < n && !visited[r + 1][c] && board[r + 1][c] != '#') nextInLine.push({r + 1, c, d + 1, r, c});
        if(r - 1 >= 0 && !visited[r - 1][c] && board[r - 1][c] != '#') nextInLine.push({r - 1, c, d + 1, r, c});
        if(c + 1 < m && !visited[r][c + 1] && board[r][c + 1] != '#') nextInLine.push({r, c + 1, d + 1, r, c});
        if(c - 1 >= 0 && !visited[r][c - 1] && board[r][c - 1] != '#') nextInLine.push({r, c - 1, d + 1, r, c});
    }
    cout << "NO\n";
}
