#include <bits/stdc++.h>
using namespace std;

void tspGreedy(vector<vector<int>>& costMatrix, int numCities) {
    vector<bool> visitedCity(numCities, false);
    vector<int> path;
    int current_city = 0;
    int totalCost = 0;

    visitedCity[current_city] = true;
    path.push_back(current_city);
    /*
    ---> c0  c1  c2  c3
    c0-> 00  10  15  20
    c1-> 10  00  35  25
    c2-> 15  35  00  30
    c3-> 20  25  30  00
    path-> c0  c1  c3  c2 c0
    10+ 25 + 30 + 15
    */

    //current city -> 0 1
    // path --------> 0 1
    // total cost->   10

    for (int row = 1; row < numCities; ++row) {
        int nearestCity = -1;
        int minCost = INT_MAX;
        for (int city = 0; city < numCities; ++city) {
                // c1-> 10  00  35  25
                // city = 0
            if (!visitedCity[city] && costMatrix[current_city][city] < minCost) {
                minCost = costMatrix[current_city][city];
                nearestCity = city;
            }
        }
        current_city = nearestCity;
        path.push_back(current_city);
        visitedCity[current_city] = true;
        totalCost += minCost;
    }
    path.push_back(0);
    totalCost += costMatrix[current_city][0];

    for (int i = 0; i < numCities + 1; ++i) {
        cout << path[i] << " ";
    }
    cout << endl << totalCost << endl;
}

int main() {
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    vector<vector<int>> costMatrix(numCities, vector<int>(numCities, 0));


    cout << "Enter the cost matrix (each row in a new line, elements separated by spaces):\n";
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            cin >> costMatrix[i][j];
        }
    }
    /*
    ---> c0  c1  c2  c3 -> 4
    c0-> 00  10  15  20
    c1-> 10  00  35  25
    c2-> 15  35  00  30
    c3-> 20  25  30  00

    path-> c0 -> c1 -> c3 -> c2 -> c0
    cost-> 10 + 25 + 30 + 15 = 80

    */

    tspGreedy(costMatrix, numCities);

    return 0;
}
