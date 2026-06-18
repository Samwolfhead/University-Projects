#include <stdio.h>

int main()
{
    // Store the original string entered by the user
    char str[2000];

    // Store the reversed version of the string
    char reverse[2000];

    // Pointer used to traverse the string
    char *p;

    // Counters for statistics
    int length = 0;
    int letterCount = 0;
    int numberCount = 0;
    int spaceCount = 0;

    // Variables used for reversing the string
    int i, j = 0;

    // Ask the user to enter a string
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Check if the user entered an empty line
    if (str[0] == '\n')
    {
        printf("Input is empty.\n");
        return 0;
    }

    // Remove the newline character added by fgets()
    p = str;
    while (*p != '\0')
    {
        if (*p == '\n')
        {
            *p = '\0';
            break;
        }
        p++;
    }

    // Point back to the beginning of the string
    p = str;

    // Calculate length and count letters, numbers, and spaces
    while (*p != '\0')
    {
        // Count total characters
        length++;

        // Check if the character is a letter
        if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
        {
            letterCount++;
        }
        // Check if the character is a digit
        else if (*p >= '0' && *p <= '9')
        {
            numberCount++;
        }
        // Check if the character is a space
        else if (*p == ' ')
        {
            spaceCount++;
        }

        p++;
    }

    // Convert uppercase letters to lowercase
    p = str;

    while (*p != '\0')
    {
        if (*p >= 'A' && *p <= 'Z')
        {
            *p = *p + 32;
        }

        p++;
    }

    // Reverse the string
    for (i = length - 1; i >= 0; i--)
    {
        reverse[j] = str[i];
        j++;
    }

    // Add string terminator at the end
    reverse[j] = '\0';

    // Display results
    printf("\nLength = %d\n", length);
    printf("Letters = %d\n", letterCount);
    printf("Numbers = %d\n", numberCount);
    printf("Spaces = %d\n", spaceCount);

    printf("\nLowercase string:\n%s\n", str);

    printf("\nReversed string:\n%s\n", reverse);

    return 0;
}