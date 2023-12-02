#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	FILE *file_pointer;
	char value[100];
	char ch;
	int sum = 0;
	int first_value = 0;
	int last_value = 0;
	int current_value = 0;
	char str_nums[][5] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

	file_pointer = fopen("adventofcode.com_2023_day_1_input.txt", "r");
	// file_pointer = fopen("test_values.txt", "r");

	if(file_pointer == NULL){
		printf("Cannot open file\n");
		return 0;
	}

	while (fgets(value, 100, file_pointer )) {
		// DEBUG MESSAGE
		// printf("%s", value);

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

			// DEBUG MESSAGE
			// printf("fv: %d  |  lv: %d\n\n", first_value, last_value);
			ch = value[i];
			if (isdigit(ch)){
				// char digit - '0' -> Converts the digit value to integer
				current_value = ch - '0';
			} else {
				// Build a 5 string starting from i position on the string
				char text_snippet[] = {
					*(value + i),
					*(value + i + 1),
					*(value + i + 2),
					*(value + i + 3),
					*(value + i + 4),
					*(value + i + 5),
					'\0' };

				// 9 Because of amount of numbers, 1-9
				for (int i = 0; i < 9; i++){
					// != NULL means that the string is found inside the other.
					if(strstr(text_snippet, str_nums[i]) != NULL){
						current_value = i + 1;

					}
				}
			}

			i++;
		} while (ch != '\0');
		// Transform the first_value to decimal
		sum += first_value * 10;
		sum += last_value;
	}

	printf("Sum: %d\n", sum);
}
