
#include <thread>
#include <mutex>

#include "kitchen/ingredients.hpp"


int main()
{
    int guests = 6;

    std::cout << "Preparing curry with rice for " << guests << " guests!" << std::endl;
    cookbook::begin_ingredients();
    
    /* Side Dish */
    Stove rice_stove;
    Pot rice_pot{2.0};
    Rice rice{0.075 * guests, Rice::Kind::Jasmine, Rice::Packaging::Bag};

    /* Main Dish */
    Stove stove;
    Pan chicken_pan{Pan::Type::Frying};
    Pan tofu_pan{Pan::Type::Frying};
    Pot curry_pot{4.0};
    Mug mug{0.25};

    Onion onions{1./3. * guests, Onion::Kind::Red};
    Carrot carrots{0.5 * guests};
    Oil curry_pot_oil{0.1, Oil::Type::Rapeseed};
    Oil tofu_pan_oil{0.1, Oil::Type::Rapeseed};
    Broth vegetable_broth{0.1 * guests, Broth::Source::Vegetable, Broth::Form::Cubes};
    Tofu tofu{0.05 * guests};
    Milk coconut_milk{0.4, Milk::Type::Coconut};
    Chicken chicken{0.1 * guests, Chicken::Part::Breast};
    Flour flour{0.05, Flour::Type::Plain};
    Water water(0.1);

    cookbook::begin_recipe();

    // let the rice cook and move onto other things while it's cooking
    rice.start_cooking(rice_pot, rice_stove);
    rice.monitor_cooking(rice_pot, rice_stove);

    // Begin preparing the curry
    onions.peel();
    onions.chop();
    carrots.peel();
    carrots.chop();

    curry_pot.add(curry_pot_oil);
    curry_pot.add(onions);
    stove.cook(curry_pot, Stove::Heat::Medium);
    cookbook::wait(std::chrono::minutes(5));
    curry_pot.add(carrots);
    carrots.add_spice("turmeric"); // quite a lot, 4 big spoons
    carrots.add_spice("pepper");
    curry_pot.add(carrots);
    curry_pot.add(vegetable_broth);
    curry_pot.add_lid();
    // Let it cook

    // Lets prepare the tofu.
    tofu_pan.add(tofu_pan_oil);
    tofu.cut();
    tofu.add_spice("paprika");
    tofu_pan.add(tofu);
    stove.cook(tofu_pan, Stove::Heat::High);
    cookbook::wait(std::chrono::minutes(5));

    //vratime se k nasemu curry pot
    curry_pot.remove_lid();
    curry_pot.add(coconut_milk);
    curry_pot.add(tofu_pan.remove(tofu));
    curry_pot.add_lid();

    // Prepare the chicken
    chicken.cut_into_cubes();
    chicken.add_spice("paprika");
    add_salt(chicken);
    chicken_pan.add(chicken);
    stove.cook(chicken_pan, Stove::Heat::Medium);
    cookbook::wait(std::chrono::minutes(15));
    stove.finish_cooking(chicken_pan);

    mug.add(flour);
    mug.add(water);
    mug.mix();

    curry_pot.remove_lid();
    curry_pot.add(flour); // slowly add mug contents bit by bit until the sauce is thick
    stove.finish_cooking(curry_pot);

    //rice_thread.join();
    //curry_thread.join();

    cookbook::finish();

    return 0;
}
