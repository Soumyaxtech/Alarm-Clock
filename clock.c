#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // For sleep() function

// Structure to hold alarm information
struct Alarm {
    int hour;
    int minute;
    int active; // Flag to indicate if the alarm is active or not
};

// Function to display the menu
void displayMenu() {
    printf("\n1. Set Alarm\n");
    printf("2. Turn Off Alarm\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to set an alarm
void setAlarm(struct Alarm *alarm) {
    printf("\nEnter hour (0-23): ");
    scanf("%d", &alarm->hour);
    printf("Enter minute (0-59): ");
    scanf("%d", &alarm->minute);
    alarm->active = 1;
    printf("Alarm set for %02d:%02d\n", alarm->hour, alarm->minute);
}

// Function to check if the current time matches the alarm time
int checkAlarm(struct Alarm alarm) {
    time_t now;
    struct tm *currentTime;
    time(&now);
    currentTime = localtime(&now);
    printf("%c",currentTime);
    if (alarm.active && currentTime->tm_hour == alarm.hour && currentTime->tm_min == alarm.minute) {
        return 1; // Alarm time matches current time
    }
    return 0; // Alarm time does not match current time
}

int main() {
    struct Alarm userAlarm = {0}; // Initialize alarm
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setAlarm(&userAlarm);
                break;
            case 2:
                userAlarm.active = 0; // Turn off the alarm
                printf("Alarm turned off.\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please enter again.\n");
        }

        while (!checkAlarm(userAlarm)) {
            // Check for alarm trigger every second
            // This loop is just for demonstration, not an efficient way to handle time in a real application
            sleep(1);
        }

        printf("Alarm triggered!\n");
        // Here you might implement logic to turn off the alarm or take further actions
    }

    return 0;
}
