#include <stdio.h>

#include <cuda_runtime_api.h>

#include <time.h>



//compile with: nvcc 2040511_Task3_A.cu -o 2040511_Task3_A



__device__ int is_a_match(char *attempt) {

	char plain_password1[] = "AR29";

	char plain_password2[] = "RR70";

	char plain_password3[] = "PP90";

	char plain_password4[] = "KO78";





	char *s = attempt;

	char *u = attempt;

	char *a = attempt;

	char *y = attempt;

	char *p1 = plain_password1;

	char *p2 = plain_password2;

	char *p3 = plain_password3;

	char *p4 = plain_password4;



	while(*s == *p1) {

		if(*s == '\0')

		{

			printf("Password: %s\n",plain_password1);

			break;

		}



		s++;

		p1++;

	}



	while(*u == *p2) {

		if(*u == '\0')

		{

			printf("Password: %s\n",plain_password2);

			break;

		}



		u++;

		p2++;

	}



	while(*a == *p3) {

		if(*a == '\0')

		{

			printf("Password: %s\n",plain_password3);

			break;

		}



		a++;

		p3++;

	}



	while(*y == *p4) {

		if(*y == '\0')

		{

			printf("Password: %s\n",plain_password4);

			return 1;

		}



		y++;

		p4++;

	}

	return 0;



}



__global__ void  kernel() {

	char i1,i2;



	char password[5];

	password[4] = '\0';



	int i = blockIdx.x+65;

	int j = threadIdx.x+65;

	char firstMatch = i;

	char secondMatch = j;



	password[0] = firstMatch;

	password[1] = secondMatch;

	for(i1='0'; i1<='9'; i1++){

		for(i2='0'; i2<='9'; i2++){



					password[2] = i1;

					password[3] = i2;



					if(is_a_match(password)) {

					}

					else {



					}

				}

			}

		}




int time_difference(struct timespec *start,

	struct timespec *finish,

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





int main() {



	struct  timespec start, finish;

	long long int time_elapsed;

	clock_gettime(CLOCK_MONOTONIC, &start);



	kernel <<<26,26>>>();

	cudaThreadSynchronize();



	clock_gettime(CLOCK_MONOTONIC, &finish);

	time_difference(&start, &finish, &time_elapsed);

	printf("Time elapsed was %lldns or %0.9lfs\n", time_elapsed, (time_elapsed/1.0e9));



	return 0;

}


