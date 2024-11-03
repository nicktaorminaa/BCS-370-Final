#pragma once
class HomeworkManager {
private:
    vector<Assignment> assignments;
    int getAssignmentIndexByName(const string& name) {
        for (int i = 0; i < assignments.size(); i++) {
            if (assignments[i].getName() == name) {
                return i;
            }
        }
        return -1;  
    }

    void searchAssignmentsDueWithinDaysHelper(const int days, const int currentIndex, vector<Assignment>& result) {
        if (currentIndex == assignments.size()) {
            return;
        }
        const auto& currentAssignment = assignments[currentIndex];
        if (currentAssignment.isDueWithinDays(days)) {
            result.push_back(currentAssignment);
        }
        searchAssignmentsDueWithinDaysHelper(days, currentIndex + 1, result);
    }

public:
    void addAssignment(Assignment& assignment) {
        assignments.push_back(assignment);
    }
   
    void updateAssignment(const Assignment& assignment) {
        const int index = getAssignmentIndexByName(assignment.getName());
        if (index >= 0 && index < assignments.size())
        { 
            assignments[index] = assignment;
        }
    }

    void displayAllAssignments() const {
        if (assignments.empty()) {
            cout << "No assignments found.\n";
            return;
        }
        cout << "All Assignments:\n";
        cout << "----------------\n";
        for (const auto& assignment : assignments) {
            assignment.display();
            cout << endl;
        }
    }

    void deleteAssignment(const Assignment& assignmentToDelete) {
        for (auto it = assignments.begin(); it != assignments.end(); ++it) {
            if (*it == assignmentToDelete) {
                assignments.erase(it);
                return;
            }
        }
    }


    vector<Assignment> searchAssignments() const {
        return assignments;
    }
    
    vector<Assignment> searchAssignmentsDueWithinDays(const int days) {
        vector<Assignment> result;
        searchAssignmentsDueWithinDaysHelper(days, 0, result);
        return result;
    }

    vector<Assignment> searchAssignmentsByCourse(const string& course) {
        vector<Assignment> result;
        for (const auto& assignment : assignments) {
            if (assignment.getCourse() == course) {
                result.push_back(assignment);
            }
        }
        return result;
    }

    vector<Assignment> searchInProgressAssignments() {
        vector<Assignment> result;
        for (const auto& assignment : assignments) {
            if (!assignment.getisCompleted()) {
                result.push_back(assignment);
            }
        }
        return result;
    }

    void displayInProgressAssignments() {
        vector<Assignment> inProgressAssignments = searchInProgressAssignments();

        if (inProgressAssignments.empty()) {
            cout << "There are no in progress assignments." << endl;
            return;
        }

        cout << "In progress assignments:" << endl;
        for (const Assignment& assignment : inProgressAssignments) {
            cout << assignment.getName() << " - Due on: " << assignment.getDueDate() << endl;
        }
    }
    void saveToFile(const string& homework) {
      
        ofstream outFile(homework, ios::binary);
        if (!outFile) {
            cout << "Error: Unable to open file " << homework << endl;
            return;
        }
        for (const auto& assignment : assignments) {
            outFile.write(reinterpret_cast<const char*>(&assignment), sizeof(assignment));
        }
        outFile.close();
    }

    void loadFromFile(const string& homework) {

        ifstream inFile(homework, ios::binary);
        if (!inFile) {
            cout << "Error: Unable to open file " << homework << endl;
            return;
        }
        assignments.clear();
        Assignment assignment;
        while (inFile.read(reinterpret_cast<char*>(&assignment), sizeof(assignment))) {
            assignments.push_back(assignment);
        }
        inFile.close();
    }
};