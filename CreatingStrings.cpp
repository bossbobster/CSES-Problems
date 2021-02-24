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
 
string st;
bool used[10];
int n;
string cur = "";
set<string> pos;
void printAll(int n1)
{
    if(n1 == 0)
    {
        pos.insert(cur);
        return;
    }
    for(int i = 0; i < n; i ++)
    {
        if(used[i]) continue;
        cur[n - n1] = st[i];
        used[i] = true;
        printAll(n1 - 1);
        used[i] = false;
    }
}
 
int main()
{
    cin >> st;
    n = (int)st.length();
    for(int i = 0; i < n; i ++) cur += "a";
    printAll(n);
    cout << pos.size() << "\n";
    for(auto str : pos)
        cout << str << "\n";
}
