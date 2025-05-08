#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <list>

// Structure to represent user credentials
struct Credentials {
    std::string email;
    std::string password;
};

// Linked list to store user credentials
std::list<Credentials> credentials;

// Function to check if the given email and password match any stored credentials
bool authenticate(const std::string& email, const std::string& password) {
    for (const auto& cred : credentials) {
        if (cred.email == email && cred.password == password) {
            return true; // Authentication successful
        }
    }
    return false; // Authentication failed
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window
    SDL_Window* window = SDL_CreateWindow("Login Screen", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create a renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Load the font
    if (TTF_Init() != 0) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    TTF_Font* font = TTF_OpenFont("C:/Windows/Fonts/arial.ttf", 24);
    if (font == nullptr) {
        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        TTF_Quit();
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Initialize credentials (you can replace this with your own data)
    credentials.push_back({"user1@example.com", "password1"});
    credentials.push_back({"user2@example.com", "password2"});

    // Main loop
    bool quit = false;
    SDL_Event event;

    std::string inputEmail = "";
    std::string inputPassword = "";

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_RETURN) {
                        // Check credentials and transition to homepage if valid
                        if (authenticate(inputEmail, inputPassword)) {
                            // Authentication successful, open homepage
                            std::cout << "Login successful. Opening homepage." << std::endl;
                            quit = true; // Exit the main loop (you can replace this with your homepage logic)
                        } else {
                            std::cout << "Login failed. Please try again." << std::endl;
                            // Clear input fields
                            inputEmail = "";
                            inputPassword = "";
                        }
                    } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                        // Handle backspace
                        if (!inputEmail.empty()) {
                            inputEmail.pop_back();
                        }
                    } else if (event.key.keysym.sym == SDLK_ESCAPE) {
                        quit = true;
                    }
                    break;
                case SDL_TEXTINPUT:
                    // Handle text input
                    inputEmail += event.text.text;
                    break;
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Render input fields and labels (you can replace this with your own GUI rendering logic)

        // Render email label
        SDL_Color textColor = {0, 0, 0, 255};
        SDL_Surface* emailSurface = TTF_RenderText_Solid(font, "Email:", textColor);
        SDL_Texture* emailTexture = SDL_CreateTextureFromSurface(renderer, emailSurface);

        SDL_Rect emailRect = {50, 100, emailSurface->w, emailSurface->h};
        SDL_RenderCopy(renderer, emailTexture, nullptr, &emailRect);

        SDL_FreeSurface(emailSurface);
        SDL_DestroyTexture(emailTexture);

        // Render password label
        SDL_Surface* passwordSurface = TTF_RenderText_Solid(font, "Password:", textColor);
        SDL_Texture* passwordTexture = SDL_CreateTextureFromSurface(renderer, passwordSurface);

        SDL_Rect passwordRect = {50, 150, passwordSurface->w, passwordSurface->h};
        SDL_RenderCopy(renderer, passwordTexture, nullptr, &passwordRect);

        SDL_FreeSurface(passwordSurface);
        SDL_DestroyTexture(passwordTexture);

        // Render input email
        SDL_Surface* inputEmailSurface = TTF_RenderText_Solid(font, inputEmail.c_str(), textColor);
        SDL_Texture* inputEmailTexture = SDL_CreateTextureFromSurface(renderer, inputEmailSurface);

        SDL_Rect inputEmailRect = {200, 100, inputEmailSurface->w, inputEmailSurface->h};
        SDL_RenderCopy(renderer, inputEmailTexture, nullptr, &inputEmailRect);

        SDL_FreeSurface(inputEmailSurface);
        SDL_DestroyTexture(inputEmailTexture);

        // Render input password (you may want to render '*' characters instead of the actual password)
        SDL_Surface* inputPasswordSurface = TTF_RenderText_Solid(font, inputPassword.c_str(), textColor);
        SDL_Texture* inputPasswordTexture = SDL_CreateTextureFromSurface(renderer, inputPasswordSurface);

        SDL_Rect inputPasswordRect = {200, 150, inputPasswordSurface->w, inputPasswordSurface->h};
        SDL_RenderCopy(renderer, inputPasswordTexture, nullptr, &inputPasswordRect);

        SDL_FreeSurface(inputPasswordSurface);
        SDL_DestroyTexture(inputPasswordTexture);

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
