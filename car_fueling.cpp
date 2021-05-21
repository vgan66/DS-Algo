#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int nr = 0; int cr = 0; int d = 0;
	int n = stops.size();
	stops.push_back(dist);
	while (cr < stops.size())
	{
		int lr = cr;
		while (cr < stops.size() && (stops[cr] - d <= tank))
			++cr;
		if (lr == cr)
			return -1;
		d = stops[cr - 1];
		if(cr <= n)
		 nr = nr + 1;
	}
    return nr;
}


int main() {
		int d = 0;
		cin >> d;
		int m = 0;
		cin >> m;
		int n = 0;
		cin >> n;

		vector<int> stops(n);
		for (size_t i = 0; i < n; ++i)
			cin >> stops.at(i);

		cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
