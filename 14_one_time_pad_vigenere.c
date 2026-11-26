#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char p[]="SEND MORE MONEY";int k[]={9,0,1,7,23,15,21,14,11,11,2,8,9};int j=0;
 printf("Plaintext: %s\nCiphertext: ",p);
 for(int i=0;p[i];i++)if(isalpha((unsigned char)p[i]))putchar('A'+((toupper((unsigned char)p[i])-'A'+k[j++])%26));else putchar(p[i]);
 puts("");puts("For any target plaintext, key[i] = (cipher[i] - target[i]) mod 26.");return 0;
}
