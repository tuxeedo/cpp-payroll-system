
#include <iostream>
#include <windows.h>
#include <unistd.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>
#include <fstream>


#include <string>
#include <cctype>
#include <conio.h> // for _getch()
#include <windows.h> // for Sleep()

#include <iostream>
#include <fstream>
#include <iomanip> // For std::setw and std::left
#include <unistd.h> // For sleep function



using namespace std;

class Employee_management {
private:
    char name[30];
    char id[5];
    char designation[10];
    int age, ctc, working_hours, loan_amount;
    char experience[20];
   
public:
    void menu();
    void waitForEnter();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
    void generatePayslip(const char* emp_id);
   
};



void Employee_management::menu()
{
    int password_user();
    password_user();
    while(true)
    {
        int choice;
        char x;
        system("cls");
        cout << "\n\t\t\t-------------------------------------------------------";
        cout << "\n\t\t\t>>               PAYROLL MANAGEMENT SYSTEM            <<";
        cout << "\n\t\t\t-------------------------------------------------------";
        cout << "\n\t\t\t\t 1. Enter New Record " <<endl;
        cout << "\n\t\t\t\t 2. Display Record " <<endl;
        cout << "\n\t\t\t\t 3. Modify Record " <<endl;
        cout << "\n\t\t\t\t 4. Search Record " <<endl;
        cout << "\n\t\t\t\t 5. Delete Record " <<endl;
        cout << "\n\t\t\t\t 6. Generate Payslip " <<endl;
        cout << "\n\t\t\t\t 7. Exit " <<endl;
       
        cout << "\n\t\t\t......................................................." << endl;
        cout << "\n\t\t\t>>     Choose Option: [1/2/3/4/5/6/7]     <<" <<endl;
        cout << "\n\t\t\t......................................................." << endl;
        cout << "\n Enter Your Choice : ";
        cin >> choice;
   
        switch(choice)
        {
            case 1:
                do {
                    insert();
                    cout << "\n\n\t\t\t Add Another Employee Record Press (Y, N) : ";
                    cin >> x;
                } while(x == 'y' || x == 'Y');
                waitForEnter();
                break;
            case 2:
                display();
                break;
            case 3:
                modify();
                break;
            case 4:
                search();
                break;
            case 5:
                deleted();
                break;
            case 6:
                {
                    char emp_id[5];
                    cout << "\nEnter Employee ID to generate payslip: ";
                    cin >> emp_id;
                    generatePayslip(emp_id);
                }
                break;
            case 7:
                system("cls");
                cout << "\n\n\n\n\t--------------------------------------------------------------------------"<<endl;
                cout << "\n\t\t\t>> PAYROLL MANAGEMENT SYSTEM - By Abhishek Developer <<";
                cout << "\n\n\t--------------------------------------------------------------------------"<<endl;
                for(int i=10; i>=1; i--) {
                    cout << i << " Second remaining...\r" << flush;
                    sleep(1);
                }
                exit(0);
                break;
            default:
                cout << "\n\n\n\t\t\t\t Invalid Choice... Please Try Again... \n";
        }
        getch();
    }
}






void Employee_management::insert()
{
    system("cls");
    fstream file;
    bool idExists = false;
    
    cout << "\n--------------------------------------------------------------------------" << endl;
    cout << "--------------------------------Insert Employee Data----------------------" << endl;

    // Collect new employee data
    cout << "\n Enter Name of Employee : ";
    cin >> name;

    // Check for unique Employee ID
    while (true) {
        cout << "\n Enter Employee ID [max 4 digits] : ";
        cin >> id;

        // Open file for reading
        file.open("Employee_Record.txt", ios::in);
        if (file.is_open()) {
            char fileName[30], fileId[5], fileDesignation[10], fileexperience[20];
            int fileAge, fileCTC;
            int fileworking_hours; // Added to match with working hours in file
            float fileloan_amount; // Added to match with loan amount in file

            idExists = false; // Reset ID existence flag
            while (file >> fileName >> fileId >> fileDesignation >> fileAge >> fileCTC >> fileworking_hours >> fileloan_amount >> fileexperience) {
                if (strcmp(id, fileId) == 0) {
                    idExists = true;
                    break;
                }
            }
            file.close(); // Close the file after reading
        }

        if (idExists) {
            cout << "\nEmployee ID already exists. Please enter a unique ID.";
        } else {
            break; // Exit loop if ID is unique
        }
    }

    // Continue collecting other employee data
    cout << "\n Enter Designation : ";
    cin >> designation;
    cout << "\n Enter Employee Age : ";
    cin >> age;
    cout << "\n Enter Employee Hourly Rate : ";
    cin >> ctc;
    cout << "\n Enter Employee Experience : ";
    cin >> experience;
    cout << "\n Enter Working Hours : ";
    cin >> working_hours; // Added input for working hours
    cout << "\n Enter Loan Amount : "; // Added prompt for loan amount
    cin >> loan_amount; // Added input for loan amount

    // Proceed to insert the new record
    file.open("Employee_Record.txt", ios::app | ios::out);
    if (file.is_open()) {
        file << name << " " << id << " " << designation << " " << age << " " << ctc << " " << working_hours << " " << loan_amount << " " << experience << "\n";
        file.close(); // Close the file after writing
    } else {
        cout << "\nUnable to open file for appending.";
        waitForEnter();
        return;
    }

    cout << "\nEmployee record added successfully!";
    waitForEnter();
}





using namespace std;

void Employee_management::display()
{
    system("cls");
    int total = 1;
    fstream file;
    
    cout << "\n\t\t\t\t-------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t-------------------------- Record Employee Data -------------------" << endl;
    
    file.open("Employee_Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t No Data is Present...";
        file.close();
        return; // Exit the function if file could not be opened
    }

    // Read the first line
    file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience;   // ctc means Hourly Rate
    
    // Header for the table
    cout << "\n-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|| " << setw(20) << left << "NAME" 
         << "|| " << setw(10) << left << "ID" 
         << "|| " << setw(20) << left << "DESIGNATION" 
         << "|| " << setw(5) << left << "AGE" 
         << "|| " << setw(15) << left << "Hourly Rate" 
         << "|| " << setw(18) << left << "WORKING HOURS" 
         << "|| " << setw(15) << left << "LOAN AMOUNT" 
         << "|| " << setw(10) << left << "EXPERIENCE" 
         << "||" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

    // Displaying the records
    while (file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience)
    {
        cout << "|| " << setw(20) << left << name 
             << "|| " << setw(10) << left << id 
             << "|| " << setw(20) << left << designation 
             << "|| " << setw(5) << left << age 
             << "|| " << setw(15) << left << ctc 
             << "|| " << setw(18) << left << working_hours 
             << "|| " << setw(15) << left << loan_amount 
             << "|| " << setw(10) << left << experience 
             << "||" << endl;
    }

    // Cleanup
    cout << "\n\n\n";
    for (int i = 10; i >= 1; i--) {
        cout << i << " Second remaining...\r" << flush;
        sleep(1);
    }
    
    file.close();
    waitForEnter();
}




void Employee_management::modify()
{
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;
    bool idExists = false; // Variable to check if new ID already exists
   
    cout << "\n------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Modify Employee Data -------------------------------" << endl;
   
    file.open("Employee_Record.txt", ios::in);
    if (!file) {
        cout << "\n\t\t No Data is Present....";
        file.close();
        waitForEnter();
        return;
    }
   
    cout << "\nEnter Employee ID to Modify: ";
    cin >> checkId;
   
    file1.open("temp_record.txt", ios::out);  // Open a temporary file for writing

    if (!file1) {
        cout << "\n\t\t Unable to open temporary file for writing...";
        file.close();
        waitForEnter();
        return;
    }

    file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience;
    while (!file.eof()) {
        if (strcmp(checkId, id) == 0) {
            // Found the record to modify
            cout << "\n Enter New Name of Employee: ";
            cin >> name;
            
            // Check if new Employee ID already exists
            while (true) {
                cout << "\n Enter New Employee ID [max 4 digits]: ";
                cin >> id;
                
                // Check if the ID already exists in the file
                fstream checkFile;
                checkFile.open("Employee_Record.txt", ios::in);
                if (!checkFile) {
                    cout << "\n\t\t Unable to open file for checking ID...";
                    file.close();
                    file1.close();
                    waitForEnter();
                    return;
                }

                char tempName[30], tempId[5], tempDesignation[10], tempexperience[20];
                int tempAge, tempCTC;
                int tempworking_hours; 
                float temploan_amount;

                bool idFound = false;
                while (checkFile >> tempName >> tempId >> tempDesignation >> tempAge >> tempCTC >> tempworking_hours >> temploan_amount >> tempexperience) {
                    if (strcmp(id, tempId) == 0) {
                        idFound = true;
                        break;
                    }
                }
                checkFile.close();

                if (!idFound || strcmp(id, checkId) == 0) {
                    break; // ID is either unique or the same as the old ID
                }

                cout << "\nEmployee ID already exists. Please enter a unique ID.";
            }

            cout << "\n Enter New Designation: ";
            cin >> designation;
            cout << "\n Enter New Employee Age: ";
            cin >> age;
            cout << "\n Enter New Employee Hourly Rate: ";
            cin >> ctc;
            cout << "\n Enter New Working Hours: ";
            cin >> working_hours;
            cout << "\n Enter New Loan Amount: ";
            cin >> loan_amount;
            cout << "\n Enter New Employee Experience: ";
            cin >> experience;
            cout << "\n\n Successfully Modified Details of Employee";
            found++;
        }
       
        // Write the current record (whether modified or not) to the temporary file
        file1 << name << " " << id << " " << designation << " " << age << " " << ctc << " " << working_hours << " " << loan_amount << " " << experience << "\n";
        file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience;
    }
   
    if (found == 0) {
        cout << "\n\n\t Employee ID Not Found... Please Try again";
    }
   
    file.close();
    file1.close();
   
    // Remove the old file and rename the temporary file to the old file's name
    remove("Employee_Record.txt");
    rename("temp_record.txt", "Employee_Record.txt");
   
    waitForEnter();
}






void Employee_management::search() {
    system("cls");
    fstream file;
    char checkId[5];
    char checkName[30];
    int choice;

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------ Search Employee Data -------------------------------------" << endl;
    cout << "\n\n Search by: " << endl;
    cout << "1. Employee ID" << endl;
    cout << "2. Employee Name" << endl;
    cout << "\n Enter Your Choice (1/2): ";
    cin >> choice;

    file.open("Employee_Record.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t No Data is Present... ";
        waitForEnter();
        return;
    }

    switch (choice) {
        case 1:
            cout << "\n Enter Employee ID: ";
            cin >> checkId;
            while (file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience) {
                if (strcmp(checkId, id) == 0) {
                    cout << "\n------------------------------\n\n";
                    cout << "Employee Name: " << name << endl;
                    cout << "Employee ID: " << id << endl;
                    cout << "Employee Designation: " << designation << endl;
                    cout << "Employee Age: " << age << endl;
                    cout << "Employee Hourly Rate: " << ctc << endl;
                    cout << "Employee Working Hours: " << working_hours << endl;
                    cout << "Employee Loan Amount: " << loan_amount << endl;
                    cout << "Employee Experience: " << experience << endl;
                    cout << "\n------------------------------\n";
                }
            }
            break;

        case 2:
            cout << "\n Enter Employee Name: ";
            cin >> checkName;
            while (file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience) {
                if (strcmp(checkName, name) == 0) {
                    cout << "\n------------------------------\n\n";
                    cout << "Employee Name: " << name << endl;
                    cout << "Employee ID: " << id << endl;
                    cout << "Employee Designation: " << designation << endl;
                    cout << "Employee Age: " << age << endl;
                    cout << "Employee Hourly Rate: " << ctc << endl;
                    cout << "Employee Working Hours: " << working_hours << endl;
                    cout << "Employee Loan Amount: " << loan_amount << endl;
                    cout << "Employee Experience: " << experience << endl;
                    cout << "\n------------------------------\n";
                }
            }
            break;

        default:
            cout << "\nInvalid choice. Please try again." << endl;
            break;
    }

    file.close();
    waitForEnter();
}






void Employee_management::deleted() {
    system("cls");
    char checkId[5];
    fstream file, file1;
    int found = 0;

    cout << "\n----------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------ Delete Employee Data -------------------------------------" << endl;

    file.open("Employee_Record.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t No Data is Present... ";
        waitForEnter();
        return;
    }

    cout << "\nEnter Employee ID To Remove Data: ";
    cin >> checkId;

    file1.open("temp_record.txt", ios::out);
    if (!file1) {
        cout << "\n\t\t\t Unable to open file for writing... ";
        file.close();
        waitForEnter();
        return;
    }

    while (file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience) {
        if (strcmp(checkId, id) != 0) {
            file1 << name << " " << id << " " << designation << " " << age << " " << ctc << " " << working_hours << " " << loan_amount << " " << experience << "\n";
        } else {
            found++;
            cout << "\n\t\t\t Successfully Deleted Data";
        }
    }

    if (found == 0) {
        cout << "\n\n\t Employee ID Not Found... Please Try again";
    }

    file.close();
    file1.close();

    remove("Employee_Record.txt");
    rename("temp_record.txt", "Employee_Record.txt");

    waitForEnter();
}





void Employee_management::generatePayslip(const char* emp_id)
{
    system("cls");
    fstream file;
    char fileId[5];
    bool found = false;

    file.open("Employee_Record.txt", ios::in);
    if (!file) {
        cout << "\n\t\t\t No Data is Present... ";
        file.close();
        waitForEnter();
        return;
    }

    file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience;
    while (!file.eof()) {
        if (strcmp(emp_id, id) == 0) {
            found = true;
            break;
        }
        file >> name >> id >> designation >> age >> ctc >> working_hours >> loan_amount >> experience;
    }
    file.close();

    if (!found) {
        cout << "\nEmployee ID not found.";
        waitForEnter();
        return;
    }

    // Calculating earnings and deductions
    float money=working_hours*ctc;     //ctc means Hourly Rate
    float hra = 0.27 *money;
    float da = 0.50 *money;
    float meal_allowance = 0.04*money; // Example value
    float medical_allowance = 0.07*money; // Example value
    float transport_allowance = 0.03*money; // Example value
    float pf = 0.12 * money; // PF deduction
    float tax = 0.15 *money; // Tax deduction

    float total_earnings = hra + da + meal_allowance + medical_allowance + transport_allowance;
    float total_deductions = pf + tax;
    float gross_pay = ctc + total_earnings - total_deductions;

    // Display payslip
    cout << "\n---------------------------- Payslip ----------------------------" << endl;
    cout << "Employee Name: " << name << endl;
    cout << "Employee ID: " << id << endl;
    cout << "Designation: " << designation << endl;
    cout << "Hourly Rate: " << ctc << endl;
    cout << "Working Hours: " << working_hours << endl;
    cout << "Loan Amount: " << loan_amount << endl;
    cout << "\nEarnings:" << endl;
    cout << "HRA: " << hra << endl;
    cout << "DA: " << da << endl;
    cout << "Meal Allowance: " << meal_allowance << endl;
    cout << "Medical Allowance: " << medical_allowance << endl;
    cout << "Transport Allowance: " << transport_allowance << endl;
    cout << "\nDeductions:" << endl;
    cout << "PF: " << pf << endl;
    cout << "Tax: " << tax << endl;
    cout << "\nGross Pay: " << gross_pay << endl;
    cout << "------------------------------------------------------------------" << endl;

    waitForEnter();
}

void Employee_management::waitForEnter()
{
    cout << "\n\n Press enter to go back : ";
    cin.ignore();
    cin.get();
}





#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>   // For _getch()
#include <windows.h> // For Sleep()

using namespace std;

// Function to check password validity
bool isValidPassword(const string& password) {
    bool hasCapital = false;
    bool hasSpecial = false;

    for (size_t i = 0; i < password.length(); ++i) {
        char c = password[i];
        if (isupper(c)) {
            hasCapital = true;
        } else if (ispunct(c)) { // Check for special characters
            hasSpecial = true;
        }
    }

    return hasCapital && hasSpecial;
}

// Function to set console text color (Windows-specific)
void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Function to clear screen (Windows-specific)
void clearScreen() {
    system("cls");
}

// Function to pause and wait for user input
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

int password_user() {
    string pass_reg = "";
    string name_reg = "";
    string pass = "";
    string name = "";
    fstream file;
    char ch;
    
    clearScreen();
    setConsoleColor(10); // Set color to green
    cout << "\n\t\t\t-------------------------------------------------------";
    cout << "\n\t\t\t||       WELCOME TO PAYROLL MANAGEMENT SYSTEM       ||";
    cout << "\n\t\t\t-------------------------------------------------------";
    setConsoleColor(15); // Reset color to white
    cout << "\n\n\t\t\t     Press: [1] SignUp";
    cout << "\n\n\t\t\t     Press: [2] Login ";

    int selection;
    cout << "\n\n Please Enter Value : ";
    cin >> selection;

    if (selection == 1) {
        clearScreen();
        setConsoleColor(14); // Set color to yellow
        cout << "\n\t\t\t\t-------------------------------";
        cout << "\n\t\t\t\t>> REGISTRATION ADMIN <<";
        cout << "\n\t\t\t\t-------------------------------";
        setConsoleColor(15); // Reset color to white
        cout << "\n\n\t\t\t\t Enter UserName : ";
        cin >> name_reg;

        while (true) {
            cout << "\n\t\t\t\t Enter Password : ";
            ch = _getch();
            pass_reg.clear();
            while (ch != 13) { // Enter key
                pass_reg.push_back(ch);
                cout << '*';
                ch = _getch();
            }
            if (isValidPassword(pass_reg)) {
                break;
            } else {
                cout << "\nPassword must contain at least one capital letter and one special character. Please try again.";
            }
        }

        file.open("dp_data.txt", ios::app);
        file << name_reg << " " << pass_reg << "\n";
        file.close();
        setConsoleColor(10); // Set color to green
        cout << " \n Registration Successfully Saved...";
        setConsoleColor(15); // Reset color to white
        waitForEnter();
        password_user();
    } else if (selection == 2) {
        clearScreen();
        file.open("dp_data.txt", ios::in);
        setConsoleColor(14); // Set color to yellow
        cout << "\n\t\t\t\t---------------------------------";
        cout << "\n\t\t\t\t>>   LOGIN ADMIN    <<";
        cout << "\n\t\t\t\t---------------------------------";
        setConsoleColor(15); // Reset color to white
        cout << "\n\n\t\t\t\t Enter UserName : ";
        cin >> name;
        cout << "\n\t\t\t\t Enter Password : ";
        ch = _getch();
        while (ch != 13) { // Enter key
            pass.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        file >> name_reg >> pass_reg;
        while (!file.eof()) {
            if (pass == pass_reg && name == name_reg) {
                setConsoleColor(10); // Set color to green
                cout << "\n\n\n\t\t\t\t\t| Verifying ADMIN |\n\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++) {
                    Sleep(500);
                    cout << "**";
                }
                cout << "\n\n Access Granted.. \n\n";
                setConsoleColor(15); // Reset color to white
                waitForEnter();
                clearScreen();
                break;
            } else {
                setConsoleColor(12); // Set color to red
                cout << "\n\n\n\t\t\t\t\t| Verifying ADMIN |\n\t\t\t\t\t";
                for (int a = 1; a < 8; a++) {
                    Sleep(500);
                    cout << "**";
                }
                cout << "\n\n Access Aborted.. \n\n";
                setConsoleColor(15); // Reset color to white
                waitForEnter();
                clearScreen();
                password_user();
            }
            file >> name_reg >> pass_reg;
        }
        file.close();
    } else {
        cout << "\nInvalid Input, Please try Again..\n";
        password_user();
    }

    return 0;
}





int main()
{
    Employee_management system;
    system.menu();
    return 0;
}


