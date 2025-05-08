#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstdio>

void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y) {
    SDL_Color textColor = { 255, 255, 255, 255 }; // White color

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = { x, y, textSurface->w, textSurface->h };

    SDL_RenderCopy(renderer, textTexture, NULL, &textRect);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }

    SDL_Window* win = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);

    Uint32 render_flags = SDL_RENDERER_ACCELERATED;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    // Initialize SDL_ttf
    if (TTF_Init() != 0) {
        printf("error initializing SDL_ttf: %s\n", TTF_GetError());
    }

    TTF_Font* font = TTF_OpenFont("PixelSport-nRVRV.ttf", 24); // Replace "arial.ttf" with your font file

    if (!font) {
        printf("error loading font: %s\n", TTF_GetError());
    }

    int close = 0;
    int speed = 300; //remov

    while (!close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close = 1;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_DOWN: {
                            SDL_Window* newWin = SDL_CreateWindow("Workout Instructions",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 800, 0);
                            SDL_Renderer* newRend = SDL_CreateRenderer(newWin, -1, render_flags);

                            // Display workout text on the new screen
                    renderText(newRend, font, "Basic Chest Workout", 10, 40);  
                    
                    renderText(newRend, font, "                     ", 10, 60);        
                    renderText(newRend, font, "Dumbbell Bench Press 3x12", 10, 70);
                    renderText(newRend, font, "Barbell Bench Press 3x8", 10, 100);
                    renderText(newRend, font, "Wide grip Pushups 3x20", 10, 130);
                    renderText(newRend, font, "Incline Barbell press 4x10", 10, 160);
                    renderText(newRend, font, "Incline DB Fly's 3x8", 10, 190);

                    renderText(newRend, font, "Intermediate Chest Workout", 350, 40);  
                    
                    renderText(newRend, font, "                     ", 350, 60);        
                    renderText(newRend, font, "Dumbbell Bench Press 4x12", 350, 80);
                    renderText(newRend, font, "Barbell DB Press 5x8", 350, 110);
                    renderText(newRend, font, "Diamond grip Pushups 4x20", 350, 140);
                    renderText(newRend, font, "Incline Barbell press with hold  4x10", 350, 170);
                    renderText(newRend, font, "Incline DB Fly's 3x10", 350, 200);

                    
                    renderText(newRend, font, "Advanced Chest Workout", 250, 240);  
                    
                    renderText(newRend, font, "                     ", 250, 260);        
                    renderText(newRend, font, "Dumbbell Bench Press 5x10 (Failure)",250, 290);
                    renderText(newRend, font, "Barbell Incline Press 5x12", 250, 330);
                    renderText(newRend, font, "Diamond grip Pushups (Superset) 3x12", 250, 360);
                    renderText(newRend, font, "Incline Barbell press with  10 seconds hold  4x10", 250, 390);
                    renderText(newRend, font, "Incline DB Fly's 4x10", 250, 420);
                    
                                    SDL_RenderPresent(newRend);
                            

                            //SDL_RenderPresent(newRend);
                            SDL_Delay(5000000000000000000000000000); // Delay for 5 seconds (you can adjust this)
                            
                            SDL_DestroyRenderer(newRend);
                            SDL_DestroyWindow(newWin);
                            break;
                        }
                        case SDL_SCANCODE_UP:
                         {
                            SDL_Window* newWin = SDL_CreateWindow("Workout Instructions",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 800, 0);
                            SDL_Renderer* newRend = SDL_CreateRenderer(newWin, -1, render_flags);

                            // Display workout text on the new screen
                     renderText(newRend, font, "Basic Back Workout", 10, 40);
    
    renderText(newRend, font, "                     ", 10, 60);
    renderText(newRend, font, "Barbell Overhand Rows 3x12", 10, 70);
    renderText(newRend, font, "Barbell Underhand Rows 3x8", 10, 100);
    renderText(newRend, font, "Wide Grip Lat pulldown 3x10", 10, 130);
    renderText(newRend, font, "Seated Machine Rows 4x10", 10, 160);
    renderText(newRend, font, "Dumbbell Pullover 3x8", 10, 190);
renderText(newRend, font, "Intermediate Back Workout", 350, 40);
    
    renderText(newRend, font, "                     ", 350, 60);
    renderText(newRend, font, "V-Grip Lat Pulldown 2x15", 350, 80);
    renderText(newRend, font, "Single Arm Seated Rows 3x12", 350, 110);
    renderText(newRend, font, "Deadlift 3x12/10/8 (Progressively overload the Weight)", 350, 140);
    renderText(newRend, font, "Chest Supported DB Rows", 350, 170);
    renderText(newRend, font, "5 Mins Stretching", 350, 200);
    renderText(newRend, font, "Rope Pulldown 2x10", 350, 230);
                      renderText(newRend, font, "Advanced Back Workout", 250, 290);
    
    renderText(newRend, font, "                     ", 250, 310);
    renderText(newRend, font, "Heavy Deadlift 3x12/10/8", 250, 360);
    renderText(newRend, font, "Barbell Overhand Rows 3x12 (Heavy)", 250, 410);
    renderText(newRend, font, "DB Single Arm Rows 3x15 + Lat Pulldown (Wide Grip) 3x12 Superset", 250, 460);
    renderText(newRend, font, "Close grip Lat pulldown 3x12 (max 20 sec rest)", 250, 520);
    renderText(newRend, font, "Incline Barbell press 4x12", 250, 580);
    renderText(newRend, font, "Incline DB Fly's 3x10", 250, 640);
    renderText(newRend, font, "Hope you survived :) Good Job!", 250, 700);
      SDL_RenderPresent(newRend);
                            

                            //SDL_RenderPresent(newRend);
                            SDL_Delay(5000000000000000000000000000); // Delay for 5 seconds (you can adjust this)
                            
                            SDL_DestroyRenderer(newRend);
                            SDL_DestroyWindow(newWin);
                            break;
}

case SDL_SCANCODE_LEFT:
                         {
                            SDL_Window* newWin = SDL_CreateWindow("Workout Instructions",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 800, 0);
                            SDL_Renderer* newRend = SDL_CreateRenderer(newWin, -1, render_flags);

                            // Display workout text on the new screen
                      renderText(newRend, font, "Basic Arms Workout", 10, 40);

    renderText(newRend, font, "                     ", 10, 60);
    renderText(newRend, font, "Tricep Dips x10", 10, 70);
    renderText(newRend, font, "Diamond Pushups x6", 10, 100);
    renderText(newRend, font, "Chest Press Pulse\t00:16", 10, 130);
    renderText(newRend, font, "Diamond Plank x10", 10, 160);

     renderText(newRend, font, "Intermediate Arms Workout", 350, 40);

    renderText(newRend, font, "                     ", 350, 60);
    renderText(newRend, font, "Arm Circles Counterclockwise\t00:30", 350, 80);
    renderText(newRend, font, "Floor Tricep Tips x14", 350, 110);
    renderText(newRend, font, "Military Pushups x16", 350, 140);
    renderText(newRend, font, "Alternating Hooks\t00:30", 350, 170);
    renderText(newRend, font, "Push-Ups And Rotation x12", 350, 200);
    renderText(newRend, font, "Left Barbell Curl Left x12", 350, 230);
    renderText(newRend, font, "Triceps Stretch Left\t00:30", 350, 260);
    renderText(newRend, font, "Triceps Stretch Right\t00:30", 350, 290);
    renderText(newRend, font, "Advanced Arms Workout", 250, 340);

    renderText(newRend, font, "                     ", 250, 360);
    renderText(newRend, font, "Arm Circles Clockwise\t00:30", 250, 380);
    renderText(newRend, font, "Arm Circles Counterclockwise\t00:30", 250, 410);
    renderText(newRend, font, "Skipping Without Rope\t 00:30", 250, 440);
    renderText(newRend, font, "Left Barbell Curl Left x16", 250, 470);
    renderText(newRend, font, "Left Barbell Curl Right x16", 250, 500);
    renderText(newRend, font, "Floor Tricep Tips x14", 250, 530);
    renderText(newRend, font, "Military Pushups x16", 250, 560);
    renderText(newRend, font, "Alternating Hooks\t00:30", 250, 590);
    renderText(newRend, font, "Triceps Stretch Left\t00:30", 250, 620);
    renderText(newRend, font, "Triceps Stretch Right\t00:30", 250, 650);
    renderText(newRend, font, "Jumping Jacks\t00:25", 250, 680);
      SDL_RenderPresent(newRend);
                            

                            //SDL_RenderPresent(newRend);
                            SDL_Delay(5000000000000000000000000000); // Delay for 5 seconds (you can adjust this)
                            
                            SDL_DestroyRenderer(newRend);
                            SDL_DestroyWindow(newWin);
                            break;}

                            
case SDL_SCANCODE_RIGHT:
                         {
                            SDL_Window* newWin = SDL_CreateWindow("Workout Instructions",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                800, 800, 0);
                            SDL_Renderer* newRend = SDL_CreateRenderer(newWin, -1, render_flags);

                            // Display workout text on the new screen
                       renderText(newRend, font, "Basic Legs Workout", 10, 40);

    renderText(newRend, font, "                     ", 10, 60);
    renderText(newRend, font, "Jumping Jacks\t00:15", 10, 70);
    renderText(newRend, font, "Side Hops\t00:30", 10, 100);
    renderText(newRend, font, "Squats x12", 10, 130);
    renderText(newRend, font, "25 minutes\t10 workouts", 10, 160);
    renderText(newRend, font, "Jumping Jacks\t00:15", 10, 190);
    renderText(newRend, font, "Side Hops\t00:30", 10, 220);
 renderText(newRend, font, "Intermediate Legs Workout", 350, 40);

    renderText(newRend, font, "                     ", 350, 60);
    renderText(newRend, font, "Jumping Jacks\t00:15", 350, 80);
    renderText(newRend, font, "Squats x14", 350, 110);
    renderText(newRend, font, "Squats x14", 350, 140);
    renderText(newRend, font, "Fire Hydrant Right x12", 350, 170);
    renderText(newRend, font, "Fire Hydrant Left x14", 350, 200);
    renderText(newRend, font, "Lunges x16", 350, 230);
    renderText(newRend, font, "Side Leg Circles Left x12", 350, 260);
    renderText(newRend, font, "Side Leg Circles right x12", 350, 290);
    renderText(newRend, font, "Sumo Squat x12", 350, 320);
    renderText(newRend, font, "Reverse Flutter Kicks x12", 350, 350);

     renderText(newRend, font, "Advanced Legs Workout", 250, 400);

    renderText(newRend, font, "                     ", 250, 420);
    renderText(newRend, font, "Squats x14", 250, 440);
    renderText(newRend, font, "Side Leg Circles right x12", 250, 470);
    renderText(newRend, font, "Curtsy Lunges x16", 250, 500);
    renderText(newRend, font, "Jumping squats x14", 250, 530);
    renderText(newRend, font, "Wall Sit\t00:40", 250, 560);
    renderText(newRend, font, "Glute kickback  x12", 250, 590);
    renderText(newRend, font, "Calf stretch left\t00:40", 250, 620);
    renderText(newRend, font, "Calf stretch right\t00:40", 250, 650);
    renderText(newRend, font, "Lying butterfly stretch\t00:40", 250, 680);
    renderText(newRend, font, "Leaning stretcher raises x12", 250, 710);
      SDL_RenderPresent(newRend);
                            

                            //SDL_RenderPresent(newRend);
                            SDL_Delay(5000000000000000000000000000); // Delay for 5 seconds (you can adjust this)
                            
                            SDL_DestroyRenderer(newRend);
                            SDL_DestroyWindow(newWin);
                            break;}

                            case SDL_SCANCODE_W:
                         {
                            SDL_Window* newWin = SDL_CreateWindow("Workout Instructions",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                1000, 1000, 0);
                            SDL_Renderer* newRend = SDL_CreateRenderer(newWin, -1, render_flags);

                            // Display workout text on the new screen
                       renderText(newRend, font, "Basic Shoulder-Back Workout", 10, 40);

    renderText(newRend, font, "                     ", 10, 60);
    renderText(newRend, font, "Jumping Jacks\t00:15", 10, 70);
    renderText(newRend, font, "Arm Raises\t00:30", 10, 100);
    renderText(newRend, font, "Side Arm Raises\t00:16", 10, 130);
    renderText(newRend, font, "Knee Pushups x14", 10, 160);
    renderText(newRend, font, "Arm Scissors\t00:30", 10, 190);
    renderText(newRend, font, "Rhomboid Pulls x12", 10, 220);
    renderText(newRend, font, "Cat Cow Pulls\t00:30", 10, 250);
    renderText(newRend, font, "Prone Triceps Pushups x14", 10, 280);
renderText(newRend, font, "Intermediate Shoulder-Back Workout", 350, 40);

    renderText(newRend, font, "                     ", 350, 60);
    renderText(newRend, font, "Jumping Jacks\t00:30", 350, 80);
    renderText(newRend, font, "Child's Pose\t00:30", 350, 110);
    renderText(newRend, font, "Hover Push up x12", 350, 140);
    renderText(newRend, font, "Floor tricep dips x14", 350, 170);
    renderText(newRend, font, "Cat Cow Pulls\t00:30", 350, 200);
    renderText(newRend, font, "Incline Pushups x14", 350, 230);
    renderText(newRend, font, "Triceps kickbacks x14", 350, 260);
    renderText(newRend, font, "Hip hinges x10", 350, 290);
    renderText(newRend, font, "Triceps kickbacks x14", 350, 320);
    renderText(newRend, font, "Arm Scissors\t00:30", 350, 350); 
    
    renderText(newRend, font, "Advanced Shoulder-Back Workout", 250, 400);

    renderText(newRend, font, "                     ", 250, 420);
    renderText(newRend, font, "Jumping Jacks\t00:15", 250, 440);
    renderText(newRend, font, "Inch worm x14", 250, 470);
    renderText(newRend, font, "Hyper extension x12", 250, 500);
    renderText(newRend, font, "Cat Cow Pose\t00:30", 250, 530);
    renderText(newRend, font, "Child's Pose\t00:30", 250, 560);
    renderText(newRend, font, "Reverse snow angels x12", 250, 590);
    renderText(newRend, font, "Reverse push ups x12", 250, 620);
    renderText(newRend, font, "Side lying floor stretch left\t00:30", 250, 650);
    renderText(newRend, font, "Side lying floor stretch right\t00:30", 250, 680);
    renderText(newRend, font, "Floor Y raises x12", 250, 710);  SDL_RenderPresent(newRend);
                            

                            //SDL_RenderPresent(newRend);
                            SDL_Delay(5000000000000000000000000000); // Delay for 5 seconds (you can adjust this)
                            
                            SDL_DestroyRenderer(newRend);
                            SDL_DestroyWindow(newWin);
                            break;}






                        
                        case SDL_QUIT:
                        close = 1;
                        break;
                    }

                    break;
            }
        }

        // Your existing rendering code goes here

        SDL_RenderPresent(rend);
        SDL_Delay(1000 / 60);
    }

    // Cleanup
    TTF_CloseFont(font);
    TTF_Quit();

    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
