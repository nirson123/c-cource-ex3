#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE 256
#define WORD 30

int getLine(char s[]) {
	char c;
	int i = 0;
	while ((c = getchar()) != '\n' && c != EOF) {
		if (c != '\r') { s[i++] = c; }
	}
	s[i] = '\0';
	return i;
}

int getword(char w[]){
	char c;
	int i = 0;
	
	while ((c = getchar()) != '\n' && c != '\t' && c != ' ' && c != EOF) {
		if (c != '\r') { w[i++] = c; }
	}
	w[i] = '\0';
	return i;
}

int isSubstring(const char* str1, const char* str2) {
	return (strstr(str1, str2) != NULL);
}

void copy_no_i(char dest[], const char src[], int i) {
	int j, k = 0;
	for (j = 0; j < strlen(src) + 1; j++) {
		if (j != i) {
			dest[k] = src[j];
			k++;
		}
	}
}

int isSimilar(const char* s, const char* t) {
	if (strcmp(s, t) == 0) { return 1; }
	if ((strlen(t) - strlen(s)) != 1) { return 0; }
	int i;
	char drop[WORD];
	for (i = 0; i < strlen(t); i++) {
		copy_no_i(drop, t, i);
		if (strcmp(drop, s) == 0) { return 1; }
	}
	return 0;
}

void print_lines(char* str) {
	char line[LINE];
	while (getLine(line) > 0) {
		if (isSubstring(line, str)) {
			printf("%s\n", line);
		}
	}
}

void print_similar_words(char* str) {
	char word[WORD];
	while (getword(word) > 0) {
		if (isSimilar(str, word)) {
			printf("%s\n", word);
		}
	}
}

int main() {

	char word[WORD];
	getword(word);
	char SO = getchar();
	getchar(); getchar(); getchar(); getchar();
	if (SO == 'a') {
		print_lines(word);
	}
	else {
		print_similar_words(word);
	}
	return 0;
}

