#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		long long n, x;
		cin >> n >> x;
		vector<long long> s(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> s[i] >> r[i];
		}
		// create a 'Compare' function to be added in the sort function
		// the condition of sorting must be based on the IMDB rating of each video
		auto Compare = [&](int a, int b) {
			return r[a - 1] < r[b - 1];
		};
		// the concept applied here is the same as in a graph
		// there are vertices, and each vertex has its own adjacent nodes
		// create a 'temp' vector to serve as a vertex to those adjacent nodes
		// which is the size of the movie, and the corresponding IMDB rating
		// sort them in a way that we will use the elements of the 'temp'
		// vector as an index to sort the two vectors ('s' and 'r') based
		// on the IMDB rating
		vector<int> temp(n, 0);
		for (int i = 0; i < n; i++) {
			// set the elements in the increasing order from 1 to 'n'
			temp[i] = i + 1;
		}
		// use the 'Compare' function as an argument in the sort function
		sort(temp.begin(), temp.end(), Compare);
		long long ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			// if the current size can be accommdated by 'x' space
			// then store the movie with the highest IMDB rating
			if (x >= s[temp[i] - 1]) {
				ans = max(ans, r[temp[i] - 1]);
				// don't forget to subtract the movie size from the 'x' space
				x -= s[temp[i] - 1];
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
