#include <iostream>
#include <string>
#include "BMI.hpp"
#include "Nutrition.hpp"

using namespace std;

class Nutrition
{
public:
    void Nutrition::showDailyDiet(BMI B)
    {
        if (B.getBMI() < 18.5)
        {
            cout << "Daily diet plan for Underweight person" << endl;
            cout << "Below is the meal plan generated for you.\n\n";
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                  MONDAY                              |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |          Dinner       |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|         Cereal         |       Roast Beef    |     Grilled salmon    |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("| Muesli with fresh fruit|       Sandwich      |    Asparagus salad    |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1 Cup Low fat milk    |    Fruits Smoothy   |          Peach        |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                  TUESDAY                             |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |          Dinner       |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|   Toaste with cheese   |   Baked Tuna Pasta  |      White Salad      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|     Fresh tomato       |    Parmesan Cheese  |    Bluberry Muffins   |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|      Butter Lettuce    |    Fruit smoothie   |      Rice Cracker     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                Wednesday                             |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |          Dinner       |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|    Multigrain bread    | Deep Dark Chocolate |      Pumpkin Soup     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|     Grilled salmon     | Troasted Vegetables |       Boiled Corn     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|        Avocado         |       Pretzel       | Toasted Turkish Bread |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                Thursday                              |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |           Dinner      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|          1 Banana      |       Turkey Wrap   |    4 Salmon fillet    |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1 Cup Cooked oat meal |       1 Banana      | 4Fresh Pineapple Rings|\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1/4 Cup Raisens       |      Protein Bar    |   1/2 Cup Brown Rice  |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                Friday                                |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |           Dinner      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|           1 Tuna       |Ukrainian borsch soup|    Mongolian beef     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|      Boiled egg        |    Toasted bread    |   pumpkin pastry pie  |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|   Green salad leaves   |     Banana bread    |     Steamed carrot    |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                Saturday                              |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |           Dinner      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  Croissants with jam   |   Pasta marinara    |     Seafood pizza     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1/2 Cup Fruit Salad   | vegetable sandwich  |   Mahi Mahi Tacos     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|   Almond and Orange    |   1 Boiled Corn     |    1 Small Totrilla   |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                Sunday                                |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |           Dinner      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  Oatmeal with Apples   |    Cheese Sandwich  |     Roasted beef      |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|    Whole Grain Toast   |    Green  Salad     |     1 Cup Walnuts     |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|   Chocolate cake slice |   Fruit smoothie    |   Chicken Breasts     |\n");
            cout << (" -----------------------------------------------------------------------\n");
        }
        else if (B.getBMI() < 25)
        {
            cout << "Daily diet plan for Normal person" << endl;
            cout << "Below is the meal plan generated for you.\n\n";
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|                                  MONDAY                              |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       Breakfast        |         Lunch       |          Dinner       |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|       1 Banana         |    Turkey Sandwich  |      Chicken Breast   |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1 Cup Cooked meal     |    Cereal Bar       |  Baked Sweet Potato   |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|  1 Cup Low fat milk    |    Fruits Smoothy   |          Peach        |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("|     1/4 Cup Walnuts    |         Apple       |    Cup Low Fat Milk   |\n");
            cout << (" -----------------------------------------------------------------------\n");
            cout << ("\n\n");
        }
    }
};