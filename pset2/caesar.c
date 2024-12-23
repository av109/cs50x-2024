#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototype
bool only_digit(string text);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    // Make sure every character in argv[1] is a digit

    if (argc != 2 || only_digit(argv[1]) == false)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int num = atoi(argv[1]);

    // Prompt user for plaintext
    string ptext = get_string("plaintext: ");

    // For each character in the plaintext:
    // Rotate the character if it's a letter
    for (int i = 0, n = strlen(ptext); i < n; i++)
    {
        // Process each character here
        ptext[i] = rotate(ptext[i], num);
    }
    printf("ciphertext: %s", ptext);
    printf("\n");

    return 0;
}

bool only_digit(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]))
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        return c = (c - 'A' + n) % 26 + 'A';
    }
    else if (islower(c))
    {
        return c = (c - 'a' + n) % 26 + 'a';
    }
    else
    {
        return c;
    }
}
