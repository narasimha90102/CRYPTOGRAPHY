#include <stdio.h>
#include <ctype.h>

int main()
{
    char text[200];
    int freq[26] = {0};
    int i, j, temp;
    char letters[26];

    printf("Enter Cipher Text: ");
    fgets(text, sizeof(text), stdin);

    // Count frequency
    for(i = 0; text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            char ch = toupper(text[i]);
            freq[ch - 'A']++;
        }
    }

    // Store alphabets
    for(i = 0; i < 26; i++)
        letters[i] = 'A' + i;

    // Sort letters by frequency
    for(i = 0; i < 25; i++)
    {
        for(j = i + 1; j < 26; j++)
        {
            if(freq[i] < freq[j])
            {
                temp = freq[i];
                freq[i] = freq[j];
                freq[j] = temp;

                char t = letters[i];
                letters[i] = letters[j];
                letters[j] = t;
            }
        }
    }

    printf("\nFrequency Order:\n");

    for(i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
            printf("%c = %d\n", letters[i], freq[i]);
    }

    printf("\nMost frequent letters are likely to represent E, T, A or O.\n");

    return 0;
}