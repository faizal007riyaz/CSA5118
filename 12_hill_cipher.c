#include <stdio.h>
#include <string.h>
#include <ctype.h>
int mod(int x){x%=26;return x<0?x+26:x;}
int inv(int x){for(int i=1;i<26;i++)if(x*i%26==1)return i;return -1;}
int main(void){
 char p[500],a[500];int n=0;int k00=9,k01=4,k10=5,k11=7,det=mod(k00*k11-k01*k10),di=inv(det);
 if(di<0){puts("Key matrix is not invertible modulo 26.");return 1;}
 printf("Plaintext: ");fgets(p,sizeof p,stdin);for(int i=0;p[i];i++)if(isalpha((unsigned char)p[i]))a[n++]=toupper((unsigned char)p[i]);if(n%2)a[n++]='X';
 printf("Ciphertext: ");for(int i=0;i<n;i+=2){int x=a[i]-'A',y=a[i+1]-'A';printf("%c%c",'A'+mod(k00*x+k01*y),'A'+mod(k10*x+k11*y));}
 printf("\nDeterminant mod 26 = %d; inverse determinant = %d\n",det,di);
 printf("Decryption matrix: [%d %d; %d %d]\n",mod(di*k11),mod(-di*k01),mod(-di*k10),mod(di*k00));return 0;
}
