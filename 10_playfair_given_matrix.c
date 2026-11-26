#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char m[5][5]={{'M','F','H','I','K'},{'U','N','O','P','Q'},{'Z','V','W','X','Y'},{'E','L','A','R','G'},{'D','S','T','B','C'}};
 char p[500],a[500];int n=0;printf("Plaintext: ");fgets(p,sizeof p,stdin);
 for(int i=0;p[i];i++)if(isalpha((unsigned char)p[i])){char c=toupper((unsigned char)p[i]);if(c=='J')c='I';a[n++]=c;}if(n%2)a[n++]='X';
 printf("Ciphertext: ");for(int i=0;i<n;i+=2){int r1=-1,c1=-1,r2=-1,c2=-1;for(int r=0;r<5;r++)for(int c=0;c<5;c++){if(m[r][c]==a[i])r1=r,c1=c;if(m[r][c]==a[i+1])r2=r,c2=c;}
 if(r1==r2)printf("%c%c",m[r1][(c1+1)%5],m[r2][(c2+1)%5]);else if(c1==c2)printf("%c%c",m[(r1+1)%5][c1],m[(r2+1)%5][c2]);else printf("%c%c",m[r1][c2],m[r2][c1]);}puts("");return 0;
}
