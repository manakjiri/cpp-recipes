
#include <exception>

namespace exceptions
{

} // namespace exceptions


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
    }

    void remove_lid()
    {
        has_lid = false;
    }

    void fill(double amount)
    {
        filled_volume = amount;
    }

    void pour_out(double amount)
    {
        filled_volume -= amount;
    }

    void empty()
    {
        filled_volume = 0;
    }
};
