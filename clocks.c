// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <unistd.h> // For sleep() function

// // Structure to hold alarm information
// struct Alarm {
//     int hour;
//     int minute;
//     int active; // Flag to indicate if the alarm is active or not
// };

// // Function to display the alarm setting interface
// void displayAlarmSettingInterface() {
//     printf("\n1. Set Alarm\n");
//     printf("2. Turn Off Alarm\n");
//     printf("3. Exit\n");
//     printf("Enter your choice: ");
// }

// // Function to set an alarm
// void setAlarm(struct Alarm *alarm) {
//     printf("\nEnter hour (0-23): ");
//     scanf("%d", &(alarm->hour));
//     printf("Enter minute (0-59): ");
//     scanf("%d", &(alarm->minute));
//     alarm->active = 1;
//     printf("Alarm set for %02d:%02d\n", alarm->hour, alarm->minute);

// }

// // Function to check if the current time matches the alarm time
// int checkAlarm(struct Alarm alarm) {
//     time_t now;
//     struct tm *currentTime;
//     time(&now);
//     current.Time = localtime(&now);

//     if (alarm.active && current.Time.tm_hour == alarm.hour && current.Time.tm_min == alarm.minute) 
//  {
//         return 1; // Alarm time matches current time
//     }

//     return 0; // Alarm time does not match current time
// }


// // Function to trigger the alarm notification
// void triggerAlarmNotification() {
//     printf("\nALARM! ALARM! ALARM!\n");
//     printf("Wake up! It's time to get up.\n");
// }

// // Function to allow users to stop or snooze alarms
// void handleAlarmResponse() {
//     printf("\n1. Stop Alarm\n");
//     printf("2. Snooze Alarm (10 minutes)\n");
//     printf("Enter your choice: ");

//     int choice;
//     scanf("%d", &choice);

//     switch (choice) {
//         case 1:
//             printf("Alarm stopped.\n");
//             break;
//         case 2:
//             printf("Alarm snoozed for 10 minutes.\n");
//             if (choice == 2){
//             sleep(10 * 60); // Sleep for 10 minutes
//             triggerAlarmNotification(); // Trigger alarm again after 10 minutes
//             }
//             break;
//         default:
//             printf("Invalid choice. Please enter again.\n");
//             handleAlarmResponse(); // Handle alarm response again
//     }
// }

// int main() {
//     struct Alarm userAlarm = {0}; // Initialize alarm

//     while (1) {
//         displayAlarmSettingInterface();
//         int choice;
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 setAlarm(&userAlarm);
//                 break;
//             case 2:
//                 userAlarm.active = 0; // Turn off the alarm
//                 printf("Alarm turned off.\n");
//                 break;
//             case 3:
//                 printf("Exiting...\n");
//                 return 0;
//             default:
//                 printf("Invalid choice. Please enter again.\n");
//         }

//         while (!checkAlarm(userAlarm)) {
//             // Check for alarm trigger every second
//             sleep(1);
//         }

//         triggerAlarmNotification();
//         handleAlarmResponse(); // Handle user response to the alarm
//     }

//     return 0;
// }
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include<time.h>

// // Structure to hold alarm details
// struct Alarm {
//     int hour;
//     int minute;
//     int isActive;
// };

// // Function to trigger alarm notification
// void triggerAlarm(struct Alarm alarm) {
//     printf("\nALARM: %02d:%02d\n", alarm.hour, alarm.minute);
//     printf("ALARM! ALARM! ALARM!\n");
//     printf("It's Time to Walk up.... ");
// }

// int main() {
//     struct Alarm alarms[10]; // Array to hold up to 10 alarms
//     int totalAlarms = 0;

//     while (1) {
//         printf("\n1. Set Alarm\n2. Stop Alarm\n3. Snooze Alarm\n4. Exit\n");
//         int choice;
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 if (totalAlarms >= 10) {
//                     printf("Maximum number of alarms reached.\n");
//                     break;
//                 }

//                 printf("Enter hour (0-23): ");
//                 scanf("%d", &alarms[totalAlarms].hour);
//                 printf("Enter minute (0-59): ");
//                 scanf("%d", &alarms[totalAlarms].minute);
//                 printf("alarm set successfully");
//                 alarms[totalAlarms].isActive = 1;
//                 totalAlarms++;
//                 break;

//             case 2:
//                 printf("Stopping alarm...\n");
//                 // Code to stop the alarm (not implemented in this basic example)
//                 break;

//             case 3:
//                 printf("Snoozing alarm for 5 minutes...\n");
//                 sleep(300); // Snooze for 5 minutes (300 seconds)
//                 break;

//             case 4:
//                 printf("Exiting...\n");
//                 exit(0);
//                 break;

//             default:
//                 printf("Invalid choice! Please try again.\n");
//         }

//         // Check if any alarms need to be triggered
//         time_t currentTime;
//         struct tm *localTime;

//         currentTime = time(NULL);
//         localTime = localtime(&currentTime);

//         for (int i = 0; i < totalAlarms; i++) {
//             if (alarms[i].isActive &&
//                 alarms[i].hour == localTime->tm_hour &&
//                 alarms[i].minute == localTime->tm_min) {
//                 triggerAlarm(alarms[i]);
//                 alarms[i].isActive = 0; // Deactivate the triggered alarm
//             }
//         }
//     }

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_ALARMS 10

struct Alarm {
    int hour;
    int minute;
    int isActive;
};

void displayCurrentTime() {
    time_t now;
    struct tm *localTime;

    now = time(NULL);
    localTime = localtime(&now);

    printf("Current Time: %02d:%02d\n", localTime->tm_hour, localTime->tm_min);
}

void triggerAlarm(struct Alarm alarm) {
    printf("\nALARM: %02d:%02d\n", alarm.hour, alarm.minute);
    printf("ALARM! ALARM! ALARM!\n");
    printf("It's Time to Wake up.... ");
}

int main() {
    struct Alarm alarms[MAX_ALARMS];
    int totalAlarms = 0;

    while (1) {
        displayCurrentTime();

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
                int hour, minute;
                scanf("%d", &hour);
                printf("Enter minute (0-59): ");
                scanf("%d", &minute);

                // Validate input
                if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
                    printf("Invalid time. Please enter a valid hour (0-23) and minute (0-59).\n");
                    break;
                }

                // Check for alarm conflicts
                int conflict = 0;
                for (int i = 0; i < totalAlarms; i++) {
                    if (alarms[i].hour == hour && alarms[i].minute == minute) {
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
                alarms[totalAlarms].isActive = 1;
                totalAlarms++;
                printf("Alarm set for %02d:%02d\n", hour, minute);
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

        // Check if any alarms need to be triggered
        time_t currentTime;
        struct tm *localTime;

        currentTime = time(NULL);
        localTime = localtime(&currentTime);

        for (int i = 0; i < totalAlarms; i++) {
            if (alarms[i].isActive &&
                alarms[i].hour == localTime->tm_hour &&
                alarms[i].minute == localTime->tm_min) {
                triggerAlarm(alarms[i]);
                alarms[i].isActive = 0; // Deactivate the triggered alarm
            }
        }
    }

    return 0;
}
