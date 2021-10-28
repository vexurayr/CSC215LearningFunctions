// InteractiveSimulationApp showcasing functions, pass & return parameters

#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <chrono>
#include <thread>

using namespace std;

// function prototypes
void introduction();
int changeHealth(string answer);
int changeCash(string answer);
string fightOrFlee(string choice);
void fight1();
void fight2();
void fight3();
void fight4();
void fight5();
void fight6();
void fight7();
void fight8();
void success();
void failure();
int quitOrPlayAgain();

int health = 100;   // global variables, as I don't know how to pass in multiple variables to the same function
int cash = 10;

int main()
{
    srand(static_cast<unsigned int>(time(0)));   // seed for random #
    string answer;
    int loop = 0;
    do
    {
        introduction();
        fight1();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);

        fight2();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight3();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight4();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight5();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight6();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight7();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        fight8();
        cout << "Current Health: " << health << endl;
        cout << "Current Cash: " << cash << endl;
        answer = fightOrFlee("\nWill you fight or flee: ");
        health = changeHealth(answer);
        cash = changeCash(answer);
        if (health <= 0 || cash <= 0)
        {
            goto outcomeFailure;
        }

        success();
        cout << "Remaining Health: " << health << endl;
        cout << "Remaining Cash: " << cash << "\n\n";
        goto playAgain;

    outcomeFailure:
        failure();
        cout << "Remaining Health: ";
        if (health <= 0)
        {
            cout << "0\n\n";
        }
        else
        {
            cout << health << "\n\n";
        }
        cout << "Remaining Cash: ";
        if (cash <= 0)
        {
            cout << "0\n\n";
        }
        else
        {
            cout << cash << "\n\n";
        }

    playAgain:
        loop = quitOrPlayAgain();
    } while (loop != 1);

    return 0;
}

// function declarations
void introduction()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "Welcome challenger, to a world full of battle and hard choices.\n" };
    char str2[] = { "Balance your health and money until you reach the land of peace.\n" };
    char str3[] = { "Accepting fights will lower your health, but you'll take their cash.\n" };
    char str4[] = { "Turning down fights will keep you healthy, but they'll take some of your cash.\n" };
    char str5[] = { "You'll be screwed if you let your health or cash hit zero. Are you ready?\n\n" };

        int a = strlen(str1);   // makes the text appear letter by letter for better readability
        int b = strlen(str2);
        int c = strlen(str3);
        int d = strlen(str4);
        int e = strlen(str5);

        for (int i = 0; i < a; i++) {
            putchar(str1[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < b; i++) {
            putchar(str2[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < c; i++) {
            putchar(str3[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < d; i++) {
            putchar(str4[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < e; i++) {
            putchar(str5[i]);
            this_thread::sleep_for(timespan);
        }
    system("pause");
    printf("\n");
}

inline string fightOrFlee(string choice)
{
    string answer;
    do   // asks the player to make a decision, records their input, and gives the input back for other functions to use
    {
        cout << choice;
        cin >> answer;
        cout << endl;
    } while ((answer != "fight") && (answer != "Fight") && (answer != "flee") && (answer != "Flee"));
    return answer;
}

inline int changeHealth(string answer)
{
    int randomBad = rand() % 9 + 16;   // player can lose 16-24 health
    if ((answer == "Fight") || (answer == "fight"))   // decreases health if you chose to fight, stays the same otherwise
    {
        health = health - randomBad;
    }
    return health;
}
inline int changeCash(string answer)
{
    int randomBad = rand() % 6 + 3;   // player can lose 3-9 cash
    int randomGood = rand() % 1 + 6;   // player can gain 6-7 cash
    if ((answer == "Fight") || (answer == "fight"))   // increases cash if you chose to fight
    {
        cash = cash + randomGood;
    }
    else   // decreases cash if you chose to run away
    {
        cash = cash - randomBad;
    }
    return cash;
}

void fight1()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "You knew that in order to reach the land of peace,\n" };
    char str2[] = { "you'd have to make it through the most dangerous city around.\n" };
    char str3[] = { "With nothing to lose, you press onwards.\n" };
    char str4[] = { "But you only take two steps inside the city's border before someone approaches.\n" };
    char str5[] = { "\"I wouldn't take another two steps forward if I were you!\"\n\n"};

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);
    int e = strlen(str5);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < e; i++) {
        putchar(str5[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight2()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "Out of breath but alive, you keep moving. The man gave you quite the scare,\n" };
    char str2[] = { "but he was behind you now. You are nervous about the rest of your journey.\n" };
    char str3[] = { "How many more guys like him were you going to run into?\n" };
    char str4[] = { "Speak of the devil, here comes another one.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight3()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "You were able to overcome a second obstacle,\n" };
    char str2[] = { "so you find yourself in a better mood.\n" };
    char str3[] = { "The larger buildings in the city still loomed in the distance.\n" };
    char str4[] = { "They feel so far away, especially with another man blocking your path.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight4()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "You love having company, so it's unfortunate everyone you run across\n" };
    char str2[] = { "only wants to fight you. Already forgetting, you say hi to the next man\n" };
    char str3[] = { "on your travels. His fists were raised the moment you opened your mouth.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight5()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "Your feet are sore but the pain is hidden by a feeling of accomplishment.\n" };
    char str2[] = { "You place your hand on the large glass pane of the nearest skyscraper.\n" };
    char str3[] = { "It felt cool, cooler than the temper of the man headed right for you.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight6()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "Maybe he was just the owner upset you were smudging his glass.\n" };
    char str2[] = { "Oh well. You have to keep moving before night sets in.\n" };
    char str3[] = { "People want you even more dead after sundown.\n" };
    char str4[] = { "Just ask that guy over there.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight7()
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "It has been a hard trek but you can feel the end approaching.\n" };
    char str2[] = { "You didn't want to have to fight so many people, \n" };
    char str3[] = { "but you didn't always have a choice.\n" };
    char str4[] = { "Your philosophical session is cut off with a fist to the face.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
}

void fight8()   // last fight of the game
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "Surprised you made it this far, you take a peak at the city behind you.\n" };
    char str2[] = { "Soon all the lights would come on, which would be the signal to start running.\n" };
    char str3[] = { "You look forward again and see one last man blocking the city's western exit.\n" };
    char str4[] = { "Even with the sun in your eyes, you believe you can make it through.\n" };
    char str5[] = { "You are so close to your destination, after all.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);
    int e = strlen(str5);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < e; i++) {
        putchar(str5[i]);
        this_thread::sleep_for(timespan);
    }
}

void success()   // you have beaten the game
{
    chrono::duration<int, milli> timespan(40);
    char str1[] = { "The biggest smile broke out on your face.\n" };
    char str2[] = { "A breeze picked up, and the delicate field of grass bent with it.\n" };
    char str3[] = { "This is what it feels like to be free.\n" };
    char str4[] = { "All that fighting and running left you extremely tired, but you no longer hold any fear.\n" };
    char str5[] = { "Since the sun was now out of sight, you collapsed to the ground for a well deserved rest.\n\n" };

    int a = strlen(str1);
    int b = strlen(str2);
    int c = strlen(str3);
    int d = strlen(str4);
    int e = strlen(str5);

    for (int i = 0; i < a; i++) {
        putchar(str1[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < b; i++) {
        putchar(str2[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < c; i++) {
        putchar(str3[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < d; i++) {
        putchar(str4[i]);
        this_thread::sleep_for(timespan);
    }
    for (int i = 0; i < e; i++) {
        putchar(str5[i]);
        this_thread::sleep_for(timespan);
    }
}

void failure()
{
    chrono::duration<int, milli> timespan(40);
    if (health <= 0)   // ending you recieve if you die from losing all your health
    {
        char str1[] = { "The biggest frown broke out on your face.\n" };
        char str2[] = { "You fought one too many fights.\n" };
        char str3[] = { "The exhaustion was killing you. No, wait, it's these really angry, punchy\n" };
        char str4[] = { "guys that are killing you. Eventually, they knock you out cold.\n" };
        char str5[] = { "Let's just say you stay on the ground for a very very very very very long time.\n\n" };

        int a = strlen(str1);
        int b = strlen(str2);
        int c = strlen(str3);
        int d = strlen(str4);
        int e = strlen(str5);

        for (int i = 0; i < a; i++) {
            putchar(str1[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < b; i++) {
            putchar(str2[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < c; i++) {
            putchar(str3[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < d; i++) {
            putchar(str4[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < e; i++) {
            putchar(str5[i]);
            this_thread::sleep_for(timespan);
        }
    }
    else   // ending you recieve if you die from losing all your cash
    {
        char str1[] = { "The next guy to see you is not happy. Not happy at all.\n" };
        char str2[] = { "You don't have any money he can steal from you!\n" };
        char str3[] = { "Fighting or fleeing is no longer an option, only crying.\n" };
        char str4[] = { "He lets out a few good punches, then invites everyone nearby to come laugh\n" };
        char str5[] = { "at how broke you are. You are so humiliated you die on the spot.\n\n" };

        int a = strlen(str1);
        int b = strlen(str2);
        int c = strlen(str3);
        int d = strlen(str4);
        int e = strlen(str5);

        for (int i = 0; i < a; i++) {
            putchar(str1[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < b; i++) {
            putchar(str2[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < c; i++) {
            putchar(str3[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < d; i++) {
            putchar(str4[i]);
            this_thread::sleep_for(timespan);
        }
        for (int i = 0; i < e; i++) {
            putchar(str5[i]);
            this_thread::sleep_for(timespan);
        }
    }
}

int quitOrPlayAgain()   // well I think this one speaks for itself
{
    char playAgain;
    bool repeat;
    int loop;
    chrono::duration<int, milli> timespan(1000);
    do
    {
        cout << "Would you like to play again? y/n: ";
        cin >> playAgain;
        cout << endl;

        switch (playAgain) {
        case 'y':
        case 'Y':
            cout << "Resetting the game...\n\n";
            health = 100;
            cash = 10;
            repeat = true;
            loop = 0;
            this_thread::sleep_for(timespan);
            break;

        case 'n':
        case 'N':
            cout << "Goodbye! Thanks for playing.\n\n";
            repeat = true;
            loop = 1;
            this_thread::sleep_for(timespan);
            break;

        default:
            cout << "Please respond with y/n.\n\n";
            repeat = false;
        }
    } while (!repeat);
    return loop;
}