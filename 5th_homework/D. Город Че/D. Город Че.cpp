#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, r;
    vector<int> monuments;
    int R = 1, L = 0;
    long int counter = 0;

    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int buf;
        cin >> buf;
        monuments.push_back(buf);
    }

    while (R < n) {
        if (monuments[R] - monuments[L] <= r)
            ++R;
        else {
            counter += n - R;
            ++L;
        }
    }

    cout << counter;
}
