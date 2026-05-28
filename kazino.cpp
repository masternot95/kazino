#include <iostream>
#include <cstdlib>
#include <ctime>

int Wallet = 1100;

class SlotMachine {
private:
    int slots[3];

    int randomNumber() {
        return rand() % 7 + 2;
    }

    int calculateReward() {
        int a = slots[0], b = slots[1], c = slots[2];

        if (a == b && b == c) {
            if (a == 7) return 100;
            if (a == 8) return 50;
            return 20;
        }
        else if (a == b || a == c || b == c) {
            return 5;
        }
        return 0;
    }
public:
    void spin() {
        for (int i = 0; i < 3; i++) {
            slots[i] = randomNumber();
        }
    }

    void showResult() {
        std::cout << slots[0] << " " << slots[1] << " " << slots[2] << std::endl;
        int reward = calculateReward();
        if (reward > 0)
        {
            std::cout << "Win: " << reward << std::endl;
            Wallet = Wallet + reward;
        }
        else
        {
            std::cout << "Loss" << std::endl;
        }
    }
};

int main() {
    srand(time(0));
    SlotMachine machine;
    bool show = false;
    while (true)
    {   
        Wallet = Wallet - 100;
        if (Wallet <= 0 && !show)
        {
            char memory_leak;
            std::cout << "balance: " << Wallet << std::endl;
            std::cout << "do you want to continue playing? (n/Y): ";
            std::cin >> memory_leak;
            if (memory_leak == 'y' || memory_leak == 'Y')
            {
                show = true;
            } else if(memory_leak == 'n' || memory_leak == 'N')
            {
                break;
            }

        }
        machine.spin();
        machine.showResult();
        std::cout << Wallet << std::endl;

        char memory_leak_v_2;
        std::cout << "(n/y)";
        std::cin >> memory_leak_v_2;
        if (memory_leak_v_2 == 'n' || memory_leak_v_2 == 'N')
        {
            break;
        }

    }
    if (show)
    {
        std::cout << "time to work, did you think it would be that easy?" << std::endl;
        int debt = Wallet;
        while (true)
        {
            char you_debt = 'n';
            std::cout << "agree to the credits: " << std::endl;
            std::cout << "(n/y)";
            std::cin >> you_debt;
            if (you_debt == 'y' || you_debt == 'Y')
            {
                debt += 1;
            }
            else{
                std::cout << "no, you must repay your debt to the casino" << std::endl;
            }
            if (debt >= 100)
            {
                std::cout << "get out of here" << std::endl;
                break;
            }
        }
    }
    std::cout << "bye";
    return 0;
}