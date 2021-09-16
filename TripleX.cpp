#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty; 
    std::cout << " secure server room...\nYou need to enter the correct codes to continue...\n\n"; 
}

bool PlayGame(int Difficulty)
{

    PrintIntroduction(Difficulty);
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;


    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProd = CodeA * CodeB * CodeC;


    // Print sum and product to the terminal
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "\nThe codes add-up to: " << CodeSum; 
    std::cout << "\nThe codes product is: " << CodeProd << std::endl;

    // Store players guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    

    // Check if the players guss is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProd)
    {
        std::cout << "\nYou win! Next Level";
        return true;
    }
    else
    {
        std::cout << "\nYou lose :c Retry.";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 15;

    while (LevelDifficulty <= MaxLevel) // Loop until complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        

    }
    
    std::cout << "You completed the game! Good Luck next time!";

    return 0;
}