#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/*******************************************************************************
 * Function prototype
*******************************************************************************/
void towerHanoi(int, string, string, string, int&);

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls a function to recursively determine
 * solutions for the first 5 instances of the Tower of Hanoi problem.
 * 
 * Input:
 * N/A
 *
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    // solve the first 5 cases of the Tower of Hanoi problem
    for (int i = 1, numMoves = 0; i <= 5; i++, numMoves = 0) {
        cout << setfill('-') << setw(40) << "" << endl;
        cout << "Trying n = " << i << endl << endl;
        towerHanoi(i, "Source Rod", "Temp Rod", "Destination Rod", numMoves);
        cout << endl << "Number of Moves = " << numMoves << endl;
    }

    // terminate
    return 0;
}

void towerHanoi(int n, string sourceRod, string tempRod, string destRod, int& moves){

    //base case
    if (n == 0) return;

    towerHanoi(n - 1, "Source Rod", "Temp Rod", "Destination Rod", moves);

    cout << "Moving disc " << n << " from " << sourceRod << " to " << destRod << endl;
    ++moves;

    towerHanoi(n - 1, "Temp Rod", "Destination Rod", "Source Rod", moves);
}