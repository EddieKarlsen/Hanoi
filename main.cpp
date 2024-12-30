#include <iostream>
#include "Stack.h"

class Hanoi {
private:
    Stack pins[3];

public:
    Hanoi(int numDisks) {
        for(int i = numDisks; i> 0; --i){
            pins[0].push(i);
        }
    }
    void moveDisk(int from, int to){
        if(pins[from].isEmpty()){
            std::cout << "ingen ring finns att flytta från denna pinne" << from << std::endl;
            return;
        }
        int diskToMove = pins[from].peek();
        if (!pins[to].isEmpty() && pins[to].peek() <diskToMove){
            std::cout << "får ej placer en större ring på en mindre" << std::endl;
            return;
        }
        void printState(){
            for(int i = 0; i < 3; i++){
                std::cout <<"Pinne" <<i +1 << " :";
            }
            std::cout << std::endl;
        }
        void solve(int numDisks, int from, int to, int helper)
        if (numDisks == 1){
            moveDisk(from, to)
            return;
        }
        solve(numDisks -1,from, helper, to);
        moveDisk(from, to);
        solve(numDisks -1, helper, to ,from);
    }
};

int main() {
    int numDisks
    std::cout << "hur många diskar skall vi spela med? max 20" << std::endl;
    std::cin >> numDisks  >>
    
    Hanoi hanoi(numDisks);
    hanoi.printState();

    hanoi.solve(numDisks, 0, 2, 1);  
    std::cout << "Slutligt tillstånd: " << std::endl;
    hanoi.printState();

    return 0;
}