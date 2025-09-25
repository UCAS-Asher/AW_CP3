//AW, Pokemon Battle

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Pokemons{
    string name;
    string type;
    int hp;
    int level;
    string attack_1;
    int attack_1_dmg;
    string attack_2;
    int attack_2_dmg;
    string attack_3;
    int attack_3_dmg;
    string attack_4;
    int attack_4_dmg;
};

enum Main{
    Explore = 1,
    Battle,
    Inventory,
    Exit
};

enum Battle{
    Attack = 1,
    Items,
    Pokemon,
    Run
};

void print_nice(string message, bool line_new){
    for(int i = 0; i < size(message); i++){
        cout << message[i];
        this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    if(line_new == true)
        cout << endl;
}

int rand_num_gen(int chance){
    int ran_num = (rand() % chance) + 1;

    return ran_num;
}

map<string, int> explore(map<string, int> items){
    int ran_num = rand_num_gen(5);

    if(ran_num == 1){
        cout << "You found a pokemon" << endl;
    }
    else if(ran_num == 2 || ran_num == 3){
        int ran_item = rand_num_gen(100);
        int amount_item = rand_num_gen(3);

        if(ran_item < 45){
            items["Potions"] +=amount_item;
            cout << "You found a Potion" << endl;
        }
        else if(ran_item > 45 & ran_item < 70){
            items["Good Potions"] +=amount_item;
            cout << "You found a Good Potion! Great" << endl;
        }
        else if(ran_item > 70 & ran_item < 80){
            items["Hyper Potions"] +=amount_item;
            cout << "You found a  Hyper Potion! So lucky" << endl;
        }
        else if(ran_item > 80 & ran_item < 95){
            items["Rare Candy"] +=amount_item;
            cout << "You found a Rare Candy! Lucky" << endl;
        }
        else if(ran_item >= 95){
            items["Ultra Rare Candy"] +=amount_item;
            cout << "You found an Ultra Rare Candy! So so very lucky!" << endl;
        }
    }
    else if(ran_num == 4){
        int get_pokeballs = rand_num_gen(5);
        int pokeball_type = rand_num_gen(10);
        
        if(pokeball_type < 60){
            items["Pokeballs"] +=get_pokeballs;
            cout << "You found " << get_pokeballs << " Pokeballs" << endl;
        }
        else if(pokeball_type < 90 & pokeball_type >= 60){
            items["Great Balls"] +=get_pokeballs;
            cout << "You found " << get_pokeballs << " Great Balls" << endl;
        }
        else if(pokeball_type >= 90){
            items["Ultra Balls"] +=get_pokeballs;
            cout << "You found " << get_pokeballs << " Ultra Balls" << endl;
        }
    }
    else{
        cout << "You found nothing! So unlucky" << endl;
    }
    return items;
}

void candy(bool ultra_rare){

}

void potion(string potion_type){

}

void use_item(map<string, int>& items, string item){
    for( auto& pair : items){
        if (pair.first == item && pair.second > 0){
            items[pair.first] -=1;
            if(item == "Rare Candy"){
                candy(false);
            }
            else if(item == "Ultra Rare Candy"){
                candy(true);
            }
            else if(item == "Potions" || item == "")
        }
        else if(pair.first == item && pair.second < 1){
            cout << "You have none of this item" << endl;
        }
        else{
            cout << "This item doesnt exist!" << endl;
        }
    }
}

void battle(){

}

void check_items(map<string, int>& items){
    cout << "Items" << endl;
    for( auto& pair : items){
        cout << pair.first <<": " << pair.second << endl;
    }
    cout << "Do you want to use an item(Y/N): ";
    string use;
    if(!(cin >> use)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
        cout << "Not an Option!" << endl << endl;
    }

    if(use == "Y"){
        cout << "What Item do you want to use: ";
        string item;
        cin >> item;
        use_item(map<string, int>& items, item);
    }
    else if(use == "N"){
        
    }
    else{
        cout << "Not an option!" << endl;
    }
}



int main(){
    vector<Pokemons> pokemon;
    pokemon.push_back({"Charmander", "Fire", 15});

    map<string, int> items;

    items["Pokeballs"] = 5;
    items["Great Balls"] = 0;
    items["Ultra Balls"] = 0;
    items["Money"] = 0;
    items["Potions"] = 5;
    items["Good Potions"] = 0;
    items["Hyper Potions"] = 0;
    items["Rare Candy"] = 0;
    items["Ultra Rare Candy"] = 0;



    srand(time(nullptr));
    this_thread::sleep_for(std::chrono::milliseconds(500));
    print_nice("Welcome to the world of pokemon! This world is inhabited by creatures called pokemon! For some people, they are pets. Others use them for fights. What will you use them for as you explore this world?", true);
    print_nice("Do you want to continue and explore this world(Y/N): ", false);
    string opening;

    if(!(cin >> opening)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
        cout << "I will asume this is a Yes :)" << endl << endl;
    }

    if(opening == "Y"){
        cout << "Nice Choice" << endl << endl;
    }
    else if(opening == "N"){
        cout << "Bye Bye :(" << endl  << endl;
        return 0;
    }
    else{
        cout << "I will asume this is a Yes :)" << endl << endl;
    }



    while(true){
        int choice;
        cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Items" << endl << "4. Exit" << endl << "Choose a Number: ";

        while(!(cin >> choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Items" << endl << "4. Exit" << endl << "Choose a Number: ";
        }

        if(choice == Main::Explore){
            explore(map<string, int> items);
        }
        else if(choice == Main::Battle){
            battle();
        }
        else if(choice == Main::Inventory){
            check_items(map<string, int> items);
        }
        else if(choice == Main::Exit){
            cout << "Program End";
            break;
        }
        else{
            cout << "Not an Option!";
        }
   }
   return 0;
}
