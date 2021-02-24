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
 
struct thing
{
    int first, second;
};
multimap<int, thing> stuff;
int n;
set<vector<int>> visited;
int nums[1010];
int target;
int main()
{
    cin >> n >> target;
    for(int i = 0; i < n; i ++)
        cin >> nums[i];
    vector<int> tmp;
    pair<multimap<int, thing>::iterator, multimap<int, thing>::iterator> range;
    for(int i = 0; i < n - 1; i ++)
        for(int j = i + 1; j < n; j ++)
            stuff.insert(pair<int, thing>(nums[i] + nums[j], {i, j}));
    for(int i = 0; i < n - 1; i ++)
        for(int j = i + 1; j < n; j ++)
        {
            range = stuff.equal_range(target - nums[i] - nums[j]);
            for(multimap<int, thing>::iterator it = range.first; it != range.second; ++ it)
            {
                if(j != it->second.first && j != it->second.second && i != it->second.first && i != it->second.second && it->second.first != it->second.second){}
                else continue;
                tmp.clear();
                tmp.push_back(i); tmp.push_back(j); tmp.push_back(it->second.first); tmp.push_back(it->second.second);
                sort(tmp.begin(), tmp.end());
                for(int k = 0; k < tmp.size(); k ++)
                    cout << tmp[k] + 1 << " ";
                cout << "\n";
                return 0;
            }
        }
    cout << "IMPOSSIBLE\n";
}
