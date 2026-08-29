#include <stdio.h>
#include <ctype.h>

int main()
{
    char cipher[200];
    int freq[26] = {0};
    int i, j, max, temp;
    char letters[26];

    printf("Enter Cipher Text: ");
    fgets(cipher, sizeof(cipher), stdin);

    // Count frequency
    for(i = 0; cipher[i] != '\0'; i++)
    {
        if(isalpha(cipher[i]))
        {
            cipher[i] = toupper(cipher[i]);
            freq[cipher[i] - 'A']++;
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

    printf("\nMost frequent letters are likely to represent E, T, A, O.\n");

    return 0;
}