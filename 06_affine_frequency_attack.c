#include <stdio.h>
#include <string.h>
#include <ctype.h>
int gcd(int a,int b){while(b){int t=a%b;a=b;b=t;}return a;}
int inv(int a){for(int x=1;x<26;x++)if((a*x)%26==1)return x;return -1;}
int main(void){
 char c[2000];printf("Ciphertext: ");fgets(c,sizeof c,stdin);
 /* Try the common assumption: most frequent B represents E; second U represents T. */
 int a,b,found=0;
 for(a=1;a<26;a++)if(gcd(a,26)==1){b=(1 /* B */ - a*4%26+26)%26;if((a*20+b)%26==19){found=1;break;}}
 if(!found){puts("No affine key matches B->E and U->T simultaneously.");return 0;}
 printf("Possible key: a=%d b=%d\nPlaintext: ",a,b);int ai=inv(a);
 for(int i=0;c[i]&&c[i]!='\n';i++)if(isalpha((unsigned char)c[i]))putchar('A'+(ai*(toupper((unsigned char)c[i])-'A'-b+26*2))%26);else putchar(c[i]);puts("");return 0;
}
