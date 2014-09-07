/// This program lists the characters common to two input strings.
/// ASCII & UNICODE encodings are supported.
///
/// @author Ravi Agrawal
/// @date Sep 2014

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <inttypes.h>

#define ASCII 128
#define UTF8 256
#define UTF16 65536
#define UTF32 110000 /* As of date */

/// This method reads input from user and stores each unique
/// character as a corresponding bit set inside 'str_chars'.
///
/// @param str_chars: 'int' array representing unique characters from input
///
void input_string(int* str_chars)
{
	int c;
	while (((c = getchar()) != '\n')){
		int index = (c / (8 * sizeof(int)));
		str_chars[index] |= (1 << c);
	}
}

/// This method finds & lists the characters common to two strings.
///
/// @param str1_chars: 'int' array representing unique characters from first string.
/// @param str2_chars: 'int' array representing unique characters from second string.
/// @param size: number of characters for the chosen encoding.

void list_common_chars(int* str1_chars, int* str2_chars, uint64_t size)
{
	printf("common chars: \n");
	for (int i = 0; i < (size / (8 * sizeof(int))); i++){
		if ((str1_chars[i] == 0) || (str2_chars[i] == 0))
			continue;
		int mask = 1, j = 0;
		
		// Compare each bit/character
		while (j < (8 * sizeof(int))){
			int bit_str1 = str1_chars[i] & mask;
			int bit_str2 = str2_chars[i] & mask;
			if ((bit_str1) && (bit_str2))
				printf("%c ", j + (i * 8 * sizeof(int)));
			j++;
			mask <<= 1;
		}
	}
}
int main(int argc, char** argv)
{
	uint64_t size;
	if (argc < 1){
		fprintf(stderr, "Argument missing, format: ./$(EXE) <encoding>\n");
		fprintf(stderr, "where encoding: 'a' - ASCII, 'u8' - UTF8, 'u16' - UTF16, 'u32' - UTF32\n");
		exit(1);
	}
	if (strcmp(argv[1], "a") == 0)
		size = ASCII;
	else if (strcmp(argv[1], "u8") == 0)
		size = UTF8;
	else if (strcmp(argv[1], "u16") == 0)
		size = UTF16;
	else if (strcmp(argv[1], "u32") == 0)
		size = UTF32;
	else{
		fprintf(stderr, "Invalid argument\n");
		fprintf(stderr, "Valid values: 'a' - ASCII, 'u8' - UTF8, 'u16' - UTF16, 'u32' - UTF32\n");
		exit(1);
	}

	const int SIZE = size / (8 * sizeof(int));
	int str1_chars[SIZE], str2_chars[SIZE];

	for (int i = 0; i < SIZE; i++){
		str1_chars[i] = 0;
		str2_chars[i] = 0;
	}

	printf("Enter string 1: ");
	input_string(str1_chars);

	printf("Enter string 2: ");
	input_string(str2_chars);

	list_common_chars(str1_chars, str2_chars, size);
	return 0;
}