#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Gets the name from the user
    string name = get_string("What's your name?\n");

    // Prints out the salutation plus te name
    printf("hello, %s\n", name);
}
