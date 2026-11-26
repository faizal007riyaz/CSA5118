#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char p[500],k[100];printf("Plaintext: ");fgets(p,sizeof p,stdin);printf("Key: ");scanf("%99s",k);
 int j=0,n=strlen(k);printf("Ciphertext: ");for(int i=0;p[i]&&p[i]!='\n';i++)if(isalpha((unsigned char)p[i])){int x=toupper((unsigned char)p[i])-'A',s=toupper((unsigned char)k[j++%n])-'A';putchar('A'+(x+s)%26);}else putchar(p[i]);puts("");return 0;
}
