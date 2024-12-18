#include <iostream>
#include <vector>

using namespace std;

struct Treasure {
	int weight;
	int value;

};

void fillDynamicTable(int W, const vector<Treasure>& treasures, vector<int>& dp) {
	int n = treasures.size();
	dp[0] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = treasures[i].weight; j <= W; j++) {
			if (dp[j - treasures[i].weight] != INT_MAX) {
				dp[j] = min(dp[j], dp[j - treasures[i].weight] + treasures[i].value);
			}
		}
	}
}
int lastAnswer(int W, const vector<int>& dp) {
	return dp[W];
}
int main() {
	int theChestWeight;
	int numOfTreasures;
	int numOfTreasures;

	cout << "Enter the chest weight in grams: ";
	cin >> theChestWeight;

	cout << "Enter the number of types for treasures: ";
	cin >> numOfTreasures;

	vector<Treasure> treasures(numOfTreasures);

	for (int i = 0; i < numOfTreasures; i++) {
		cout << "Treasure " << i + 1 << " weight = ";
		cin >> treasures[i].weight;
		cout << "Treasure " << i + 1 << " value = ";
		cin >> treasures[i].value;
	}
	vector<int> dp(theChestWeight + 1, INT_MAX);

	fillDynamicTable(theChestWeight, treasures, dp);

	int res = lastAnswer(theChestWeight, dp);
	if (res == INT_MAX) {
		cout << "Not possible" << endl;
	}
	else {
		cout << "The minimum possible value of the chest = " << res << endl;
	}
	return 0;
}