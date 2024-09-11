#pragma once
#include <iostream>

struct cookbook
{
    static void begin_ingredients()
    {
        current_state = state::ingredients;
        std::cout << std::endl << "INGREDIENTS" << std::endl;
    }

    static void begin_recipe()
    {
        recipe_step = 0;
        current_state = state::recipe;
        std::cout << std::endl << "RECIPE" << std::endl;
    }

    static void finish()
    {
        std::cout << "The meal is ready to be served.\U0001F35B Bon apetite!" << std::endl;
    }

    static std::ostream& format(std::ostream &os) {
        switch (current_state)
        {
        case state::ingredients:
            return os << "- ";
        case state::recipe:
            return os << ++recipe_step << ". ";
        }
        return os;
    };

    private:
    enum class state
    {
        ingredients,
        recipe
    };

    static inline state current_state = state::ingredients;
    static inline int recipe_step = 0;
};