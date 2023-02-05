#include <stdio.h>

#define MAX_REQUESTS 200
#define MAX_CYLINDERS 5000

int requests[MAX_REQUESTS];

void sort_requests(int n) {
    int temp, i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (requests[i] > requests[j]) {
                temp = requests[i];
                requests[i] = requests[j];
                requests[j] = temp;
            }
        }
    }
}

int find_previous_request(int current, int n) {
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (requests[i] < current) {
            return i;
        }
    }
    return -1;
}

int find_next_request(int current, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (requests[i] > current) {
            return i;
        }
    }
    return -1;
}

int SCAN(int start, int n) {
    int i, current, previous, next, head_movement = 0;
    current = start;
    sort_requests(n);
    previous = find_previous_request(start, n);
    if (previous != -1) {
        for (i = previous; i >= 0; i--) {
            head_movement += current - requests[i];
            current = requests[i];
        }
        head_movement += current;
        current = 0;
    }
    next = find_next_request(start, n);
    if (next != -1) {
        for (i = next; i < n; i++) {
            head_movement += requests[i] - current;
            current = requests[i];
        }
    }
    return head_movement;
}

int main() {
    int i, n, start, total_head_movement = 0;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    printf("Enter the requests: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &start);
    total_head_movement = SCAN(start, n);
    printf("Total head movement: %d\n", total_head_movement);
    printf("Average head movement: %f\n", (float) total_head_movement / n);
    return 0;
}

OUTPUT:
Enter the number of disk requests: 5
Enter the requests: 55
58
60
70
18
Enter the initial head position: 58
Total head movement: 128
Average head movement: 25.600000

--------------------------------
Process exited after 76.38 seconds with return value 0
Press any key to continue . . .
