#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void){
 char c[3000],map[26];int cnt[26]={0},used[26]={0};
 printf("Enter cryptogram: ");fgets(c,sizeof c,stdin);
 for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i]))cnt[toupper((unsigned char)c[i])-'A']++;
 /* Basic frequency mapping to ETAOIN...; this is a starting guess, not guaranteed plaintext. */
 const char *eng="ETAOINSHRDLCUMWFGYPBVKJXQZ";
 for(int r=0;r<26;r++){int b=-1;for(int j=0;j<26;j++)if(!used[j]&&(b<0||cnt[j]>cnt[b]))b=j;map[b]=eng[r];used[b]=1;}
 printf("Frequency-based candidate: ");for(int i=0;c[i];i++)if(isalpha((unsigned char)c[i])){char x=map[toupper((unsigned char)c[i])-'A'];putchar(islower((unsigned char)c[i])?tolower(x):x);}else putchar(c[i]);return 0;
}
