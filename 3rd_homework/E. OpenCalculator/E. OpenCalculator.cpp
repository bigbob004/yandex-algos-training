#include <iostream>
#include <set>

using namespace std;

size_t Size_of_new_set(int number, set<int>& old_set) {
    while (number != 0) {
        old_set.insert(number % 10);
        number /= 10;
    }
    return old_set.size();
}

int main()
{
    set<int> unique_digits;
    int digit = 0;
    int number = 0;
    for (int i = 0; i < 3; ++i) {
        cin >> digit;
        unique_digits.insert(digit);
    }
    int old_size = unique_digits.size();
    cin >> number;
    cout << Size_of_new_set(number, unique_digits) - old_size;

}
