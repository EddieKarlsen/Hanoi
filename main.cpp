#include <iostream>
#include "Stack.h" 

class Hanoi {
private:
    Stack pins[3];

public:
    // Konstruktor som initierar Hanoi-spelet
    Hanoi(int numDisks) {
        for (int i = numDisks; i > 0; --i) {
            pins[0].push(i);
        }
    }

    void moveDisk(int from, int to) {
        if (pins[from].isEmpty()) {
            std::cout << "Ingen ring finns att flytta från denna pinne " << from << std::endl;
            return;
        }
        int diskToMove = pins[from].peek();
        if (!pins[to].isEmpty() && pins[to].peek() < diskToMove) {
            std::cout << "Får ej placera en större ring på en mindre." << std::endl;
            return;
        }
        pins[from].pop();
        pins[to].push(diskToMove);
        std::cout << "Flyttade disk " << diskToMove << " från pinne " << from << " till pinne " << to << std::endl;
    }

    void printState() {
        for (int i = 0; i < 3; i++) {
            std::cout << "Pinne " << i + 1 << ": ";
            pins[i].print();
        }
        std::cout << std::endl;
    }

    // Löser Hanoi-spelet rekursivt
    void solve(int numDisks, int from, int to, int helper) {
        if (numDisks == 1) {
            moveDisk(from, to);
            return;
        }
        solve(numDisks - 1, from, helper, to);
        moveDisk(from, to);
        solve(numDisks - 1, helper, to, from);
    }
};

int main() {
    int numDisks;
    int option;
    int from;
    int to;
    Hanoi* hanoi = nullptr; 

    while(true)
    {   
        std::cout << "välkommen till detta Hanoi spel" << std::endl;  

        
        std::cout << "alternativ 1 starta spel" << std::endl;  
        std::cout << "alternativ 2 flytta disk" << std::endl;  
        std::cout << "alternativ 3 lös spelet" << std::endl; 
        std::cout << "alternativ 4 nytt spel" << std::endl;
        std::cout << "alternativ 5 avsluta spelet" << std::endl;
        std::cin >> option;
        switch (option)
        {
        case 1:
            std::cout << "Hur många diskar ska vi spela med? Max 20." << std::endl;
            std::cin >> numDisks;
            if (numDisks <= 0 || numDisks > 20) 
            {
                std::cout << "Ogiltigt antal diskar. Vänligen ange ett antal mellan 1 och 20." << std::endl;
                return 1;
            }
            hanoi = new Hanoi(numDisks);
            break;
        case 2:
            hanoi->printState();
            std::cout << "från vilken pinne skall vi flytta?" << std::endl;
            std::cin >> from;
            std::cout <<"till vilken pinne skall vi flytta ringen?" <<std::endl;
            std::cin >> to;
            hanoi->moveDisk(from, to);
            break;
        case 3:
            hanoi->solve(numDisks, 0, 2, 1);
            std::cout << "Slutligt tillstånd: " << std::endl;
            hanoi->printState();
            break;
        case 4:
            delete hanoi;
            hanoi = nullptr;
            break;
            break;
        case 5:
            delete hanoi;
            return 0;
        
        default:
            std::cout << "Ogiltligt alternativ" << std::endl;  
            break;
        }
    }
}
