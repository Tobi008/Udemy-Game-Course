// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    GetValidWords(Words);
    //Setting up game
    SetupGame();
    PrintLine(TEXT("The HiddenWord is: %s."), *HiddenWord);// Debug Line
}

void UBullCowCartridge::OnInput(const FString& PlayerInput) // When the player hits enter
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
        ProcessGuess(PlayerInput);
         }
}

void UBullCowCartridge::SetupGame()
{

     // Welcome Messages
    PrintLine(TEXT("Hello, welcome to the bulls & cows game"));
    
     HiddenWord = GetValidWords(Words)[0]; // set HiddenWord
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
    ClearScreen();
    PrintLine(TEXT("\nPress Enter to Play Again..."));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    
    // check if right number of characters
    if(Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("Sorry, try guessing again! \nYou have %i lives remaining "), Lives);
        PrintLine(TEXT("The hidden word is %i characters long"),HiddenWord.Len());
        return; 
    }

    // check guess against HiddenWord 
    if (Guess == HiddenWord)
    {
        /* input passes */
        ClearScreen();
        PrintLine(TEXT("You have Won!"));
        EndGame();
        return;
    }

    // check if Guess is Isogram 
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("Guess is not an Isogram"));
    }  

    
    /* Subtract 1 life*/
    --Lives;
    PrintLine(TEXT("You have Lost a life!!"));
    
    //check if Lives > 0
    if(Lives <= 0)
    {
        PrintLine(TEXT("You have ran out of lives"));
        PrintLine(TEXT("The Hidden word was %s"), HiddenWord);
        EndGame();
        return;
    }
    
    //Show the player  the Bulls and Cows
    // if yes GuessAgain 
    //If no Game Over and display HiddenWord?
    //play Again
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    //Loop through player input 

   for (int32 Index = 0; Index < Word.Len(); Index++)
   {
       for (int32 Comparison = Index + 1; Comparison < Word.Len(); Comparison++)
       {
            // comparing the first character to the following ones
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
       }
       
       /* code */
   }
   
   return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for(FString IsoWord: WordList){
        if(IsoWord[Index].Len() >= 4 && IsoWord[Index].Len() <= 8)
        {
            if(IsIsogram(IsoWord[Index]))
            {
                ValidWords.Emplace(IsoWord[Index]);
            }
        }        
    }
    return ValidWords;
}