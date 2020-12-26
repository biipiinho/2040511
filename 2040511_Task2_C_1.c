#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#include <unistd.h>
#include <math.h>
#include <time.h>


//compile with: cc 2040511_Task2_C_1.c -o 2040511_Task2_C_1 -lcrypt

int count=0;     // A counter used to track the number of combinations explored so far



void substr(char *dest, char *src, int start, int length){
  memcpy(dest, src + start, length);
  *(dest + length) = '\0';
}


void crack(char *salt_and_encrypted){
  int x, y, z;     // Loop counters
  char salt[7];    // String used in hashing the password. Need space for \0
  char plain[7];   // The combination of letters currently being checked //
  char *enc;       // Pointer to the encrypted password

  substr(salt, salt_and_encrypted, 0, 6);

  for(x='A'; x<='Z'; x++){
    for(y='A'; y<='Z'; y++){
      for(z=0; z<=99; z++){
        sprintf(plain, "%c%c%02d", x, y, z);
        enc = (char *) crypt(plain, salt);
        count++;
        if(strcmp(salt_and_encrypted, enc) == 0){
	    printf("#%-8d%s %s\n", count, plain, enc);
		//return;	/
        }
      }
    }
  }
}
int time_difference(struct timespec *start, struct timespec *finish,
                    long long int *difference) {
  long long int ds =  finish->tv_sec - start->tv_sec;
  long long int dn =  finish->tv_nsec - start->tv_nsec;

  if(dn < 0 ) {
    ds--;
    dn += 1000000000;
  }
  *difference = ds * 1000000000 + dn;
  return !(*difference > 0);
}

int main(int argc, char *argv[]){
 struct timespec start, finish;

  long long int time_elapsed;


  clock_gettime(CLOCK_MONOTONIC, &start);

  crack("$6$AS$VxMeY9u3VrfXqfXqwpO.NdYZ1Xza0gYXzjPJ8FgEHRfsaS4AkR3nQjshacBiHLWf4r6UUgj89aIN8q1g/FsWx.");

  clock_gettime(CLOCK_MONOTONIC, &finish);
  time_difference(&start, &finish, &time_elapsed);
  printf("%d solutions explored\n Time elapsed was %lldns or %0.9lfs\n", count, time_elapsed,  (time_elapsed/1.0e9));



  return 0;
}

