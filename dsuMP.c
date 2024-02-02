#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
// Structure for department
typedef struct Department {
    int dept_id;
    char dept_name[50];
} Department;
// Circular Queue for Department Management
typedef struct CircularQueue {
    Department data[MAX];
    int front, rear, itemCount;
} CircularQueue;
void initializeQueue(CircularQueue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->itemCount = 0;
}
int isQueueEmpty(CircularQueue* queue) {
    return (queue->itemCount == 0);
}
int isQueueFull(CircularQueue* queue) {
    return (queue->itemCount == MAX);
}
void enqueue(CircularQueue* queue, Department newItem) {
    if (isQueueFull(queue)) {
        printf("Department queue is full. Cannot add more departments.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = newItem;
    queue->itemCount++;
    printf("Department added successfully.\n");
}
// Function to dequeue an element from the queue
void dequeue(CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Department queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleting the department with ID: %d\n", queue->data[queue->front].dept_id);

    // Move the front index to the next element
    queue->front = (queue->front + 1) % MAX;
    queue->itemCount--;

    if (queue->front == -1) {
        // If the queue becomes empty, reset rear to -1 as well
        queue->rear = -1;
    }
}

void displayDepartments(CircularQueue* queue) {
    if (isQueueEmpty(queue)) {
        printf("No departments to display.\n");
        return;
    }

    printf("Displaying departments:\n");
    int i = queue->front;
    int count = 0;
    do {
        Department currentDept = queue->data[i];
        printf("Department ID: %d, Name: %s\n", currentDept.dept_id, currentDept.dept_name);
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);
}

void searchDepartment(CircularQueue* queue, int searchID) {
    if (isQueueEmpty(queue)) {
        printf("No departments to search.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        Department currentDept = queue->data[i];
        if (currentDept.dept_id == searchID) {
            printf("Department found:\n");
            printf("Department ID: %d, Name: %s\n", currentDept.dept_id, currentDept.dept_name);
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Department not found.\n");
}
void updateDepartment(CircularQueue* queue, int id) {
    if (isQueueEmpty(queue)) {
        printf("No departments to update.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        Department* currentDept = &queue->data[i];
        if (currentDept->dept_id == id) {
            printf("Enter new department name: ");
            scanf("%s", currentDept->dept_name);
            printf("Department updated successfully.\n");
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Department not found.\n");
}

void departmentSubMenu(CircularQueue* queue) {
    int searchID;
    int choice;
    Department newDept;

    do {
        printf("\nDepartment Management\n");
        printf("1. Add Department\n");
        printf("2. Display Departments\n");
        printf("3. Search Department\n");
        printf("4. Update Department\n");
        printf("5. Delete Department\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter department ID: ");
                scanf("%d", &newDept.dept_id);
                printf("Enter department name: ");
                scanf("%s", newDept.dept_name);
                enqueue(queue, newDept);
                break;
            case 2:
                displayDepartments(queue);
                break;
            case 3:
                printf("Enter department ID to search: ");
                scanf("%d", &searchID);
                searchDepartment(queue, searchID);
                break;
            case 4:
                printf("Enter department ID to update: ");
                scanf("%d", &searchID);
                updateDepartment(queue, searchID);
                break;
            case 5:
                dequeue(queue);
                break;
            case 6:
                printf("Exiting the department management.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);
}
// Structure for staff
typedef struct Staff {
    int staff_id;
    char staff_name[50];
} Staff;

// Circular Queue for Staff Management
typedef struct CircularQueueStaff {
    Staff data[MAX];
    int front, rear, itemCount;
} CircularQueueStaff;

void initializeQueueStaff(CircularQueueStaff* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->itemCount = 0;
}

int isQueueEmptyStaff(CircularQueueStaff* queue) {
    return (queue->itemCount == 0);
}

int isQueueFullStaff(CircularQueueStaff* queue) {
    return (queue->itemCount == MAX);
}

void enqueueStaff(CircularQueueStaff* queue, Staff newItem) {
    if (isQueueFullStaff(queue)) {
        printf("Staff queue is full. Cannot add more staff members.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = newItem;
    queue->itemCount++;
    printf("Staff member added successfully.\n");
}

void dequeueStaff(CircularQueueStaff* queue) {
    if (isQueueEmptyStaff(queue)) {
        printf("Staff queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleting the staff member with ID: %d\n", queue->data[queue->front].staff_id);

    queue->front = (queue->front + 1) % MAX;
    queue->itemCount--;

    if (queue->front == -1) {
        queue->rear = -1;
    }
}

void displayStaff(CircularQueueStaff* queue) {
    if (isQueueEmptyStaff(queue)) {
        printf("No staff members to display.\n");
        return;
    }

    printf("Displaying staff members:\n");
    int i = queue->front;
    int count = 0;
    do {
        Staff currentStaff = queue->data[i];
        printf("Staff ID: %d, Name: %s\n", currentStaff.staff_id, currentStaff.staff_name);
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);
}

void searchStaff(CircularQueueStaff* queue, int searchID) {
    if (isQueueEmptyStaff(queue)) {
        printf("No staff members to search.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        Staff currentStaff = queue->data[i];
        if (currentStaff.staff_id == searchID) {
            printf("Staff member found:\n");
            printf("Staff ID: %d, Name: %s\n", currentStaff.staff_id, currentStaff.staff_name);
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Staff member not found.\n");
}

void updateStaff(CircularQueueStaff* queue, int id) {
    if (isQueueEmptyStaff(queue)) {
        printf("No staff members to update.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        Staff* currentStaff = &queue->data[i];
        if (currentStaff->staff_id == id) {
            printf("Enter new staff member name: ");
            scanf("%s", currentStaff->staff_name);
            printf("Staff member updated successfully.\n");
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Staff member not found.\n");
}

void staffSubMenu(CircularQueueStaff* queue) {
    int searchID;
    int choice;
    Staff newStaff;

    do {
        printf("\nStaff Management\n");
        printf("1. Add Staff Member\n");
        printf("2. Display Staff Members\n");
        printf("3. Search Staff Member\n");
        printf("4. Update Staff Member\n");
        printf("5. Delete Staff Member\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter staff member ID: ");
                scanf("%d", &newStaff.staff_id);
                printf("Enter staff member name: ");
                scanf("%s", newStaff.staff_name);
                enqueueStaff(queue, newStaff);
                break;
            case 2:
                displayStaff(queue);
                break;
            case 3:
                printf("Enter staff member ID to search: ");
                scanf("%d", &searchID);
                searchStaff(queue, searchID);
                break;
            case 4:
                printf("Enter staff member ID to update: ");
                scanf("%d", &searchID);
                updateStaff(queue, searchID);
                break;
            case 5:
                dequeueStaff(queue);
                break;
            case 6:
                printf("Exiting the staff management.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);
}
// Structure for personal details
typedef struct PersonalDetails {
    int id;
    char name[50];
    char address[100];
    int age;
} PersonalDetails;

// Circular Queue for Personal Details Management
typedef struct CircularQueuePersonal {
    PersonalDetails data[MAX];
    int front, rear, itemCount;
} CircularQueuePersonal;

void initializeQueuePersonal(CircularQueuePersonal* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->itemCount = 0;
}

int isQueueEmptyPersonal(CircularQueuePersonal* queue) {
    return (queue->itemCount == 0);
}

int isQueueFullPersonal(CircularQueuePersonal* queue) {
    return (queue->itemCount == MAX);
}

void enqueuePersonal(CircularQueuePersonal* queue, PersonalDetails newItem) {
    if (isQueueFullPersonal(queue)) {
        printf("Personal details queue is full. Cannot add more records.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = newItem;
    queue->itemCount++;
    printf("Personal details added successfully.\n");
}

void dequeuePersonal(CircularQueuePersonal* queue) {
    if (isQueueEmptyPersonal(queue)) {
        printf("Personal details queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleting the record with ID: %d\n", queue->data[queue->front].id);

    queue->front = (queue->front + 1) % MAX;
    queue->itemCount--;

    if (queue->front == -1) {
        queue->rear = -1;
    }
}

void displayPersonal(CircularQueuePersonal* queue) {
    if (isQueueEmptyPersonal(queue)) {
        printf("No records to display.\n");
        return;
    }

    printf("Displaying personal details:\n");
    int i = queue->front;
    int count = 0;
    do {
        PersonalDetails currentRecord = queue->data[i];
        printf("ID: %d, Name: %s, Address: %s, Age: %d\n", currentRecord.id, currentRecord.name, currentRecord.address, currentRecord.age);
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);
}

void searchPersonal(CircularQueuePersonal* queue, int searchID) {
    if (isQueueEmptyPersonal(queue)) {
        printf("No records to search.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        PersonalDetails currentRecord = queue->data[i];
        if (currentRecord.id == searchID) {
            printf("Record found:\n");
            printf("ID: %d, Name: %s, Address: %s, Age: %d\n", currentRecord.id, currentRecord.name, currentRecord.address, currentRecord.age);
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Record not found.\n");
}

void updatePersonal(CircularQueuePersonal* queue, int id) {
    if (isQueueEmptyPersonal(queue)) {
        printf("No records to update.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        PersonalDetails* currentRecord = &queue->data[i];
        if (currentRecord->id == id) {
            printf("Enter new name: ");
            scanf("%s", currentRecord->name);
            printf("Enter new address: ");
            scanf("%s", currentRecord->address);
            printf("Enter new age: ");
            scanf("%d", &currentRecord->age);
            printf("Record updated successfully.\n");
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Record not found.\n");
}

void personalSubMenu(CircularQueuePersonal* queue) {
    int searchID;
    int choice;
    PersonalDetails newRecord;

    do {
        printf("\nPersonal Details Management\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Update Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &newRecord.id);
                printf("Enter name: ");
                scanf("%s", newRecord.name);
                printf("Enter address: ");
                scanf("%s", newRecord.address);
                printf("Enter age: ");
                scanf("%d", &newRecord.age);
                enqueuePersonal(queue, newRecord);
                break;
            case 2:
                displayPersonal(queue);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &searchID);
                searchPersonal(queue, searchID);
                break;
            case 4:
                printf("Enter ID to update: ");
                scanf("%d", &searchID);
                updatePersonal(queue, searchID);
                break;
            case 5:
                dequeuePersonal(queue);
                break;
            case 6:
                printf("Exiting the personal details management.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);
}

// Structure for Leave Record
typedef struct LeaveRecord {
    int employee_id;
    int leave_days;
} LeaveRecord;

// Circular Queue for Leave Record Management
typedef struct CircularQueueLeaveRecord {
    LeaveRecord data[MAX];
    int front, rear, itemCount;
} CircularQueueLeaveRecord;

void initializeQueueLeaveRecord(CircularQueueLeaveRecord* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->itemCount = 0;
}

int isQueueEmptyLeaveRecord(CircularQueueLeaveRecord* queue) {
    return (queue->itemCount == 0);
}

int isQueueFullLeaveRecord(CircularQueueLeaveRecord* queue) {
    return (queue->itemCount == MAX);
}

void enqueueLeaveRecord(CircularQueueLeaveRecord* queue, LeaveRecord newItem) {
    if (isQueueFullLeaveRecord(queue)) {
        printf("Leave record queue is full. Cannot add more records.\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = newItem;
    queue->itemCount++;
    printf("Leave record added successfully.\n");
}

void dequeueLeaveRecord(CircularQueueLeaveRecord* queue) {
    if (isQueueEmptyLeaveRecord(queue)) {
        printf("Leave record queue is empty. Cannot delete.\n");
        return;
    }

    printf("Deleting the leave record for employee with ID: %d\n", queue->data[queue->front].employee_id);

    queue->front = (queue->front + 1) % MAX;
    queue->itemCount--;

    if (queue->front == -1) {
        queue->rear = -1;
    }
}

void displayLeaveRecord(CircularQueueLeaveRecord* queue) {
    if (isQueueEmptyLeaveRecord(queue)) {
        printf("No leave records to display.\n");
        return;
    }

    printf("Displaying leave records:\n");
    int i = queue->front;
    int count = 0;
    do {
        LeaveRecord currentRecord = queue->data[i];
        printf("Employee ID: %d, Leave Days: %d\n", currentRecord.employee_id, currentRecord.leave_days);
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);
}

void searchLeaveRecord(CircularQueueLeaveRecord* queue, int searchID) {
    if (isQueueEmptyLeaveRecord(queue)) {
        printf("No leave records to search.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        LeaveRecord currentRecord = queue->data[i];
        if (currentRecord.employee_id == searchID) {
            printf("Leave record found:\n");
            printf("staff ID: %d, Leave Days: %d\n", currentRecord.employee_id, currentRecord.leave_days);
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Leave record not found.\n");
}

void updateLeaveRecord(CircularQueueLeaveRecord* queue, int id) {
    if (isQueueEmptyLeaveRecord(queue)) {
        printf("No leave records to update.\n");
        return;
    }

    int i = queue->front;
    int count = 0;
    do {
        LeaveRecord* currentRecord = &queue->data[i];
        if (currentRecord->employee_id == id) {
            printf("Enter new leave days: ");
            scanf("%d", &currentRecord->leave_days);
            printf("Leave record updated successfully.\n");
            return;
        }
        i = (i + 1) % MAX;
        count++;
    } while (count < queue->itemCount);

    printf("Leave record not found.\n");
}

void leaveRecordSubMenu(CircularQueueLeaveRecord* queue) {
    int searchID;
    int choice;
    LeaveRecord newRecord;

    do {
        printf("\nLeave Record Management\n");
        printf("1. Add Leave Record\n");
        printf("2. Display Leave Records\n");
        printf("3. Search Leave Record\n");
        printf("4. Update Leave Record\n");
        printf("5. Delete Leave Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Staff ID: ");
                scanf("%d", &newRecord.employee_id);
                printf("Enter leave days: ");
                scanf("%d", &newRecord.leave_days);
                enqueueLeaveRecord(queue, newRecord);
                break;
            case 2:
                displayLeaveRecord(queue);
                break;
            case 3:
                printf("Enter Staff ID to search: ");
                scanf("%d", &searchID);
                searchLeaveRecord(queue, searchID);
                break;
            case 4:
                printf("Enter Staff ID to update: ");
                scanf("%d", &searchID);
                updateLeaveRecord(queue, searchID);
                break;
            case 5:
                dequeueLeaveRecord(queue);
                break;
            case 6:
                printf("Exiting the leave record management.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (choice != 6);
}

int main() {
    CircularQueue deptQueue;
    initializeQueue(&deptQueue);
    CircularQueueStaff staffQueue;
    initializeQueueStaff(&staffQueue);
    CircularQueuePersonal personalQueue;
    initializeQueuePersonal(&personalQueue);
    CircularQueueLeaveRecord leaveRecordQueue;
    initializeQueueLeaveRecord(&leaveRecordQueue);

    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Department Management\n");
        printf("2. Staff Management\n");
        printf("3. Personal Details Management\n");
        printf("4. Leave Record Management\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                departmentSubMenu(&deptQueue);
                break;
            case 2:
                staffSubMenu(&staffQueue);
                break;
            case 3:
                personalSubMenu(&personalQueue);
                break;
            case 4:
                leaveRecordSubMenu(&leaveRecordQueue);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}