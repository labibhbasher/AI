#include <iostream>
#include <climits>
using namespace std;

int n;
int cost[10][10];
bool visited[10];

int bestCost = INT_MAX;
int bestPath[10];
int currentPath[10];

void tsp(int city, int count, int currentCost, int start)
{
    currentPath[count - 1] = city;

    if (count == n)
    {
        if (cost[city][start] > 0)
        {
            int totalCost = currentCost + cost[city][start];

            if (totalCost < bestCost)
            {
                bestCost = totalCost;

                for (int i = 0; i < n; i++)
                    bestPath[i] = currentPath[i];
            }
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && cost[city][i] > 0)
        {
            visited[i] = true;
            tsp(i, count + 1, currentCost + cost[city][i], start);
            visited[i] = false;
        }
    }
}

int main()
{
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    int start = 0;

    visited[start] = true;
    tsp(start, 1, 0, start);

    cout << "\nMinimum Cost = " << bestCost << endl;

    cout << "Best Route: ";
    for (int i = 0; i < n; i++)
        cout << bestPath[i] << " ";

    cout << start << endl; // return to start city

    return 0;
}