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
        ProcessGuess(Input);
         }
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
    ClearScreen();
    PrintLine(TEXT("\nPress Enter to Play Again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess)
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

bool UBullCowCartridge::IsIsogram(FString Word) const
{
    //Loop through player input 

   for (int32 Index = 0, Comparision = Index + 1; Comparision < Word.Len(); Comparision++)
   {
       // comparing the first character to the following ones
       if (Word[Index] == Word[Comparision])
       {
           return false;
       }
       
       /* code */
   }
   
   return true;
    
    //until Word.len() - 1
    //if Hiddenword[i]!=Hiddenword[i++] return true
    //else false
    return true;
}