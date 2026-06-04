#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string username, password, inLine, uname, pass, firstName, lastName, dateOfBirth, addPlayerChoice, team1, team2;
string displayIn, playerIn, regNumber, registrationNumber, searchPlayerChoice, teamName, addPlayerTeamChoice;
string addAnotherTeam, teamIn, teamNameEnter, registrationNumberArray[30], viewTeamDetailsChoice, choice;

ifstream loginFile, displayFile, searchFile, viewTeamFile;

ofstream playerFile, manageTeamsFile;

bool found=false;

int runsScored, i=0;

void login();
void addNewPlayer();
void displayPlayersInformation();
void searchPlayers();
void manageTeams();
void viewTeamDetails(); 

int main(){

    login();

    //Below code is for user main menu.
    if(found==true){

        do{

            cout<<"--------------------------------------------"<<endl;
            cout<<endl;
            
            cout<<"--- Upcountry Warriors Baseball Club ---"<<endl;
            cout<<endl;
            
            cout<<"1. Display Players Information"<<endl;
            cout<<"2. Add New Player"<<endl;
            cout<<"3. Manage Teams"<<endl;
            cout<<"4. Search Player"<<endl;
            cout<<"5. View Team Details"<<endl;
            cout<<"6. Logout"<<endl;
            cout<<endl;

            cout<<"--------------------------------------------"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;

            if(choice=="1"){
                
                displayPlayersInformation();

            }

            else if(choice=="2"){
                
                addNewPlayer();
                
            }

            else if(choice=="3"){
                
                manageTeams();
                
            }

            else if(choice=="4"){
                
                searchPlayers();
                
            }

            else if(choice=="5"){
                
                viewTeamDetails();
                
            }

            else if(choice=="6"){

                cout<<"--------------------------------------------"<<endl;
                cout<<endl;
                cout<<"Logout successfully...."<<endl;
                cout<<endl;
                cout<<"--------------------------------------------";
                
            }

            else{

                cout<<"--------------------------------------------"<<endl;
                cout<<endl;
                cout<<"Invalid input. Please try again......"<<endl;
                cout<<endl;
            }

        }while(choice!="6"); //When choice=6, user logout from the system.
    }   
}

//Function for user login.
void login(){

    //Username='admin' and Password='password'.

    cout<<"--------------------------------------------"<<endl;

    cout<<"Enter Username: ";
    cin>>username;
    
    cout<<"Enter Password: ";
    cin>>password;

    loginFile.open("Login.txt"); //To create a connection with the login text file.

    if(loginFile.is_open()){

        while(getline(loginFile, inLine)){

            if(inLine.length()>0){

                stringstream ss(inLine);
                ss>>uname>>pass;
                
                if(username==uname && password==pass){
                    
                    found=true;
                    break;
                }
            }
        }

        if (found==false) {
            
            cout<<"--------------------------------------------"<<endl;
            cout<<"Invalid login. Exiting..."<<endl;
            cout<<"--------------------------------------------";
        }
    
    }

    loginFile.close();

}

//Function for add a new player.
void addNewPlayer(){

    cout<<"--------------------------------------------"<<endl;
        
    cout<<endl;
    cout<<"--- Add New Player ---"<<endl;
    
    do{

        playerFile.open("Players_information.txt", ios_base::app);

        cout<<endl;
        cout<<"# Do not enter your data with spaces #"<<endl;
        cout<<endl;
        
        cout<<"Enter Registration Number: ";
        cin>>registrationNumber;
        
        cout<<"Enter First Name: ";
        cin>>firstName;
        
        cout<<"Enter Last Name: ";
        cin>>lastName;
        
        cout<<"Enter Date of Birth (YYYY-MM-DD): ";
        cin>>dateOfBirth;
        
        cout<<"Enter Runs Scored: ";
        cin>>runsScored;

        cout<<"Enter selected teams by the player"<<endl;
        cout<<"  Enter team NO:01 : ";
        cin>>team1;
        cout<<"  Enter team NO:02 : ";
        cin>>team2;

        //To input user data to the 'Players_information' text file.
        playerFile<<registrationNumber<<" "<<firstName<<" "<<lastName<<" "<<dateOfBirth<<" ";
        playerFile<<runsScored<<" "<<team1<<" "<<team2<<endl;

        playerFile.close();

        cout<<endl;
        //This is for enter another player, if user wants. Otherwise exit fron this function.
        cout<<"Do you want to add another player? (If, enter 'Y', if not, enter any aother key to exit): ";
        cin>>addPlayerChoice;

    }while(addPlayerChoice=="Y");

   

}

//Function for display all players information.
void displayPlayersInformation(){

    displayFile.open("Players_information.txt"); //To create a connection with 'Players_information' text file.
    
    if(displayFile.is_open()){

        cout<<"--------------------------------------------"<<endl;
       
        cout<<endl;
        cout<<"---Display players information---"<<endl;
        cout<<endl;

        while(getline(displayFile, displayIn)){
            
            if(displayIn.length()>0){

                stringstream ss(displayIn);
                ss>>registrationNumber>>firstName>>lastName>>dateOfBirth>>runsScored>>team1>>team2;
                //Above line to bring all player's information from the 'Players_information' text file. 

                cout<<"Player's registration NO: "<<registrationNumber<<endl;
                cout<<"Player's name: "<<firstName<<" "<<lastName<<endl;
                cout<<"Player's date of birth: "<<dateOfBirth<<endl;
                cout<<"Runs scored by the player: "<<runsScored<<endl;
                cout<<"Selected teams by the player:- "<<endl;
                cout<<"  1.Team NO:01 : "<<team1<<endl;
                cout<<"  2.Team NO:02 : "<<team2<<endl;

                cout<<endl;
            }

        }

    }

    displayFile.close();

}

//Function for search for a player.
void searchPlayers(){

    cout<<"--------------------------------------------"<<endl;
    cout<<endl;
        
    cout<<"---Search Players---"<<endl;
    
    do{
        
        searchFile.open("Players_information.txt"); //To create a connection with 'Players_information' text file.

        cout<<endl;
        cout<<"Enter registration NO: ";
        cin>>regNumber;
        cout<<endl;

        if(searchFile.is_open()){

            while(getline(searchFile, playerIn)){

                if(playerIn.length()>0){

                    stringstream ss(playerIn);
                    ss>>registrationNumber>>firstName>>lastName>>dateOfBirth>>runsScored>>team1>>team2;
                    //Above line to bring all player's information from the 'Players_information' text file.
                        
                        if(registrationNumber==regNumber){

                            cout<<"Player's registration NO: "<<registrationNumber<<endl;
                            cout<<"Player's name: "<<firstName<<" "<<lastName<<endl;
                            cout<<"Player's date of birth: "<<dateOfBirth<<endl;
                            cout<<"Runs scored by the player: "<<runsScored<<endl;
                            cout<<"Selected teams by the player:- "<<endl;
                            cout<<"  1.Team NO:01 : "<<team1<<endl;
                            cout<<"  2.Team NO:02 : "<<team2<<endl;

                        }
            
                }
            }

        }

        searchFile.close();

        cout<<endl;
        //This is for search another player, if user wants. Otherwise exit fron this function.
        cout<<"Do you want to search for any other player? (If, enter 'Y', if not, enter any other key to exit): ";
        cin>>searchPlayerChoice;
    
    }while(searchPlayerChoice=="Y");    
}

//Function for manage teams(Add players to the teams).
void manageTeams(){

    cout<<"--------------------------------------------"<<endl;
    cout<<endl;

    cout<<"---Manage teams---"<<endl;
    
    do{

        manageTeamsFile.open("Manage_teams.txt", ios_base::app); //To create a connection with 'Manage_teams' text file.

        cout<<endl;
        cout<<"Enter team name: ";
        cin>>teamName;
        manageTeamsFile<<teamName<<" "; //This is for store team name in the 'Manage_teams' text file.

        do{

            cout<<endl;
            cout<<"Enter player's registration number to add to the team: ";
            cin>>registrationNumberArray[i]; //Use an array to store player's registration numbers seperately to the 'Manage_teams' text file.

            manageTeamsFile<<registrationNumberArray[i]<<" "; //This is for store registration numbers in the 'Manage_teams' text file.

            cout<<endl;
            //This is for add another player, if user wants. Otherwise exit.
            cout<<"Do you want to add another player? (If, enter 'Y', if not, enter any other key to exit): ";
            cin>>addPlayerTeamChoice;

            i++;

        }while(addPlayerTeamChoice=="Y");

        cout<<endl;
        //This is for add players to another team, if user wants. Otherwise exit fron this function.
        cout<<"Do you want to add players to another team? (If, enter 'Y', if not, enter any other key to exit): ";
        cin>>addAnotherTeam;

        manageTeamsFile<<endl;

        manageTeamsFile.close();
    
    }while(addAnotherTeam=="Y");
}

//Function for view team details.
void viewTeamDetails(){

    cout<<"--------------------------------------------"<<endl;

    cout<<endl;
    cout<<"---View team details---"<<endl;
    
    do{
    
        viewTeamFile.open("Manage_teams.txt"); //To create connection with 'Manage_teams' text file.
        
        cout<<endl;
        cout<<"Enter team's name:";
        cin>>teamNameEnter;

        if(viewTeamFile.is_open()){

            while(getline(viewTeamFile, teamIn)){

                if(teamIn.length()>0){

                    stringstream ss(teamIn);
                    ss>>teamName;

                    if(teamName==teamNameEnter){

                        cout<<endl;
                        
                        cout<<teamName<<endl;
                        
                        //Below for loop code is for cout the registration numbers stored in the 'Manage_teams' text file using 'registrationNumberArray[]'.
                        for(int j=0; j<30; j++){

                            ss>>registrationNumberArray[j];

                            cout<<"  "<<registrationNumberArray[j];


                        }

                        cout<<endl<<endl;

                    }

                }

            }
        }

        viewTeamFile.close();

        //This is for serach about another team, if user wants. Otherwise exit fron this function.
        cout<<"Do you want to search for any other team? (If, enter 'Y', if not, enter any other key to exit): ";
        cin>>viewTeamDetailsChoice;

    }while(viewTeamDetailsChoice=="Y");

} 

// Do not delete any data of the text files when program is running.
// If does, some features of the program will not run as expected.
