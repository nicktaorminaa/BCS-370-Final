/**********************************************************/
/**********PROGRAM: COLLEGE STUDENT SCHEDULING SYSTEM******/
/**********WRITTEN BY: NICHOLAS TAORMINA*******************/
/**********DATE: 5/11/2023*********************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "HomeworkManager.h"
#include "Assignment.h"

using namespace std;


int main() {
    HomeworkManager manager;
    bool exit_program = false;
    Assignment newAssignment;
    string homework = "homework.bin";

    int days;
    while (!exit_program) {
        cout << "Homework Management System\n";
        cout << "--------------------------\n";
        cout << "1. Add Assignment\n";
        cout << "2. Update Assignment\n";
        cout << "3. Search Assignments by days\n";
        cout << "4. Delete Assignment\n";
        cout << "5. Search Assignments by course\n";
        cout << "6. Display All Assignments\n";
        cout << "7. Display All in progress Assignments\n";
        cout << "8. Save Assignments to File\n";
        cout << "9. Load Assignments from File\n";
        cout << "10. Exit Program\n";
        cout << "Please select an option (1-10): ";

        int option;
        cin >> option;

        switch (option) {
        case 1:
            manager.addAssignment(newAssignment);
            break;
        case 2:
        {
            vector<Assignment> searchResults = manager.searchAssignments();
            int index;
            cout << "Enter the index of the assignment to update: ";
            cin >> index;

            if (index >= 0 && index < searchResults.size()) {
                manager.updateAssignment(searchResults[index]);
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;
        case 3:
        {
            cout << "Enter the number of days within which the assignments are due: ";
            cin >> days;
            manager.searchAssignmentsDueWithinDays(days);
        }
        break;
        case 4:
        {
            vector<Assignment> searchResults = manager.searchAssignments();
            int index;
            cout << "Enter the index of the assignment to delete: ";
            cin >> index;

            if (index >= 0 && index < searchResults.size()) {
                manager.deleteAssignment(searchResults[index]);
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        break;
        case 5:
        {
            string course;
            cout << "Enter course name: ";
            cin >> course;
            vector<Assignment> courseAssignments = manager.searchAssignmentsByCourse(course);
            cout << "Assignments for course " << course << ":" << endl;
            break;
        }
        break; 
        case 6:
            manager.displayAllAssignments();
            break;
        case 7: 
            manager.displayInProgressAssignments();
            break;
        case 8:
            manager.saveToFile(homework);
            break;
        case 9:
            manager.loadFromFile(homework);
            break;
        case 10:
            exit_program = true;
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }

        cout << "\nPress Enter to continue...";
        cin.get();
        cout << "\n\n";
    }

    return 0;
}