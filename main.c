#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 40

// Directions for moving in 4 directions (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Function to find the position of a character in the map
void find_position(char map[ROWS][COLS], char target, int *x, int *y) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (map[i][j] == target) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

// Flood Fill (DFS) to find the path from (x, y) to (target_x, target_y)
bool flood_fill(char map[ROWS][COLS], char path_map[ROWS][COLS], int x, int y, int target_x, int target_y) 
{
    // Base case: If the current position is the target, return true
    if (x == target_x && y == target_y) {
        path_map[x][y] = 'X'; // Mark the target position
        return true;
    }

    // Mark the current position as visited
    path_map[x][y] = 'X';

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // Check if the new position is within bounds and traversable
        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS &&
            (map[nx][ny] == '0' || map[nx][ny] == 'C' || map[nx][ny] == 'P') &&
            path_map[nx][ny] == '0') {
            // Recursively call flood_fill
            if (flood_fill(map, path_map, nx, ny, target_x, target_y)) {
                return true; // Path found
            }
        }
    }

    // If no path is found, backtrack
    path_map[x][y] = '0';
    return false;
}

// Function to print the map
void print_map(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Input map
    char map[ROWS][COLS] = {
        "111111111111111111111111111111111111",
        "1E10001111101110100000011011111010C1",
        "10100011100C111000001H000010C00C0001",
        "10C0000P00000000001110000000C01C01C1",
        "111111111111111111111111111111111111"
    };

    // Initialize the path map with '0'
    char path_map[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            path_map[i][j] = '0';
        }
    }

    // Find the positions of the enemy (H) and the player (P)
    int enemy_x, enemy_y, player_x, player_y;
    find_position(map, 'H', &enemy_x, &enemy_y);
    find_position(map, 'P', &player_x, &player_y);

    // Use Flood Fill to find the path from the enemy to the player
    flood_fill(map, path_map, enemy_x, enemy_y, player_x, player_y);

    // Print the path map
    printf("Path Map:\n");
    print_map(path_map);

    return 0;
}