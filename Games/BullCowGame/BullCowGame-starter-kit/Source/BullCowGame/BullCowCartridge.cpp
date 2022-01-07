// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    // Welcome Messages
    PrintLine(TEXT("Hello, welcome to the bulls & cows game"));
    PrintLine(TEXT("Guess the 6 letter word")); // Change from 6 to length of HiddenWord
    PrintLine(TEXT("Press Enter to continue..."));
    
    //Setting up game
    InitGame();
   
    // Prompt for guess
 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen(); 
    
    // check if guess is isogram

    // check guess against HiddenWord 
    if (Input == HiddenWord)
    {
        /* input passes */
        PrintLine(TEXT("You have Won!"));
    
    }
    else
    {
        PrintLine(TEXT("You have Lost!"));

    }

    // check if Guess is Isogram
    // check if right number of characters
    /* Subtract 1 life*/

    //check if Lives > 0
    // if yes GuessAgain 
    //If no Game Over and display HiddenWord?
    //play Again
    

   
}

void UBullCowCartridge::InitGame()
{
     HiddenWord = TEXT("Boxers"); // set HiddenWord

    // set and display number of lives
    Lives = 6;
}