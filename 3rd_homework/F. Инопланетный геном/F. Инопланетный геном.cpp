#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> pair_of_basics(const string& s) {
    vector<string> pair_of_basics;
    for (int i = 0; i < s.size() - 1; ++i) {
        char buf[3] = { s[i], s[i + 1], '\0' };
        string s_buf(buf);
        pair_of_basics.push_back(buf);
    }
    return pair_of_basics;
}



int main()
{
    string s1;
    
    string s2;

    cin >> s1;
    cin >> s2;

    vector<string> pair_of_basics1 = pair_of_basics(s1);
    vector<string> pair_of_basics2 = pair_of_basics(s2);

    set<string> unique_pair_of_basics2(pair_of_basics2.begin(), pair_of_basics2.end());
    int ans = 0;

    for (auto& item : pair_of_basics1) {
        if (unique_pair_of_basics2.find(item) != unique_pair_of_basics2.end())
            ++ans;
    }
    cout << ans;
    return 0;
}

