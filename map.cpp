#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <unistd.h> // For usleep
// #include <windows.h> // Remove windows.h

using namespace std;

class game {
private:
    // Define your class members here
public:
    void inputDebugMessage(string message);
    string showDebugMessage();
    string showPanzongMessage();
    void inputPanzongMessage(string message);

    // Define the rest of your member functions here
};

void game::inputDebugMessage(string message) {
    // Implementation
}

string game::showDebugMessage() {
    // Implementation
}

string game::showPanzongMessage() {
    // Implementation
}

void game::inputPanzongMessage(string message) {
    // Implementation
}

// Define the rest of your member functions here

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // srand((unsigned int)time(NULL)); // srand is already in use in your code

    game gameInstaller;
    while (1) {
        gameInstaller.drawMenu();
        gameInstaller.inputStar();
        gameInstaller.senseInput();
        if (gameInstaller.isStart) {
            break;
        }
        if (gameInstaller.isExit) {
            return 0;
        }
        usleep(20000); // Replace Sleep(20);
        system("clear"); // Replace system("cls");
    }

    // Replace clock_t startTime = clock(); with:
    auto startTime = chrono::high_resolution_clock::now();

    // Replace clock_t curTime = clock(); with:
    auto curTime = chrono::high_resolution_clock::now();

    // Replace clock_t EndTime = clock(); with:
    auto EndTime = chrono::high_resolution_clock::now();

    // Continue updating and adapting your code accordin
