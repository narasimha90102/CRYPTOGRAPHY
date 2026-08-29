#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

static void add_pkcs7_padding(unsigned char *buffer, size_t len, size_t *padded_len)
{
    size_t pad = 8 - (len % 8);
    if (pad == 0)
        pad = 8;

    for (size_t i = 0; i < pad; i++)
        buffer[len + i] = (unsigned char)pad;

    *padded_len = len + pad;
}

int main(void)
{
    char text[128];
    unsigned char key[24] = {
        '1','2','3','4','5','6','7','8',
        '9','0','1','2','3','4','5','6',
        '7','8','9','0','1','2','3','4'
    };
    unsigned char iv[8] = {'1','2','3','4','5','6','7','8'};
    unsigned char padded[128];
    unsigned char output[128];
    size_t len, padded_len;

    printf("Enter Plain Text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Input error!\n");
        return 1;
    }

    len = strlen(text);

    if (len > 0 && text[len - 1] == '\n')
        text[--len] = '\0';
    if (len > 0 && text[len - 1] == '\r')
        text[--len] = '\0';

    if (len == 0)
    {
        printf("Plain text is empty.\n");
        return 1;
    }

    memcpy(padded, text, len);
    add_pkcs7_padding(padded, len, &padded_len);

    DES_cblock key1, key2, key3;
    DES_key_schedule ks1, ks2, ks3;

    memcpy(key1, key, 8);
    memcpy(key2, key + 8, 8);
    memcpy(key3, key + 16, 8);

    DES_set_key_unchecked(&key1, &ks1);
    DES_set_key_unchecked(&key2, &ks2);
    DES_set_key_unchecked(&key3, &ks3);

    DES_ede3_cbc_encrypt(
        padded,
        output,
        (long)padded_len,
        &ks1,
        &ks2,
        &ks3,
        (DES_cblock *)iv,
        DES_ENCRYPT
    );

    printf("Encrypted Text: ");
    for (size_t i = 0; i < padded_len; i++)
        printf("%02X", output[i]);

    printf("\n");
    return 0;
}