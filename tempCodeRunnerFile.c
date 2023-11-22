int main() {
    int choice;

    while (1) {
        printMenu();

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                setAlarm();
                break;

            case 2:
                stopAlarm();
                break;

            case 3:
                snoozeAlarm();
                break;

            case 4:
                viewAlarms();
                break;

            case 5:
                checkAlarms();
                break;

            case 6:
                displayCurrentTime();
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}