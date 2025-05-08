#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <windows.h>   
using namespace std;
class MemberAccount {
private:
    string name;
    int age;
    float height;
    float weight;
    float waistSize;
    string bloodGroup;
    string sugarLevel;
    string athleteStatus;
public:
    MemberAccount(string n, int a, float h, float w, float ws, string bg, string sl, string as)
        : name(n), age(a), height(h), weight(w), waistSize(ws), bloodGroup(bg), sugarLevel(sl), athleteStatus(as) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    float getHeight() const { return height; }
    float getWeight() const { return weight; }
    float getWaistSize() const { return waistSize; }
    string getBloodGroup() const { return bloodGroup; }
    string getSugarLevel() const { return sugarLevel; }
    string getAthleteStatus() const { return athleteStatus; }
   
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setHeight(float h) { height = h; }
    void setWeight(float w) { weight = w; }
    void setWaistSize(float ws) { waistSize = ws; }
    void setBloodGroup(string bg) { bloodGroup = bg; }
    void setSugarLevel(string sl) { sugarLevel = sl; }
    void setAthleteStatus(string as) { athleteStatus = as; }
};
class Trainer {
private:
    string name;
    int age;
    string gender;
    int rating;
    string cost;

public:
    Trainer() : name(""), age(0), gender(""), rating(0),cost(0) {}

    Trainer(string name, int age, string gender, int rating,string cost)
        : name(name), age(age), gender(gender), rating(rating),cost(cost) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    int getRating() const { return rating; }
    string getcost() const {return cost;}

    void setName(string name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setGender(string gender) { this->gender = gender; }
    void setRating(int rating) { this->rating = rating; }

    friend ostream& operator<<(ostream& os, const Trainer& trainer);
};
ostream& operator << (ostream& T, const Trainer& trainer){
    T << "Name: " << trainer.name << endl;
    T << "Gender: " << trainer.gender << endl;
    T << "Rating: " << trainer.rating << endl;
    T << "Cost: " << trainer.cost <<endl;
    return T;
}
class Legs {
public:
    virtual void basicWorkout() {};
    virtual void intermediateWorkout() {};
    virtual void advancedWorkout() {};
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
        cout<<("Squats x12\n");
        cout<<("Side Squats x12\n");
        cout<<("Backward Lunge x14\n");
        cout<<("Donkey Kicks Left x16\n");
        cout<<("Donkey Kicks Right x16\n");
        cout<<("Wall Calf Raises x12\n");
        cout<<("Cobra Stretch\t00:20\n");
        cout<<("Calf Stretch\t00:30\n");
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
        cout<<("Wall Sit\t00:30\n");
        cout<<("Calf Raise With Splayed Foot x12\n");
    }
    void advancedWorkout(){
        cout<<("30 minutes\t14 workouts\n\n");
        cout<<("Squats x14\n");
        cout<<("Squats x14\n");
        cout<<("Side Leg Circles Left x12\n");
        cout<<("Side Leg Circles right x12\n");
        cout<<("Curtsy Lunges x16\n");
        cout<<("Burpees x12\n");
        cout<<("Jumping squats x14\n");
        cout<<("Wall Sit\t00:40\n");
        cout<<("Glute kickback right x12\n");
        cout<<("Glute kickback left x12\n");
        cout<<("Calf stretch left\t00:40\n");
        cout<<("Calf stretch right\t00:40\n");
        cout<<("Lying butterfly stretch\t00:40\n");
        cout<<("Leaning stretcher raises x12\n");
    }
};
class Chest {
public:
    virtual void basicWorkout() {};
    virtual void intermediateWorkout() {};
    virtual void advancedWorkout() {};
};
class ChestExercise : public Chest {
public:
    void basicWorkout() {
        cout<<("17 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:20\n");
        cout<<("Inclined Pushups x6\n");
        cout<<("Tricep Dips x6\n");
        cout<<("Wide Arm Pushups x4\n");
        cout<<("Inclined Pushups x4\n");
        cout<<("Knee Pushups x4\n");
        cout<<("Chest Stretch\t00:20\n");
        cout<<("Declined Pushups x4\n");
        cout<<("Plank\t00:30\n");
        cout<<("Pushups x10\n");
    }
    void intermediateWorkout() {
        cout<<("17 minutes\t12 workouts\n\n");
        cout<<("Jumping Jacks\t00:30\n");
        cout<<("Knee Pushups x16\n");
        cout<<("Tricep Dips x26\n");
        cout<<("Wide Arm Pushups x16\n");
        cout<<("Inclined Pushups x14\n");
        cout<<("Hindu Pushups x14\n");
        cout<<("Chest Stretch\t00:40\n");
        cout<<("Decline Pushups x14\n");
        cout<<("Shoulder Stretch\t00:30\n");
        cout<<("Cobra Stretch\t00:30\n");
        cout<<("Diamond Pushups x12\n");
        cout<<("Staggered Push-ups x12\n");
}
    void advancedWorkout() {
        cout<<("17 minutes\t14 workouts\n\n");
        cout<<("Jumping Jacks\t00:30\n");
        cout<<("Burpees x10");
        cout<<("Box Pushups x16\n");
        cout<<("Declined Pushups x14\n");
        cout<<("Hindu Pushups x14\n");
        cout<<("Chest Stretch\t00:40\n");
        cout<<("Spiderman Pushups x20\n");
        cout<<("Shoulder Stretch\t00:30\n");
        cout<<("Cobra Stretch\t00:30\n");
        cout<<("Diamond Pushups x16\n");
        cout<<("Staggered Push-ups x16\n");
        cout<<("Burpees x10");
        cout<<("Arm circles x20");
        cout<<("Push up and rotation\n");
    }
};
class Abs {
public:
    void basicWorkout() {
        cout<<("20 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:20\n");
        cout<<("Abdominal Crunches x16\n");
        cout<<("Russian Twist x20\n");
        cout<<("Mountain Climber x16\n");
        cout<<("Plank\t00:20\n");
        cout<<("Heel Touch\t00:20\n");
        cout<<("Leg Raises x16\n");
        cout<<("Cobra Stretch\t00:30\n");
        cout<<("Spine Lumbar Twist Stetch Left\t00:30\n");
        cout<<("Leg Raises x10\n");
    }

    void intermediateWorkout() {
        cout<<("25 minutes\t12 workouts\n\n");
        cout<<("Jumping Jacks\t00:20\n");
        cout<<("Heel Touch x26\n");
        cout<<("Crossover Crunch x20\n");
        cout<<("Mountain Climber x20\n");
        cout<<("Side Bridges Left x12\n");
        cout<<("Side Bridges Right x12\n");
        cout<<("Butt Bridge x20\n");
        cout<<("Bicycle Crunches x12\n");
        cout<<("V-Up x20\n");
        cout<<("Heel Touch x26\n");
        cout<<("Plank \t00:30\n");
        cout<<("Abdominal Crunches x20\n");
    }

    void advancedWorkout() {
        cout<<("30 minutes\t14 workouts\n\n");
        cout<<("Jumping Jacks\t00:30\n");
        cout<<("Sit ups x20\n");
        cout<<("Side Bridges Left x20\n");
        cout<<("Side Bridges Right x20\n");
        cout<<("Abdominal Crunches x20\n");
        cout<<("Bicycle Crunches x24\n");
        cout<<("Heel Touch x34\n");
        cout<<("Crossover Crunch x24\n");
        cout<<("Mountain Climber x30\n");
        cout<<("Butt Bridge x30\n");
        cout<<("V-Up x20\n");
        cout<<("Plank \t01:00\n");
        cout<<("Cobra Stretch \t00:30\n");
        cout<<("Push up and rotation x20\n");
    }
};
class Arms {
public:
    void basicWorkout() {
        cout<<("17 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:15\n");
        cout<<("Side Arm Raises\t00:30\n");
        cout<<("Arm Raises\t00:30\n");
        cout<<("Tricep Tips x10\n");
        cout<<("Diamond Pushups x6\n");
        cout<<("Chest Press Pulse\t00:16\n");
        cout<<("Punches\t00:30\n");
        cout<<("Diamond Plank x10\n");
        cout<<("Wall Pushups x12\n");
        cout<<("Inch Worms x12\n");
    }

    void intermediateWorkout() {
        cout<<("27 minutes\t12 workouts\n\n");
        cout<<("Jumping Jacks\t00:25\n");
        cout<<("Arm Circles Clockwise\t00:30\n");
        cout<<("Arm Circles Counterclockwise\t00:30\n");
        cout<<("Floor Tricep Tips x14\n");
        cout<<("Military Pushups x16\n");
        cout<<("Alternating Hooks\t00:30\n");
        cout<<("Push-Ups And Rotation x12\n");
        cout<<("Left Barbell Curl Left x12\n");
        cout<<("Left Barbell Curl Right x12\n");
        cout<<("Skipping Without Rope\t 00:30\n");
        cout<<("Triceps Stretch Left\t00:30\n");
        cout<<("Triceps Stretch Right\t00:30\n");
    }

    void advancedWorkout() {
        cout<<("27 minutes\t14 workouts\n\n");
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
        cout<<("Push-Ups And Rotation x12\n");
        cout<<("Chest Press pulse\t00:18\n");
        cout<<("Shoulder gator x16\n");
    }
};
class ShoulderBack {
public:
    void basicWorkout() {
        cout<<("20 minutes\t10 workouts\n\n");
        cout<<("Jumping Jacks\t00:15\n");
        cout<<("Arm Raises\t00:30\n");
        cout<<("Side Arm Raises\t00:16\n");
        cout<<("Knee Pushups x14\n");
        cout<<("Arm Scissors\t00:30\n");
        cout<<("Rhomboid Pulls x12\n");
        cout<<("Cat Cow Pulls\t00:30\n");
        cout<<("Prone Triceps Pushups x14\n");
        cout<<("Child's Pose\t00:14\n");
        cout<<("Reclined Rhomboid Squeeze x12\n");
    }

    void intermediateWorkout() {
        cout<<("20 minutes\t12 workouts\n\n");
        cout<<("Jumping Jacks\t00:30\n");
        cout<<("Child's Pose\t00:30\n");
        cout<<("Hover Push up x12\n");
        cout<<("Floor tricep dips x14\n");
        cout<<("Cat Cow Pulls\t00:30\n");
        cout<<("Incline Pushups x14\n");
        cout<<("Rhomboid Pulls x12\n");
        cout<<("Swimmer and superman x12\n");
        cout<<("Triceps kickbacks x14\n");
        cout<<("Hip hinges x10\n");
        cout<<("Triceps kickbacks x14\n");
        cout<<("Arm Scissors\t00:30\n");
        cout<<("Side Lying floor stretch right\t00:30\n");
        cout<<("Side Lying floor stretch left\t00:30\n");
    }

    void advancedWorkout() {
        cout<<("20 minutes\t12 workouts\n\n");
        cout<<("Jumping Jacks\t00:15\n");
        cout<<("Inch worm x14\n");
        cout<<("Hyper extension x12\n");
        cout<<("Cat Cow Pose\t00:30\n");
        cout<<("Child's Pose\t00:30\n");
        cout<<("Supine Pushups x14\n");
        cout<<("Pike Pushups x14\n");
        cout<<("Reverse snow angels x12\n");
        cout<<("Reverse push ups x12\n");
        cout<<("Side lying floor stretch left\t00:30\n");
        cout<<("Side lying floor stretch right\t00:30\n");
        cout<<("Floor Y raises x12\n");
        cout<<("Arm Scissors\t00:30\n");
        cout<<("Inch worm x14\n");
    }
};
class BMI {
private:
    double height;
    double weight;
    double bmi;
public:
    BMI()
    {
        
    }

    void set(double height, double weight) {
        this->height = height;
        this->weight = weight;
    }

    void calcBMI() {
        bmi = weight / pow(height, 2);
    }
    double getBMI()  
    {
        return bmi;
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
    int choice,option;
    int i;
	for(i=0;i<7;i++){
		cout<<endl;
		cout << "------------------------" << endl;
		cout<<"Daily routine for "<<day[i]<<endl;
		cout << "------------------------" << endl;
		cout<<"\nEnter which exercise you want to perform\n";
		cout<<"1. Legs\n2. Chest\n3. Arms\n4. Shoulder and Back\n5. Abs\n\n";
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
			case 5:
				cout << "\nWhat level of Training would you like to Opt for?\n";
	    		cout << "1. Basic \n2. Intermediate\n3. Advanced\n";
	    		cin >> choice;
	    			if(choice==1){
	    			cout << "\nAbs workout: " << endl;
	    			cout << "---------------" << endl;
	    			cout << "Basic:" << endl;
	    			Abs::basicWorkout();
				}
				else if(choice==2){
					cout << "\nAbs workout: " << endl;
	    			cout << "---------------" << endl;
	   				cout << "Intermediate:" << endl;
	    			Abs::intermediateWorkout();
				}
				else if(choice==3){
					cout << "\nAbs workout: " << endl;
	    			cout << "---------------" << endl;
	   				cout << "Advanced:" << endl;
	    			Abs::advancedWorkout();
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
    MonthlyProgress(double w1, double w7, double wd1, double wd7)
        : weight_day1(w1), weight_day7(w7), waist_day1(wd1), waist_day7(wd7) {}
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
void wisewords()
{
    char quotation[200];
    int a, i = 0;
    srand(time(NULL));
    a = rand() % 12;

    ifstream inFile("motivation.txt");
    if (!inFile)
    {
        cout << "File could not be opened." << endl;
    }
    else
    {
        cout << "Quote of the Day:" << endl;
        
        while (i < 13)
        {
            inFile.getline(quotation, 200);
            if (a == i)
            {
                cout << quotation << endl;
            }
            i++;
        }
        
        inFile.close();
    }
}
int main() {
    string name,rate;
    int age,opt,choi;
    double weight, height,h, waist, weight1, waist1;
    char gender,choice;
    BMI b;

    wisewords();
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
