
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ALARMS 10

// Struct for representing an alarm
struct Alarm {
  int hour;
  int minute;
  int isActive;
};

// Function prototypes
void displayMenu();
void setAlarm(struct Alarm *alarms, int *alarmCount);
void editAlarm(struct Alarm *alarms, int alarmCount);
void deleteAlarm(struct Alarm *alarms, int *alarmCount);
void viewAlarms(struct Alarm *alarms, int alarmCount);
void triggerAlarm(struct Alarm *alarm);
int getCurrentTime();
int compareTime(int alarmTime, int currentTime);

int main() {
  // Initialize variables
  struct Alarm alarms[MAX_ALARMS];
  int alarmCount = 0;
  int choice;

  // Main loop
  while (1) {
    displayMenu();
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        setAlarm(alarms, &alarmCount);
        break;
      case 2:
        editAlarm(alarms, alarmCount);
        break;
      case 3:
        deleteAlarm(alarms, &alarmCount);
        break;
      case 4:
        viewAlarms(alarms, alarmCount);
        break;
      case 5:
        return 0;
      default:
        printf("\nInvalid choice\n");
    }

    // Check for triggered alarms and display current time
    time_t currentTime = getCurrentTime();
    for (int i = 0; i < alarmCount; i++) {
      if (alarms[i].isActive && compareTime(alarms[i].hour * 60 + alarms[i].minute, currentTime) == 0) {
        triggerAlarm(&alarms[i]);
      }
      printf("\nCurrent Time: %s", ctime(&currentTime));
    }
  }

  return 0;
}

// Define other functions here (setAlarm, editAlarm, deleteAlarm, etc.)
