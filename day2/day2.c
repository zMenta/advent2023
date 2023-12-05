#include <ctype.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	FILE *file_pointer;
	char str_colors[][6] = {"green", "blue", "red"};
	char text[200];
	int max_blue = 14;
	int max_green = 13;
	int max_red = 12;
	int valid_games_sum = 0;

	file_pointer = fopen("input.txt", "r");
	// file_pointer = fopen("test_input.txt", "r");

	if(file_pointer == NULL){
		printf("Cannot open file\n");
		return 1;
	}

	while (fgets(text, 200, file_pointer)){
		char color_value_str[10];
		char color_section_str[30];
		char game_str[5];
		int i = 0;
		int j = 0;
		int is_game_valid = 1;

		// Get current game value
		do {
			if(isdigit(text[i])){
				game_str[j] = text[i];
				j++;
			}
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
							case 0: if (atoi(color_value_str) > max_green) {
										is_game_valid = 0;
									}
									break;
							case 1: if (atoi(color_value_str) > max_blue) {
										is_game_valid = 0;
									}
									break;
							case 2: if (atoi(color_value_str) > max_red) {
										is_game_valid = 0;
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

		if (is_game_valid == 1) {
			valid_games_sum += atoi(game_str);
		}
	}
	printf("Valid games sum: %d\n", valid_games_sum);
}
