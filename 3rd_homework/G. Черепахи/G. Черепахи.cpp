#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> a, b;
	int N;
	int counter = 0;

	cin >> N;
	
	int buf1 = 0;
	int buf2 = 0;


	for (int i = 0; i < N; ++i) {
		cin >> buf1 >> buf2;
		if (buf1 >= 0 and buf2 >= 0)
			if(buf1 + buf2 == N - 1)
				if (a.find(buf1) == a.end() && b.find(buf2) == b.end()) {
					a.insert(buf1);
					b.insert(buf2);
					++counter;
				}
	}

	cout << counter;
	return 0;
}

