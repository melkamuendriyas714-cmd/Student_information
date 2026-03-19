#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip> 

using namespace std;

const int MAX_SIZE = 10;
const int STR_LEN = 50;
int p_count = 0;

class StudentType {
private:
    char name[STR_LEN];
    char ID[STR_LEN];
    char Department[STR_LEN];
    int age;
    double gpa;

    bool isAlphaOnly(char str[]) {
        if (strlen(str) == 0) 
	      	return false;
        for (int i = 0; str[i] != '\0'; i++) {
            if (!isalpha(str[i]) && str[i] != ' ') 
			return false;
        }
          return true;
    }

public:
    StudentType();
    
    void setName(char n[]) { 
	strncpy(name, n, STR_LEN); 
	}
    void getName(char out[]) const { 
	strcpy(out, name); 
	}
    void getID(char out[]) const { 
	strcpy(out, ID); 
	}
    int getAge() const {
	 return age; 
	 }
    double getGpa() const {
	 return gpa; 
	}

    void setData();
    void printData(StudentType student[]);
    void sortByID(StudentType student[]);
    void sortByName(StudentType student[]);
    int searchByID(StudentType student[], char key[]);
    void deleteByID(StudentType student[], char key[]);
};

StudentType::StudentType() {
    name[0] = '\0';
    ID[0] = '\0';
    Department[0] = '\0';
    age = 0;
    gpa = 0.0;
}

void StudentType::setData() {
    cin.ignore();
    do {
        cout << "Enter Name (Alphabets only): ";
        cin.getline(name, STR_LEN);
    } while (!isAlphaOnly(name));

    cout << "Enter Student ID: ";
    cin.getline(ID, STR_LEN);
    
    cout << "Enter Student Department: ";
    cin.getline(Department, STR_LEN);

    do {
        cout << "Enter the student Age (0-99): ";
        cin >> age;
    } while (age >= 100 || age < 0);

    do {
        cout << "Enter The Studdent GPA (0-4): ";
        cin >> gpa;
    } while (gpa < 0.0 || gpa > 4.0);
}

void StudentType::printData(StudentType student[]) {
    if (p_count == 0) {
        cout << "\nList is empty.\n";
        return;
    }

   cout << "--------------------------------------------------------------" << endl;
    cout << "\n" << left << setw(15) << "ID" 
         << setw(25) << "Name" 
         << setw(15) << "Age" 
         << "GPA" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < p_count; i++) {
        cout << left << setw(15) << student[i].ID 
             << setw(25) << student[i].name 
             << setw(15) << student[i].age 
             << fixed << setprecision(2) << student[i].gpa << endl;
    }
}


void StudentType::deleteByID(StudentType student[], char key[]) {
    int loc = searchByID(student, key);
    
    if (loc != -1) {
        
        for (int j = loc; j < p_count - 1; j++) {
            student[j] = student[j+1];
        }
        p_count--; 
        cout << "\nStudent with ID " << key << " successfully deleted.\n";
    } else {
        cout << "\nError: Student with ID " << key << " not found.\n";
    }
}


void StudentType::sortByID(StudentType student[]) {
    StudentType temp;
    bool flag;
    for (int i = 0; i < p_count - 1; i++) {
        flag = false;
        for (int j = 0; j < p_count - 1 - i; j++) {
            if (strcmp(student[j].ID, student[j+1].ID) > 0) {
                temp = student[j];
                student[j] = student[j+1];
                student[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) 
		break;
    }
    cout << "\nThe Studen Information is Sorted by ID successfully.\n";
}

void StudentType::sortByName(StudentType student[]) {
    StudentType temp;
    bool flag;
    for (int i = 0; i < p_count - 1; i++) {
        flag = false;
        for (int j = 0; j < p_count - 1 - i; j++) {
            if (strcmp(student[j].name, student[j+1].name) > 0) {
                temp = student[j];
                student[j] = student[j+1];
                student[j+1] = temp;
                flag = true;
            }
        }
        if (!flag) 
		break;
    }
    cout << "\nThe Student Information is Sorted by Name successfully.\n";
}

int StudentType::searchByID(StudentType student[], char key[]) {
    for (int i = 0; i < p_count; i++) {
        if (strcmp(student[i].ID, key) == 0) 
		return i;
    }
       return -1;
}

int main() {
    int choice;
    StudentType studentList[MAX_SIZE];
    StudentType manager; 
    char key[STR_LEN];
cout<<"   \n MELKAMU ENDRIYAS           ID RU1445/17         SECTION 2"<<endl;
    while (true) {
    	
        cout << "\n--- Student Management System ---";
       
        cout<<"\nPress 1 to set person information";
        cout<<"\nPress 2 to print person information";
        cout<<"\nPress 3 to sort person information by ID";
        cout<<"\nPress 4 to sort person information by Name";
        cout<<"\nPress 5 to Search person information by ID";
        cout<<"\nPress 6 to delete person information by ID";
        cout<<"\nPress 0 to Exit";
        cout<<"\n Select Operation : ";
       
        cin >> choice;
        
        if (choice == 0) 
		break;

        switch (choice) {
            case 1:
                if (p_count < MAX_SIZE) {
                    studentList[p_count].setData();
                    p_count++;
                } else 
				   cout << "Error: List is full!\n";
                break;
            case 2: manager.printData(studentList); 
			   break;
            case 3: manager.sortByID(studentList); 
			   break;
            case 4: manager.sortByName(studentList); 
			   break;
            case 5:
                cout << "Search Studednt By ID: "; 
				cin >> key;
                int loc;
                loc = manager.searchByID(studentList, key);
                if (loc != -1) 
				cout << "The Student Found at index " << loc << endl;
                else 
				cout << "The  student at ID is Not found.\n";
                break;
            case 6:
                cout << "Delete The Student ID: "; 
				cin >> key;
                manager.deleteByID(studentList, key);
                break;
            default: 
			cout << "Invalid choice.\n";
        }
    }
    return 0;
}
