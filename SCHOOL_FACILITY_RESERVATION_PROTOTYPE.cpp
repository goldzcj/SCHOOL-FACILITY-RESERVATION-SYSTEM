#include <iostream>
#include <iomanip>
#include "final_function.h"
using namespace std; 

//const string facility [4] = {"AVR","GYMNASIUM", "ROOM 1", "ROOM 2"};
//const string month [12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
void create_reserve();
void manage_reserve();

int main()
{

	int main_choice;	
do {
	system ("color 70");
	//USE WHILE LOOP TO CHECK IF THE INPUTIS INTEGER
	//IF INPUT IS INTEGER IT WILL BREAK AND PROCEED TO THE NEXT PROCEDURE
  	while (true) {	
	  
	  	system ("cls");
		cout << "\n" << setw(36) << " " << "PUP FACILITY RESERVATION SYSTEM \n \n"; 
		cout << "\n" << setw(36) << " " <<"(1) - Create Reservation \n"; 
		cout << "\n" << setw(36) << " " <<"(2) - Manage Reservation \n"; 
		cout << "\n" << setw(36) << " " <<"(3) - Exit. \n";
        cout << "\n" << setw(36) << " " <<"Enter an your choice: ";
        cin >> main_choice;
		
	
        if (cin.fail()) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            	  	system ("cls");
            cout << "Invalid input. Please enter an integer.\n";
			cout << "\n" << setw(36) << " " << system ("pause>0");
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
    }
    
    
	switch (main_choice)
	{
		
		//CREATE RESERVATIONS
		case 1 : system ("cls");
		{
			cout << "\n" << setw(36) << " " << "You chose Create Reservation\n"; 
			cout << "\n" << setw(36) << " " << "Press any key to Proceed"; 
			cout << "\n" << setw(36) << " " << system ("pause>0");
			create_reserve();

		}break;
		
		//MANAGE RESERVATIONS 
		case 2 : system ("cls");
		{
			cout << "\n" << setw(36) << " " << "You chose Manage Reservation\n"; 
			cout << "\n" << setw(36) << " " << "Press any key to Proceed"; 
			cout << "\n" << setw(36) << " " << system ("pause>0"); 
			manage_reserve();
			
		}break;
		
		//EXIT 	
		case 3 : system ("cls");
		{
			cout << "\n" << setw(36) << " " << "Exiting Program...";
			exit (0);
			
		}break; 
		
		default : system ("cls");
		{
			
			cout << "\n" << setw(36) << " " << "Invalid Input. Try Again \n";
			cout <<  setw(36) << system ("pause"); 
			
		}
	}

}while (main_choice != 3);	
}





void create_reserve()
{
	int response; 
	int create_reservation_choice;
	do {	

	while (true) {	
		system ("cls");		
		cout << "\n" << setw(36) << " " <<"Choose Occupation \n"; 
		cout << "\n" << setw(36) << " " <<"(1) - Student \n"; 
		cout << "\n" << setw(36) << " " <<"(2) - Professor \n"; 
		cout << "\n" << setw(36) << " " <<"(3) - Return to Main Menu\n";
		cout << "\n" << setw(36) << " " <<" Input your choice: ";  
		cin >> create_reservation_choice;
		chooseProfession(create_reservation_choice);	
        if (cin.fail()) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system ("cls");
            cout << "\n" << setw(36) << " " << "Invalid input. Please enter an integer.\n";
            system ("pause>0"); 
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        }
    }
	


	switch (create_reservation_choice)
	{

//STUDENT------------------------------------------------
		case 1: system ("cls");{
		cout << "\n" << setw(36) << " " << "You've chosen Student \n";
		cout << "\n" << setw(36) << " " << "Click Enter to continue";
		// system ("pause>0"); 
		student_info();		
		//cout << endl<<endl;
		system ("cls");
		cout << "\n" << setw(36) << " " << "THESE ARE THE CURRENT RESERVATIONS.\n\n";
		view_reservations_justshow();
   do {
   	
        system("cls");
        reservation();
		
		system ("cls"); 
        cout << "\n" << setw(36) << " " << "Do you want to reserve another? \n";
        cout << "\n" << setw(36) << " " << "(1) - Yes \n";
        cout << "\n" << setw(36) << " " <<"(2) - No \n";
        cout << "\n" << setw(36) << " " << "Input your choice: ";
        cin >> response;

        if (cin.fail()) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system("cls");
            cout << "\n" << setw(36) << " " << "Invalid input. Please enter an integer.\n";
            system("pause>0");
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            if (response == 1) {
                // Go back to reservation() if the user inputted 1
                continue;
            } else if (response == 2) {
                // Break the loop if the user inputted 2
                break;
            } else {
                system("cls");
                cout << "\n" << setw(36) << " " << "Invalid choice. Please enter either 1 or 2.\n";
                system("pause>0");
            }
        }
    } while (true);
    
  		system ("cls");   	
		//view_reservations();
		return; 
	}break; 
		
		
//PROFESSOR------------------------------------------------		
		case 2:system ("cls");{
		cout << "\n" << setw(36) << " " << "You've chosen Professor \n";
		cout << "\n" << setw(36) << " " << "Click Enter to continue"; 	
		professor_info(); 
		//cout << endl<<endl;
		system ("cls");
		cout << "\n" << setw(36) << " " << "THESE ARE THE CURRENT RESERVATIONS.\n\n";
		view_reservations_justshow();
	//	reservation();


   do {
   	
        system("cls");
        reservation();
		
		system ("cls"); 
        cout << "\n" << setw(36) << " " << "Do you want to reserve another? \n";
        cout << "\n" << setw(36) << " " << "(1) - Yes \n";
        cout <<"\n" << setw(36) << " " << "(2) - No \n";
        cout << "\n" << setw(36) << " " << "Input your choice: ";
        cin >> response;

        if (cin.fail()) {
            // Invalid input (non-integer)
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system("cls");
            cout << "\n" << setw(36) << " " << "Invalid input. Please enter an integer.\n";
            system("pause>0");
        } else {
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            if (response == 1) {
                // Go back to reservation() if the user inputted 1
                continue;
            } else if (response == 2) {
                // Break the loop if the user inputted 2
                break;
            } else {
                system("cls");
                cout << "\n" << setw(36) << " " << "Invalid choice. Please enter either 1 or 2.\n";
                system("pause>0");
            }
        }
    } while (true);
	
	
  		system ("cls");   	
		//view_reservations();
		return; 
		
		}break; 
		
		case 3: system ("cls");{
			cout << "\n" << setw(36) << " " <<  "Returning to Main Menu...";
			return; 	
		}break; 
		
		
		default : system ("cls");
		{
			cout << "\n" << setw(36) << " " << "Invalid Input. Try Again \n";
			system ("pause>0"); 
			
		}break;
		
		
	}
}while (create_reservation_choice != 3);

	
	
}


void manage_reserve()
{
		int manage_choice; 
	do 
	{
	
	while (true)
	{
	system("cls");		
	cout << "\n" << setw(36) << " " << "MANAGE RESERVATIONS \n"; 
	cout << "\n" << setw(36) << " " << "(1) - DISPLAY ALL RESERVATIONS \n";
	cout <<"\n" << setw(36) << " " << "(2) - DELETE A RESERVATION/S \n";	
	cout << "\n" << setw(36) << " " <<"(3) - Exit\n";
	cout << "\n" << setw(36) << " " << "Enter your choice: ";
	cin >> manage_choice; 
	
	 	    if (cin.fail() || manage_choice < 1 || manage_choice > 3) 
			 {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            system("cls");
            cout << "Invalid input. Please enter a valid integer between 1 and 3.\n";
            system("pause>0");
         	}   
         	
         	else
			{
            // Input is a valid integer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any additional characters in the input buffer
            break;
        	}
	
	
	}
		
		
		
		switch (manage_choice)
		{
			
			case 1:system("cls");{
			
			cout <<"\n" << setw(36) << " " << "DISPLAY RESERVATIONS\n";
			view_reservations_justshow();
		
				
			}break;
			
			case 2:system("cls");{
			
			
			cout << "\n" << setw(36) << " " << "DELETE RESERVATION/S \n"; 
 			deleteline();			
			 
				
			}break;
			
			
			case 3:system("cls");{
			cout <<"\n" << setw(36) << " " <<  "Exiting..."; 
				
			}break;		

		default : system ("cls");
		{
			cout << "\n" << setw(36) << " " << "Invalid Input. Try Again \n";
			cout << "\n" << setw(36) << " " <<	system ("pause>0"); 

			
		}break; 
			
		}
		
	}while (manage_choice!=3); 
	
	
	
}





