#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> X;
    int x = 0, y = 0;
    int N = 0;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> x >> y;
        X.insert(x);
    }

    cout << X.size();
    return 0;
}


