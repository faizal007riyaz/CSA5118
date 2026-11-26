#include <stdio.h>
int main(void){
 puts("Hill cipher: C = K * P (mod 26).");
 puts("Given enough known plaintext/ciphertext blocks, form matrices P and C.");
 puts("If P is invertible modulo 26, recover the key: K = C * inverse(P) (mod 26).");
 puts("A chosen-plaintext attacker can choose P as the identity matrix.");
 puts("Then C = K, so the key matrix is revealed directly.");
 puts("Condition: gcd(det(P),26) must equal 1.");return 0;
}
