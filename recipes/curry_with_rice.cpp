#include "ingredients.hpp"

//defaultni jednotky vyresit
// thready vyresit



int main()
{
    int guests = 6;

    std::cout << "Preparing curry with rice for " << guests << " guests!" << std::endl;

    Pot rice_pot{2.0};
    Rice rice{0.075 * guests, Rice::Kind::Jasmine, Rice::Packaging::Bag};
    Stove stove;

    //jeden thread vari ryzi
    rice.cook(rice_pot, stove);

    Onion onions{1./3. * guests, Onion::Kind::Red};
    Carrot carrots{0.5 * guests};


    // priprava curry pt 1
    onions.peel();
    onions.chop();
    carrots.peel();
    carrots.chop();

    Pot curry_pot{4.0};
    Oil curry_pot_oil{0.1, Oil::Type::Rapeseed}; //is rapeseed legit 
    curry_pot.add(curry_pot_oil);
    curry_pot.add(onions);
    stove.cook(curry_pot, Stove::Heat::Medium);
    // wait(5 minut)
    curry_pot.add(carrots);
    carrots.add_spice("turmeric"); // quite a lot, 4 big spoons
    carrots.add_spice("pepper");
    Broth vegetable_broth{0.6 * guests, Broth::Source::Vegetable, Broth::Form::Cubes};
    curry_pot.add(carrots);
    curry_pot.add_lid();
    // Let it cook

    // Lets prepare the tofu.
    Pan tofu_pan{Pan::Type::Frying};
    tofu_pan.add(*(new Oil{0.1, Oil::Type::Rapeseed}));
    Tofu tofu{0.05 * guests};
    tofu.cut();
    tofu.add_spice("paprika");
    tofu_pan.add(tofu);
    stove.cook(tofu_pan, Stove::Heat::High);
    //wait(5 minut)

    //vratime se k nasemu curry pot
    Milk coconut_milk{0.4, Milk::Type::Coconut};
    curry_pot.remove_lid();
    curry_pot.add(coconut_milk);
    curry_pot.add(tofu_pan.remove(tofu));
    curry_pot.add_lid();

    // Prepare the chicken
    Pan chicken_pan{Pan::Type::Frying};
    Chicken chicken{0.1 * guests, Chicken::Part::Breast}; //todo amount
    chicken.cut_into_cubes();
    chicken.add_spice("paprika");
    add_salt(chicken);
    chicken_pan.add(chicken);
    stove.cook(chicken_pan, Stove::Heat::Medium);
    // wait(15 minut)
    stove.finish_cooking(chicken_pan);

    Mug mug{0.25};
    mug.add(*(new Flour{0.05, Flour::Type::Plain}));
    mug.add(*(new Water(0.1)));
    mug.mix();

    curry_pot.remove_lid();
    //curry_pot.add(mug.remove()); // slowly add mug contents bit by bit until the sauce is thick
    //curry_pot.add(mug) nelze bohuzel
    stove.finish_cooking(curry_pot);


    std::cout << "The meal is ready to be served.\U0001F35B Bon apetite!" << std::endl;
    return 0;
}

//vytvorit wait funkci, neimplementovat, std::chrono::duration jako arg.