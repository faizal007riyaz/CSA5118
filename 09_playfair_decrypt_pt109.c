#include <stdio.h>
#include <string.h>
#include <ctype.h>
void build(char *k,char m[5][5]){int s[26]={0},n=0;char t[200];strcpy(t,k);strcat(t,"ABCDEFGHIKLMNOPQRSTUVWXYZ");for(int i=0;t[i];i++){char c=toupper((unsigned char)t[i]);if(c=='J')c='I';if(c<'A'||c>'Z'||s[c-'A'])continue;s[c-'A']=1;m[n/5][n%5]=c;n++;}}
void find(char m[5][5],char c,int *r,int *x){if(c=='J')c='I';for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(m[i][j]==c){*r=i;*x=j;return;}}
int main(void){char key[100],ct[1000];char m[5][5];printf("Enter Playfair keyword: ");scanf("%99s",key);getchar();printf("Enter ciphertext: ");fgets(ct,sizeof ct,stdin);build(key,m);printf("Plaintext: ");char a=0,b=0;for(int i=0;ct[i];i++)if(isalpha((unsigned char)ct[i])){if(!a)a=toupper((unsigned char)ct[i]);else{b=toupper((unsigned char)ct[i]);int r1,c1,r2,c2;find(m,a,&r1,&c1);find(m,b,&r2,&c2);if(r1==r2){putchar(m[r1][(c1+4)%5]);putchar(m[r2][(c2+4)%5]);}else if(c1==c2){putchar(m[(r1+4)%5][c1]);putchar(m[(r2+4)%5][c2]);}else{putchar(m[r1][c2]);putchar(m[r2][c1]);}a=0;}}}puts("");return 0;}
