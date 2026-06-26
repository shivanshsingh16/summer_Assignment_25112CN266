#include<iostream>
#include<vector>
using namespace std;


void q102()
{
    vector<vector<int>> voters;  
    int input;
    while(true)
    {
        cout << "\n===== VOTING ELIGIBILITY SYSTEM =====\n";
        cout << "enter input: 1- Register Voter  2- Cast Vote  3- Check Voter Status  4- Exit\n";
        cin >> input;
        
        if (input == 1)
        {
            int age;
            cout << "Enter your age: ";
            cin >> age;
            
            if (age >= 18)
            {
                voters.push_back({age, 0});  // 0 means not voted yet
                cout << "Voter registered successfully!\n";
                cout << "You are eligible to vote.\n";
            }
            else
            {
                cout << "Error! You must be 18 or older to register.\n";
                cout << "Your age: " << age << " (Not eligible)\n";
            }
        }
        else if (input == 2)
        {
            int voterId;
            cout << "Enter voter ID (0 to " << voters.size() - 1 << "): ";
            cin >> voterId;
            
            bool found = false;
            if (voterId >= 0 && voterId < voters.size())
            {
                found = true;
                if (voters[voterId][1] == 0)
                {
                    voters[voterId][1] = 1;
                    cout << "Vote cast successfully!\n";
                    cout << "Thank you for voting.\n";
                }
                else
                {
                    cout << "Error! You have already voted.\n";
                }
            }
            
            if (!found)
            {
                cout << "Voter ID not found!\n";
            }
        }
        else if (input == 3)
        {
            int voterId;
            cout << "Enter voter ID (0 to " << voters.size() - 1 << "): ";
            cin >> voterId;
            
            if (voterId >= 0 && voterId < voters.size())
            {
                cout << "Voter Age: " << voters[voterId][0] << endl;
                if (voters[voterId][0] >= 18)
                {
                    cout << "Eligibility Status: ELIGIBLE\n";
                    if (voters[voterId][1] == 1)
                    {
                        cout << "Voting Status: VOTED\n";
                    }
                    else
                    {
                        cout << "Voting Status: NOT VOTED\n";
                    }
                }
                else
                {
                    cout << "Eligibility Status: NOT ELIGIBLE\n";
                }
            }
            else
            {
                cout << "Voter ID not found!\n";
            }
        }
        else if (input == 4)
        {
            cout << "Thank you for using Voting System!\n";
            break;
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }
    }
}


int main(){
    q102();
}