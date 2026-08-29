#include <stdio.h>
#include <ctype.h>

int main()
{
    char cipher[200];
    int freq[26] = {0};
    int i, j, temp;
    char letters[26];

    printf("Enter Cipher Text: ");
    fgets(cipher, sizeof(cipher), stdin);

    // Count letter frequency
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
        {
            char ch = toupper(cipher[i]);
            freq[ch - 'A']++;
        }
    }

    // Store alphabets
    for(i = 0; i < 26; i++)
        letters[i] = 'A' + i;

    // Sort according to frequency
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

    printf("\nLetter Frequency:\n");

    for(i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
            printf("%c = %d\n", letters[i], freq[i]);
    }

    printf("\nMost frequent letters may represent E, T, A or O.\n");

    return 0;
}