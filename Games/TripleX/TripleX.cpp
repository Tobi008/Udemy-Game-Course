#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
    //Intro Art 
    std::cout << "\n ______   ______     __     ______   __         ______     __  __    " << std::endl;
    std::cout << "/\\__  _\\ /\\  == \\   /\\ \\   /\\  == \\ /\\ \\       /\\  ___\\   /\\_\\_\\_\\  " << std::endl;
    std::cout << "\\/_/\\ \\/ \\ \\  __<   \\ \\ \\  \\ \\  _-/ \\ \\ \\____  \\ \\  __\\   \\/_/\\_\\/_  " << std::endl;
    std::cout << "   \\ \\_\\  \\ \\_\\ \\_\\  \\ \\_\\  \\ \\_\\    \\ \\_____\\  \\ \\_____\\   /\\_\\/\\_\\ " << std::endl;
    std::cout << "    \\/_/   \\/_/ /_/   \\/_/   \\/_/     \\/_____/   \\/_____/   \\/_/\\/_/ \n" << std::endl;

    //Print Welcome statement 
    std::cout << "\n\nYou are in the process of robbing the biggest bank in the world!...\n";
    std::cout << "You have to break into the level " << Difficulty << " vault where the Gold is stashed and need the correct codes to continue... \n";
}

void LossArt()
{
     std::cout << "          _ ._  _ , _ ._\n";
    std::cout << "        (_ ' ( `  )_  .__)\n";
    std::cout << "      ( (  (    )   `)  ) _)\n";
    std::cout << "     (__ (_   (_ . _) _) ,__)\n";
    std::cout << "         `~~`\\ ' . /`~~`\n";
    std::cout << "              ;   ;\n";
    std::cout << "              /   \\ \n";
    std::cout << "_____________/_ __ \\_____________\n";
}
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    // Declare codes
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print CodeSum and CodeProduct of codes to the terminal
    std::cout << "\n+ There are 3 number in the code\n";
    std::cout << "+ The codes add up to: " << CodeSum << "\n";
    std::cout << "+ The codes multipy to give: "<< CodeProduct << "\n";

    // Store player Guesses
    int GuessA, GuessB, GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if players Guess is correct
    if(GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n\n------------------------------------\n";
        std::cout << "          Congratulations!!!        \n";
        std::cout << " You've broken through a layer of the vault! Keep going! \n";
        std::cout << "------------------------------------\n";
        return true;
    } 
    else 
    {
        LossArt();
        std::cout << "\n\n------------------------------------\n";
        std::cout << "          ERROR!!        \n";
        std::cout << " Careful! You entered the wrong code! Try again \n";
        std::cout << "------------------------------------\n";
        
        return false;
    }
 
}
int main()
{
    srand(time(NULL)); // creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while(LevelDifficulty <= MaxDifficulty)// Loops game until all levels are completed 
    {

        bool bLevelComplete =  PlayGame(LevelDifficulty);
         std::cin.clear(); // clear any error 
         std::cin.ignore(); // Discards buffer

         if(bLevelComplete)
         {
            // increase difficulty 
            LevelDifficulty++;

         }
    }

    std::cout << "\n+ Congratulations!! You've hacked the vault!! You're Rich!";

       return 0;
}