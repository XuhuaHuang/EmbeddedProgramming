/**
 * @file pax_the_cat_v2.cc
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2024-05-05
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>

// function to get valid user input from given range [min, max]
static inline int get_user_input(const int, const int);
// function to display options and get user choice
static inline int prompt_and_get_choice(const std::string&, const std::string&, const std::string&);
// function to play the game
static inline void play_game();

int main()
{
    int play_again = 0;
    do
    {
        play_game();
        std::cout << "Would you like to try again? 1 - yes, 2 - no"
                  << "\n";
        play_again = get_user_input(1, 2);
    } while (play_again == 1);
    return 0;
}

// function to get valid user input from given range [min, max]
int get_user_input(const int min, const int max)
{
    int choice;
    do
    {
        std::cin >> choice;
        if (choice < min || choice > max)
        {
            std::cout << "Invalid choice. Please try again: ";
        }
    } while (choice < min || choice > max);
    return choice;
}

// function to display options and get user choice
int prompt_and_get_choice(const std::string& prompt, const std::string& option1, const std::string& option2)
{
    std::cout << prompt << "\n";
    std::cout << "1. " << option1 << "\n";
    std::cout << "2. " << option2 << "\n";
    std::cout << "Enter your choice: ";
    return get_user_input(1, 2);
}

// function to play the game
void play_game()
{
    int choice;
    std::cout << "Once upon a time there was a fluffy cat named Pax."
              << "\n";
    std::cout << "Pax had a favourite piece of yellow rope that he liked to play with."
              << "\n";
    std::cout << "One day he went to play with his rope but it was gone. Where could it be?"
              << "\n";
    choice = prompt_and_get_choice("Could it be in the bowl or the washing machine?", "bowl", "washing machine");

    if (choice == 1)
    {
        std::cout << "Pax hopped into the bowl. No rope here. He curled up and had a little rest."
                  << "\n";
        choice = prompt_and_get_choice(
            "After his rest he wondered what to do next. Maybe having a drink or something to eat would help.", "drink",
            "something to eat");
        if (choice == 1)
        {
            std::cout << "Pax had a drink from his water fountain. Then he carried on looking."
                      << "\n";
            choice = prompt_and_get_choice("Where should he look next?", "in the dishwasher", "in a plastic container");
        }
        else
        {
            std::cout << "Pax ate his dinner then he carried on looking."
                      << "\n";
            choice = prompt_and_get_choice("Where should he look next?", "a bag", "a box");
        }
    }
    else
    {
        std::cout << "Pax looked in the washing machine. There was an odd sock but no rope."
                  << "\n";
        choice =
            prompt_and_get_choice("Maybe he should have a sleep but where would be best, on the computer on a shoe?",
                                  "on a shoe", "on a computer");
        if (choice == 1)
        {
            std::cout << "Pax had a little sleep on the shoe then carried on looking."
                      << "\n";
            choice = prompt_and_get_choice("Where should he look next?", "in the dishwasher", "in a plastic container");
        }
        else
        {
            std::cout << "Pax had a little sleep on the computer then carried on looking."
                      << "\n";
            choice = prompt_and_get_choice("Where should he look next?", "a bag", "a box");
        }
    }

    if (choice == 1)
    {
        std::cout << "It wasn't in the dishwasher so he carried on looking."
                  << "\n";
        choice = prompt_and_get_choice("Where should he look next?", "in the suitcase", "in the plastic bags");
    }
    else
    {
        std::cout << "It wasn't in the plastic container so he carried on looking."
                  << "\n";
        choice = prompt_and_get_choice("Where should he look next?", "in the suitcase", "in the plastic bags");
    }

    if (choice == 1)
    {
        std::cout << "Yes, it was in the suitcase. Pax was very happy."
                  << "\n";
    }
    else
    {
        std::cout << "No it wasn't there. Pax was very sad."
                  << "\n";
    }
    return;
}
