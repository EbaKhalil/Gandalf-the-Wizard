#include <iostream>
#include <vector>

using namespace std;

struct Treasure {
	int weight;
	int value;

};

int minimumValue(int W, const vector<Treasure>& treasures, int index) {
	if (W < 0 || index == treasures.size())
		return INT_MAX;
	if (W == 0)
		return 0;

	int add = INT_MAX;
	int leaveOut = minimumValue(W, treasures, index + 1);

	if (treasures[index].weight <= W) {
		int res = minimumValue(W - treasures[index].weight, treasures, index);
		if (res != INT_MAX) {
			add = res + treasures[index].value;
		}
	}
	return min(add, leaveOut);
}
int main() {
	int theChestWeight;
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
	int res = minimumValue(theChestWeight, treasures, 0);
	if (res == INT_MAX) {
		cout << "Not possible" << endl;
	}
	else {
		cout << "The minimum value of the chest = " << res << endl;
	}
	return 0;
}