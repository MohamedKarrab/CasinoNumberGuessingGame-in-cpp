#include <iostream>
#include <ctime>
#include <random>
#include <array>

class Player {
private:
    int cash;
public:
    Player() : cash(1000) {}


    void Guess(int k);
    int getCash() { return cash; }
};

void Player::Guess(int k) {
  
    std::cout << "Sir you currently have " << cash << "$ left\n";
    std::cout << "How much would you put in?\n";
    int gamblingMoney;
    do {
        std::cin >> gamblingMoney;
        if (gamblingMoney < 0) {
            std::cout << "What are you doing sir!\n";
        }
        else if (gamblingMoney > cash) std::cout << "You only got " << cash << "$ sir!\n";
    } while (gamblingMoney<0 || gamblingMoney>cash);

    std::cout << "We picked a random number from 1 to 10, try to guess it!\n";
    int guess;
    std::cin >> guess;
    if (guess == k) {
        cash += gamblingMoney * 10;
        std::cout << "Nice you got it! here is your money " << gamblingMoney * 10 << "$, now you have : " << cash << "$\n";
    }
    else {
        cash -= gamblingMoney;

        std::cout << "You guessed wrong and lost " << gamblingMoney << "$, gimme your money hehe, now you only have " << cash << "$\n";
        std::cout << "The actual number is " << k << "\n";
    }
    
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib{ 1,10 };
    
    Player player;
    char choice;
    do {
       system("cls");
        std::cout << "Your goal is to reach 10000$ to win\n";
        player.Guess(distrib(gen));
        if (player.getCash() <= 0) {
            std::cout << "You lost noob!\n"; break;
        }
        else if (player.getCash() >= 10000) {
            std::cout << "\nCongratulations, you reached 10000$ and won the game!\n";
        }
       std:: cout << "\n\n-->Do you want to risk your money and play again (y/n)? \n";
       std:: cin >> choice;
    }while (choice == 'Y' || choice == 'y');
   
    //   std::cout << "k = " << k << '\n';

}