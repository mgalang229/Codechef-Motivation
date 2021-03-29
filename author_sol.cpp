#include <bits/stdc++.h>

using namespace std;
	
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n >> x;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int s, r;
			cin >> s >> r;
			// check if the current size is less than x 
			// and the rating is STRICTLY higher than
			// the rating that we saved in 'ans'
			if (s <= x && ans < r) {
				ans = r;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
