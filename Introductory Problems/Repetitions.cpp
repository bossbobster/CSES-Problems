#include <iostream>
using namespace std;
 
int main()
{
    string s;
    int best = 1, cur = 1;
    cin >> s;
    for(int i = 1; i < s.length(); i ++)
    {
        if(s[i] == s[i - 1]) cur ++;
        else cur = 1;
        best = max(best, cur);
    }
    cout << best << endl;
}
