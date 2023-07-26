#ifndef FINAL_FUNCTION_H
#define FINAL_FUNCTION_H
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <set>
#include <limits>
#include <vector>
#include <cctype> // For toupper() function
#include <iomanip>

using namespace std; 

const string facility [4] = {"AVR","GYM", "ROOM 1", "ROOM 2"};
const string month [12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	string fname; 
	string lname; 
	string occupation; 
	


void clearInputBuffer() {
    // Clear input buffer until a newline character is found
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}




void chooseProfession(int res_choice)
{
	string student = "[Student] "; 
	string prof = "[Professor] ";
	
	if (res_choice == 1) {occupation = student;}

	else if (res_choice==2) {occupation = prof;}

}


/*
int lineduplicate(int i, int j, int day_choice) {
	
 
    fstream reservations;
    reservations.open("first.txt", ios::out);

    if (reservations.is_open()) {
        //reservations << facility[i - 1] << " - " << month[j - 1] << " - " << day_choice << endl;
        reservations << occupation << lname << ", " << fname << ": " << facility[i - 1] << " - " << month[j - 1] << " - " << day_choice << endl;
        reservations << "______________________________________________________________________________ \n";
        reservations.close();
    } else {
        cout << "Failed to Open File first.txt" << endl;
        return 1;
    }

    ifstream firstFile("first.txt");
    if (!firstFile.is_open()) {
        cerr << "Error: Unable to open first.txt for reading." << endl;
        return 1;
    }

    string existingLine;
    getline(firstFile, existingLine);
    firstFile.close();

    ifstream mainFile("main.txt");
    if (!mainFile.is_open()) {
        // The main.txt file doesn't exist, so create it
        ofstream newMainFile("main.txt");
        if (!newMainFile.is_open()) {
            cerr << "Error: Unable to create main.txt." << endl;
            return 1;
        }
        newMainFile.close();
        
        // Now try opening it again
        mainFile.open("main.txt");
        if (!mainFile.is_open()) {
            cerr << "Error: Unable to open main.txt for reading." << endl;
            return 1;
        }
    }
    set<string> uniqueLines;
    string line;

    while (getline(mainFile, line)) {
        uniqueLines.insert(line);
    }

    mainFile.close();

    ofstream mainFileAppend("main.txt", ios::app);
    if (!mainFileAppend.is_open()) {
        cerr << "Error: Unable to open main.txt for appending." << endl;
        return 1;
    }

    if (uniqueLines.find(existingLine) == uniqueLines.end()) {
        mainFileAppend << existingLine << endl;
        system ("cls");
        cout << "Successfully reserved!" << endl;
        system ("pause"); 
    } else {
        cout << "Sorry, but this date and facility is already reserved." << endl;
        system ("pause"); 
    }

    mainFileAppend.close();

    return 0;
}



*/


#include <fstream>
#include <iostream>
#include <set>

using namespace std;

int lineduplicate(int i, int j, int day_choice) {
    fstream reservations;
    reservations.open("first.txt", ios::out);

    if (reservations.is_open()) {
        //reservations << facility[i - 1] << " - " << month[j - 1] << " - " << day_choice << endl;
        reservations << occupation << lname << ", " << fname << ": " << facility[i - 1] << " - " << month[j - 1] << " - " << day_choice << endl;
        reservations << "______________________________________________________________________________ \n";
        reservations.close();
    } else {
        cout << "\n" << setw(36) << " " << "Failed to Open File first.txt" << endl;
        return 1;
    }

    ifstream firstFile("first.txt");
    if (!firstFile.is_open()) {
        // The first.txt file doesn't exist, so create it
        ofstream newFirstFile("first.txt");
        if (!newFirstFile.is_open()) {
            cerr << "\n" << setw(36) << " " << "Error: Unable to create first.txt." << endl;
            return 1;
        }
        newFirstFile.close();

        // Now try opening it again
        firstFile.open("first.txt");
        if (!firstFile.is_open()) {
            cerr <<"\n" << setw(36) << " " << "Error: Unable to open first.txt for reading." << endl;
            return 1;
        }
    }

    string existingLine;
    getline(firstFile, existingLine);
    firstFile.close();

    ifstream mainFile("main.txt");
    if (!mainFile.is_open()) {
        // The main.txt file doesn't exist, so create it
        ofstream newMainFile("main.txt");
        if (!newMainFile.is_open()) {
            cerr << "\n" << setw(36) << " " << "Error: Unable to create main.txt." << endl;
            return 1;
        }
        newMainFile.close();

        // Now try opening it again
        mainFile.open("main.txt");
        if (!mainFile.is_open()) {
            cerr << "\n" << setw(36) << " " << "Error: Unable to open main.txt for reading." << endl;
            return 1;
        }
    }
    
    set<string> uniqueLines;
    string line;

    while (getline(mainFile, line)) {
        uniqueLines.insert(line);
    }

    mainFile.close();

    ofstream mainFileAppend("main.txt", ios::app);
    if (!mainFileAppend.is_open()) {
        cerr <<"\n" << setw(36) << " " <<  "Error: Unable to open main.txt for appending." << endl;
        return 1;
    }

    if (uniqueLines.find(existingLine) == uniqueLines.end()) {
        mainFileAppend << existingLine << endl;
        system("cls");
        cout << "\n" << setw(36) << " " << "Successfully reserved!" << endl;
 		cout <<"\n" << setw(36) << " " << system("pause");
    } else {
    	system("cls");
        cout << "\n" << setw(36) << " " << "Sorry, but this date and facility is already reserved." << endl;
        cout <<"\n" << setw(36) << " " << system("pause");
    }

    mainFileAppend.close();

    return 0;
}



/*
void professor_info() {
    string professor_name;
    string prof_fname;
    string prof_lname;
    int response;
    //char userInput;
    
    
    
while(true){

   		cin.ignore();  
    	system("cls"); 
    	cout << "Enter your Name (First Name then Last Name) \n";

   		cout << "First Name: ";
    	getline(cin, prof_fname);
    	fname = prof_fname; 
    	cout << "Last Name: ";
   		getline(cin, prof_lname);
		lname = prof_lname;       
		
	while (true){    
    
    	system ("cls"); 
        cout << "Are you sure? \n";
        cout << "(1) - Yes \n";
        cout << "(2) - No \n"; 
        cout << "Input your choice: "; 
        cin >> response;	
        
       if (cin.fail()) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system ("cls");
            cout << "Invalid input. Please enter an integer.\n";
            system ("pause>0"); 
	       
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }   	
    	
    	
	}
break; 
}

/*
    do {
        cout << "Are you sure? (y/n): ";
        cin >> response;

        userInput = toupper(response);

        if (userInput == 'Y') {
           // cout << "You chose Yes!\n";
            break; // Exit the inner do-while loop if 'Y' is chosen
        } else if (userInput == 'N') {
            //cout << "You chose No!\n";
            system ("cls");
            // Reset the name variables to ask for the name again
            prof_fname = "";
            prof_lname = "";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            cout << "Enter your Name (First Name then Last Name) \n";
            cout << "First Name: ";
            getline(cin, prof_fname);
            cout << "Last Name: ";
            getline(cin, prof_lname);
        } else {
            cout << "Invalid input. Please enter 'y' for Yes or 'n' for No.\n";
        }
    } while (true);
*/

/*
    // WELCOME SCREEN WITH NAME
    system("cls");
    cout << "Welcome " << prof_fname << " " << prof_lname << endl;
    system("pause");
    
    
    
    
}

*/




void professor_info() {
    string professor_name;
    string prof_fname;
    string prof_lname;
    int response;
    //char userInput;

    while (true) {
        cin.ignore();
        system("cls");
        cout << "\n" << setw(36) << " " << "Enter your Name (First Name then Last Name) \n";

        cout << "\n" << setw(36) << " " << "First Name: ";
        getline(cin, prof_fname);
        fname = prof_fname;
        cout << "\n" << setw(36) << " " << "Last Name: ";
        getline(cin, prof_lname);
        lname = prof_lname;

        while (true) {
            system("cls");
            cout << "\n" << setw(36) << " " << "Are you sure? \n";
            cout  << setw(36) << " " << "(1) - Yes \n";
            cout  << setw(36) << " " << "(2) - No \n";
            cout << "\n" << setw(36) << " " << "Input your choice: ";
            cin >> response;

            if (cin.fail()) {
                // Invalid input (non-integer)
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                system("cls");
                cout <<"\n" << setw(36) << " " << "Invalid input. Please enter an integer.\n";
                system("pause>0");
            } else if (response == 1) {
                // Input is a valid integer and user is sure
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                break;
            } else if (response == 2) {
                // User is not sure, go back to asking for the name
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                break;
            } else {
                // Invalid input (not 1 or 2)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                system("cls");
                cout << "\n" << setw(36) << " " << "Invalid input. Please enter 1 or 2.\n";
                system("pause>0");
            }
        }

        if (response == 1) {
            // User is sure, break out of the outer loop
            break;
        }
    }
    
    
    
    
}


void student_info() {
	int course_choice; 
	int level_choice; 
	string student_fname;  
	string student_lname;  	
	int response;

	
	string course [12] = {"BSA","BSOA", "BSED ENGLISH", "BSED MATH" , "BSIT", "BSBA HRM", "BSBA MM", "BSME", "BSECE", "DICT", "DOMT", "DIT"};
	string stud_year [4] = {"First Year", "Second Year", "Third Year", "Fourth Year"}; 

    while (true) {
        system("cls");
        cout << "\n" << setw(36) << " " << "Enter your Name (First Name then Last Name) \n";
        cout << "\n" << setw(36) << " " <<"First Name: ";
        getline(cin, student_fname);
        fname = student_fname;
        cout << "\n" << setw(36) << " " << "Last Name: ";
        getline(cin, student_lname);
        lname = student_lname;

        while (true) {
            system("cls");
            cout << "\n" << setw(36) << " " << "Are you sure? \n";
            cout <<  setw(36) << " " << "(1) - Yes \n";
            cout <<  setw(36) << " " << "(2) - No \n";
            cout << "\n" << setw(36) << " " << "Input your choice: ";
            cin >> response;

            if (cin.fail()) {
                // Invalid input (non-integer)
                cin.clear(); // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
                system("cls");
                cout << "\n" << setw(36) << " " << "Invalid input. Please enter an integer.\n";
                system("pause>0");
            } else if (response == 1) {
                // Input is a valid integer and user is sure
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                break;
            } else if (response == 2) {
                // User is not sure, go back to asking for the name
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                break;
            } else {
                // Invalid input (not 1 or 2)
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
                system("cls");
                cout << "\n" << setw(36) << " " << "Invalid input. Please enter 1 or 2.\n";
                system("pause>0");
            }
        }

        if (response == 1) {
            // User is sure, break out of the outer loop
            break;
        }
        
        
    }
    
    
    
    	while (true) {	
	  	
	  	//INPUT COURSE 
			system ("cls");	
			cout <<   setw(36) << " " << "Please Input your Course \n";
			cout <<   setw(36) << " " <<"(1) - BSA\n";
			cout <<   setw(36) << " " <<"(2) - BSOA \n";	
			cout <<   setw(36) << " " <<"(3) - BSED ENGLISH \n";
			cout <<   setw(36) << " " <<"(4) - BSED MATH \n";
			cout <<   setw(36) << " " <<"(5) - BSIT \n";
			cout <<   setw(36) << " " <<"(6) - BSBA HRM \n";
			cout <<   setw(36) << " " <<"(7) - BSBA MM \n";
			cout <<   setw(36) << " " <<"(8) - BSME \n";
			cout <<   setw(36) << " " <<"(9) - BSECE \n";
			cout <<   setw(36) << " " <<"(10) - DICT \n";
			cout <<   setw(36) << " " <<"(11) - DOMT \n";
			cout <<  setw(36) << " " << "(12) - DIT \n";
			cout << "\n" << setw(36) << " " <<"Input your course: "; 
			cin >> course_choice; 
			
			
        if (cin.fail()|| course_choice < 1 || course_choice > 12) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            	  	system ("cls");
            cout << "\n" << setw(36) << " " <<"Invalid input. Please enter an integer or less than 12.\n";
            system ("pause>0"); 
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
    }
	
	
	
  	while (true) {	
	  
	
		//INPUT GRADE LEVEL 
		system ("cls");
		cout << "\n" << setw(36) << " " <<"Please Input your Level \n";
		cout <<"\n" << setw(36) << " " << "(1) -> 1-1: FIRST YEAR \n";
		cout << "\n" << setw(36) << " " <<"(2) -> 2-1: SECOND YEAR \n";
		cout <<"\n" << setw(36) << " " << "(3) -> 3-1: THIRD YEAR \n";
		cout << "\n" << setw(36) << " " <<"(4) -> 4-1: FOURTH YEAR \n";
		cout << "\n" << setw(36) << " " <<" Input Level: ";
		cin >> level_choice;
	 
	
        if (cin.fail()|| level_choice < 1 || level_choice > 4) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            	  	system ("cls");
            cout << "\n" << setw(36) << " " << "Invalid input. Please enter an integer or less than 4.\n";
            system ("pause>0"); 
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
    }
	
	/*
	system ("cls");	
	//ASK FOR ADVISOR NAME 
	cin.ignore();
	cout << "Please Input the Name of Your Adviser: ";
	getline (cin, advisor_name); 
	*/
	
	/*
	 system ("cls");
	cout  << setw(36) << " " << "Welcome " << student_fname << " " << student_lname << endl; 
	cout << setw(36) << " " << "Of " << stud_year [level_choice-1] << " - " << course [course_choice-1] << endl; 
	//cout << "Your Advisor is " << advisor_name << endl; 
	system ("pause");
    */
    
    
    
    //THIS IS WHERE THE REST OF THE LOOPS GO
}








void reservation()
{
	
	int month_choice; 
	int faci_choice;



	while(true)
	{
	system ("cls"); 
	cout << "\n" << setw(36) << " " << "Please choose which facility you want to reserve \n"; 
	cout << "\n" << setw(36) << " " << "(1) - AVR (AUDIO VISUAL ROOM)\n"; 
	cout <<"\n" << setw(36) << " " <<"(2) - GYMNASIUM \n"; 
	cout <<"\n" << setw(36) << " " <<"(3) - ROOM 1 \n"; 
	cout << "\n" << setw(36) << " " << "(4) - ROOM 2 \n"; 
	cout << "\n" << setw(36) << " " << "Input your choice: "; 
	cin >> faci_choice;

   	        if (cin.fail() || faci_choice < 1 || faci_choice > 4) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system("cls");
            cout << "\n" << setw(36) << " " << "Invalid input. Please enter a valid integer between 1 and 4.\n";
            system("pause>0");
         }   
         	
         else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
}

	while (true)
	{
	system ("cls");
	cout << setw(36) << " " << "Choose a Month\n\n"; 
	cout << setw(36) << " " << "Months \n";
	cout << setw(36) << " " << "(1) - JANUARY \n";
	cout << setw(36) << " " << "(2) - FEBRUARY\n";
	cout << setw(36) << " " << "(3) - MARCH\n";
	cout << setw(36) << " " << "(4) - APRIL\n";
	cout << setw(36) << " " << "(5) - MAY\n";
	cout << setw(36) << " " << "(6) - JUNE\n";
	cout << setw(36) << " " << "(7) - JULY\n";
	cout << setw(36) << " " << "(8) - AUGUST\n";
	cout << setw(36) << " " << "(9) - SEPTEMBER \n";
	cout << setw(36) << " " << "(10) - OCTOBER \n";
	cout << setw(36) << " " << "(11) - NOVEMBER\n";
	cout << setw(36) << " " << "(12) - DECEMBER \n";
	cout << setw(36) << " " << "Enter your choice: "; 
	cin >> month_choice; 

  	    if (cin.fail() || month_choice < 1 || month_choice > 12) 
		{
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system("cls");
            cout << "\n" << setw(36) << " "<< "Invalid input. Please enter a valid integer between 1 and 12.\n";
            system("pause>0");
         }   
         	
        else 
		{
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
        
    }



	switch (month_choice)
	{
		
		case 1 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<< "You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<< "There are 31 days in this month \n"; 
			cout << "\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice << endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice);
			
		}break;
		
		
		case 2 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<< "You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<< "There are 28 days in this month \n"; 			
			cout << "\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 28); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );


		}break;
			
		case 3 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<< "You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<< "There are 31 days in this month \n"; 
			cout << "\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );			
			
			
		}break; 
		
		case 4 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<< "You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<< "There are 30 days in this month \n"; 
			cout <<"\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 30); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );		
		}break; 		
		
		
		case 5 : system ("cls");
		{
			int day_choice; 
			do {
			cout <<"\n" << setw(36) << " "<< "You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<< "There are 31 days in this month \n"; 
			cout <<"\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );			
		}break; 	
		
			

		case 6 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 30 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 30); 
			//cout << "sucessful \n";
			cout <<"\n" << setw(36) << " "<<"You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );	
			
			
		}break; 		
		
		
		
		case 7 : system ("cls");
		{
			int day_choice; 
			do {
			cout <<"\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout <<"\n" << setw(36) << " "<<"There are 31 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<<"You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );	
			
			
		}break; 		
		


		case 8 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 31 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );		
			
			
		}break; 		
		

		case 9 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 30 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 30); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<<"You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );
			
		}break; 		
		

		case 10 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 31 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout <<"\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );	
			
			
		}break; 		
		

		case 11 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 30 days in this month \n"; 
			cout << "\n" << setw(36) << " "<<"Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 30); 
			//cout << "sucessful \n";
			cout <<"\n" << setw(36) << " "<< "You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );	
			
			
		}break; 		

		case 12 : system ("cls");
		{
			int day_choice; 
			do {
			cout << "\n" << setw(36) << " "<<"You've chosen " << month [month_choice-1] << endl; 
			cout << "\n" << setw(36) << " "<<"There are 31 days in this month \n"; 
			cout <<"\n" << setw(36) << " "<< "Enter which day you want to reserve: "; 
			cin >> day_choice; 
			} while (day_choice > 31); 
			//cout << "sucessful \n";
			cout << "\n" << setw(36) << " "<<"You've reserved for " << facility[faci_choice-1]<< " on " << month [month_choice-1] << " - " << day_choice <<endl; //" - 2023 \n"; 
			lineduplicate (faci_choice, month_choice, day_choice );	
			
			
		}break; 		
		
		default : system ("cls");
		{
			cout << "Invalid Input. Try Again";
			system ("pause>0"); 
			return; 
			
		}break; 

	}

}



void view_reservations()
{
//FOR VIEWING RESERVATIONS; 
char choice; 
cout  << setw(36) << " "<<"View the reservations? \n"; 
cout << setw(36) << " "<< "y/n :  "; 
cin >> choice; 


system("cls");
if (choice == 'y' || choice == 'Y')
{
	// OPEN FILE 
	ifstream inputFile ("main.txt");
	int linecount = 0;
	//CHECK IF FILE IS OPEN
	if (inputFile.is_open())
	{
		//PUT INPUTFILE CONTENTS IN "LINE" 
		string line; 
		cout  << setw(36) << " "<<"RESERVED ([OCCUPATION] - NAME - FACILITY - MONTH - DAY)\n"; 
		cout  << setw(36) << " "<<"--------------------------------------------------------\n"; 
		cout << setw(36) << " "<<"--------------------------------------------------------\n\n"; 	
		while (getline(inputFile,line))
		{
			// OUTPUT THE TRANSFERRED CONTENT
			linecount++; 
			cout  << setw(36) << " "<< "(" <<linecount << ")" << line << endl;
			cout  << setw(36) << " "<< "--------------------------------------------------------\n"; 
		}
		// CLOSE 
		inputFile.close();
		system ("pause"); 
	}
	else 
	{
	cout <<"\n" << setw(36) << " "<<"Failed to open file" << endl; 
	}

	
}
else if (choice == 'n' || choice == 'N')
{
	return; 
}
		
	
}


void view_reservations_justshow()
{

	// OPEN FILE 
	ifstream inputFile ("main.txt");
	int linecount = 0;
	//CHECK IF FILE IS OPEN
	if (inputFile.is_open())
	{
		//PUT INPUTFILE CONTENTS IN "LINE" 
		string line; 
		cout  << setw(36) << " "<< "RESERVED ([OCCUPATION] - NAME - FACILITY - MONTH - DAY)\n"; 
		cout  << setw(36) << " "<< "--------------------------------------------------------\n\n"; 
		cout  << setw(36) << " "<< "--------------------------------------------------------\n"; 	
		while (getline(inputFile,line))
		{
			// OUTPUT THE TRANSFERRED CONTENT
			linecount++; 
			cout << setw(36) << " "<< "(" <<linecount << ")" << line << endl;
			cout  << setw(36) << " "<< "--------------------------------------------------------\n"; 
		}
		// CLOSE 
		inputFile.close();
		system ("pause"); 
	}
	else 
	{
	cout << "\n" << setw(36) << " "<< "Failed to open file" << endl; 
	}

	
}




int deleteline() {
    ifstream inFile("main.txt");

    if (!inFile) {
        cerr << "\n" << setw(36) << " "<< "Error opening file: main.txt" << endl;
        return 1;
    }

    // Read the content of the file into a vector of strings
    vector<string> lines;
    string line;
    while (getline(inFile, line)) {
        lines.push_back(line);
    }

    inFile.close();

    // Check if there are no existing lines in the file
    if (lines.empty()) {
        cout << "\n" << setw(36) << " "<< "There are no reservations yet." << endl;
        system("pause>0");
        return 0;
    }

    // Display the content of the file to the user
		cout  << setw(36) << " "<< "RESERVED ([OCCUPATION] - NAME - FACILITY - MONTH - DAY)\n"; 
		cout  << setw(36) << " "<< "--------------------------------------------------------\n\n"; 
		cout  << setw(36) << " "<< "--------------------------------------------------------\n"; 	
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << "\n" << setw(36) << " "<< "(" << i + 1 << ")" << lines[i] << endl;
        cout << setw(36) << " "<< "--------------------------------------------------------";
    }

    // Ask the user for the line number to delete or exit
    int lineNumber;
    while (true) {
        cout << "\n" << setw(30) << " "<< "Enter the line number to delete (1 to " << lines.size() << "), or enter 0 to go back to the menu: ";
        cin >> lineNumber;

        if (lineNumber == 0) {
            system("cls");
            cout << "\n" << setw(36) << " "<< "Going back to Menu..." << endl;
            system("pause>0");
            return 0; // Exit the function and go back to the menu
        }

        // Validate user input
        if (lineNumber < 1 || lineNumber > static_cast<int>(lines.size())) {
            system("cls");
            cout << "Invalid line number. Please enter a valid line number." << endl;

            // Display the content of the file again
		cout << setw(36) << " "<< "RESERVED ([OCCUPATION] - NAME - FACILITY - MONTH - DAY)\n"; 
		cout << setw(36) << " "<< "--------------------------------------------------------\n\n"; 
		cout  << setw(36) << " "<< "--------------------------------------------------------\n"; 	
            for (size_t i = 0; i < lines.size(); ++i) {
                cout  << setw(36) << " "<< "(" << i + 1 << ")" << lines[i] << endl;
                cout << setw(36) << " "<< "--------------------------------------------------------\n";
            }

            system("pause>0");
        } else {
            break; // Valid input, exit the loop
        }
    }

    // Ask the user if they want to delete the specified line (accept only 'Y' or 'N')
    char response;
    bool validResponse = false;

    do {
        cout << "\n" << setw(36) << " "<< "Are you sure you want to delete line " << lineNumber << "? (Y/N): ";
        cin >> response;
        response = toupper(response); // Convert input to uppercase for case-insensitivity

        if (response == 'Y' || response == 'N') {
            validResponse = true; // Valid response received, exit the loop
        } else {
            cout << "\n" << setw(36) << " "<< "Invalid response. Please enter 'Y' or 'N'." << endl;
        }
    } while (!validResponse);

    // Check if the user wants to delete the line
    if (response == 'Y') {
        // Remove the selected line from the vector
        lines.erase(lines.begin() + lineNumber - 1);

        // Open the file in write mode to update the content
        ofstream outFile("main.txt");

        if (!outFile) {
            cerr << "\n" << setw(36) << " "<< "Error opening file: main.txt" << endl;
            return 1;
        }

        // Write the updated content back to the file
        for (size_t i = 0; i < lines.size(); ++i) {
            outFile << lines[i] << endl;
        }

        outFile.close();
        system("cls");
        cout << "\n" << setw(36) << " "<< "Reservation no. " << lineNumber << " has been deleted from the file." << endl;
        cout << "\n" << setw(36) << " "<< "File successfully updated and saved." << endl;
        system("pause>0");
    } else {
        system("cls");
        cout << "\n" << setw(36) << " "<< "Deletion canceled. The file remains unchanged." << endl;
        cout << "\n" << setw(36) << " "<< "Going back to Menu...";
        system("pause>0");
    }

    return 0;
}


#endif // MY_MODULE_H
