#include <iostream>
#include <string>
using namespace std;

int main()
{
    struct Student
    {
        int studID;
        string studName;
        string studCourse;
        int age;
    };

    Student student[5];

    student[0] = {24006291, "Jessy", "Computer Science", 20};
    student[1] = {24006292, "Chua", "Information Technology", 19};
    student[2] = {24006293, "Bob", "Business Management", 21};
    student[3] = {24006294, "Alice", "Chemical Engineering", 20};
    student[4] = {24006295, "Charlie", "Petroleum Engineering", 22};

    cout << "===== STUDENT RECORDS =====" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "----- Student " << i + 1 << " -----" << endl;
        cout << "ID: " << student[i].studID << endl;
        cout << "Name: " << student[i].studName << endl;
        cout << "Course: " << student[i].studCourse << endl;
        cout << "Age: " << student[i].age << endl;
    }

    int searchID;
    int studIndex = -1;

    cout << "\n===== SEARCH STUDENT =====" << endl;
    cout << "Enter Student ID to search: ";
    cin >> searchID;
    cin.ignore();

    for (int i = 0; i < 5; i++)
    {
        if (student[i].studID == searchID)
        {
            studIndex = i;
            break;
        }
    }

    if (studIndex != -1)
    {
        cout << "\n--- Student Found ---" << endl;
        cout << "ID: " << student[studIndex].studID << endl;
        cout << "Name: " << student[studIndex].studName << endl;
        cout << "Course: " << student[studIndex].studCourse << endl;
        cout << "Age: " << student[studIndex].age << endl;
        cout << endl;
    }
    else
    {
        cout << "Student ID " << searchID << " not found." << endl;
    }

    int updateID;
    int updateIndex = -1;

    cout << "\n===== UPDATE STUDENT RECORD =====" << endl;
    cout << "Enter Student ID to update: ";
    cin >> updateID;
    cin.ignore();

    for (int i = 0; i < 5; i++)
    {
        if (student[i].studID == updateID)
        {
            updateIndex = i;
            break;
        }
    }

    if (updateIndex != -1)
    {
        cout << "\nUpdating Student ID " << updateID << "..." << endl;

        cout << "Enter new name: ";
        getline(cin, student[updateIndex].studName);

        cout << "Enter new course: ";
        getline(cin, student[updateIndex].studCourse);

        cout << "Enter new age: ";
        cin >> student[updateIndex].age;

        cout << "\n--- Updated Record ---" << endl;
        cout << "ID: " << student[updateIndex].studID << endl;
        cout << "Name: " << student[updateIndex].studName << endl;
        cout << "Course: " << student[updateIndex].studCourse << endl;
        cout << "Age: " << student[updateIndex].age << endl;
    }
    else
    {
        cout << "Student ID " << updateID << " not found." << endl;
    }

    return 0;
}