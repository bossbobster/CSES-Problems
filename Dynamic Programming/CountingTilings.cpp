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

vector<vector<int>> fib[11];
vector<int> nx[1050]; // around 5 to 6 for each state
vector<pii> small;
vector<int> curNx;
int dp[1010][1050];
void findAll(vector<int> cur, int idx)
{
    if(idx == small.size())
    {
        int sum = 0, pw = 1;
        for(int i = 0; i < cur.size(); i ++)
        {
            sum += cur[i] * pw;
            pw *= 2;
        }
        curNx.push_back(sum);
        return;
    }
    for(int i = 0; i < fib[small[idx].s].size(); i ++)
    {
        for(int j = 0; j < small[idx].s; j ++)
            cur[j + small[idx].f] = fib[small[idx].s][i][j];
        findAll(cur, idx + 1);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> emp;
    fib[0].push_back(emp); emp.push_back(1); fib[1].push_back(emp);
    for(int i = 2; i <= n; i ++)
    {
        for(int j = 0; j < fib[i - 2].size(); j ++)
        {
            vector<int> tmp = fib[i - 2][j];
            tmp.push_back(0); tmp.push_back(0);
            fib[i].push_back(tmp);
        }
        for(int j = 0; j < fib[i - 1].size(); j ++)
        {
            vector<int> tmp = fib[i - 1][j];
            tmp.push_back(1);
            fib[i].push_back(tmp);
        }
    }
    for(int i = 0; i < (1 << n); i ++)
    {
        vector<int> tmp, cur;
        tmp.resize(n);
        small.clear(); curNx.clear();
        for(int j = 0; j < n; j ++)
        {
            if(((1 << j) & i)) cur.push_back(1);
            else cur.push_back(0);
        }
        for(int j = 0; j < n; j ++)
        {
            if(cur[j] == 1)
                tmp[j] = 0;
            else
                tmp[j] = 2;
        }
        pii pb = {0, 0};
        for(int j = 0; j < n; j ++)
        {
            if(tmp[j] == 0)
            {
                if(pb.s > 0) small.push_back(pb);
                pb.f = j + 1; pb.s = 0;
            }
            else
                pb.s ++;
        }
        if(pb.s > 0) small.push_back(pb);
        findAll(tmp, 0);
        nx[i] = curNx;
    }
    for(int i = 0; i < fib[n].size(); i ++)
    {
        int sum = 0, pw = 1;
        for(int j = 0; j < n; j ++)
        {
            sum += fib[n][i][j] * pw;
            pw *= 2;
        }
        dp[0][sum] ++;
    }
    for(int i = 0; i < m - 1; i ++)
        for(int j = 0; j < (1 << n); j ++)
            for(int k = 0; k < nx[j].size(); k ++)
                dp[i + 1][nx[j][k]] = (dp[i + 1][nx[j][k]] + dp[i][j]) % 1000000007;
    cout << dp[m - 1][0] << "\n";
    return 0;
}
