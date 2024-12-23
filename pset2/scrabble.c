#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scorearray[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int p1score = 0;
int p2score = 0;

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");

    // Making it lowercase
    for (int i = 0, len = strlen(player1); i < len; i++)
    {
        if (isalpha(player1[i]))
        {
            player1[i] = tolower(player1[i]);
        }
    }
    for (int i = 0, len = strlen(player2); i < len; i++)
    {
        if (isalpha(player2[i]))
        {
            player2[i] = tolower(player2[i]);
        }
    }

    // Compute the score of each word
    for (int i = 0, len = strlen(player1); i < len; i++)
    {
        if (isalpha(player1[i]))
        {
            int ascii_value = (int) player1[i];
            int index = ascii_value - 97;
            int score = scorearray[index];
            p1score = p1score + score;
        }
    }
    for (int i = 0, len = strlen(player2); i < len; i++)
    {
        if (isalpha(player2[i]))
        {
            int ascii_value = (int) player2[i];
            int index = ascii_value - 97;
            int score = scorearray[index];
            p2score = p2score + score;
        }
    }

    // Print the winner
    if (p1score > p2score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p2score > p1score)
    {
        printf("Player 2 wins!\n");
    }
    else if (p1score == p2score)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("ERROR\n");
    }

    return 0;
}
