#include <iostream>
using namespace std;

int main() {
    string a, b;

    cout << "=== Stag Hunt Game ===\n";
    cout << "Choices: stag or rabbit\n\n";

    
    cout << "Player A choice: ";
    cin >> a;

    cout << "Player B choice: ";
    cin >> b;

    int A = 0, B = 0;



    if (a == "stag" && b == "stag") {
        A = 4; B = 4;   // best cooperation
    }
    else if (a == "stag" && b == "rabbit") {
        A = 0; B = 3;   // A fails, B safe
    }
    else if (a == "rabbit" && b == "stag") {
        A = 3; B = 0;   // B fails, A safe
    }
    else if (a == "rabbit" && b == "rabbit") {
        A = 3; B = 3;   // safe but low reward
    }
    else {
        cout << "Invalid input! Use only 'stag' or 'rabbit'.\n";
        return 0;
    }

    // Output result
    cout << "\n--- Result ---\n";
    cout << "Player A gets: " << A << " points\n";
    cout << "Player B gets: " << B << " points\n";

    return 0;
}