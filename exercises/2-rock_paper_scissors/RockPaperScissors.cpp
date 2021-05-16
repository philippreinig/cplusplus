#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;


/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(int playerChoice, int computerChoice){
    if (playerChoice == 1 && computerChoice == 3) return true;
    else if (playerChoice == 2 && computerChoice == 1) return true;
    else if (playerChoice == 3 && computerChoice == 2) return true;
    else return false;
    // switch(playerChoice, computerChoice){
    //     case(1,3): return true;
    //     case(2,1): return true;
    //     case(3,2): return true;
    //     default: return false;
    // }
}

int getRandomComputerChoice(){
    return rand() % 3 + 1;
}

string gameChoiceToString(int i){
    if (i < 1 || i > 3){
        cout << "Invalid gameChoice: " << i << endl;
        return "";
    }
    else{
        switch (i){
            case(1): return "Rock";
            case(2): return "Paper";
            case(3): return "Scissors";
            default:
                //unrechable code
                return "";
        }
    }
}


/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play(){
    bool gotValidUserInput = false;
    bool gameHasResult = false;
    int userInput = -1;
    int computerChoice = -1;

    while(!gameHasResult){
        cout << "Please enter your choice: [1] Rock, [2] Paper, [3] Scissors" << endl;
        while (!gotValidUserInput){
            cin >> userInput;
            if (userInput >= 1 && userInput <= 3){
                gotValidUserInput = true;
            }
            else{
                cout << userInput << " is not a valid choice! Please enter a number between 1 and 3!"  << endl;
            }
        }
        computerChoice = getRandomComputerChoice();
        if (userInput == computerChoice){
            cout << "The computer chose " << gameChoiceToString(userInput) << " aswell, play again."  << endl;
        }
        else{
            cout << "The computer chose "  << gameChoiceToString(computerChoice) << endl; 
            gameHasResult = true;
        }
    }    
    // cout << "user beats computer: " << beats(userInput, computerChoice) << endl;
    if (beats(userInput, computerChoice)){
        return true;
    }
    else{
        return false;
    }
}

/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3(){
    cout << "You chose game mode bestOf3" << endl;
    int gamesWonPlayer = 0;
    int gamesWonComputer = 0;
    for(int i = 1; i<=3; i++){
        cout << i << ". round:" <<endl;
        cout << "Current game state: " << gamesWonPlayer << ":" << gamesWonComputer << endl; 
        bool playerWonGame = play();
        if (playerWonGame){
            cout << "Congratualions. You won this round." << endl;
            gamesWonPlayer++;
        }
        else{
            cout << "You lost this round." << endl;
            gamesWonComputer++;
        }
    }
    return gamesWonPlayer>gamesWonComputer;
    // Insert your code here
}

/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5(){
     cout << "You chose game mode bestOf5" << endl;
    int gamesWonPlayer = 0;
    int gamesWonComputer = 0;
    for(int i = 1; i<=5; i++){
        cout << i << ". round:" << endl;
         cout << "Current game state: " << gamesWonPlayer << ":" << gamesWonComputer << endl; 
        bool playerWonGame = play();
        if (playerWonGame){
            cout << "Congratualions. You won this round." << endl;
            gamesWonPlayer++;
        }
        else{
            cout << "You lost this round." << endl;
            gamesWonComputer++;
        }
    }
    return gamesWonPlayer>gamesWonComputer;
    return gamesWonPlayer>gamesWonComputer;
}

/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char* gameModeToString(int mode)
{
    switch(mode){
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}

int main(){
    // Initialize random seed
    srand(time(0));

    int mode = 0;
    while(true)
    {
        cout << "Choose a game mode:" << endl
             << "1: " << gameModeToString(1)  << endl
             << "2: " << gameModeToString(2) << endl
             << "3: " << gameModeToString(3)  << endl
             << "0: exit" << endl;
        cout << "Your choice: ";
        cin >> mode;
        if(mode == 0) return 0;
        if(mode < 1 || mode > 3)
        {
            cout << "Invalid choice" << endl;
            continue;
        }
        break;
    }

    bool won = false;
    switch(mode)
    {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if(won)
    {
        cout << "Congratulations! You win the game!" << endl;
    }
    else
    {
        cout << "Unfortunate! You lose the game." << endl;
    }
    return 0;
}