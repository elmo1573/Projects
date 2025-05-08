#include <string>
#include <iostream>
using namespace std;
#include "Shoulder.cpp"
#include "Arms.cpp"
#include "Legs.cpp"
#include "Chest.cpp"
#include "BMI.cpp"
#include "Back.cpp"
#include "Nutrition.cpp"
#include "DailyRoutine.hpp"

    void  DailyRoutine:: showRoutine()
    {
        char day[7][20] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        int choice, option, i;

        for (i = 0; i < 7; i++)
        {
            cout << endl;

            cout << "------------------------" << endl;

            cout << "Daily routine for " << day[i] << endl;

            cout << "------------------------" << endl;

            cout << "\nEnter which exercise you want to perform\n";

            cout << "1. Legs\n2. Chest\n3. Arms\n4. Shoulder and Back\n";

            cin >> option;

            switch (option)
            {

            case 1:

                cout << "\nWhat level of Training would you like to Opt for?\n";

                cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

                cin >> choice;

                if (choice == 1)
                {

                    cout << "\nLegs workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Basic:" << endl;

                    LegsExercise::basicWorkout();
                }

                else if (choice == 2)
                {

                    cout << "\nLegs workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Intermediate:" << endl;

                    LegsExercise::intermediateWorkout();
                }

                else if (choice == 3)
                {

                    cout << "\nLegs workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Advanced:" << endl;

                    LegsExercise::advancedWorkout();
                }

                else
                {

                    cout << "Enter the correct Key" << endl;
                }

                break;

            case 2:

                cout << "\nWhat level of Training would you like to Opt for?\n";

                cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

                cin >> choice;

                if (choice == 1)
                {

                    cout << "\nChest workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Basic:" << endl;

                    ChestWorkout::basic();
                }

                else if (choice == 2)
                {

                    cout << "\nChest workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Intermediate:" << endl;

                    ChestWorkout::intermediate();
                }

                else if (choice == 3)
                {

                    cout << "\nChest workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Advanced:" << endl;

                    ChestWorkout::advanced();
                }

                else
                {

                    cout << "Enter the correct Key" << endl;
                }

                break;

            case 3:

                cout << "\nWhat level of Training would you like to Opt for?\n";

                cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

                cin >> choice;

                if (choice == 1)
                {

                    cout << "\nArms workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Basic:" << endl;

                    Arms::basicWorkout();
                }

                else if (choice == 2)
                {

                    cout << "\nArms workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Intermediate:" << endl;

                    Arms::intermediateWorkout();
                }

                else if (choice == 3)
                {

                    cout << "\nArms workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Advanced:" << endl;

                    Arms::advancedWorkout();
                }

                else
                {

                    cout << "Enter the correct Key" << endl;
                }

                break;

            case 4:

                cout << "\nWhat level of Training would you like to Opt for?\n";

                cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

                cin >> choice;

                if (choice == 1)
                {

                    cout << "\nShoulder & Back workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Basic:" << endl;

                    ShoulderBack::basicWorkout();
                }

                else if (choice == 2)
                {

                    cout << "\nShoulder & Back workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Intermediate:" << endl;

                    ShoulderBack::intermediateWorkout();
                }

                else if (choice == 3)
                {

                    cout << "\nShoulder & Back workout: " << endl;

                    cout << "---------------" << endl;

                    cout << "Advanced:" << endl;

                    ShoulderBack::advancedWorkout();
                }

                else
                {

                    cout << "Enter the correct Key" << endl;
                }

                break;

            default:
                cout << "Invalid-Key" << endl;
                cin >> option;
            }
        }
    }

