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
vector<short> board;
void rec(int r, vector<short> cur)
{
    if(r == 8) { ans ++; return; }
    for(int i = 0; i < 8; i ++)
        if(cur[r * 8 + i] == 0)
        {
            cur[r * 8 + i] ++;
            for(int j = 0; j < 8; j ++)
                if(j != i)
                    cur[r * 8 + j] ++;
            for(int j = 0; j < 8; j ++)
                if(j != r)
                    cur[j * 8 + i] ++;
            for(int j = -7; j < 8; j ++)
                if(j + r >= 0 && j + r < 8 && j + i >= 0 && j + i < 8 && j != 0)
                    cur[(r + j) * 8 + i + j] ++;
            for(int j = -7; j < 8; j ++)
                if(r - j >= 0 && r - j < 8 && j + i >= 0 && j + i < 8 && j != 0)
                    cur[(r - j) * 8 + i + j] ++;
            rec(r + 1, cur);
            cur[r * 8 + i] --;
            for(int j = 0; j < 8; j ++)
                if(j != i)
                    cur[r * 8 + j] --;
            for(int j = 0; j < 8; j ++)
                if(j != r)
                    cur[j * 8 + i] --;
            for(int j = -7; j < 8; j ++)
                if(j + r >= 0 && j + r < 8 && j + i >= 0 && j + i < 8 && j != 0)
                    cur[(r + j) * 8 + i + j] --;
            for(int j = -7; j < 8; j ++)
                if(r - j >= 0 && r - j < 8 && j + i >= 0 && j + i < 8 && j != 0)
                    cur[(r - j) * 8 + i + j] --;
        }
}
int main()
{
    string tmp;
    board.resize(70);
    for(int i = 0; i < 8; i ++)
    {
        cin >> tmp;
        for(int j = 0; j < 8; j ++)
            if(tmp[j] == '*')
                board[i * 8 + j] = 1;
    }
    rec(0, board);
    cout << ans << "\n";
}
