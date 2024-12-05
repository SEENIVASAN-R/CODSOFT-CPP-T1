#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to generate a random number between 1 and 200
int generateRandomNumber() {
    return rand() % 200 + 1;  // Generates a number between 1 and 200
}

// Function to display the game instructions
void displayInstructions() {
    cout << "-------------------------------------------------" << endl;
    cout << "Welcome to the 'Guess the Number' Game!" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "I have generated a random number between 1 and 200." << endl;
    cout << "Your task is to guess the number in as few attempts as possible." << endl;
    cout << "After each guess, I will tell you if your guess is too high or too low." << endl;
    cout << "Additionally, I will give you more precise feedback if you're close!" << endl;
    cout << "Good luck and have fun!" << endl;
    cout << "-------------------------------------------------" << endl;
}

// Function to handle user input and ensure it's a valid integer
int getUserGuess() {
    int guess;
    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        // Check if the input is a valid integer
        if (cin.fail()) {
            // Clear the error flag and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer between 1 and 200." << endl;
        } else if (guess < 1 || guess > 200) {
            cout << "Please enter a number between 1 and 200." << endl;
        } else {
            return guess;
        }
    }
}

// Function to provide feedback based on the difference between guess and the random number
void provideFeedback(int userGuess, int randomNumber) {
    int difference = abs(userGuess - randomNumber);  // Calculate the absolute difference

    if (userGuess < randomNumber) {
        if (difference <= 20) {
            cout << "Low! But you're very close!" << endl;
        } else {
            cout << "Too low! Try again." << endl;
        }
    } else if (userGuess > randomNumber) {
        if (difference <= 20) {
            cout << "High! But you're very close!" << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }
}

// Function to play the game
void playGame() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number
    int randomNumber = generateRandomNumber();
    int userGuess = 0;
    int attempts = 0;

    while (userGuess != randomNumber) {
        userGuess = getUserGuess();
        attempts++;

        // Provide feedback based on the user's guess
        provideFeedback(userGuess, randomNumber);
    }

    cout << "Congratulations! You guessed the correct number (" << randomNumber << ") in " << attempts << " attempts." << endl;
}

// Main function
int main() {
    // Display instructions to the user
    displayInstructions();

    // Play the game
    playGame();

    // Ask the user if they want to play again
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;

    if (playAgain == 'y' || playAgain == 'Y') {
        main();  // Restart the game
    } else {
        cout << "Thank you for playing! Goodbye!" << endl;
    }

    return 0;
}
