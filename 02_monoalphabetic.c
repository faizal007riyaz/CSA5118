#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char p[500],key[27]; int seen[26]={0};
 printf("Enter 26-letter cipher alphabet: "); if(scanf("%26s",key)!=1)return 1;
 if(strlen(key)!=26){puts("Key must contain 26 letters.");return 1;}
 for(int i=0;i<26;i++){key[i]=(char)toupper((unsigned char)key[i]);if(key[i]<'A'||key[i]>'Z'||seen[key[i]-'A']++){puts("Invalid key: use each letter once.");return 1;}}
 getchar(); printf("Plaintext: ");if(!fgets(p,sizeof p,stdin))return 1;
 printf("Ciphertext: ");for(int i=0;p[i];i++){char c=p[i];if(isalpha((unsigned char)c)){char x=key[toupper((unsigned char)c)-'A'];putchar(islower((unsigned char)c)?tolower(x):x);}else putchar(c);}return 0;
}
