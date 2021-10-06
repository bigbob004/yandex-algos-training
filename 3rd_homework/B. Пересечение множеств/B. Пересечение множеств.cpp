#include <iostream>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{   
    set<int> A;
    set<int> B;
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    stringstream inp1(s1);
    stringstream inp2(s2);

    int a;
    while (inp1 >> a) {
        A.insert(a);
    }
    while (inp2 >> a) {
        B.insert(a);
    }

    for (auto& item : A) {
        auto finded = B.find(item);
           if (finded != end(B)) {
               cout << item << " ";
        }
    }

}


