
#include "kitchen/cookware.hpp"

enum class RiceKind
{
    Basmati,
    Jasmine,
    Arborio,
    Sushi,
    Brown,
    Parboiled
};

enum class RicePackaging
{
    Loose,
    Bag
};

struct Rice
{
    double weight;
    RiceKind type;
    RicePackaging packaging;

    Rice(double weight, RiceKind type, RicePackaging packaging)
        : weight(weight), type(type), packaging(packaging) {}

    void begin_cooking(Pot &pot)
    {
        double water_volume = weight * 2;
        if (pot.volume < water_volume)
            throw std::exception();

        
    }
};
