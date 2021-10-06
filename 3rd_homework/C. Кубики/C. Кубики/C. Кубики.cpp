#include <iostream>
#include <set>
#include <vector>

using namespace std;

void Input_set(set<int>& data, const int& size) {
    int buf = 0;
    for (int i = 0; i < size; i++) {
        cin >> buf;
        data.insert(buf);
    }
}

void Output(const vector<int>& data) {
    cout << data.size() << endl;
    for (auto& item : data)
        cout << item << " ";
    cout << endl;
}

void Merge_two_sets(vector<int>& uniq_lhs, vector<int>& uniq_rhs, vector<int>& intersec, const set<int>& lhs, const set<int>& rhs) {
    auto i = begin(lhs);
    auto j = begin(rhs);
    while (i != end(lhs) && j != end(rhs)) {
        if (*i == *j) {
            intersec.push_back(*i);
            ++i;
            ++j;
        }
        else
            if (*i < *j) {
                uniq_lhs.push_back(*i);
                ++i;
            }
            else {
                uniq_rhs.push_back(*j);
                ++j;
            }
    }

    while (i != end(lhs)) {
        uniq_lhs.push_back(*i);
        ++i;
    }

    while (j != end(rhs)) {
        uniq_rhs.push_back(*j);
        ++j;
    }
}

int main()
{
    int N = 0, M = 0;
    set<int> A;
    set<int> B;
    vector<int> intersection;
    vector<int> uniq_A;
    vector<int> uniq_B;

    cin >> N >> M;
    Input_set(A, N);
    Input_set(B, M);

    /*for (auto& item : B) {
        auto finded = A.find(item);
        if (finded != end(A))
            intersection.insert(item);
        else
            uniq_B.push_back(item);
    }

    for (auto& item : A) {
        auto finded = intersection.find(item);
        if (finded == end(intersection))
            uniq_A.push_back(item);
    }*/
    Merge_two_sets(uniq_A, uniq_B, intersection, A, B);
    
    Output(intersection);
    Output(uniq_A);
    Output(uniq_B);
   
    return 0;
}

