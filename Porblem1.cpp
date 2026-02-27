#include<iostream>
#include<string>
using namespace std;

struct Employee{
    string empName;
    int empID;
    float salary;
    
    Employee findHighestPaid(Employee *eArr) {
        Employee highest = eArr[0];
        for (int i = 1; i < 5; i++) {
            if (eArr[i].salary > highest.salary) {
                highest = eArr[i];
            }
        }
        return highest;
    }
    Employee* sortByName(Employee *eArr) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4 - i; j++) {
                if (eArr[j].empName > eArr[j + 1].empName) {
                    // Manual swap
                    Employee temp  = eArr[j];
                    eArr[j]        = eArr[j + 1];
                    eArr[j + 1]    = temp;
                }
            }
        }
        return eArr;
    }
   
};

int main() {
// Allocate dynamic array of 5 employees
    Employee *empArray = new Employee[5];
    
    empArray[0] = {"Elon Musk", 101, 95000.0};
    empArray[1] = {"Larry Page", 102, 72000.0};
    empArray[2] = {"Sergey Brin", 103, 48000.0};
    empArray[3] = {"Jeff Bezos", 104, 55000.0};
    empArray[4] = {"Mark Zucketberg",105, 61000.0};

    Employee e;
    
    
//dispaly hihest salary
    Employee highest = e.findHighestPaid(empArray);
    cout << "Highest Paid Employee:" << endl;
    cout << "  Name  : " << highest.empName << endl;
    cout << "  ID    : " << highest.empID   << endl;
    cout << "  Salary: $" << highest.salary << endl;

    cout << endl;
//sort
    Employee *sorted = e.sortByName(empArray);
    cout << "Employees Sorted by Name:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "  " << sorted[i].empName
             << " | ID: " << sorted[i].empID
             << " | Salary: $" << sorted[i].salary << endl;
    }

    delete[] empArray;
    return 0;
}

