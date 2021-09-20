/*
.
.Sharmishtha Nath
.
*/

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX_TRIES = 5;
int letterFill(char, string, string &);

int main()
{
    string name;
    char letter;

    string country[] =
        {
            "india",
            "italy",
            "nepal",
            "rome",
            "alaska",
            "france",
            "egypt",
            "canada",
            "spain",
            "korea"};

    string color[] =
        {
            "violet",
            "green",
            "blue",
            "aqua",
            "beige",
            "lime",
            "teal",
            "purple",
            "pink",
            "olive"};

    string flower[] =
        {
            "tulip",
            "rose",
            "daisy",
            "lily",
            "lotus",
            "dahlia",
            "poppy",
            "peony",
            "blossom",
            "violet"};

    cout << "\n\n--------Welcome to Hangman--------\n\n";

start:
    int MAX_TRIES = 5;
    int num_of_wrong_guesses = 0;

    cout << "\n \nWhat do you want to guess? \n 1.Country \n 2.Colour \n 3.Flower \n";
    cout << "\n Your choice : ";
    int ch;
    cin >> ch;
    srand(time(NULL));
    int n = rand() % 10;
    string word;

    switch (ch)
    {
    case 1:
    {
        word = country[n];
        break;
    }
    case 2:
    {
        word = color[n];
        break;
    }
    case 3:
    {
        word = flower[n];
        break;
    }
    default:
        cout << ("\n Enter correct choice \n");
        goto start;
    }

    //word=words[n];

    string unknown(word.length(), '*');

    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word Or you'll be HANGED.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    while (num_of_wrong_guesses < MAX_TRIES)
    {
        cout << "\n\n"
             << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        if (letterFill(letter, word, unknown) == 0)
        {
            cout << endl
                 << "ooops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
        }
        else
        {
            cout << endl
                 << "You found a letter! " << endl;
        }

        cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
        cout << " guesses left." << endl;

        if (word == unknown)
        {
            cout << "\n-------" << word << "-------\n"
                 << endl;
            cout << "You guessed the word! " << endl;

            cout << "  ______" << endl;
            cout << "  |    |" << endl;
            cout << "  |    |" << endl;
            cout << "       |" << endl;
            cout << "       |" << endl;
            cout << " \\O/   |" << endl;
            cout << "  |    |" << endl;
            cout << " / \\   |" << endl;
            cout << "   --------" << endl;

            break;
        }
    }
    if (num_of_wrong_guesses == MAX_TRIES)
    {
        cout << "\n Sorry, you lost...you've been..." << endl;
        cout << "  ______" << endl;
        cout << "  |    |H" << endl;
        cout << "  |    |A" << endl;
        cout << "  O    |N" << endl;
        cout << " /|\\   |G" << endl;
        cout << " / \\   |E" << endl;
        cout << "       |D" << endl;
        cout << "       |!" << endl;
        cout << "   --------" << endl;

        cout << "The word was : " << word << endl;
        cout << "\n Better luck next time! \n"
             << endl;
    }

    cout << "\n Do you want to play again? y/n" << endl;
    char ans;
    cout << "\n Your choice : ";
    cin >> ans;
    if (ans == 'y' || ans == 'Y')
    {
        goto start;
    }
    else
    {
        cout << "\n Hope you enjoyed that!";
    }
    cin.get();
    return 0;
}

int letterFill(char guess, string secretword, string &guessword)
{
    int i;
    int matches = 0;
    int len = secretword.length();
    for (i = 0; i < len; i++)
    {

        if (guess == guessword[i])
            return 0;

        if (guess == secretword[i])
        {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}