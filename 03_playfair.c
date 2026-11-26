#include <stdio.h>
#include <string.h>
#include <ctype.h>
void make(char *key,char m[5][5]){
 int seen[26]={0},n=0; char s[100]; strcpy(s,key);strcat(s,"ABCDEFGHIKLMNOPQRSTUVWXYZ");
 for(int i=0;s[i];i++){char c=toupper((unsigned char)s[i]);if(c=='J')c='I';if(c<'A'||c>'Z'||seen[c-'A'])continue;seen[c-'A']=1;m[n/5][n%5]=c;n++;}
}
void pos(char m[5][5],char c,int *r,int *col){if(c=='J')c='I';for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(m[i][j]==c){*r=i;*col=j;return;}}
int main(void){
 char key[100],p[500],a[300];char m[5][5];int n=0;
 printf("Keyword: ");scanf("%99s",key);getchar();printf("Plaintext: ");fgets(p,sizeof p,stdin);
 for(int i=0;p[i];i++)if(isalpha((unsigned char)p[i])){char c=toupper((unsigned char)p[i]);if(c=='J')c='I';a[n++]=c;}a[n]='\0';
 make(key,m);puts("Key matrix:");for(int i=0;i<5;i++){for(int j=0;j<5;j++)printf("%c ",m[i][j]);puts("");}
 printf("Ciphertext: ");
 for(int i=0;i<n;){char x=a[i++],y=(i<n)?a[i++]:'X';if(x==y){y='X';i--;}int r1,c1,r2,c2;pos(m,x,&r1,&c1);pos(m,y,&r2,&c2);
 if(r1==r2){putchar(m[r1][(c1+1)%5]);putchar(m[r2][(c2+1)%5]);}
 else if(c1==c2){putchar(m[(r1+1)%5][c1]);putchar(m[(r2+1)%5][c2]);}
 else{putchar(m[r1][c2]);putchar(m[r2][c1]);}}
 puts("");return 0;
}
