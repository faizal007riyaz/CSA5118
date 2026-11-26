#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char s[2000];double score[26];const double f[26]={8.2,1.5,2.8,4.3,12.7,2.2,2,6.1,7,0.15,0.77,4,2.4,6.7,7.5,1.9,0.095,6,6.3,9.1,2.8,0.98,2.4,0.15,2,0.074};
 printf("Ciphertext: ");fgets(s,sizeof s,stdin);
 for(int k=0;k<26;k++){score[k]=0;for(int i=0;s[i];i++)if(isalpha((unsigned char)s[i]))score[k]+=f[(toupper((unsigned char)s[i])-'A'-k+26)%26];}
 puts("Top 10 candidates:");for(int rank=1;rank<=10;rank++){int b=-1;for(int k=0;k<26;k++)if(score[k]>=0&&(b<0||score[k]>score[b]))b=k;printf("%2d. Shift %2d: ",rank,b);for(int i=0;s[i]&&s[i]!='\n';i++)if(isalpha((unsigned char)s[i]))putchar('A'+(toupper((unsigned char)s[i])-'A'-b+26)%26);else putchar(s[i]);puts("");score[b]=-1;}return 0;
}
