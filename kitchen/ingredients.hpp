#pragma once
#include "kitchen/cookware.hpp"
#include "kitchen/cookbook.hpp"

template <typename T>
void add_salt(T &thing)
{
    // Add a pinch of salt.
    std::cout << cookbook::format << "Adding a pinch of salt. \U0001F9C2\U0001F90F" << std::endl;
}

struct Ingredient
{
    std::string name;

    Ingredient(const std::string &name) : name(name) {}

    void add_spice(std::string spice) // todo amount
    {
        std::cout << cookbook::format << "Adding a pinch of " << spice << ".\U0001F90F" << std::endl;
    }

    virtual ~Ingredient() {}
};

std::ostream &operator<<(std::ostream &os, const Ingredient &i)
{
    return (os << i.name);
};

struct Rice : Ingredient
{
    enum class Kind
    {
        Basmati,
        Jasmine,
        Arborio,
        Sushi,
        Brown,
        Parboiled
    };

    enum class Packaging
    {
        Loose,
        Bag
    };

    double weight;
    Kind kind;
    Packaging packaging;

    Rice(double weight, Kind kind, Packaging packaging)
        : Ingredient("rice"), weight(weight), kind(kind), packaging(packaging)
    {
        std::cout << cookbook::format;

        switch (kind)
        {
        case Kind::Basmati:
            std::cout << "Basmati ";
            break;
        case Kind::Jasmine:
            std::cout << "Jasmine ";
            break;
        case Kind::Arborio:
            std::cout << "Arborio ";
            break;
        case Kind::Sushi:
            std::cout << "Sushi ";
            break;
        case Kind::Brown:
            std::cout << "Brown ";
            break;
        case Kind::Parboiled:
            std::cout << "Parboiled ";
            break;
        default:
            break;
        }
        std::cout << "Rice ";

        switch (packaging)
        {
        case Packaging::Loose:
            std::cout << "(loose) ";
            break;
        case Packaging::Bag:
            std::cout << "(bagged) ";
            break;
        default:
            break;
        }

        std::cout << weight << " kg" << std::endl;
    }

    void start_cooking(Pot &pot, Stove &stove)
    {
        std::cout << cookbook::format << "Preparing to cook rice \U0001F35A" << std::endl;

        double water_volume = weight * 2;
        if (pot.volume < water_volume)
            throw std::exception();

        pot.add(*this);
        add_salt(pot);
        stove.cook(pot, Stove::Heat::Medium);
    }

    void monitor_cooking(Pot &pot, Stove &stove)
    {
        // Wait for the rice to cook.
        std::cout << cookbook::format << "Waiting for the rice to cook.\U0001F35A" << std::endl;

        cookbook::wait(std::chrono::minutes(10));
        for (int i = 0; i < 10; i++)
        {
            if (packaging == Packaging::Bag)
            {
                /* check if the bag is full, if so, break out */
            }
            else if (packaging == Packaging::Loose)
            {
                /* check if the rice is cooked by tasting it, if so, break out */
            }
            cookbook::wait(std::chrono::minutes(1));
            /* it should take 20 minutes maximum */
        }
        stove.finish_cooking(pot);
    }
};

struct Onion : public Ingredient
{
    enum class Kind
    {
        White,
        Red,
    };

    double amount;
    Kind kind;

    Onion(double amount, Kind kind) : Ingredient("onion"), amount(amount), kind(kind)
    {
        std::cout << cookbook::format;

        switch (kind)
        {
        case Kind::White:
            std::cout << "White ";
            break;
        case Kind::Red:
            std::cout << "Red ";
            break;
        default:
            break;
        }

        std::cout << "Onion " << amount << " pieces" << std::endl;
    }

    void peel()
    {
        std::cout << cookbook::format << "Peeling the onion." << std::endl;
    }

    void chop()
    {
        std::cout << cookbook::format << "Choping the onion.\U0001F52A" << std::endl;
    }
};

struct Carrot : public Ingredient
{

    double amount;

    Carrot(double amount) : Ingredient("carrot"), amount(amount) {
        std::cout << cookbook::format << "Carrot " << amount << " pieces" << std::endl;
    }

    void peel()
    {
        std::cout << cookbook::format << "Peeling the carrot.\U0001F955" << std::endl;
    }

    void chop()
    {
        std::cout << cookbook::format << "Choping the carrot.\U0001F52A\U0001F955" << std::endl;
    }
};

struct Tofu : public Ingredient
{
    double weight;

    Tofu(double weight) : Ingredient("tofu"), weight(weight) {
        std::cout << cookbook::format << "Tofu " << weight << " kg" << std::endl;
    }

    void cut()
    {
        // Cut into cubes.
        std::cout << cookbook::format << "Cutting tofu into cubes.\U0001F52A" << std::endl;
    }
};

struct Oil : public Ingredient
{
    enum class Type
    {
        Olive,
        Sunflower,
        Coconut,
        Rapeseed
    };
    double amount;
    Type type;

    Oil(double amount, Type type) : Ingredient("oil"), amount(amount), type(type) {
        std::cout << cookbook::format;

        switch (type)
        {
        case Type::Olive:
            std::cout << "Olive ";
            break;
        case Type::Sunflower:
            std::cout << "Sunflower ";
            break;
        case Type::Coconut:
            std::cout << "Coconut ";
            break;
        case Type::Rapeseed:
            std::cout << "Rapeseed ";
            break;
        default:
            break;
        }

        std::cout << "Oil " << amount << " l" << std::endl;
    }
};

struct Chicken : public Ingredient
{
    enum class Part
    {
        Breast,
        Thigh
    };
    double weight;
    Part part;

    Chicken(double weight, Part part) : Ingredient("chicken"), weight(weight), part(part) {
        std::cout << cookbook::format;

        switch (part)
        {
        case Part::Breast:
            std::cout << "Chicken breast ";
            break;
        case Part::Thigh:
            std::cout << "Chicken thigh ";
            break;
        default:
            break;
        }

        std::cout << weight << " kg" << std::endl;
    }

    void cut_into_cubes()
    {
        std::cout << cookbook::format << "Cutting chicken into cubes. \U0001F52A\U0001F357" << std::endl;
        // Cut into cubes.
    }
};

struct Broth : public Ingredient
{
    enum class Source
    {
        Chicken,
        Vegetable
    };

    enum class Form
    {
        Cubes,
        Fresh
    };

    Source source;
    Form form;

    double amount; // how many litres

    Broth(double amount, Source source, Form form) : Ingredient("broth"), amount(amount), source(source), form(form) {
        std::cout << cookbook::format;

        switch (source)
        {
        case Source::Chicken:
            std::cout << "Chicken ";
            break;
        case Source::Vegetable:
            std::cout << "Vegetable ";
            break;
        default:
            break;
        }

        std::cout << "Broth " << amount << " l" << std::endl;
    }
};

struct Milk : public Ingredient
{
    enum class Type
    {
        Cow,
        Coconut,
        Oat
    };

    Type type;

    double amount;

    Milk(double amount, Type type) : Ingredient("milk"), amount(amount), type(type) {
        std::cout << cookbook::format;

        switch (type)
        {
        case Type::Cow:
            std::cout << "Cow ";
            break;
        case Type::Coconut:
            std::cout << "Coconut ";
            break;
        case Type::Oat:
            std::cout << "Oat ";
            break;
        default:
            break;
        }

        std::cout << "Milk " << amount << " l" << std::endl;
    }
};

struct Flour : public Ingredient
{
    enum class Type
    {
        AllPurpose,
        Bread,
        Plain
    };

    Type type;

    double amount;

    Flour(double amount, Type type) : Ingredient("flour"), type(type), amount(amount) {
        std::cout << cookbook::format;

        switch (type)
        {
        case Type::AllPurpose:
            std::cout << "All-purpose ";
            break;
        case Type::Bread:
            std::cout << "Bread ";
            break;
        case Type::Plain:
            std::cout << "Plain ";
            break;
        default:
            break;
        }

        std::cout << "Flour " << amount << " kg" << std::endl;
    }
};

struct Water : public Ingredient
{
    double volume;

    Water(double volume) : Ingredient("water"), volume(volume) {
        std::cout << cookbook::format << "Water " << volume << " l" << std::endl;
    }
};