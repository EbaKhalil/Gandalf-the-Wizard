#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void process(int& weightOfChest, int& numOfTreasures, vector<pair<int, int>>& treasures) {
	cin >> weightOfChest >> numOfTreasures;
	treasures.resize( numOfTreasures);

	for (auto& treasure : treasures) {
		cin >> treasure.first >> treasure.second;
	}
}
	

int getMin(int weightOfChest, const vector<pair<int, int>>& treasures) {
	const int INF = 1000000000;
	vector<int> dp(weightOfChest + 1, INF);
	dp[0] = 0;

	for (const auto& treasure : treasures) {
		int weight = treasure.first;
		int value = treasure.second;
		for (int presentWeight = weight; presentWeight <= weightOfChest; ++presentWeight) {
			if (dp[presentWeight - weight] != INF) {
				dp[presentWeight] = min(dp[presentWeight], dp[presentWeight - weight] + value);
			}
		}
	}
	return dp[weightOfChest];
}
			int main() {
				int weight0fChest;
				int numOfTreasures;
				vector<pair<int, int>> treasures;

				process(weight0fChest, numOfTreasures, treasures);
				int res = getMin(weight0fChest, treasures);

				if (res == 1000000000) {
					cout << "It's not feasible" << endl;
				}
				else {
					cout << res << endl;
				}
				return 0;
			}