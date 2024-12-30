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

};

int main()
{

}