#include <stdio.h>

#define MAX_LINE 1000

int read_line(char[], int);
void reverse_str(char[], char[], int);

/*
 * Read from stdin, reverse each line, print it back
 */
int main() {
	int i;

	char line[MAX_LINE];
	char reversed[MAX_LINE];

	while ((i = read_line(line, MAX_LINE)) > 0) {
		reverse_str(line, reversed, i);	
		// do not print the emply lines
		if (i > 1) {
			printf("%s", reversed);
		}
	}

}

/*
 * Read a line, return the number of character read
 */
int read_line(char line[], int limit) {
	char c;
	int i = 0;

	while (i < limit - 1 && (c = getchar()) != EOF && c != '\n') {
		line[i] = c;
		++i;
	}

	if (c == '\n') {
		line[i] = c;
		++i;
	}

	line[i] = '\0';

	return i;
}

/*
 * Copy contents of the given char array from 'line' to 'res' in reverse order
 */
void reverse_str(char input[], char result[], int offset) {
	// exclude '\n' and '\0' from the given char array
	// put them at the end of the string later explicitely
	int j = offset - 2; 
	int i = 0;
	
	while ((result[j] = input[i]) != '\n') {
		--j;
		++i;
	}

	result[offset - 1] = '\n';
	result[offset] = '\0';
}
