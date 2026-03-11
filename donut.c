#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

int main() {
    float A = 0, B = 0;
    float i, j;
    int k;
    float z[1760];
    char b[1760];
    
    // Clear screen and hide the cursor
    printf("\x1b[2J\x1b[?25l"); 

    time_t start_time = time(NULL);

    // Run the donut for exactly 5 seconds
    while (time(NULL) - start_time < 5) {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for(j=0; j < 6.28; j += 0.07) {
            for(i=0; i < 6.28; i += 0.02) {
                float c = sin(i), d = cos(j), e = sin(A), f = sin(j), g = cos(A), h = d + 2, 
                      D = 1 / (c * h * e + f * g + 5), l = cos(i), m = cos(B), n = sin(B), 
                      t = c * h * g - f * e;
                int x = 40 + 30 * D * (l * h * m - t * n), y= 12 + 15 * D * (l * h * n + t * m), 
                    o = x + 80 * y, N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if(22 > y && y > 0 && x > 0 && 80 > x && D > z[o]) {
                    z[o] = D;
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        printf("\x1b[H"); // Reset cursor to top left
        for(k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        usleep(30000); // 30ms delay to control the framerate
    }

    // 5 seconds are up: clear the screen, go to black, and hang forever
    // If the init process exits, the kernel will panic, so we use an infinite sleep loop.
    printf("\x1b[2J\x1b[H"); 
    while(1) {
        sleep(1000); 
    }

    return 0;
}
