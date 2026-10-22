#include <iostream>
#include <cstdlib>
#include <ctime>

int wallet = 1100;

class SlotMachine 
{
private:
    int slots[3];

    int randomNumber() 
    {
        return rand() % 7 + 2;
    }
    int calculateReward() 
    {
        int a = slots[0], b = slots[1], c = slots[2];
        if (a == b && b == c) 
        {
            if (a == 7) return 100;
            if (a == 8) return 50;
            return 20;
        }
        else if (a == b || a == c || b == c) 
        {
            return 5;
        }
        return 0;
    }
public:
    void spin() 
    {
        for (int i = 0; i < 3; i++) 
        {
            std::cout << " ___";
        }
        std::cout << "\n";
        for (int i = 0; i < 3; i++) 
        {
            slots[i] = randomNumber();
            std::cout << "|" << " " << slots[i] << " ";
        }
        std::cout << "|";
        std::cout << "\n";
        for (int i = 0; i < 3; i++) 
        {
            std::cout << " ---";
        }
        std::cout << "\n";
    }

    void showResult() {
        int reward = calculateReward();
        if (reward > 0)
        {
            std::cout << "Win: " << reward << std::endl;
            wallet += reward;
        }
        else
        {
            for (int i = 0; i < 6; i++)
            {
                std::cout << " _";
            }
            std::cout << "\n";
            std::cout << "|    Loss   |" << std::endl;
            for (int i = 0; i < 6; i++)
            {
                std::cout << " _";
            }
            std::cout << "\n";
//            std::cout << "Loss" << std::endl;
        }
    }
};

int main() 
{
    srand(time(0));
    SlotMachine machine;
    bool continueAfterDebt = false;
    
    while (true)
    {   
        wallet -= 100;
        
        if (wallet <= 0 && !continueAfterDebt)
        {
            char choice;
            std::cout << "Balance: " << wallet << std::endl;
            std::cout << "Do you want to continue playing? (n/Y): ";
            std::cin >> choice;
            
            if (choice == 'y' || choice == 'Y')
            {
                continueAfterDebt = true;
            }
            else if (choice == 'n' || choice == 'N')
            {
                break;
            }
        }
        
        machine.spin();
        machine.showResult();
        std::cout << wallet << std::endl;

        char continueChoice;
        std::cout << "(n/y): ";
        std::cin >> continueChoice;
        
        if (continueChoice == 'n' || continueChoice == 'N')
        {
            break;
        }
    }
    
    if (continueAfterDebt && wallet <=-1)
    {
        std::cout << "Time to work, did you think it would be that easy?" << std::endl;
        int debt = wallet;
        
        while (true)
        {
            char creditChoice;
            std::cout << "Agree to the credits: " << std::endl;
            std::cout << "(n/y): ";
            std::cin >> creditChoice;
            
            if (creditChoice == 'y' || creditChoice == 'Y')
            {
                debt += 1;
            }
            else
            {
                std::cout << "No, you must repay your debt to the casino" << std::endl;
            }
            
            if (debt >= 100)
            {
                std::cout << "Get out of here" << std::endl;
                break;
            }
        }
    }
    
    std::cout << "Bye";
    return 0;
}
