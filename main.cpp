#include <iostream>
#include <unistd.h>
#include "map.h"
#include <algorithm>
#include <queue>
#include "chaebo.h"
#include <cstdlib>
#include <ctime>
// #include <conio.h> // Remove conio.h, as it's not available on macOS

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // system("mode con cols=60 lines=20 | title NOT RYTHM : DEMO"); // Remove Windows-specific command
    srand(static_cast<unsigned int>(time(nullptr)));

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

    clock_t startTime = clock();
    queue<pair<int, clock_t>> notes;
    for (int i = 0; i < MAX_CHAEBO_SIZE; i++) {
        notes.push(make_pair(chaebo[i][0], chaebo[i][1] + startTime));
    }

    while (1) {
        gameInstaller.senseInput();
        gameInstaller.checkPressButton();
        gameInstaller.drawMap();
        gameInstaller.downNote();

        if (!notes.empty()) {
            clock_t curTime = clock();
            while (notes.front().second <= curTime) {
                pair<int, clock_t> temp;
                temp = notes.front();
                gameInstaller.curNotes.push(make_pair(temp.first, static_cast<int>(temp.second + 500)));
                notes.pop();
                gameInstaller.inputNote(temp.first, temp.second);
                if (notes.empty()) {
                    break;
                }
            }
        }

        if (!gameInstaller.curNotes.empty()) {
            clock_t curTime = clock();
            while (gameInstaller.curNotes.front().second + 100 < curTime) {
                gameInstaller.curNotes.pop();
                gameInstaller.inputPanzongMessage("BREAK T^T");
                gameInstaller.combo = 0;
                if (gameInstaller.curNotes.empty()) {
                    break;
                }
            }
        }

        if (notes.empty() && gameInstaller.curNotes.empty()) {
            break;
        }

        usleep(20000); // Replace Sleep(20);
        system("clear"); // Replace system("cls");
    }

    system("clear"); // Replace system("cls");

    while (1) {
        gameInstaller.drawResult();
        // TODO: Handle ESC key for breaking the loop
        usleep(100000); // Replace Sleep(100);
        system("clear"); // Replace system("cls");
    }
}
