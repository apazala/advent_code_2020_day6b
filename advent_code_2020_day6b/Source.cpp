#include <stdio.h>
#include <string.h>

int main() {
	char line[32];
	char ansyeryescount[26] = { 0 };

	FILE *fin = fopen("input.txt", "r");
	if (!fin) {
		fprintf(stderr, "Unable to open input file\n");
		return 1;
	}

	int count = 0;
	int npeople = 0;
	while (fgets(line, sizeof(line), fin)) {
		if (line[0] == '\n') {
			for (int i = 0; i < 26; i++) {
				if (ansyeryescount[i] == npeople)
					count++;
			}
			memset(ansyeryescount, 0, sizeof(ansyeryescount));
			npeople = 0;
		}
		else {
			npeople++;
			for (char *p = line; *p >= 'a'; p++) {
				int i = (*p) - 'a';
				ansyeryescount[i]++;
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (ansyeryescount[i] == npeople)
			count++;
	}

	printf("%d\n", count);

	fclose(fin);

	return 0;
}