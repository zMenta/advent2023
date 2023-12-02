#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *file_pointer;
	char text[100];
	char ch;
	int sum = 0;
	int first_value = 0;
	int last_value = 0;
	int current_value = 0;
	// No necessary converting strings to numbers
	// char str_nums[][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

	file_pointer = fopen("adventofcode.com_2023_day_1_input.txt", "r");
	// file_pointer = fopen("test_values.txt", "r");

	if(file_pointer == NULL){
		printf("Cannot open file\n");
		return 1;
	}

	while (fgets(text, 100, file_pointer )) {
		first_value = 0;
		current_value = 0;
		int i = 0;
		do {

			if(first_value == 0){
				first_value = current_value;
				last_value = current_value;
			} else if( current_value != last_value){
				last_value = current_value;
			}

			ch = text[i];
			if (isdigit(ch)){
				// char digit - '0' -> Converts the digit value to integer
				current_value = ch - '0';
			} 
			// else {
				// SADGE - Converting words to number was not necessary
				// // Build a 5 string starting from i position on the string
				// char text_snippet[] = {
				// 	*(value + i),
				// 	*(value + i + 1),
				// 	*(value + i + 2),
				// 	*(value + i + 3),
				// 	*(value + i + 4),
				// 	*(value + i + 5),
				// 	'\0' };
				//
				// // 9 Because of amount of numbers, 1-9
				// for (int j = 0; j < 9; j++){
				// 	// != NULL means that the string is found inside the other.
				// 	if(strstr(text_snippet, str_nums[j]) != NULL){
				// 		current_value = j + 1;
				// 	}
				// }
			// }
			i++;
		} while (ch != '\0');
		// Transform the first_value to decimal
		sum += first_value * 10;
		sum += last_value;
	}
	printf("Sum: %d\n", sum);
	return 0;
}
