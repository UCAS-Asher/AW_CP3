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

struct UserPokemons{
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
    Heal,
    Exit
};

enum Battle{
    Attack = 1,
    Health,
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

gen_pokemon(int num){
    if(num == 1){
        pokemon.push_back({"Charmander", "Fire", 15, 5, "Ember", 7, "Tackle", 3, "Dragon Claw", 6, "Quick Attack" , 5});
    }
    else if(num == 2){
        pokemon.push_back({"Bulbasaur", "Grass", 15, 5, "Vine Whip", 7, "Tackle", 3, "Leech Seed", 4, "Razor Leaf", 5});
    }   
    pokemon.push_back({"Squirtle", "Water", 15, 5, "Water Gun", 7, "Tackle", 3, "Bubble", 4, "Rapid Spin", 2});
        pokemon.push_back({"Pikachu", "Electric", 15, 5, "Thunder Shock", 6, "Quick Attack", 5, "Tail Whip", 2, "Electro Ball", 7});
        pokemon.push_back({"Eevee", "Normal", 15, 5, "Tackle", 3, "Sand Attack", 2, "Quick Attack", 5, "Swift", 7});
    }
}

void explore(){
    int ran_num = rand_num_gen(5);

    if(ran_num == 1|| ran_num == 2){
        ran_pokemon = rand_num_gen();
        cout << "You found a pokemon" << endl;
    }
    else{
        cout << "You found nothing! So unlucky" << endl;
    }
}

void heal(){

}

void battle(){

}



int main(){
    vector<UserPokemons> pokemon;
    pokemon.push_back({"Charmander", "Fire", 15});



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
        cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Heal" << endl << "4. Exit" << endl << "Choose a Number: ";

        while(!(cin >> choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << "Main Menu" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Heal" << endl << "4. Exit" << endl << "Choose a Number: ";
        }

        if(choice == Main::Explore){
            explore();
        }
        else if(choice == Main::Battle){
            battle();
        }
        else if(choice == Main::Heal){
            heal();
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
