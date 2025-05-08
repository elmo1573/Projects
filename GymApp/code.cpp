#include <string>
#include <iostream>
#include <vector>
#include <SDL.h>
using namespace std;

Class MemberAccount{
  string name;
  int age;
  float height,weight,waist;

public:
  
  MemberAccount(string _n, int _a, float _h,float _weight,float _w):name(_n),age(_a),height(_h),weight(_w),waist(_w){}
  string getName() const { return name; }

  int getAge() const { return age; }
  float getHeight() const { return height; }
  float getWeight() const { return weight; }
  float getWaistSize() const { return waist; }

  void setName(string n) { name = n; }
  void setAge(int a) { age = a; }
  void setHeight(float h) { height = h; }
  void setWeight(float w) { weight = w; }
  void setWaistSize(float ws) { waistSize = ws; }
};

class Trainer{
string name,gender,charges;
int age,rating;
public:
    Trainer(){}
    Trainer(string _name,string _gender, string _charges, int _ age, int _ rate):name(_name), gender(_gender),charges(_charges), age(_age), rating(_rate){}
    
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    int getRating() const { return rating; }
    string getcharges() const {return charges;}

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGender(string gender) { this->gender = gender; }
    void setRating(int rating) { this->rating = rating; }
    void setCharges(string charges){this -> charges=charges;}

    friend ostream& operator<<(ostream& os, const Trainer& trainer);

};

ostream& operator << (ostream& T, const Trainer& trainer){
    T << "Name: " << trainer.name << endl;
    T << "Gender: " << trainer.gender << endl;
    T << "Rating: " << trainer.rating << endl;
    T << "Cost: " << trainer.cost <<endl;
    return T;
}
};

class Chest{public:
virtual void basic()=0;
virtual void intermediate()=0;
virtual void advanced()=0;
}

class ChestWorkout:public Chest{
public:
void basic()  override{
  cout<<"Here is a basic chest workout plan. All the best!"<<endl<<"Max rest between sets : 1-2 mins;
  cout<<"Dumbbell Bench Press 3x12"<<endl<<"Barbell Bench Press 3x8"<<endl<<"Wide grip Pushups 3x20"<<endl<<"Incline Barbell press 4x10"<<endl<<"Incline DB Fly's 3x8"<<endl<<"Have a       Good Workout!";    }

void intermediate() override{
  cout<<"Here is an Intermediate Chest workout plan. All the best!"<<endl<<"Max rest between sets : 45-70 seconds";                        
  cout<<"Dumbbell Bench Press 4x12"<<endl<<"Barbell Bench Press 3x12"<<endl<<"Wide grip Pushups 5x12"<<endl<<"Incline Barbell press 4x12"<<endl<<"Incline DB Fly's 3x10"<<endl<<"Decline Press(Smith Machine) 3x10 "<<endl<<"Have a Good Workout!";    }

void advanced()override{  cout<<"Here is an ADVANCED Chest workout plan. All the best!"<<endl<<"Max rest between sets : 15-40 seconds";                        
  cout<<"Flat Barbell Bench Press 4x12 + Incline DB Press 4x12 superset "<<endl<<"DB Bench Press 3x15 + Machine Flies 3x12 Superset "<<endl<<"Wide grip Pushups 3x10 + Diamond Pushups 3x20 superset "<<endl<<"Incline Barbell press 4x12"<<endl<<"Incline DB Fly's 3x10"<<endl<<"Decline Press(Smith Machine) 3x10 "<<endl<<"Hope you survived :) Good Job!";    }
};

class Back{public:
virtual void basic()=0;
virtual void intermediate()=0;
virtual void advanced()=0;
}

class BackWorkout:public Back{
public:
void basic()  override{
  cout<<"Here is a basic BACK workout plan. All the best!"<<endl<<"Max rest between sets : 1-2 mins;
cout<<"Barbell Overhand Rows 3x12"<<endl<<"Barbell Underhand Rows 3x8"<<endl<<"Wide Grip Lat pulldown 3x10"<<endl<<"Seated Machine Rows 4x10"<<endl<<"Dumbbell Pullover 3x8"<<endl<<"Have a Good Workout!";    }

void intermediate() override{
  cout<<"Here is an Intermediate Back workout plan. All the best!"<<endl<<"Max rest between sets : 45-70 seconds";                        
  cout<<"V-Grip Lat Pulldown 2x15"<<endl<<"Single Arm Seated Rows 3x12"<<endl<<"Deadlift 3x 12/10/8 (Progressively overload the Weight)"<<endl<<"Chest Supported DB Rows"<<endl<<"5 Mins Stretching"<<endl<<"Rope Pulldown 2x10"<<endl<<"Have a Good Workout!";    }

void advanced()override{  cout<<"Here is an ADVANCED Back workout plan. All the best!"<<endl<<"Max rest between sets : 15-40 seconds";                        
  cout<<"Heavy Deadlift 3x12/10/8"<<endl<< "Barbell Overhand Rows 3x12 (Heavy)"<<endl<<"DB Single Arm Rows 3x15 + Lat Pulldown (Wide Grip) 3x12 Superset "<<endl<<"Close grip Lat pulldown 3x12 (max 20 sec  rest)"<<endl<<"Incline Barbell press 4x12"<<endl<<"Incline DB Fly's 3x10"<<endl<<"Decline Press(Smith Machine) 3x10 "<<endl<<"Hope you survived :) Good Job!";    }
};


class LegsExercise : public Legs {

public:

    void basicWorkout(){
        cout<<("25 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:15\n");
        cout<<("Side Hops\t00:30\n");
        cout<<("Squats x12\n");
        cout<<("25 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:15\n");
        cout<<("Side Hops\t00:30\n");

    }

    void intermediateWorkout(){

        cout<<("25 minutes\t12 workouts\n\n");

        cout<<("Jumping Jacks\t00:15\n");

        cout<<("Squats x14\n");

        cout<<("Squats x14\n");

        cout<<("Fire Hydrant Right x12\n");

        cout<<("Fire Hydrant Left x14\n");

        cout<<("Lunges x16\n");

        cout<<("Side Leg Circles Left x12\n");

        cout<<("Side Leg Circles right x12\n");

        cout<<("Sumo Squat x12\n");

        cout<<("Reverse Flutter Kicks x12\n");


    }

    void advancedWorkout(){



        cout<<("Squats x14\n");

        cout<<("Side Leg Circles right x12\n");

        cout<<("Curtsy Lunges x16\n");

        cout<<("Jumping squats x14\n");

        cout<<("Wall Sit\t00:40\n");


        cout<<("Glute kickback  x12\n");

        cout<<("Calf stretch left\t00:40\n");

        cout<<("Calf stretch right\t00:40\n");

        cout<<("Lying butterfly stretch\t00:40\n");

        cout<<("Leaning stretcher raises x12\n");

    }

};


class Arms {

public:

    void basicWorkout() {




        cout<<("Tricep Dips x10\n");
        cout<<("Diamond Pushups x6\n");
        cout<<("Chest Press Pulse\t00:16\n");
        cout<<("Diamond Plank x10\n");

        
    }

    void intermediateWorkout() {
cout<<("Arm Circles Counterclockwise\t00:30\n");

        cout<<("Floor Tricep Tips x14\n");

        cout<<("Military Pushups x16\n");

        cout<<("Alternating Hooks\t00:30\n");

        cout<<("Push-Ups And Rotation x12\n");

        cout<<("Left Barbell Curl Left x12\n");


        cout<<("Triceps Stretch Left\t00:30\n");

        cout<<("Triceps Stretch Right\t00:30\n");

    }



    void advancedWorkout() {
  cout<<("Arm Circles Clockwise\t00:30\n");

        cout<<("Arm Circles Counterclockwise\t00:30\n");

        cout<<("Skipping Without Rope\t 00:30\n");

        cout<<("Left Barbell Curl Left x16\n");

        cout<<("Left Barbell Curl Right x16\n");

        cout<<("Floor Tricep Tips x14\n");

        cout<<("Military Pushups x16\n");

        cout<<("Alternating Hooks\t00:30\n");

        cout<<("Triceps Stretch Left\t00:30\n");

        cout<<("Triceps Stretch Right\t00:30\n");

        cout<<("Jumping Jacks\t00:25\n");


    }

};

class ShoulderBack {

public:

    void basicWorkout() {


        cout<<("Jumping Jacks\t00:15\n");

        cout<<("Arm Raises\t00:30\n");

        cout<<("Side Arm Raises\t00:16\n");

        cout<<("Knee Pushups x14\n");

        cout<<("Arm Scissors\t00:30\n");

        cout<<("Rhomboid Pulls x12\n");

        cout<<("Cat Cow Pulls\t00:30\n");

        cout<<("Prone Triceps Pushups x14\n");

    }



    void intermediateWorkout() {

        cout<<("Jumping Jacks\t00:30\n");

        cout<<("Child's Pose\t00:30\n");

        cout<<("Hover Push up x12\n");

        cout<<("Floor tricep dips x14\n");

        cout<<("Cat Cow Pulls\t00:30\n");

        cout<<("Incline Pushups x14\n");

        cout<<("Triceps kickbacks x14\n");

        cout<<("Hip hinges x10\n");

        cout<<("Triceps kickbacks x14\n");

        cout<<("Arm Scissors\t00:30\n");


    }



    void advancedWorkout() {


        cout<<("Jumping Jacks\t00:15\n");

        cout<<("Inch worm x14\n");

        cout<<("Hyper extension x12\n");

        cout<<("Cat Cow Pose\t00:30\n");

        cout<<("Child's Pose\t00:30\n");

        cout<<("Reverse snow angels x12\n");

        cout<<("Reverse push ups x12\n");

        cout<<("Side lying floor stretch left\t00:30\n");

        cout<<("Side lying floor stretch right\t00:30\n");

        cout<<("Floor Y raises x12\n");

        cout<<("Arm Scissors\t00:30\n");

    }

};

class BMI {

private:

    double height;

    double weight;

    double bmi;

public:

    BMI(){}
    void set(double height, double weight) {
        this->height = height;
        this->weight = weight;
    }
    void calcBMI() {
      bmi = weight / pow(height, 2);
    }
    double getBMI()  
    {   return bmi;
    }

};

class Nutrition {

public:

    

    void showDailyDiet(BMI B) {

        if (B.getBMI() < 18.5) {

            cout << "Daily diet plan for Underweight person" << endl;

            cout<<("Below is the meal plan generated for you.\n\n");

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  MONDAY                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|         Cereal         |       Roast Beef    |     Grilled salmon    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("| Muesli with fresh fruit|       Sandwich      |    Asparagus salad    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Low fat milk    |    Fruits Smoothy   |          Peach        |\n");

       cout<<(" -----------------------------------------------------------------------\n");

      cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  TUESDAY                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Toaste with cheese   |   Baked Tuna Pasta  |      White Salad      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|     Fresh tomato       |    Parmesan Cheese  |    Bluberry Muffins   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|      Butter Lettuce    |    Fruit smoothie   |      Rice Cracker     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Wednesday                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Multigrain bread    | Deep Dark Chocolate |      Pumpkin Soup     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|     Grilled salmon     | Troasted Vegetables |       Boiled Corn     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|        Avocado         |       Pretzel       | Toasted Turkish Bread |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Thursday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|          1 Banana      |       Turkey Wrap   |    4 Salmon fillet    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Cooked oat meal |       1 Banana      | 4Fresh Pineapple Rings|\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1/4 Cup Raisens       |      Protein Bar    |   1/2 Cup Brown Rice  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("\n\n"); Sleep(1);

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Friday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|           1 Tuna       |Ukrainian borsch soup|    Mongolian beef     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|      Boiled egg        |    Toasted bread    |   pumpkin pastry pie  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Green salad leaves   |     Banana bread    |     Steamed carrot    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Saturday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Croissants with jam   |   Pasta marinara    |     Seafood pizza     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1/2 Cup Fruit Salad   | vegetable sandwich  |   Mahi Mahi Tacos     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Almond and Orange    |   1 Boiled Corn     |    1 Small Totrilla   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

   cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Sunday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Oatmeal with Apples   |    Cheese Sandwich  |     Roasted beef      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Whole Grain Toast   |    Green  Salad     |     1 Cup Walnuts     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Chocolate cake slice |   Fruit smoothie    |   Chicken Breasts     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

        } else if (B.getBMI() < 25) {

        cout << "Daily diet plan for Normal person" << endl;

        cout<<("Below is the meal plan generated for you.\n\n");

            cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  MONDAY                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       1 Banana         |    Turkey Sandwich  |      Chicken Breast   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Cooked meal     |    Cereal Bar       |  Baked Sweet Potato   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Low fat milk    |    Fruits Smoothy   |          Peach        |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|     1/4 Cup Walnuts    |         Apple       |    Cup Low Fat Milk   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

      cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  TUESDAY                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Cup Whole Wheat CereaL|    English Muffin   |    4 Red Potatoes     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Low Fat Milk    |    Cup Melon        |   4 Cup Mango Salsa   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  3/4 Cup BlueBerries   |2 Cup Cottage Cheese | 1/2 Cup Low Fat Milk  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Wednesday                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Eggs and 3 Eggs White |Salad with Chicken   |    4 Chicken BreasT   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Whole Grain Toast   |    1 Banana         |       Quesadilla      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Low fat milk    |    2 Pretzel        |Spinich Cucumber Salad |\n");

       cout<<(" -----------------------------------------------------------------------\n");

	cout<<("\n\n"); Sleep(1);

		cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Thursday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|        1 Banana        |       Turkey Wrap   |    4 Salmon fillet    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Cooked oat meal |       1 Banana      | Fresh Pineapple Rings |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    1/4 Cup Raisens     |      Protein Bar    |   1/2 Cup Brown Rice  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Friday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|          1 Banana      | Tuna Salad Sandwich |  Salad With Chicken   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Cup Whole Wheat Cereal|       1 Pear        |     5 Strawberries    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   1 Cup Low fat milk   |1Cup Non FattyYoghurt| 1 Cup Low Fat Milk    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Saturday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   3 Medium Pan Cakes   | Salad with salmon   | 1 Cup Steamed Carrots |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1/2 Cup Fruit Salad   |       2 Pear        |       Boiled Corn     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   1 Cup Low fat milk   |   1 Boiled Corn     |    1 Small Totrilla   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

   cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Sunday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Eggs and 3 Eggs White |GrilledCheeseSandwich|  Turkey Burger        |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Whole Grain Toast   |  1 Banana Muffin    |    1 Cup Watermelon   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   1 Cup Low fat milk   |     4 Cup almond    | 1 Cup Low Fat Milk    |\n");

      cout<<(" -----------------------------------------------------------------------\n");

        }

        else {

        	cout << "Daily diet plan for Overweight person" << endl;

            cout<<("Below is the meal plan generated for you.\n\n");

   cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  MONDAY                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Egg white wrap      |    Chickpea Burger  |      Chicken Satay    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Oatmeal with apples   | Apple Berry Smoothie|     Roasted Salmon    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Yogurt and Almonds    |    Mexican Pizza   |          Peach        |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|     2 Eggs and Toast   |         Apple       |    Cup Low Fat Milk   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

      cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                  TUESDAY                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("| Bagel and cream cheese |    English Muffin   |   Black Bean Chilli   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Oatmeal with apples   |     Veggie Salad    |     Turkey Kebabs     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    3/4 Cup Walnuts     |2 Cup Cottage Cheese | 1/2 Cup Low Fat Milk  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Wednesday                             |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |          Dinner       |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Waffles and Bananas  | Turkey And Avocade  |    4 Chicken BreasT   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Whole Grain Toast   |    2 Pretzel        |      Roasted Salmon   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1 Cup Low fat milk    |    2 Bananas        | Spinich Cucumber Salad|\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Thursday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   2 Eggs and Toast     |  Salmon & Blueberry |    4 chicken fillet   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Oat Meal         |Grilled Veggie Salad |    4 Pineapple Rings  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    1/4 Cup Raisens     |      Protein Bar    |   1/2 Cup Brown Rice  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Friday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

      cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

      cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|          1 Banana      |  Seared Tuna Salad  |  Mediterranean Pizza  |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Cup Whole Wheat Cereal|       1 Pear        |     5 Strawberries    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   1 Cup Low fat milk   |Turkey  Avocade Wrap |    Black Bean Chili   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Saturday                              |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|2 Eggs and 3 Eggs White |  Chickpea Burgers   |  Shrimp Veracruzana   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  1/2 Cup Fruit Salad   |    Mexican Pizza    |   Mahi Mahi Tacos     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   Almond and Orange    |   1 Boiled Corn     |    1 Small Totrilla   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

cout<<("\n\n"); Sleep(1);

   cout<<(" -----------------------------------------------------------------------\n");

cout<<("|                                Sunday                                |\n");

cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|       Breakfast        |         Lunch       |           Dinner      |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|  Oatmeal with Apples   |    Cheese Sandwich  |     Roasted salmon    |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|    Whole Grain Toast   |    Salmon Salad     |    1 Cup Watermelon   |\n");

       cout<<(" -----------------------------------------------------------------------\n");

       cout<<("|   1 Cup Low fat milk   |     4 Cup almond    |   Chicken Breasts     |\n");

       cout<<(" -----------------------------------------------------------------------\n");

        }

    }

};

class DailyRoutine : public LegsExercise, public ChestExercise, public Arms, public ShoulderBack, public Abs {

public:
  void showRoutine()
{
	char day[7][20]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
   int choice,option,i;


	for(i=0;i<7;i++){		cout<<endl;

		cout << "------------------------" << endl;

		cout<<"Daily routine for "<<day[i]<<endl;

		cout << "------------------------" << endl;

		cout<<"\nEnter which exercise you want to perform\n";

		cout<<"1. Legs\n2. Chest\n3. Arms\n4. Shoulder and Back\n";

		cin>>option;

		switch(option){

			case 1:

				cout << "\nWhat level of Training would you like to Opt for?\n";

	    		cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

	    		cin >> choice;

	    		if(choice==1){

	    			cout << "\nLegs workout: " << endl;

	     			cout << "---------------" << endl;

	     			cout << "Basic:" << endl;

	     			LegsExercise::basicWorkout();

				}

				else if(choice==2){

					cout << "\nLegs workout: " << endl;

	     			cout << "---------------" << endl;

					cout << "Intermediate:" << endl;

	     			LegsExercise::intermediateWorkout();

				}

				else if(choice==3){

					cout << "\nLegs workout: " << endl;

	     			cout << "---------------" << endl;

					 cout << "Advanced:" << endl;

	     			LegsExercise::advancedWorkout();

				}

				else{

					cout<<"Enter the correct Key"<<endl;

				}

				break;

			case 2:

				cout << "\nWhat level of Training would you like to Opt for?\n";

	    		cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

	    		cin >> choice;

	    		if(choice==1){

	    			cout << "\nChest workout: " << endl;

	   				cout << "---------------" << endl;

	  				cout << "Basic:" << endl;

	    			ChestExercise::basicWorkout();	

				}

				else if(choice==2){

					cout << "\nChest workout: " << endl;

	   				cout << "---------------" << endl;

	   				cout << "Intermediate:" << endl;

	    			ChestExercise::intermediateWorkout();

				}

				else if(choice==3){

					cout << "\nChest workout: " << endl;

	   				cout << "---------------" << endl;

	   				cout << "Advanced:" << endl;

	   				ChestExercise::advancedWorkout();

				}

				else{

					cout<<"Enter the correct Key"<<endl;

				}

				break;

			case 3:

				cout << "\nWhat level of Training would you like to Opt for?\n";

	    		cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

	    		cin >> choice;

	    			if(choice==1){

	    				cout << "\nArms workout: " << endl;

	    				cout << "---------------" << endl;

	    				cout << "Basic:" << endl;

	    				Arms::basicWorkout();	

				}

				else if(choice==2){

					cout << "\nArms workout: " << endl;

	    			cout << "---------------" << endl;

	   				cout << "Intermediate:" << endl;

	    			Arms::intermediateWorkout();

				}

				else if(choice==3){

					cout << "\nArms workout: " << endl;

	    			cout << "---------------" << endl;

	   				cout << "Advanced:" << endl;

	    			Arms::advancedWorkout();

				}

				else{

					cout<<"Enter the correct Key"<<endl;

				}

				break;

			case 4:

				cout << "\nWhat level of Training would you like to Opt for?\n";

	    		cout << "1. Basic \n2. Intermediate\n3. Advanced\n";

	    		cin >> choice;

	    			if(choice==1){

	    			cout << "\nShoulder & Back workout: " << endl;

	    			cout << "---------------" << endl;

	    			cout << "Basic:" << endl;

	    			ShoulderBack::basicWorkout();

				}

				else if(choice==2){

					cout << "\nShoulder & Back workout: " << endl;

	    			cout << "---------------" << endl;

	   				cout << "Intermediate:" << endl;

	   				ShoulderBack::intermediateWorkout();	

				}

				else if(choice==3){

					cout << "\nShoulder & Back workout: " << endl;

	    			cout << "---------------" << endl;

	   				cout << "Advanced:" << endl;

	    			ShoulderBack::advancedWorkout();

				}

				else{

					cout<<"Enter the correct Key"<<endl;

				}

				

				break;

			default:
				cout<<"Invalid-Key"<<endl;	
				cin>>option;	
		}
	}
}
};

class MonthlyProgress {
private:
    double weight_day1;
    double weight_day7;
    double waist_day1;
    double waist_day7;
public:
    MonthlyProgress(double w1, double w7, double wd1, double wd7) : weight_day1(w1), weight_day7(w7), waist_day1(wd1), waist_day7(wd7) {}
    string report() const {
        double weight_loss = weight_day1 - weight_day7;
        double waist_loss = waist_day1 - waist_day7;
        double weight_gain = weight_day7 - weight_day1;
        double waist_gain = waist_day7 - waist_day1;
        if (weight_loss > 0 && waist_loss > 0) {
            return "Great job! You lost " + to_string(weight_loss) + "kg of weight and " + to_string(waist_loss) + "cm of waist in one month!";
        } else if (weight_loss > 0 && waist_loss <= 0) {
            return "Good job! You lost " + to_string(weight_loss) + "kg of weight but your waist didn't change in one month!";

        } else if (weight_loss <= 0 && waist_loss > 0) {

            return "Good job! You didn't lose weight but you lost " + to_string(waist_loss) + "cm of waist in one month!";

        } else if(weight_gain > 0 && waist_gain >0){

        	return "Great job! You gain " + to_string(weight_gain) + "kg of weight and " + to_string(waist_gain) + "cm of waist in one month!";

		} else if(weight_gain > 0 && waist_gain <0){

			return "That is not possible, you might have entered incorrect values ";

		} else if(waist_gain > 0 && weight_gain <0){

			return "That is not possible, you might have entered incorrect values ";

		} 
		else{
            return "Oops! You didn't make any progress in one month. Keep trying!";
        }
    }
};


int main() {

    string name,rate;

    int age,opt,choi;

    double weight, height,h, waist, weight1, waist1;

    char gender,choice;

    BMI b;





    cout << endl<<endl;

	cout<<"------------------Enter Your Information--------------"<<endl<<endl<<endl;

    cout << "Please enter your name: ";

    getline(cin, name);

    cout << "Please enter your age: ";

    cin >> age;

    while (cin.fail() || age <= 12) {

        cin.clear();

        cin.ignore(10000, '\n');

        cout << "Invalid input! You are not capable enough to workout,Kindly enter the correct Key: ";

        cin >> age;

    }

    cout << "Please enter your weight in kilograms: ";

    cin >> weight;

    while (cin.fail() || weight <= 20) {

        cin.clear();

        cin.ignore(10000, '\n');

 		cout << "Invalid input! You are not capable enough to workout,Kindly enter the correct Key: ";

        cin >> weight;

    }

    cout << "Please enter your height in feets: ";

    cin >> h;

    while (cin.fail() || h <= 3.5) {

        cin.clear();

        cin.ignore(10000, '\n');

 		cout << "Invalid input! You are not capable enough to workout,Kindly enter the correct Key: ";      

  	 	cin >> h;

    }

    cout << "Please enter the size of your waist: ";

    cin >> waist;

    while (cin.fail() || waist <= 15){

        cin.clear();

        cin.ignore(10000, '\n');

 		cout << "Invalid input! You are not capable enough to workout,Kindly enter the correct Key: ";      

  	 	cin >> waist;

    }

    cout << "Please enter your gender (M/F): ";

    cin >> gender;

    while (gender != 'M' && gender != 'F') {

        cin.clear();

        cin.ignore(10000, '\n');

        cout << "Invalid input! Please enter either M for male or F for female: ";

        cin >> gender;

    }

    height=h/3.37;

    Sleep(10);

    system("cls");

    do{

    	cout<<"\nHello "<<name;

    	cout<<" do you want to generate a seven days meal plan for you or you want to go for someworkout or you want to exit?\n";

    	cout<<"--NOTE--If you go for the workout then you have to complete the goal for the seven days before that you cannot quit--"<<endl;

	    cout<<"1. Meal Plan\n2. Workout\n3. Exit\n";

	    cin>>opt;

	    if(opt==1){

	    	Sleep(1);

	    	system("cls");

	    	b.set(height, weight);

	    	b.calcBMI();

	    	cout << "Your BMI is: " << b.getBMI() << endl;

	    	Nutrition nutrition;

	    	if (b.getBMI() < 18.5) {

	        	nutrition.showDailyDiet(b);

	        	cout << endl;

	        	system("pause");

	        	system("cls");

	    	} else if (b.getBMI() >= 18.5 && b.getBMI() < 25) {

	      	  	nutrition.showDailyDiet(b);

	      	  	cout << endl;

	        	system("pause");

	        	system("cls");

	    	} else if (b.getBMI() >= 25 && b.getBMI() < 30) {

	        	nutrition.showDailyDiet(b);

	        	cout << endl;

	        	system("pause");

	        	system("cls");

	    	} else {

	        	nutrition.showDailyDiet(b);

	        	cout << endl;

	        	system("pause");

	        	system("cls");

	    	}

		}

		else if(opt==2){

			system("cls");

			DailyRoutine routine;

	    	routine.showRoutine();

	    	cout << endl;

	        system("pause");

	        system("cls");

		}

	}while(opt!=3);

	system("cls");

	Trainer T("Haris",30,"Male",5,"20$");

	Trainer T1("Huzaifa",28,"Male",4,"18$");

	Trainer T2("Marium",25,"Female",5,"18$");

	Trainer T3("Alina",27,"Female",4,"15$");

	cout<<"In order to know the progress " << name <<", you would need a Trainer to keep track of you progress\n";

	cout << "So do you need one of our certified trainer? (Y/N): ";

    cin >> choice;

    bool needTrainer = false;

    while (choice != 'Y' && choice != 'N'){

        cin.clear();

        cin.ignore(10000, '\n');

        cout << "Invalid input! Please enter either Y for yes or N for no: ";

        cin >> choice;

	}

	    if (choice == 'Y') {

	        needTrainer = true;

	        if(gender=='M'){

	        	cout<<endl<<"Below is the list of our Trainers"<<endl<<endl;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"TRAINER 1 INFORMATION:"<<endl;

	        	cout<<T;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"TRAINER 2 INFORMATION:"<<endl;

	        	cout<<T1;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"Select any one of the trainer you want\n1. Trainer 1\n2. Trainer 2\n";

	        	cin>>choi;

	        	while(choi!=1 && choi!=2){

	        		cout<<"Invalid Key,Kindly enter the correct key:";

	        		cin>>choi;

				}

	        	if(choi==1){

	        		system("cls");

	        		cout << "Congrats!! You have been scheduled a session with one of our certified trainer "<<T.getName()<<" who will tell you your Monthly Progress"<<endl;

					cout<<"So for that:"<<endl;

	        		cout<<name<<", Kindly enter your weight in the last week of the month:";

					cin>>weight1;

					cout<<name<<", Kindly enter the size of waist in the last week of the month:";

					cin>>waist1;

					MonthlyProgress progress(weight, weight1, waist, waist1);

					cout << "\nPress '+' to view monthly progress report or 'Q' to quit: ";

	        		cin >> choice;

	        		while(choice!='+' && choice!='Q'){

	        			cout<<"Invalid input,Enter the correct Key:";

	        			cin>>choice;

	        		}

        				if (choice == '+'){

            				cout << progress.report() << endl;

		            		system("pause");

		            		system("cls");

			        		cout<<"Kindly rate our app out of ***** stars:";

							cin>>rate;

							while(rate!="*" && rate!="**" && rate!="***" && rate!="****" && rate!="*****"){

								cout<<"Invalid input,Enter the correct Key:";

								cin>>rate;

							}

							cout<<"Thankyou for rating us "<<rate <<" stars, have a good day."<<endl<<endl;

							cout<<"--------------------------------------------------------------------------------------"<<endl;

							cout<<"EXERCISE NOT ONLY CHANGE YOUR BODY, IT CHANGES YOUR MIND, YOUR ATTITUDE AND YOUR MOOD"<<endl;

							cout<<"--------------------------------------------------------------------------------------"<<endl;

		    			}

	        	

				}

				else if(choi==2){

						system("cls");

						cout << "Congrats!! You have been scheduled a session with one of our certified trainer "<<T1.getName()<<" who will tell you your Monthly Progress"<<endl;

						cout<<"So for that:"<<endl;

		        		cout<<name<<" enter your weight in the last week of the month:";

						cin>>weight1;

						cout<<name<<" enter the size of waist in the last week of the month:";

						cin>>waist1;

						MonthlyProgress progress(weight, weight1, waist, waist1);

						cout << "\nPress '+' to view monthly progress report or 'Q' to quit: ";

		        		cin >> choice;

		        		while(choice!='+' && choice!='Q'){

		        			cout<<"Invalid input,Enter the correct Key:";

		        			cin>>choice;

		        		}

	        				if (choice == '+'){

	            				cout << progress.report() << endl;

			            		system("pause");

			            		system("cls");

				        		cout<<"Kindly rate our app out of ***** stars:";

								cin>>rate;

								while(rate!="*" && rate!="**" && rate!="***" && rate!="****" && rate!="*****"){

									cout<<"Invalid input,Enter the correct Key:";

									cin>>rate;

								}

								cout<<"Thankyou for rating us "<<rate <<" stars, have a good day."<<endl<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

								cout<<"EXERCISE NOT ONLY CHANGE YOUR BODY, IT CHANGES YOUR MIND, YOUR ATTITUDE AND YOUR MOOD"<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

			    			}

				}	

			}

			else if(gender=='F'){

				cout<<endl<<"Below is the list of our Trainers"<<endl<<endl;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"TRAINER 1 INFORMATION:"<<endl;

	        	cout<<T2;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"TRAINER 2 INFORMATION:"<<endl;

	        	cout<<T3;

	        	cout<<"----------------------------------------"<<endl;

	        	cout<<"Select any one of the trainer you want\n1. Trainer 1\n2. Trainer 2\n";

	        	cin>>choi;

	        	while(choi!=1 && choi!=2){

	        		cout<<"Invalid Key,Kindly enter the correct key:";

	        		cin>>choi;

				}

	        	if(choi==1){

	        		system("cls");

	        		cout << "Congrats!! You have been scheduled a session with one of our certified trainer "<<T2.getName()<<" who will tell you your Monthly Progress"<<endl;

					cout<<"So for that:"<<endl;

	        		cout<<name<<", Kindly enter your weight in the last week of the month:";

					cin>>weight1;

					cout<<name<<", Kindly enter the size of waist in the last week of the month:";

					cin>>waist1;

					MonthlyProgress progress(weight, weight1, waist, waist1);

					 cout << "\nPress '+' to view monthly progress report or 'Q' to quit: ";

	        		cin >> choice;

	        		while(choice!='+' && choice!='Q'){

	        			cout<<"Invalid input,Enter the correct Key:";

	        			cin>>choice;

	        		}

	        				if (choice == '+'){

	            				cout << progress.report() << endl;

			            		system("pause");

			            		system("cls");

				        		cout<<"Kindly rate our app out of ***** stars:";

								cin>>rate;

								while(rate!="*" && rate!="**" && rate!="***" && rate!="****" && rate!="*****"){

									cout<<"Invalid input,Enter the correct Key:";

									cin>>rate;

								}

								cout<<"Thankyou for rating us "<<rate <<" stars, have a good day."<<endl<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

								cout<<"EXERCISE NOT ONLY CHANGE YOUR BODY, IT CHANGES YOUR MIND, YOUR ATTITUDE AND YOUR MOOD"<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

			    			}

				}

				else if(choi==2){

						system("cls");

						cout << "Congrats!! You have been scheduled a session with one of our certified trainer "<<T3.getName()<<" who will tell you your Monthly Progress"<<endl;

						cout<<"So for that:"<<endl;

		        		cout<<name<<", Kindly enter your weight in the last week of the month:";

						cin>>weight1;

						cout<<name<<", Kindly enter the size of waist in the last week of the month:";

						cin>>waist1;

						MonthlyProgress progress(weight, weight1, waist, waist1);

						cout << "\nPress '+' to view monthly progress report or 'Q' to quit: ";

		        		cin >> choice;

		        		while(choice!='+' && choice!='Q'){

	        			cout<<"Invalid input,Enter the correct Key:";

	        			cin>>choice;

	        			}

	        				if (choice == '+'){

	            				cout << progress.report() << endl;

			            		system("pause");

			            		system("cls");

				        		cout<<"Kindly rate our app out of ***** stars:";

								cin>>rate;

								while(rate!="*" && rate!="**" && rate!="***" && rate!="****" && rate!="*****"){

									cout<<"Invalid input,Enter the correct Key:";

									cin>>rate;

								}

								cout<<"Thankyou for rating us "<<rate <<" stars, have a good day."<<endl<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

								cout<<"EXERCISE NOT ONLY CHANGE YOUR BODY, IT CHANGES YOUR MIND, YOUR ATTITUDE AND YOUR MOOD"<<endl;

								cout<<"--------------------------------------------------------------------------------------"<<endl;

			    			}

						}

			}

		}

		else if(choice == 'N'){

			cout<<"You wont be able to know your monthly Progress"<<endl;

			cout<<"Kindly rate our app out of ***** stars:";

			cin>>rate;

			while(rate!="*" && rate!="**" && rate!="***" && rate!="****" && rate!="*****"){

				cout<<"Invalid input,Enter the correct Key:";

				cin>>rate;

			}

			cout<<"Thankyou for rating us "<<rate <<" stars, have a good day."<<endl<<endl;

			cout<<"--------------------------------------------------------------------------------------"<<endl;

			cout<<"EXERCISE NOT ONLY CHANGE YOUR BODY, IT CHANGES YOUR MIND, YOUR ATTITUDE AND YOUR MOOD"<<endl;

			cout<<"--------------------------------------------------------------------------------------"<<endl;

		}

    return 0;

}







