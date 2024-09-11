#pragma once

#include <exception>
#include <iostream>

#include "kitchen/cookbook.hpp"

namespace exceptions
{

} // namespace exceptions

struct Stove
{
    enum class Heat
    {
        Off,
        Low,
        Medium,
        High
    };

    template <typename T>
    void cook(T &thing, Heat heat)
    {
        // Output message based on heat level
        std::cout << cookbook::format << "Starting to cook with ";
        switch (heat)
        {
        case Heat::Low:
            std::cout << "low heat.\U0001F525\U0001F975" << std::endl;
            break;
        case Heat::Medium:
            std::cout << "medium heat.\U0001F525\U0001F975" << std::endl;
            break;
        case Heat::High:
            std::cout << "high heat.\U0001F525\U0001F975" << std::endl;
            break;
        }
    }

    template <typename T>
    void finish_cooking(T &thing)
    {
        //std::cout << "Cooking finished!\U0001F958" << std::endl;
    }
};

class Pot
{
    bool has_lid;

public:
    double volume;
    double filled_volume;

    Pot(double volume) : has_lid{false}, volume(volume), filled_volume{0} {}

    void add_lid()
    {
        has_lid = true;
        std::cout << cookbook::format << "Adding the lid to the pot.\U0001F372" << std::endl;
    }

    void remove_lid()
    {
        has_lid = false;
        std::cout << cookbook::format << "Removing the lid from the pot.\U0001F372" << std::endl;
    }

    void fill(double amount)
    {
        filled_volume = amount;
        std::cout << cookbook::format << "Filling the pot with" << amount << "amount." << std::endl;
    }

    void pour_out(double amount)
    {
        filled_volume -= amount;
    }

    void empty()
    {
        filled_volume = 0;
    }

    template <typename T>
    void add(T &&thing)
    {
        // filled_volume += thing.weight; e.g. oil has no weight
        std::cout << cookbook::format << "Adding " << thing << " to the pot." << std::endl;
    }

    template <typename T>
    T remove(T &thing)
    {
        std::cout << cookbook::format << "Removing " << thing << " from the pot." << std::endl;
        return std::move(thing);
    }
};

struct Pan
{
    enum class Type
    {
        Wok,
        Stewpan,
        Frying,
        Sauce
    };

    Type type;

    Pan(Type type) : type(type) {}

    template <typename T>
    void add(T &&thing)
    {
        std::cout << cookbook::format << "Adding " << thing << " to the pan." << std::endl;
    }

    template <typename T>
    T remove(T &thing)
    {
        std::cout << cookbook::format << "Removing " << thing << " from the pan." << std::endl;
        return std::move(thing);
    }
};

struct Mug
{
    double volume;

    Mug(double volume) : volume(volume) {}

    template <typename T>
    void add(T &thing)
    {
        std::cout << cookbook::format << "Adding " << thing << " to the mug." << std::endl;
    }

    void mix()
    {
        std::cout << cookbook::format << "Mixing the contents of the mug.\U0001F944" << std::endl;
    }

    template <typename T>
    T remove(T &thing)
    {
        std::cout << cookbook::format << "Removing " << thing << " from the mug." << std::endl;
        return std::move(thing);
    }
};