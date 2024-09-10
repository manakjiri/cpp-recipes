
#include "kitchen/cookware.hpp"

template <typename T>
void add_salt(T &thing)
{
    // Add a pinch of salt.
    std::cout << "Adding a pinch of salt. \U0001F9C2\U0001F90F" << std::endl;
}

struct Ingredient{
    std::string name;

    Ingredient(const std::string& name) : name(name) {}

    void add_spice(std::string spice) // todo amount
    {
        std::cout << "Adding a pinch of " << spice << ".\U0001F90F" << std::endl;
    }

    virtual ~Ingredient() {}
};

std::ostream& operator << (std::ostream &os, const Ingredient &i) {
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
        : Ingredient("rice"),  weight(weight), kind(kind), packaging(packaging) {}

    void cook(Pot &pot, Stove &stove)
    {
        std::cout << "Preparing to cook rice \U0001F35A" << std::endl;
        
        double water_volume = weight * 2;
        if (pot.volume < water_volume)
            throw std::exception();
        
        add_salt(pot);
        pot.add(*this);
        stove.cook(pot, Stove::Heat::Medium);
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

    Onion(double amount, Kind kind) : Ingredient("onion"), amount(amount), kind(kind) {}

    void peel()
    {
        std::cout << "Peeling the onion." << std::endl;
    }

    void chop()
    {
        std::cout << "Choping the onion.\U0001F52A" << std::endl;
    }
};

struct Carrot : public Ingredient
{

    double amount;

    Carrot(double amount) : Ingredient("carrot"), amount(amount) {}

    void peel()
    {
        std::cout << "Peeling the carrot.\U0001F955" << std::endl;
    }

    void chop()
    {
        std::cout << "Choping the carrot.\U0001F52A\U0001F955" << std::endl;
    }
};



struct Tofu : public Ingredient
{

    double weight;

    Tofu(double weight) : Ingredient("tofu"), weight(weight) {}

    void cut()
    {
        // Cut into cubes.
        std::cout << "Cutting tofu into cubes.\U0001F52A" << std::endl;
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

    Oil(double amount, Type type) : Ingredient("oil"), amount(amount), type(type) {}
};

struct Chicken : public Ingredient
{
    enum class Part{
        Breast,
        Thigh
    };
    double weight;
    Part part;

    Chicken(double weight, Part part) : Ingredient("chicken"), weight(weight), part(part) {}

    void cut_into_cubes()
    {
        std::cout << "Cutting chicken into cubes. \U0001F52A\U0001F357" << std::endl;
        // Cut into cubes.
    }
};

struct Broth : public Ingredient
{
    enum class Source{
        Chicken,
        Vegetable
    };
    
    enum class Form{
        Cubes,
        Fresh
    };

    Source source;
    Form form;

    double amount; // how many litres

    Broth(double amount, Source source, Form form) : Ingredient("broth"), amount(amount), source(source), form(form) {}

    
};

struct Milk : public Ingredient
{
    enum class Type{
        Cow,
        Coconut,
        Oat
    };

    Type type;

    double amount;

    Milk(double amount, Type type) : Ingredient("milk"), amount(amount), type(type) {}
};

struct Flour : public Ingredient
{
    enum class Type {
        AllPurpose,
        Bread,
        Plain
    };

    Type type;

    double amount;

    Flour(double amount, Type type) : Ingredient("flour"), amount(amount) {}


};

struct Water : public Ingredient
{
    double volume;

    Water(double volume) : Ingredient("water") , volume(volume) {}
};