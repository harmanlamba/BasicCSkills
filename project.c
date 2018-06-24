/* ENGGEN131, Semester Two, 2017 */

/* PROJECT SOLUTION BY:  << place your name and ID number here >> */

#include "project.h"

/* HELPER FUNCTIONS */
/* If you have defined any "helper" functions, which you call from the required */
/* functions, you should place them here, at the top of the source file.  This will */
/* make it easier for the markers to locate them.  You should also include a */
/* comment at the top of each of the "helper" functions you define which clearly */
/* describes their purpose, and which of the tasks they support. */

void Swap(int *a, int *b) {

	int temp = *b;
	*b = *a;
	*a = temp;
}

int GCD2Finder(int a, int b) {

	int temp,remainder;
	if (a < b) {
		Swap(&a, &b);
	} 
	temp = b;
	remainder = a%b;
	
	while (remainder != 0) {
		temp = remainder;
		remainder = b%remainder;
	}
	return temp;
}

/* REQUIRED FUNCTIONS */
/* Implement each of the required functions below.  The code that is provided initially */
/* for each function is incorrect - you should correct this! */

/* Your comment goes here*/
int DivisorOfThree(int a, int b, int c)
{
	//Checking if Number is 0 or negative if not continuing with the code
	int GCD;

	if (a <=0 || b<=0 || c<=0 ) {
		return -1;
	}

	if (a > b) {
		Swap(&a, &b);
	}
	if (b > c) {
		Swap(&b, &c);
	}
	if (a > b) {
		Swap(&a, &b);
	}

	GCD = GCD2Finder(a, b);
	return GCD2Finder(GCD, c);
}



/* Your comment goes here*/
double AverageSheep(int *counts)
{

	int i = 0;
	int counter,sum;
	double average;
	counter = 0;
	sum = 0;
	while (counts[i] != 9999) {
		if (counts[i] != -1) {
			sum +=counts[i];
			counter++;		
		}
		i++;
	}

	if (sum == 0) {
		return 0.0;
	}
	
	average = (double)sum / counter;
	return average;
}

/* Your comment goes here*/
void Emphasise(char* word)
{
	// Find incidices of underscore

	int strlength,lastinstance,firstinstance,i;
	lastinstance = 0;
	firstinstance = 0;
	strlength = strlen(word);
	
	//Finding last instance of uncderscore
	for (i = 0; i < strlength; i++) {
		if (word[i]== '_') {
			lastinstance=i;
		}
	}
	//Finding first instance of underscore
	i = 0;
	while (word[i] != '_') {
		i++;
	}
	firstinstance = i;

	for (i = firstinstance; i < lastinstance; i++) {
		if (word[i] > 97 && word[i] < 122) {
			word[i] -= 32;
		}
	}

	for (i = firstinstance; i <= lastinstance; i++) {
		word[i] = word[i + 1];
	}
	for (i = lastinstance-1; i < strlength-1; i++) {
		word[i] = word[i + 2];
	}
}

/* Your comment goes here*/
int PrimeFactors(int n, int *factors)
{
	int divider = 2;
	int counter=0;
	
	while (n/divider >= 1) {
		if (n%divider == 0) {
			factors[counter] = divider;
			counter++;
			n = n/divider;
		}
		else {
			divider++;
		}
	}
	return counter;
}

/* Your comment goes here*/
void ConnectTwo(int maze[10][10])
{

	//finding 1 and 2 locations

	int start[2], finish[2],rowdirection, coldirection;;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (maze[i][j] == 1) {
				start[0] = i;
				start[1] = j;
			}
			else if (maze[i][j] == 2) {
				finish[0] = i;
				finish[1] = j;

			}
		}
	}

	rowdirection=((finish[0] - start[0]) > 0) ? 1 : -1;
	coldirection = ((finish[1] - start[1]) > 0) ? 1 : -1;
		

	while (start[0] != finish[0] && start[1] != finish[1]) {
		start[0] += rowdirection;
		start[1] += coldirection;
		maze[start[0]][start[1]] = 3;

	}

	while (start[0] == finish[0] && start[1] != finish[1]) {
		start[1] += coldirection;
		maze[start[0]][start[1]] = 3;
	}

	while (start[1] == finish[1] && start[0] != finish[0]) {
		start[0] += rowdirection;
		maze[start[0]][start[1]] = 3;
}

}

/* Your comment goes here*/
void DayTrader(int *prices, int numPrices, int *bestRun, int *bestRunIndex)
{
	int temp = 0;
	int startindicies = 0;
	int stoppingindicies = 0;
	int value = 0;
	int i = 0;
	int j = 0;

	while (i < numPrices) {
		for (i = stoppingindicies+1; i <= numPrices; i++) {
			stoppingindicies = i;
			if (value > temp) {
				temp = value;
				startindicies = (stoppingindicies - value-1 );
			}
			if ((prices[i - 1] < prices[i]) /*&& i != numPrices -1 */) {
				value++;
			}
			else {
				value = 0;
				break;
			}
		}
	}

	*bestRun = temp;
	*bestRunIndex = startindicies;
	

}


/* Your comment goes here*/
void Compress(int *input, int *output)
{

	int i = 0, length=0,counter=0,value=0,j=0,doublecounter=0,notcounter=0;

	while (input[i] != -1) {
		length++;
		i++;
	}

	for (i = 0; i <= length-1; i++) {
		if (input[i] == input[i+1]) {
			value = input[i + 1];
				counter+=2;
				if (input[i + 1] == input[i + 2]) {
					doublecounter++;
				}
		}
		else {
			if ((input[0] != input[1]) && (i!= (length-1))) {
				notcounter++;
				value = input[i];
				output[j] = notcounter;
				output[j + 1] = value;
				j += 2;
			}
			else {
				output[j] = counter - doublecounter;
				output[j + 1] = value;
				j += 2;
				counter = 0;
			}
		}
		
	}
	output[j]=-1;
}

/* Your comment goes here*/
void AddOne(char *input, char *output)
{
	int strlength,copyarray[MAX_ARRAY_SIZE];

	strlength = strlen(input);
	int i=strlength-1,j = 0;

	if (input[strlength-1] == '9' && input[0] == '9')  {
		while (input[i] == '9') {
			input[i] = '0';
			i--;
		}

		for (i = 0; i < strlength; i++) {
			output[j + 1] = input[i];
			j++;
}
		output[0] = '1';
		output[strlength + 1] = 0;

	}

	else if(input[strlength-1]=='9'){
		while (input[i] == '9') {
			input[i] = '0';
			i--;
		}

		input[i] += 1;
		strcpy(output, input);
	}

	else {

		input[strlength-1] += 1;
		strcpy(output, input);
	}
	

}

/* Your comment goes here*/
void Histogram(char *result, int *values, int numValues)
{
	result[0] = (char)('~' + numValues + values[0]);
}

/* Your comment goes here*/
void GoldRush(int *results, int rows, int cols, int map[MAX_MAP_SIZE][MAX_MAP_SIZE], int bonus)
{
	results[0] = 99993 + rows + cols + map[0][0] + bonus;
}

