#include <ctype.h>
#include <stdio.h>

int main(void) {
	FILE *file_pointer;
	char value[100];
	char ch;
	int sum = 0;
	int first_value = 0;
	int last_value = 0;
	int current_value = 0;

	// file_pointer = fopen("adventofcode.com_2023_day_1_input.txt", "r");
	file_pointer = fopen("test_values.txt", "r");

	if(file_pointer == NULL){
		printf("Cannot open file\n");
		return 0;
	}

	while (fgets(value, 100, file_pointer )) {
		first_value = 0;
		printf("%s", value);

		int i = 0;
		do {
			ch = value[i];
			// printf("\n%c", ch);
			// printf(" - %b", isdigit(ch));
			if (isdigit(ch)){
				// char digit - '0' -> Converts the digit value
				current_value = ch - '0';
				if(first_value == 0){
					first_value = current_value;
					last_value = current_value;
				} else if( current_value != last_value){
					last_value = current_value;
				}
			}
			i++;
		} while (ch != '\0');
		printf("fv: %d  |  lv: %d\n\n", first_value, last_value);
		printf("--------------\n");
		// Transform the first_value to decimal
		sum += first_value * 10;
		sum += last_value;
	}

	printf("Sum: %d\n", sum);
}
