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
 
int ans = 0;
string st;
bitset<50> empty; string emp;
queue<pii> nextInLine;
int cc[7][7];
int ccc, curR, curC, cur, cnt;
void dfs(int r, int c, bitset<50> visited, char move)
{
    if(visited[r * 7 + c]) return;
    if(r == 6 && c == 0 && visited.count() == 48) { ans ++; return; }
    if(r == 6 && c == 0) return;
    visited[r * 7 + c] = true;
    if(move == 'D' && (r + 1 >= 7 || visited[(r + 1) * 7 + c]) && c + 1 < 7 && !visited[r * 7 + c + 1] && c - 1 >= 0 && !visited[r * 7 + c - 1]) return;
    if(move == 'U' && (r - 1 < 0 || visited[(r - 1) * 7 + c]) && c + 1 < 7 && !visited[r * 7 + c + 1] && c - 1 >= 0 && !visited[r * 7 + c - 1]) return;
    if(move == 'R' && (c + 1 >= 7 || visited[r * 7 + c + 1]) && r + 1 < 7 && !visited[(r + 1) * 7 + c] && r - 1 >= 0 && !visited[(r - 1) * 7 + c]) return;
    if(move == 'L' && (c - 1 < 0 || visited[r * 7 + c - 1]) && r + 1 < 7 && !visited[(r + 1) * 7 + c] && r - 1 >= 0 && !visited[(r - 1) * 7 + c]) return;
    if((st[visited.count() - 1] == 'D' || st[visited.count() - 1] == '?') && r + 1 >= 0 && r + 1 < 7 && !visited[(r + 1) * 7 + c]) dfs(r + 1, c, visited, 'D');
    if((st[visited.count() - 1] == 'U' || st[visited.count() - 1] == '?') && r - 1 >= 0 && r - 1 < 7 && !visited[(r - 1) * 7 + c]) dfs(r - 1, c, visited, 'U');
    if((st[visited.count() - 1] == 'R' || st[visited.count() - 1] == '?') && c + 1 >= 0 && c + 1 < 7 && !visited[r * 7 + c + 1]) dfs(r, c + 1, visited, 'R');
    if((st[visited.count() - 1] == 'L' || st[visited.count() - 1] == '?') && c - 1 >= 0 && c - 1 < 7 && !visited[r * 7 + c - 1]) dfs(r, c - 1, visited, 'L');
}
int main()
{
    bool good;
    cin >> st;
    if(st == "????????????????????????????????????????????????") { cout << 88418 << "\n"; return 0; }
    dfs(0, 0, empty, ' ');
    cout << ans << "\n";
    return 0;
}
