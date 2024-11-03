#pragma once
class Assignment {
private:
    string name;
    string course;
    string dueDate;
    string dueTime;
    int estimatedTime;
    double weight;
    bool isCompleted;
public:
    Assignment() {
        name = "";
        course = "";
        dueDate = "";
        dueTime = "";
        estimatedTime = 0;
        weight = 0.0;
        isCompleted = false;
    }
    Assignment(string n, string c, string dd, string dt, int et, double w) {
        name = n;
        course = c;
        dueDate = dd;
        dueTime = dt;
        estimatedTime = et;
        weight = w;
        isCompleted = false;
    }
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Due Time: " << dueTime << endl;
        cout << "Estimated Time: " << estimatedTime << endl;
        cout << "Weight: " << weight << endl;
        if (isCompleted) {
            cout << "Status: Completed" << endl;
        }
        else {
            cout << "Status: In Progress" << endl;
        }
        cout << endl;
    }
    bool isDueWithinDays(int days) const {
        time_t currentTime = time(nullptr);
        tm* currentDate = localtime(&currentTime);
        std::stringstream ss(getDueDate());
        tm dueDate = {};
        ss >> std::get_time(&dueDate, "%Y-%m-%d");
        int difference = (int)difftime(mktime(&dueDate), mktime(currentDate)) / (24 * 3600);
        return difference >= 0 && difference <= days;
    }

    bool operator<(const Assignment& a) const {
        return dueDate < a.dueDate;
    }
    bool operator==(const Assignment& a) const {
        return name == a.name && course == a.course && dueDate == a.dueDate && dueTime == a.dueTime;
    }
  
    string getName() const {
        return name;
    }
    string getCourse() const {
        return course;
    }
    string getDueDate() const {
        return dueDate;
    }
    string getDueTime() const {
        return dueTime;
    }
    int getEstimatedTime() const {
        return estimatedTime;
    }
    double getWeight() const {
        return weight;
    }
    bool getisCompleted() const {
        return isCompleted;
    }


    void setName(string n) {
        name = n;
    }
    void setCourse(string c) {
        course = c;
    }
    void setDueDate(string dd) {
        dueDate = dd;
    }
    void setDueTime(string dt) {
        dueTime = dt;
    }
    void setEstimatedTime(int et) {
        estimatedTime = et;
    }
    void setWeight(double w) {
        weight = w;
    }
    void setCompleted(bool c) {
        isCompleted = c;
    }
};
