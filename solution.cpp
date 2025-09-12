#include <iostream>
#include <cstring>   // for strlen, strcpy

int NAME_BUFFER = 35; // a good length for a name

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int& capacity) {
    if (size < capacity) {
        names[size] = name;
        gpas[size++] = gpa;
    } else {
        throw "List full.";
    }
}
// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr) {
        *gpaPtr = newGpa;
    }
}
// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
    std::cout << name << "\'s GPA is " << gpa << std::endl;
}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
    if (size == 0) {
        throw "No students.";
    }

    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += gpas[i];
    }
    return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                char* name = new char[NAME_BUFFER];
                double gpa;

                std::cout << "Please enter student name: ";
                std::cin >> name;
                std::cout << "Please enter " << name << "\'s gpa: ";
                std::cin >> gpa;
                try {
                    addStudent(name, gpa, names, gpas, size, capacity);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                    return 1;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int index;
                std::cout << "Please enter the index of the student gpa you wish to update: ";
                std::cin >> index;
                if (index < size && index >= 0) {
                    double gpa;
                    std::cout << "Please enter the gpa you want to change it to: ";
                    std::cin >> gpa;
                    updateGPA(&gpas[index], gpa);
                } else {
                    std::cout << "Invalid Index." << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                for (int i = 0; i < size; i++) {
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    double average = averageGPA(gpas, size);
                    std::cout << "Average GPA: " << static_cast<int>(average) << std::endl;
                } catch (const char* msg) {
                    std::cout <<  msg << std::endl;
                    return 1;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; i++) {
        delete[] names[i];
    }

    return 0;
}
