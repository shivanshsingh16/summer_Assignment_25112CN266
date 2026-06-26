#include<iostream>
#include<vector>
using namespace std;

void q104()
{
    vector<vector<string>> userScores; 
    int input;
    
    while (true)
    {
        cout << "\n===== QUIZ APPLICATION =====\n";
        cout << "Enter input: 1- Take Quiz  2- View Leaderboard  3- View Individual Score  4- Exit\n";
        cin >> input;
        cin.ignore();  // Clear input buffer
        
        if (input == 1)
        {
            string username;
            cout << "Enter your name: ";
            getline(cin, username);
            
            int score = 0;
            cout << "\nWelcome " << username << "!\n";
            cout << "Answer all questions correctly to get points.\n";
            cout << "Each correct answer = 20 points\n\n";
            
            // Question 1
            cout << "Question 1: What is the capital of France?\n";
            cout << "1. London  2. Berlin  3. Paris  4. Amsterdam\n";
            cout << "Enter your answer (1-4): ";
            int ans1;
            cin >> ans1;
            if (ans1 == 3)
            {
                cout << "Correct!\n\n";
                score += 20;
            }
            else
            {
                cout << "Wrong! Correct answer is Paris.\n\n";
            }
            
            // Question 2
            cout << "Question 2: What is 15 * 4?\n";
            cout << "1. 50  2. 60  3. 70  4. 80\n";
            cout << "Enter your answer (1-4): ";
            int ans2;
            cin >> ans2;
            if (ans2 == 2)
            {
                cout << "Correct!\n\n";
                score += 20;
            }
            else
            {
                cout << "Wrong! Correct answer is 60.\n\n";
            }
            
            // Question 3
            cout << "Question 3: In which year did World War II end?\n";
            cout << "1. 1943  2. 1944  3. 1945  4. 1946\n";
            cout << "Enter your answer (1-4): ";
            int ans3;
            cin >> ans3;
            if (ans3 == 3)
            {
                cout << "Correct!\n\n";
                score += 20;
            }
            else
            {
                cout << "Wrong! Correct answer is 1945.\n\n";
            }
            
            // Question 4
            cout << "Question 4: Which element has the atomic number 8?\n";
            cout << "1. Carbon  2. Nitrogen  3. Oxygen  4. Fluorine\n";
            cout << "Enter your answer (1-4): ";
            int ans4;
            cin >> ans4;
            if (ans4 == 3)
            {
                cout << "Correct!\n\n";
                score += 20;
            }
            else
            {
                cout << "Wrong! Correct answer is Oxygen.\n\n";
            }
            
            // Question 5
            cout << "Question 5: What is the largest ocean on Earth?\n";
            cout << "1. Atlantic  2. Indian  3. Arctic  4. Pacific\n";
            cout << "Enter your answer (1-4): ";
            int ans5;
            cin >> ans5;
            if (ans5 == 4)
            {
                cout << "Correct!\n\n";
                score += 20;
            }
            else
            {
                cout << "Wrong! Correct answer is Pacific.\n\n";
            }
            
            cout << "========== QUIZ COMPLETED ==========\n";
            cout << "Name: " << username << endl;
            cout << "Your Score: " << score << "/100\n";
            cout << "========================================\n\n";
            
            userScores.push_back({username, to_string(score)});
        }
        else if (input == 2)
        {
            if (userScores.size() == 0)
            {
                cout << "No one has taken the quiz yet!\n";
            }
            else
            {
                cout << "\n========== LEADERBOARD ==========\n";
                cout << "Rank\tName\t\t\tScore\n";
                cout << "================================\n";
                
                for (int i = 0; i < userScores.size(); i++)
                {
                    cout << (i + 1) << "\t" << userScores[i][0] << "\t\t" << userScores[i][1] << "/100\n";
                }
                
                // Calculate statistics
                int total = 0;
                int highest = 0;
                int lowest = 100;
                
                for (int i = 0; i < userScores.size(); i++)
                {
                    int score = stoi(userScores[i][1]);
                    total += score;
                    if (score > highest)
                        highest = score;
                    if (score < lowest)
                        lowest = score;
                }
                
                cout << "================================\n";
                cout << "Total Attempts: " << userScores.size() << endl;
                cout << "Average Score: " << (total / userScores.size()) << "/100\n";
                cout << "Highest Score: " << highest << "/100\n";
                cout << "Lowest Score: " << lowest << "/100\n";
            }
        }
        else if (input == 3)
        {
            cin.ignore();
            string searchName;
            cout << "Enter name to search: ";
            getline(cin, searchName);
            
            bool found = false;
            for (int i = 0; i < userScores.size(); i++)
            {
                if (userScores[i][0] == searchName)
                {
                    found = true;
                    cout << "\n========== SCORE DETAILS ==========\n";
                    cout << "Name: " << userScores[i][0] << endl;
                    cout << "Score: " << userScores[i][1] << "/100\n";
                    cout << "===================================\n";
                }
            }
            
            if (!found)
            {
                cout << "User not found!\n";
            }
        }
        else if (input == 4)
        {
            cout << "Thank you for using Quiz Application!\n";
            break;
        }
        else
        {
            cout << "Invalid input! Please try again.\n";
        }
    }
}

int main()
{
    q104();
    return 0;
}