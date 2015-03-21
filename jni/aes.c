#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <time.h>
#include "rijndael-api-fst.h"
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>
#include <sys/time.h>

#define AES_KEY_LEN_128 128
#define AES_KEY_LEN_192 192
#define AES_KEY_LEN_256 256
#define ENCRYPT DIR_ENCRYPT
#define DECRYPT DIR_DECRYPT
#define BLOCK_SIZE 16


int main(int argc, char *argv[])
{
    int r;
    int numBlocks;
    BYTE block[BLOCK_SIZE];
    BYTE output[BLOCK_SIZE];
    char keyMaterial[320];
    keyInstance keyInst;
    cipherInstance cipherInst;
    BYTE* keyCandidat;
    BYTE* plaintextCandidat;

    keyCandidat = calloc(BLOCK_SIZE, sizeof(BYTE));
    plaintextCandidat = calloc(BLOCK_SIZE, sizeof(BYTE));

    memset(keyMaterial, 0, sizeof(keyMaterial));
    memcpy(keyMaterial, keyCandidat, 16);

    r = makeKey(&keyInst, ENCRYPT, AES_KEY_LEN_128, keyMaterial);
    if(r != TRUE)
    {
        printf("[+] makeKey error %d\n", r);
        return;
    }

    r = cipherInit(&cipherInst, MODE_ECB, NULL);
    if(r != TRUE)
    {
        printf("[+] cipherInit error %d\n", r);
        return;
    }


    numBlocks = AES_KEY_LEN_128/128;
    int i,j;

    //MODE ECB
    for(j = 0; j < 100000; j++)
    {
        for (i = numBlocks; i > 0; i--) {
            rijndaelEncrypt((&keyInst)->rk, (&keyInst)->Nr, plaintextCandidat, output);
            *(plaintextCandidat) += 16;
            *(output) += 16;
        }
    }

    return 0;
}
