#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	FILE *file_pointer;
	char str_colors[][6] = {"green", "blue", "red"};
	char text[200];
	int power_cube_sum = 0;

	file_pointer = fopen("input.txt", "r");
	// file_pointer = fopen("test_input.txt", "r");

	if(file_pointer == NULL){
		printf("Cannot open file\n");
		return 1;
	}

	while (fgets(text, 200, file_pointer)){
		char color_value_str[10];
		char color_section_str[30];
		int high_green = 0;
		int high_blue = 0;
		int high_red = 0;
		int i = 0;
		int j = 0;

		// Move the index until valid numbers show up
		do {
			i++;
		}while (text[i] != ':');

		// Get color values
		j = 0;
		int color_section_index = 0;
		do {
			if(isdigit(text[i])){
				color_value_str[j] = text[i];
				j++;
			} else {
				color_section_str[color_section_index] = text[i];
				color_section_index++;
			}
			
			if(text[i] == ',' || text[i] == ';' || text[i+1] == '\0'){
				for(int z = 0; z < sizeof(str_colors); z++){
					if(strstr(color_section_str, str_colors[z]) != NULL){
						switch (z) {
							case 0: if (atoi(color_value_str) > high_green) {
										high_green = atoi(color_value_str);
									}
									break;
							case 1: if (atoi(color_value_str) > high_blue) {
										high_blue = atoi(color_value_str);
									}
									break;
							case 2: if (atoi(color_value_str) > high_red) {
										high_red = atoi(color_value_str);
									}
									break;
						}
					}
				}
				// Clean strings
				memset(color_value_str, 0, sizeof(color_value_str));
				memset(color_section_str, 0, sizeof(color_section_str));
				j = 0;
				color_section_index = 0;
			}
			i++;
		}while (text[i] != '\0');

		// Add the power cube value
		power_cube_sum += high_red * high_blue * high_green;
	}
	printf("Games power cube sum: %d\n", power_cube_sum);
}
