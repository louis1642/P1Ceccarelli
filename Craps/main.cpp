#include <iostream>
#include <cstdlib> //srand and rand
#include <ctime>

using std::cout;
using std::endl;

unsigned int rollDice(); // rolls dice, calculates and displays sum

int main() {
    enum class Status {CONTINUE,WON, LOST};

    //randomize random number generator using current time
    srand(static_cast<unsigned int>(time(0)));

    unsigned int myPoint{0};    //point if no win or loss on first roll
    Status gameStatus;
    unsigned int sumOfDice{rollDice()};     //first roll of dice

    //game status and point (if needed ) based on first roll
    switch (sumOfDice) {
        case 7: // win
        case 11: //win
            gameStatus = Status::WON;
            break;
        case 12:    //lost
            gameStatus = Status::LOST;
            break;
        default:
            gameStatus = Status::CONTINUE;
            myPoint = sumOfDice;
            cout<< "Point is "<< myPoint<<endl;
            break;
    }

    while (Status::CONTINUE == gameStatus){
        sumOfDice = rollDice();

        if(sumOfDice == myPoint){
            gameStatus = Status::WON;
        }else{
            if(sumOfDice == 7){
                gameStatus = Status::LOST;
            }
        }
    }

    if (Status::WON == gameStatus){
        cout << "Player wins" << endl;
    }else{
        cout << "Player loses" << endl;
    }

    return 0;
}

unsigned int rollDice(){
    int die1 {1 + rand() % 6};
    int die2 {1 + rand() % 6};
    int sum {die1 + die2};

    cout <<"Player rolled " << die1 << " + " << die2 << " = " << sum << endl;

    return sum;
}
