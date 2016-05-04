#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
    enum fields {
        WORD, HINT, NUM_FIELDS
    };
    const int NUM_WORDS = 5;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
            {
                    {"pepe",  "green top meme"},
                    {"zrada", "the first hikka's program on ASM"},
                    {"flint", "The capitan..."},
                    {"revo",  "banku **** ciomu patriotu"},
                    {"paris", "where has mason been to ?"},
            };
    int score = 0;
    srand(static_cast<unsigned int>(time(0)));
    cout << "\t\tWelcome to TOP GAME\n\n";
    cout << "Guess the secret word" << endl;
    cout << "If you are stuck, you can ask a hint. Just write hint.\n";
    cout << "A Hint costs -2 points.\n";
    cout << "If you are bored enough. Just write quit.\n\n";

    z:
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];
    string theHint = WORDS[choice][HINT];
    char a = 'n';
    int fe = 0;

    string jumble = theWord;
    int len = jumble.size();
    for (int i = 0; i < len; i++) {
        int index1 = (rand() % len);
        int index2 = (rand() % len);
        char tmp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = tmp;
    }
    cout << "Guess the secret word form this mess: " << jumble << endl;;
    cout << "Your score is: " << score << endl;
    string guess;
    cout << "\n\nEnter your guess: ";
    cin >> guess;


    while ((guess != theWord) && (guess != "quit")) {
        if (guess == "hint") {
            cout << theHint;
            fe += 2;
            score -= fe;
            cout << "\nYour score is: " << score << endl;
        } else {
            cout << "Sorry dude, that's not it.";
            cout << "\nYour score is: " << score << endl;
        }
        cout << "\n\nYour guess: ";
        cin >> guess;
    }
    if (guess == theWord) {
        score = score + guess.size();
        cout << "gratz, that's it! Your score is: " << score << endl;;
    }

    while (true) {
        cout << "\nPlay again? y / n : ";
        cin >> a;
        if (a == 'n') {
            break;
        } else if (a == 'y') {
            goto z;
        } else{
            cout << "\nWrong answer";
            continue;
        }
    }
    return 0;
}
