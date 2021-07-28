#include <iostream>
#include <string.h>
#include <random>
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
#include <complex>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef pair<int, char> pic;
typedef pair<pii, int> piii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ull, ull> pull;
typedef complex<double> cd;
//#define max(n, m) ((n>m)?n:m)
//#define min(n, m) ((n<m)?n:m)
#define f first
#define s second
#define input() ios_base::sync_with_stdio(0);cin.tie(0);

struct node
{
    node* arr[26];
    int cur = 0;
};
string nums[100010];
ll dp[5010];
ll mod = 1000000007;
int main()
{
    input();
    node* root = new node(); node* cur;
    int n, k;
    string st;
    cin >> st >> k;
    n = (int)st.length();
    for(int i = 0; i < k; i ++)
    {
        cin >> nums[i];
        cur = root;
        for(int j = 0; j < nums[i].length(); j ++)
        {
            if(cur->arr[nums[i][j]-'a'] == nullptr)
                cur->arr[nums[i][j]-'a'] = new node();
            cur = cur->arr[nums[i][j]-'a'];
        }
        cur->cur++;
    }
    dp[0] = 1;
    for(int i = 0; i < n; i ++)
    {
        cur = root;
        for(int j = i; j < n; j ++)
        {
            if(cur->arr[st[j]-'a'] == nullptr)
                break;
            cur = cur->arr[st[j]-'a'];
            dp[j+1] = (dp[j+1] + dp[i] * cur->cur) % mod;
        }
    }
    cout << dp[n] << "\n";
}
