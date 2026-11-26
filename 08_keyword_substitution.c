#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char key[100],plain[500];int seen[26]={0},n=0;char alpha[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ",sub[27];
 printf("Keyword: ");scanf("%99s",key);
 for(int i=0;key[i];i++){char c=toupper((unsigned char)key[i]);if(c>='A'&&c<='Z'&&!seen[c-'A']){sub[n++]=c;seen[c-'A']=1;}}
 for(int i=0;i<26;i++)if(!seen[i])sub[n++]='A'+i;sub[26]=0;
 printf("Cipher alphabet: %s\n",sub);getchar();printf("Plaintext: ");fgets(plain,sizeof plain,stdin);printf("Ciphertext: ");
 for(int i=0;plain[i];i++)if(isalpha((unsigned char)plain[i]))putchar(sub[toupper((unsigned char)plain[i])-'A']);else putchar(plain[i]);return 0;
}
