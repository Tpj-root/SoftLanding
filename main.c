/*  Soft Landing is a terminal command that mimics the behavior of the sl command
 *  Copyright (C) 2024 by trichyhackerspace@gmail.com
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2 only of the License
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  softlanding version 1.0
 *
 *  Changelog:
 */
#include <stdio.h>
#include <unistd.h>  // for usleep()

// Function to clear the screen
void clear_screen() {
    printf("\033[H\033[J");
}

// Function to print the rocket at a given height
void print_rocket(int height) {
    for (int i = 0; i < height; i++) {
        printf("\n");
    }
    printf("    /\\\n");
    printf("   /  \\\n");
    printf("  |    |\n");
    printf("  |NASA|\n");
    printf("  |    |\n");
    printf("  |    |\n");
    printf("  |    |\n");
    printf(" '      `\n");
    printf(" |      |\n");
    printf(" |      |\n");
    printf(" |______|\n");
    printf("  '-`'-`   .\n");
    printf("  / . \\' .'\n");
    printf(" ''( .\\' .' .;'\n");
    printf("'.;.;' ;'.;' ..;;'\n");
}

// Function to print the character walking away
void print_walking_character(int step) {
    // Rocket remains stationary at the bottom
    printf("     /\\\n");
    printf("    /  \\\n");
    printf("   |    |\n");
    printf("   |NASA|\n");
    printf("   |    |\n");
    printf("   |    |\n");
    printf("   |    |\n");
    printf("  '      `\n");
    printf("  |      |\n");
    printf("  |      |\n");
    printf("  |______|\\\n");
    printf("   '-`'-`  ---\n");
    printf("   //  \\     `\\\n");
    printf("  //'  .\\      ``\\\n");
    printf(" //..; ' \\        ``\\\n");

    // The walking figure moves left based on the step
    for (int i = 0; i < step; i++) {
        printf(" ");
    }
    printf("                          O    O \n");    // head
    for (int i = 0; i < step; i++) {
        printf(" ");
    }
    printf("                         /|\\  /|\\  \n");  // body and arms
    for (int i = 0; i < step; i++) {
        printf(" ");
    }
    printf("                         / \\  / \\  \n");  // legs
}

int main() {
    int height = 0;  // starting from the top of the screen
    int max_height = 10;  // height at which the rocket will land

    // Rocket landing animation
    while (height <= max_height) {
        clear_screen();  // clear the screen for each frame
        print_rocket(height);
        usleep(500000);  // delay (500000 = 0.5 seconds)
        height++;  // move the rocket down by increasing height
    }

    // Walking figure animation after the rocket has landed
    int step = 0;
    int max_steps = 10;  // number of steps the character will take
    while (step <= max_steps) {
        clear_screen();
        print_walking_character(step);  // print the rocket and the walking figure
        usleep(500000);  // delay (500000 = 0.5 seconds)
        step++;  // move the character further to the right
    }

    printf("\nRocket has landed, finally we reach the ground.\n");
    return 0;
}

