// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <string.h>

// typedef struct Alarm {
//   int hour;
//   int minute;
//   char label[100];
//   int snoozeDuration;
//   int isRepeating;
// } Alarm;

// Alarm alarmList[10]; // Maximum of 10 alarms allowed
// int alarmCount = 0;

// void displayCurrentTime() {
//   time_t currentTime = time(NULL);
//   struct tm *localTime = localtime(&currentTime);

//   printf("\nCurrent Time: %02d:%02d:%02d\n", localTime->tm_hour, localTime->tm_min, localTime->tm_sec);
// }

// int validateAlarmTime(int hour, int minute) {
//   if (hour < 0 || hour > 23) {
//     printf("Invalid hour: %d (Hours should be between 0 and 23)\n", hour);
//     return 0;
//   }

//   if (minute < 0 || minute > 59) {
//     printf("Invalid minute: %d (Minutes should be between 0 and 59)\n", minute);
//     return 0;
//   }

//   return 1;
// }

// int validateSnoozeDuration(int snoozeDuration) {
//   if (snoozeDuration < 5 || snoozeDuration > 15) {
//     printf("Invalid snooze duration: %d (Snooze duration should be between 5 and 15 minutes)\n", snoozeDuration);
//     return 0;
//   }

//   return 1;
// }

// int checkAlarmConflict(int hour, int minute) {
//   for (int i = 0; i < alarmCount; i++) {
//     if (alarmList[i].hour == hour && alarmList[i].minute == minute) {
//       printf("Alarm conflict: New alarm time overlaps with existing alarm at %02d:%02d\n", hour, minute);
//       return 0;
//     }
//   }

//   return 1;
// }

// void setAlarm() {
//   Alarm newAlarm;

//   printf("\nEnter alarm time: ");
//   scanf("%d:%d", &newAlarm.hour, &newAlarm.minute);

//   if (!validateAlarmTime(newAlarm.hour, newAlarm.minute)) {
//     return;
//   }

//   printf("\nEnter alarm label (optional): ");
//   scanf("%[^\n]", newAlarm.label);

//   printf("\nSelect snooze duration (minutes): ");
//   printf("\n1. 5 minutes");
//   printf("\n2. 10 minutes");
//   printf("\n3. 15 minutes\n");

//   int snoozeOption;
//   scanf("%d", &snoozeOption);

//   switch (snoozeOption) {
//     case 1:
//       newAlarm.snoozeDuration = 5;
//       break;
//     case 2:
//       newAlarm.snoozeDuration = 10;
//       break;
//     case 3:
//       newAlarm.snoozeDuration = 15;
//       break;
//     default:
//       printf("Invalid snooze option: %d\n", snoozeOption);
//       return;
//   }

//   printf("\nSet alarm to repeat daily (1) or weekdays (2)?: ");
//   scanf("%d", &newAlarm.isRepeating);

//   if (!checkAlarmConflict(newAlarm.hour, newAlarm.minute)) {
//     return;
//   }

//   alarmList[alarmCount++] = newAlarm;
//   printf("\nAlarm set successfully!\n");
// }

// void displayAlarmList() {
//   if (alarmCount == 0) {
//     printf("\nNo alarms set.\n");
//     return;
//   }

//   printf("\nAlarm List:\n");

//   for (int i = 0; i < alarmCount; i++) {
//     printf("\nAlarm %d:\n", i + 1);
//     printf("  Alarm Time: %02d:%02d\n", alarmList[i].hour, alarmList[i].minute);
//     printf("  Label: %s\n", alarmList[i].label);
//     printf("  Snooze Duration: %d minutes\n", alarmList);
//   }
// }
// void triggerAlarm() {
//     time_t currentTime = time(NULL);
//     struct tm *localTime = localtime(&currentTime);
//     int currentHour = localTime->tm_hour;
//     int currentMinute = localTime->tm_min;

//     for (int i = 0; i < alarmCount; i++) {
//         if (alarmList[i].hour == currentHour && alarmList[i].minute == currentMinute) {
//             printf("\nAlarm triggered for: %02d:%02d\n", currentHour, currentMinute);
//             printf("Alarm Label: %s\n", alarmList[i].label);

//             // You might implement additional actions here when the alarm triggers

//             // For demonstration, let's remove the triggered alarm from the list
//             for (int j = i; j < alarmCount - 1; j++) {
//                 alarmList[j] = alarmList[j + 1];
//             }
//             alarmCount--;
//         }
//     }
// }
// int main() {
//     int choice;

//     while (1) {
//         displayCurrentTime();
//         triggerAlarm();

//         printf("\n--- Alarm Clock Application ---\n");
//         printf("1. Set Alarm\n");
//         printf("2. View Alarms\n");
//         printf("3. View Current Time\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 setAlarm();
//                 break;
//             case 2:
//                 displayAlarmList();
//                 break;
//             case 3:
//                 displayCurrentTime();
//                 break;
//             case 4:
//                 printf("\nExiting...\n");
//                 return 0;
//             default:
//                 printf("\nInvalid choice. Please enter again.\n");
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
  int second;
  int isActive;
};

int isAlarmTime(struct Alarm alarm, struct tm *localTime) {
  if (alarm.isActive && alarm.hour == localTime->tm_hour && alarm.minute == localTime->tm_min && alarm.second == localTime->tm_sec) {
    return 1;
  }
  return 0;
}

void triggerAlarm(struct Alarm alarm) {
  printf("\nALARM: %02d:%02d:%02d\n", alarm.hour, alarm.minute, alarm.second);
  printf("ALARM! ALARM! ALARM!\n");
  printf("It's Time to Wake up.... ");
}

int main() {
  struct Alarm alarms[MAX_ALARMS];
  int totalAlarms = 0;

  while (1) {
    time_t currentTime;
    struct tm *localTime;

    currentTime = time(NULL);
    localTime = localtime(&currentTime);

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
        int hour, minute, second;
        scanf("%d", &hour);
        printf("Enter minute (0-59): ");
        scanf("%d", &minute);
        printf("Enter second (0-59): ");
        scanf("%d", &second);

        if (hour < 0 || hour > 23 || minute < 0 || minute > 59 || second < 0 || second > 59) {
          printf("Invalid time. Please enter a valid hour (0-23), minute (0-59), and second (0-59).\n");
          break;
        }

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
        printf("Alarm set for %02d:%02d:%02d\n", hour, minute, second);
        break;

      case 2:
        printf("Stopping alarm...\n");

        int alarmToStop;
        printf("Enter the alarm number to stop (0-based indexing): ");
        scanf("%d", &alarmToStop);

        if (alarmToStop >= 0 && alarmToStop < totalAlarms) {
          alarms[alarmToStop].isActive = 0;
          printf("Alarm number %d stopped.\n", alarmToStop);
        } else {
          printf("Invalid alarm number.\n");
        }
        break;

      case 3:
        printf("Snoozing alarm...\n");

        int alarmToSnooze;
        printf("Enter the alarm number to snooze (0-based indexing): ");
        scanf("%d", &alarmToSnooze);

        if (alarmToSnooze >= 0 && alarmToSnooze < totalAlarms) {
          alarms[alarmToSnooze].isActive = 1; // Reactivate the alarm
          sleep(300); // Snooze for 5 minutes (300 seconds)
          printf("Alarm number %d snoozed for 5 minutes.\n");
        }
        break;

        case 4:
               printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
    }
  }
    return 0;
  
}
