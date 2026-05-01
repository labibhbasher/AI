#include <iostream>
using namespace std;

int main() {
    string a, b;

    cout << "=== Prisoner's Dilemma Game ===\n";
    cout << "Choices: silent or confess\n\n";

    // Input from players
    cout << "Player A choice: ";
    cin >> a;

    cout << "Player B choice: ";
    cin >> b;

    int A = 0, B = 0;

    // Game rules
    if (a == "silent" && b == "silent") {
        A = 1; B = 1;
    }
    else if (a == "silent" && b == "confess") {
        A = 5; B = 0;
    }
    else if (a == "confess" && b == "silent") {
        A = 0; B = 5;
    }
    else if (a == "confess" && b == "confess") {
        A = 3; B = 3;
    }
    else {
        cout << "Invalid input! Use only 'silent' or 'confess'.\n";
        return 0;
    }

    // Output result
    cout << "\n--- Result ---\n";
    cout << "Player A gets: " << A << " years in prison\n";
    cout << "Player B gets: " << B << " years in prison\n";

    return 0;
}