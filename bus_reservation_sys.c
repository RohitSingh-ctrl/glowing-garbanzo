#include <stdio.h>
#include <string.h>

struct Bus {
    int busNumber;
    char source[50];
    char destination[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

void displayUserMenu() {
    printf("\n=== Main Menu ===\n");
    printf("1. Book a Ticket\n");
    printf("2. Cancel a Ticket\n");
    printf("3. View All Bus Information\n");
    printf("4. Logout\n");
    printf("Enter your choice: ");
}

void bookTicket(struct Bus buses[], int numBuses) {
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    int busIndex = -1;
    for (int i = 0; i < numBuses; i++) {
        if (buses[i].busNumber == busNumber) {
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1) {
        printf("Bus with Bus Number %d not found.\n", busNumber);
    } else {
        printf("Enter Number of Seats: ");
        int seatsToBook;
        scanf("%d", &seatsToBook);

        if (buses[busIndex].availableSeats < seatsToBook) {
            printf("Sorry, only %d seats are available.\n", buses[busIndex].availableSeats);
        } else {
            buses[busIndex].availableSeats -= seatsToBook;
            printf("Booking successful! %d seats booked on Bus Number %d.\n", seatsToBook, busNumber);
        }
    }
}

void cancelTicket(struct Bus buses[], int numBuses) {
    printf("\nEnter Bus Number: ");
    int busNumber;
    scanf("%d", &busNumber);

    int busIndex = -1;
    for (int i = 0; i < numBuses; i++) {
        if (buses[i].busNumber == busNumber) {
            busIndex = i;
            break;
        }
    }

    if (busIndex == -1) {
        printf("Bus with Bus Number %d not found.\n", busNumber);
    } else {
        printf("Enter Number of Seats to Cancel: ");
        int seatsToCancel;
        scanf("%d", &seatsToCancel);

        if (seatsToCancel > (buses[busIndex].totalSeats - buses[busIndex].availableSeats)) {
            printf("Error: You can't cancel more seats than were booked.\n");
        } else {
            buses[busIndex].availableSeats += seatsToCancel;
            printf("Cancellation successful! %d seats canceled on Bus Number %d.\n", seatsToCancel, busNumber);
        }
    }
}

void displayAllBuses(struct Bus buses[], int numBuses) {
    printf("\n=== All Bus Information ===\n");
    for (int i = 0; i < numBuses; i++) {
        printf("Bus Number: %d\n", buses[i].busNumber);
        printf("Source: %s\n", buses[i].source);
        printf("Destination: %s\n", buses[i].destination);
        printf("Total Seats: %d\n", buses[i].totalSeats);
        printf("Available Seats: %d\n", buses[i].availableSeats);
        printf("Fare: %.2f\n", buses[i].fare);
        printf("------------------------------\n");
    }
}

int main() {
    struct Bus buses[3] = {
        {101, "Dehradun", "Delhi", 50, 50, 500.0},
        {102, "Dehradun", "Rishikesh", 40, 40, 400.0},
        {103, "Dehradun", "Haridwar", 30, 30, 300.0},
    };
    int numBuses = 3;

    while (1) {
        displayUserMenu();
        int userChoice;
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                bookTicket(buses, numBuses);
                break;
            case 2:
                cancelTicket(buses, numBuses);
                break;
            case 3:
                displayAllBuses(buses, numBuses);
                break;
            case 4:
                printf("Logging out.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
