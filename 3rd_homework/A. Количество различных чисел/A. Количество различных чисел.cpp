#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    set<int> A;
    string s;
    getline(cin, s);

    stringstream inp(s);

    int a;
    while (inp >> a) {
        A.insert(a);
    }
    cout << A.size();

    return 0;
}


