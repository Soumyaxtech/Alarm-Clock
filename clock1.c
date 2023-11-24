#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ALARMS 10

struct Alarm {
    int hour;
    int minute;
    int second;
    int isActive;
};

void displayCurrentTime() {
    time_t now;
    struct tm *localTime;

    now = time(NULL);
    localTime = localtime(&now);

    printf("Current Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
}

void triggerAlarm(struct Alarm alarm) {
    printf("\nALARM: %02d:%02d:%02d\n", alarm.hour, alarm.minute,alarm.second);
    printf("ALARM! ALARM! ALARM!\n");
    printf("It's Time to Wake up.... ");
}

int main() {
    struct Alarm alarms[MAX_ALARMS];
    int totalAlarms = 0;

    while (1) {
        displayCurrentTime();

        time_t currentTime;
        struct tm *localTime;

        currentTime = time(NULL);
        localTime = localtime(&currentTime);

        // Check if any alarms need to be triggered
        for (int i = 0; i < totalAlarms; i++) {
            if (alarms[i].isActive &&
                alarms[i].hour == localTime->tm_hour &&
                alarms[i].minute == localTime->tm_min &&
                alarms[i].second == localTime->tm_sec) {
                triggerAlarm(alarms[i]);
                alarms[i].isActive = 0; // Deactivate the triggered alarm
            }
        }

        printf("\n1. Set Alarm\n2. Stop Alarm\n3. Snooze Alarm\n4. Exit\n");
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (totalAlarms >= MAX_ALARMS) {
                    printf("Maximum number of alarms reached.\n");
                    break;
                }

                printf("Enter hour (0-23): ");
                int hour, minute,second;
                scanf("%d", &hour);
                printf("Enter minute (0-59): ");
                scanf("%d", &minute);
                 printf("Enter second (0-59): ");
                scanf("%d", &second);
               

                // Validate input
                if (hour < 0 || hour > 23 || minute < 0 || minute > 59|| second<0 || second>59) {
                    printf("Invalid time. Please enter a valid hour (0-23) and minute (0-59) with proper second(0-59).\n");
                    break;
                }

                // Check for alarm conflicts
                int conflict = 0;
                for (int i = 0; i < totalAlarms; i++) {
                    if (alarms[i].hour == hour && alarms[i].minute == minute && alarms[i].second == second) {
                        conflict = 1;
                        printf("Conflict: An alarm is already set for this time.\n");
                        break;
                    }
                }

                if (conflict) {
                    break;
                }

                alarms[totalAlarms].hour = hour;
                alarms[totalAlarms].minute = minute;
                alarms[totalAlarms].second = second;
                alarms[totalAlarms].isActive = 1;
                totalAlarms++;
                printf("Alarm set for %02d:%02d:%02d\n", hour, minute,second);
                break;


            case 2:
                printf("Stopping alarm...\n");
                // Code to stop the alarm (not implemented in this basic example)
                break;

            case 3:
                printf("Snoozing alarm for 5 minutes...\n");
                sleep(300); // Snooze for 5 minutes (300 seconds)
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

        // Delay for 1 minute before checking again
        sleep(60);
    }

    return 0;
}
