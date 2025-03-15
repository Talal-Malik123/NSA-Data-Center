
//

#include <iostream>
#include<windows.h>
#include <fstream>
#include<string>
using namespace std;
int ID;
struct agent {
    int id;
    string name;
    int age;
    string destination;
    string experience;
};

void addagent() {
    agent agent;
    cout << "\n\tEnter agent name : ";
    cin.get();
    getline(cin, agent.name); 
    cout << "\n\tEnter agent age : ";
    cin >> agent.age;
    cout << "\n\tEnter agent destination : ";
    cin >> agent.destination;
    cout << "\n\tEnter agent experience : ";
    cin >> agent.experience;
    ID++;

    ofstream write;
    write.open("agent.txt", ios::app);
    write << "\n" << ID;
    write << "\n" << agent.name ;
    write << "\n" << agent.age ;

    write << "\n" << agent.destination ;
    write << "\n" << agent.experience;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "\n\tData save to file";
}

void print(agent s) {
    cout << "\n\t---agent Data---";
    cout << "\n\tID is : " << s.id;
    cout << "\n\tName is : " << s.name;
    cout << "\n\tAge is : " << s.age;
    cout << "\n\tdestination is : " << s.destination;
    cout << "\n\texperience is : " << s.experience;

}

void readData() {
    agent agent;
    ifstream read;
    read.open("agent.txt");
    while (!read.eof()) {
        read >> agent.id;
        read.ignore();
        getline(read, agent.name);
        read >> agent.age;
        read >> agent.destination;
        read >> agent.experience;
        print(agent);
    }
    read.close();
}

int searchData() {
    int id;
    cout << "\n\tEnter agent id want to search : ";
    cin >> id;
    agent agent;
    ifstream read;
    read.open("agent.txt");
    while (!read.eof()) {
        read >> agent.id;
        read.ignore();
        getline(read, agent.name);
        read >> agent.age;
        read >> agent.destination;
        read >> agent.experience;
        if (agent.id == id) {
            print(agent);
            return id;
        }
    }
}

void deleteData() {
    int id = searchData();
    cout << "\n\tYou want to delete record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        agent agent;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("agent.txt");
        while (!read.eof()) {
            read >> agent.id;
            read.ignore();
            getline(read, agent.name);
            read >> agent.age;
            read >> agent.destination;
            read >> agent.experience;
            if (agent.id != id) {
                tempFile << "\n" << agent.id;
                tempFile << "\n" << agent.name;
                tempFile << "\n" << agent.age;
                tempFile << "\n" << agent.destination;
                tempFile << "\n" << agent.experience;
            }
        }
        read.close();
        tempFile.close();
        remove("agent.txt");
        rename("temp.txt", "agent.txt");
        cout << "\n\tData deleted successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

void updateData() {
    int id = searchData();
    cout << "\n\tYou want to update record (y/n) : ";
    char choice;
    cin >> choice;
    if (choice == 'y') {
        agent newData;
        cout << "\n\tEnter agent name : ";
        cin.get();
        getline(cin, newData.name);
        cout << "\n\tEnter agent age : ";
        cin >> newData.age;
        cout << "\n\tEnter agent destination : ";
        cin >> newData.destination;
        cout << "\n\tEnter agent experience : ";
        cin >> newData.experience;
        agent agent;
        ofstream tempFile;
        tempFile.open("temp.txt");
        ifstream read;
        read.open("agent.txt");
        while (!read.eof()) {
            read >> agent.id;
            read.ignore();
            getline(read, agent.name);
            read >> agent.age;
            read >> agent.destination;
            read >> agent.experience;
            if (agent.id != id) {
                tempFile << "\n" << agent.id;
                tempFile << "\n" << agent.name;
                tempFile << "\n" << agent.age;
                tempFile << "\n" << agent.destination;
                tempFile << "\n" << agent.experience;
            }
            else {
                tempFile << "\n"<< agent.id;
                tempFile << "\n"<< agent.name;
                tempFile << "\n"<< agent.age;
                tempFile << "\n" << agent.destination;
                tempFile << "\n"<< agent.experience;
            }
        }
        read.close();
        tempFile.close();
        remove("agent.txt");
        rename("temp.txt", "agent.txt");
        cout << "\n\tData updated successfuly";
    }
    else {
        cout << "\n\tRecord not deleted";
    }
}

int main()
{
	system("Color 0F");
	string ID,password;
	start:
	cout<<"\n\t\t\t|ENTER ID| ";
	cin>>ID;
	cout<<"\n\t\t\t--------------------";
	
	cout<<"\n\t\t\t|ENTER PASSWORD| ";
               cin>>password;	
	cout<<"\n\t\t\t---------------------";

	
	if(ID=="001"&&password=="1234")
	{
	cout<<"\n\t\t....YOU ARE LOGGED IN SUCCESSFULLY.... ";
	}
else if( ID=="001"&&password!="1234")

 
{
	cout<<"\n\t\t\tincorrect password";
	cout<<"\n\t\t\t---------------------";
	
	cout<<"\n\t\t\tPLEASE TRY AGAIN";

	goto start;		
}

else if((ID!="001")&& (password =="1234"))

{
	cout<<"\n\t\t\tincorrect ID";
	cout<<"\n\t\t\t---------------------";
	cout<<"\n\t\t\tPLEASE TRY AGAIN";
	goto start;		
}

	cout<<                           "\t\t\t\t\t....you are logged in....\n ";
	system                                         ("CLS");
	cout<<                			   "                                                        \n ";
	cout<<               				    "                                                  \n";
	cout<<                  			 "\t\t\t|               WELCOME                     |\n";
	cout<<                				   "                                                  \n";
	cout<<                   "\t\t\t|                 TO                        |\n";
	cout<<                   "                                                  \n";
	cout<<                   "\t\t\t|        NATIONAL SECURITY AGENCY           |\n";
	cout<<                   "                                                  \n";
	cout<<                   "\t\t\t     *********** N S A ***********                  \n";
	cout<<                   "                                                  \n";
	cout<<                   "\t\t\t|          INFORMATION CENTER               |  \n";
	cout<<                   "\t\t\t|                                           |  \n"; 
               cout<<        "\t\t\t-----please follow the given instructions----------\n";
               cout<<"                                                        \n ";
               cout<<"                                                        \n ";
               cout<<"                                                        \n ";
               cout<<"                                                        \n ";
               cout<<"                                                        \n ";
               
               
    ifstream read;
    read.open("id.txt");
    if (!read.fail()) {
        read >> ID;
    }
    else {
        ID ;
    }
    read.close();

    while (true) {
        cout << "\n\t1.CREATE AGENT DATA";
        cout << "\n\t2.READ AGENT DATA";
        cout << "\n\t3.UPDATE AGENT DATA";
        cout << "\n\t4.DELETE AGENT DATA";
        cout << "\n\t5.SEARCH AGENT DATA";

        int choice;
        
        cout << "\n\tEnter choice : ";
        cin >> choice;
        switch (choice) {
        case 1:
            addagent();
            break;
        case 2:
            readData();
            break;
        case 3:
            updateData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            searchData();
            break;
        }
    }

}


