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
    int r, c, a, b;
};

queue<st> nextInLine;
string board[1010];
bool visited[1010][1010];
pii par[1010][1010];
int main()
{
    int n, m, r, c, a, b, rB, cB, rE, cE;
    string ans = ""; ans.reserve(1000010);
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(board[i][j] == 'A') { rB = i; cB = j; }
            if(board[i][j] == 'B') { rE = i; cE = j; }
        }
    nextInLine.push({rB, cB, -1, -1});
    while(!nextInLine.empty())
    {
        r = nextInLine.front().r; c = nextInLine.front().c; a = nextInLine.front().a; b = nextInLine.front().b;
        nextInLine.pop();
        if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || board[r][c] == '#') continue;
        par[r][c] = {a, b};
        if(r == rE && c == cE)
        {
            while(r != -1)
            {
                rB = par[r][c].f; cB = par[r][c].s;
                if(rB == -1) break;
                if(rB < r) ans += "D";
                if(rB > r) ans += "U";
                if(cB < c) ans += "R";
                if(cB > c) ans += "L";
                r = rB; c = cB;
            }
            for(int i = 0; i < ans.length() / 2; i ++) swap(ans[i], ans[ans.length() - i - 1]);
            cout << "YES\n" << ans.length() << "\n" << ans << "\n";
            return 0;
        }
        visited[r][c] = true;
        nextInLine.push({r + 1, c, r, c});
        nextInLine.push({r - 1, c, r, c});
        nextInLine.push({r, c + 1, r, c});
        nextInLine.push({r, c - 1, r, c});
    }
    cout << "NO\n" << "\n";
}
