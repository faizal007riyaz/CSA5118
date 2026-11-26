#include <stdio.h>
#include <ctype.h>
int main(void){
 char s[500]; int k;
 printf("Plaintext: "); if(!fgets(s,sizeof s,stdin)) return 1;
 printf("Key (1-25): "); if(scanf("%d",&k)!=1) return 1; k=(k%26+26)%26;
 printf("Ciphertext: ");
 for(int i=0;s[i];i++){char c=s[i]; if(isupper((unsigned char)c)) putchar('A'+(c-'A'+k)%26); else if(islower((unsigned char)c)) putchar('a'+(c-'a'+k)%26); else putchar(c);}
 return 0;
}
