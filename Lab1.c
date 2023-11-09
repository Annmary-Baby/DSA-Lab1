#include <stdio.h>
#include <stdlib.h>

#define EMPLOYEES 3

struct employeeStruct
{
    char employee_name[25];
    int employee_id;
    float salary;
};

struct employeeStruct employees[EMPLOYEES];

void insertionDisplay();
int removeEmployee(int id);
void displayEmployees();
int findEmployee(int id);
void hireEmployee();
void hrMenu();

int main()
{
    int choice, id;
    int continueMenu = 1;

    while (continueMenu)
    {
        hrMenu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter Employee Details:\n");
            insertionDisplay();
            break;
        case 2:
            printf("Enter Employee ID to Remove: ");
            scanf("%d", &id);
            removeEmployee(id);
            break;
        case 3:
            displayEmployees();
            break;
        case 4:
            printf("Enter Employee ID to Find: ");
            scanf("%d", &id);
            findEmployee(id);
            break;
        case 5:
            printf("----------------HIRE NEW EMPLOYEE----------------------\n");
            hireEmployee();
            break;
        case 0:
            continueMenu = 0;
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void hireEmployee()
{
    printf("Enter Employee Details:\n");
    int i;
    for (i = 0; i < EMPLOYEES; ++i)
    {
        if (employees[i].employee_id == 0)
        {
            printf("Name: ");
            scanf("%s", &employees[i].employee_name);
            printf("Employee ID: ");
            scanf("%d", &employees[i].employee_id);
            printf("Salary: ");
            scanf("%f", &employees[i].salary);
            printf("Employee hired successfully!\n");
            return;
        }
    }

    printf("Maximum employee capacity reached. Cannot hire more employees.\n");
}

void hrMenu()
{
    printf("----------------------HR_Management_System---------------------------\n");
    printf("Enter your Choice (1: Add Employee, 2: Remove Employee, 3: Display Employees, 4: Find Employee, 5: Hire Employee, 0: Exit): ");
}

void insertionDisplay()
{
    for (int i = 0; i < EMPLOYEES; i++)
    {
        printf("Name: ");
        scanf("%s", &employees[i].employee_name);
        printf("Employee ID: ");
        scanf("%d", &employees[i].employee_id);
        printf("Salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("----------------------Employee Details---------------------------\n");
    displayEmployees();
}

int removeEmployee(int id)
{
    for (int i = 0; i < EMPLOYEES; i++)
    {
        if (employees[i].employee_id == id)
        {
            employees[i].employee_id = 0; // Mark the employee as removed
            printf("Employee with ID %d removed successfully!\n", id);
            return 0;
        }
    }

    printf("No employee found with ID %d.\n", id);
    return 0;
}

void displayEmployees()
{
    printf("----------------------Employee List---------------------------\n");
    for (int i = 0; i < EMPLOYEES; i++)
    {
        if (employees[i].employee_id != 0)
        {
            printf("Name: %s | ID: %d | Salary: %.2f\n", employees[i].employee_name, employees[i].employee_id, employees[i].salary);
        }
    }
}

int findEmployee(int id)
{
    printf("----------------------------Finding Employee----------------------------------\n");

    for (int i = 0; i < EMPLOYEES; i++)
    {
        if (employees[i].employee_id == id)
        {
            printf("Employee found: %s | ID: %d | Salary: %.2f\n", employees[i].employee_name, employees[i].employee_id, employees[i].salary);
            return 0;
        }
    }

    printf("No employee found with ID %d.\n", id);
    return 0;
}