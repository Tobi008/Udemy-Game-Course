// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    //Setting up game
    SetupGame();

    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);// Debug Line
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
/* 
    if game is over then do ClearScreen() and SetupGame() the game
    
    else check if player guess is isogram
 */
    if(bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else 
    {
        ProcessGuess();
        // check guess against HiddenWord 
        if (Input == HiddenWord)
        {
            /* input passes */
            PrintLine(TEXT("You have Won!"));
            EndGame();
        }
        else
        {
            --Lives;
            PrintLine(TEXT("You have Lost a life!!"));
            if(Lives > 0)
            {
                if(Input.Len() != HiddenWord.Len())
                {
                    PrintLine(TEXT("Sorry, try guessing again! \nYiu have %i lives remaining "), Lives); 
                }
            }else
            {
                PrintLine(TEXT("You have ran out of lives"));
                EndGame();
            }
    }
    }

    // check if Guess is Isogram
    // check if right number of characters
    /* Subtract 1 life*/

    //check if Lives > 0
    // if yes GuessAgain 
    //If no Game Over and display HiddenWord?
    //play Again
    

   
}

void UBullCowCartridge::SetupGame()
{

     // Welcome Messages
    PrintLine(TEXT("Hello, welcome to the bulls & cows game"));
    
     HiddenWord = TEXT("Boxers"); // set HiddenWord
    // set and display number of lives
    Lives = HiddenWord.Len();
    bGameOver = true;

    PrintLine(TEXT("Guess the %i letter word"), HiddenWord.Len()); // Change from 6 to length of HiddenWord
    PrintLine(TEXT("You have %i Lives"), Lives);
    PrintLine(TEXT("Type in your Guess and \nPress Enter to continue..."));// Prompt for guess
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;

    PrintLine(TEXT("Press Enter to Play Again..."));
}

void UBullCowCartridge::ProcessGame()
{

}