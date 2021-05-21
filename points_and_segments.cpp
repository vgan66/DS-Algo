#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>

using std::vector;

vector<int> partition3_1(vector<std::pair<long, char>> &v, int l, int r)
{
	vector <int> p;
	int j = l;
	char k = v[l].second;
	for (int i = l + 1; i <= r; ++i)
	{
		if (v[i].second <= k)
		{
			++j;
			swap(v[i], v[j]);
		}
	}

	std::swap(v[l], v[j]);
	p.push_back(j);
	k = v[j].second;
	int q = l;
	for (int i = l; i < j; ++i)
	{
		if (v[i].second < k)
		{
			swap(v[i], v[q]);
			++q;
		}
	}
	if (v[q] != v[j])
		q = q + 1;
	p.push_back(q);
	std::swap(p[0], p[1]);
	return p;
}

void quicksort3_1(vector<std::pair<long, char>> &v, int l, int r)
{
	if (l >= r)
		return;

	int k = l + rand() % (r - l + 1);
	swap(v[l], v[k]);
	vector<int> m = partition3_1(v, l, r);
	quicksort3_1(v, l, m[0] - 1);
	quicksort3_1(v, m[1] + 1, r);
}

vector<int> partition3(vector<std::pair<long, char>> &v, int l, int r)
{
	vector <int> p;
	int j = l;
	long k = v[l].first;
	for (int i = l + 1; i <= r; ++i)
	{
		if (v[i].first <= k)
		{
			++j;
			swap(v[i], v[j]);
		}
	}

	std::swap(v[l], v[j]);
	p.push_back(j);
	k = v[j].first;
	int q = l;
	for (int i = l; i < j; ++i)
	{
		if (v[i].first < k)
		{
			swap(v[i], v[q]);
			++q;
		}
	}
	if (v[q].first != v[j].first)
		q = q + 1;
	p.push_back(q);
	std::swap(p[0], p[1]);
	quicksort3_1(v, p[0], p[1]);;
	return p;
}

void quicksort3(vector<std::pair<long, char>> &v, int l, int r)
{
	if (l >= r)
		return;

	int k = l + rand() % (r - l + 1);
	swap(v[l], v[k]);
	vector<int> m = partition3(v, l, r);
	quicksort3(v, l, m[0] - 1);
	quicksort3(v, m[1] + 1, r);
}

std::map<long,long> fast_count_segments(vector<long> starts, vector<long> ends, vector<long> points) {
  std::map<long,long> cnt;

  vector<std::pair<long, char>> v;
  
  for (size_t k = 0; k < ends.size(); ++k)
  {
	  v.push_back(std::make_pair(starts[k], 'l'));
	  //v.push_back(std::make_pair(ends[k], 'r'));
  }
  for (auto i : points)
	  v.push_back(std::make_pair(i, 'p'));

  for (size_t k = 0; k < ends.size(); ++k)
  {
	  //v.push_back(std::make_pair(starts[k], 'l'));
	  v.push_back(std::make_pair(ends[k], 'r'));
  }

  quicksort3(v, 0, v.size() - 1);

  int j = 0;
 /* for (size_t i = 1; i < v.size(); ++i)
  {
	  if (v[j].first == v[i].first)
	  {
		  if (v[j].second > v[i].second)
		  {
			  std::swap(v[j], v[i]);
			  ++j;
		  }
	  }
  }*/
  long long c = 0LL;
  for (size_t i = 0; i < v.size(); ++i)
  {
	  if (v[i].second == 'p')
	  {
		//  int j = v[i].first;
		  cnt.insert({ v[i].first, c });
	  }

	  if (v[i].second == 'l')
		  ++c;
	  if (v[i].second == 'r')
		  --c;
 }
  
  //write your code here
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
	/*while (true)
	{*/
		int n, m;
		std::cin >> n >> m;
		vector<long> starts(n), ends(n);
		for (size_t i = 0; i < starts.size(); i++) {
			std::cin >> starts[i] >> ends[i];
		}
		vector<long> points(m);
		for (size_t i = 0; i < points.size(); i++) {
			std::cin >> points[i];
		}
		//use fast_count_segments
		std::map<long, long> cnt = fast_count_segments(starts, ends, points);
		for (size_t i = 0; i < points.size(); i++) {
			std::cout << cnt[points[i]] << ' ';
		}
		std::cout << "\n";
//	}
}
