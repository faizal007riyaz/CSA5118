#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int main(void){
 int a,b;char p[500];printf("Enter a and b: ");scanf("%d%d",&a,&b);a=(a%26+26)%26;b=(b%26+26)%26;
 if(gcd(a,26)!=1){puts("Invalid a: gcd(a,26) must be 1.");puts("Allowed a: 1,3,5,7,9,11,15,17,19,21,23,25. Any b from 0 to 25 is allowed.");return 0;}
 getchar();printf("Plaintext: ");fgets(p,sizeof p,stdin);printf("Ciphertext: ");
 for(int i=0;p[i];i++)if(isalpha((unsigned char)p[i]))putchar('A'+(a*(toupper((unsigned char)p[i])-'A')+b)%26);else putchar(p[i]);return 0;
}
