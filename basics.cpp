#include <iostream>
#include <random>
#include <cassert>

int takeInt() 
{
    std::cout << "Please enter a number between 1 and 100.";
    int number{ 0 };
    std::cin >> number;
    return number;
}


void checkIfItIsHighOrLow(int pickedNumber, int generatedRandomNumber)
{
    if (pickedNumber == generatedRandomNumber)
    {
        std::cout << "You won!" << std::endl;
        return;
    }
    else if (pickedNumber > generatedRandomNumber)
    {
        std::cout << "You need to enter lower number" << std::endl;
    }
    else if (pickedNumber < generatedRandomNumber)
    {
        std::cout << "You need to enter higher number" << std::endl;
    }
    else
    {
        std::cout << "Something went wrong" << std::endl;
    }
}


int main()
{
    std::random_device rd;
    std::seed_seq ss{ rd(),rd(),rd(),rd(),rd(),rd(),rd(),rd() };
    std::mt19937 mt{ ss };
    std::uniform_int_distribution oneRandNum{ 1, 100 };
    int generatedRandomNumber = oneRandNum(mt);
    std::cout << generatedRandomNumber;
    char wantToPlay = 'y';

    while (wantToPlay == 'y')
    {
        int pickedNumber = takeInt();
        checkIfItIsHighOrLow(pickedNumber, generatedRandomNumber);
        std::cout << "Do you want to guess again? y/n" << std::endl;
        std::cin >> wantToPlay;
    }
    

    return 0;
}