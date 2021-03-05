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

queue<pii> nextInLine;
string board[1010];
bool visited[1010][1010];
int main()
{
    int n, m, ans = 0, r, c;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        cin >> board[i];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            if(visited[i][j] || board[i][j] == '#') continue;
            ans ++;
            nextInLine.push({i, j});
            while(!nextInLine.empty())
            {
                r = nextInLine.front().f; c = nextInLine.front().s;
                nextInLine.pop();
                if(r < 0 || r >= n || c < 0 || c >= m || visited[r][c] || board[r][c] == '#') continue;
                visited[r][c] = true;
                nextInLine.push({r + 1, c});
                nextInLine.push({r - 1, c});
                nextInLine.push({r, c + 1});
                nextInLine.push({r, c - 1});
            }
        }
    cout << ans << "\n";
}
