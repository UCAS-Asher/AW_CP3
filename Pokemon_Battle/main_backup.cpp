//AW, Pokemon Battle

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

struct AllPokemon{
    string name;
    string type;
    int max_hp;
    int current_hp;
    int level;
    string attack_1;
    int attack_1_dmg;
    string type_1;
    string attack_2;
    int attack_2_dmg;
    string type_2;
    string attack_3;
    int attack_3_dmg;
    string type_3;
    string attack_4;
    int attack_4_dmg;
    string type_4;
};


struct UserPokemons{
    string name;
    string type;
    int max_hp;
    int current_hp;
    int level;
    string attack_1;
    int attack_1_dmg;
    string type_1;
    string attack_2;
    int attack_2_dmg;
    string type_2;
    string attack_3;
    int attack_3_dmg;
    string type_3;
    string attack_4;
    int attack_4_dmg;
    string type_4;
};

enum Main{
    Explore = 1,
    Battle,
    Heal,
    See_Pokemon,
    Exit
};

enum Battle{
    Attack = 1,
    Health,
    Pokemon,
    Run
};

string check_input(string input){
    if(!(cin >> input)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
        cout << "Not an Option!" << endl << endl;
    }
    return input;
}

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

void gen_pokemon(int num, vector<UserPokemons>& pokemon){
    if(num <= 25){
        cout << "A wild Charmander appered! Do you want to catch it(Y/N): ";
        string choice;
        choice = check_input(choice);
        if(choice == "Y"){
            pokemon.push_back({"Charmander", "Fire", 15, 15, 5, "Ember", 7, "Fire", "Tackle", 3, "Normal", "Scratch", 6, "Normal", "Quick Attack" , 5, "Normal"});
            cout << "You Caught a Charmander!" << endl;
        }
        else{
            cout << "No Catch I Guess ¯_(ツ)_/¯" << endl;
        }
    }
    else if(num > 25 & num <= 50){
        cout << "A wild Bulbasaur appered! Do you want to catch it(Y/N): ";
        string choice;
        choice = check_input(choice);
        if(choice == "Y"){
            pokemon.push_back({"Bulbasaur", "Grass", 15, 15, 5, "Vine Whip", 7, "Grass", "Tackle", 3, "Normal", "Razor Leaf", 6, "Grass", "Quick Attack", 5, "Normal"});
            cout << "You Caught a Bulbasaur!" << endl;
        }
        else{
            cout << "No Catch I Guess ¯_(ツ)_/¯" << endl;
        }
    }   
    else if(num > 50 & num <= 75){
        cout << "A wild Squirtle appered! Do you want to catch it(Y/N): ";
        string choice;
        choice = check_input(choice);
        if(choice == "Y"){
            pokemon.push_back({"Squirtle", "Water", 15, 15, 5, "Water Gun", 7, "Water", "Tackle", 3, "Normal", "Bubble", 6, "Water", "Quick Attack", 5, "Normal"});
            cout << "You Caught a Squirtle!" << endl;
        }
        else{
            cout << "No Catch I Guess ¯_(ツ)_/¯" << endl;
        }
    }
    else if(num >= 90){
        cout << "A wild Pikachu appered! Do you want to catch it(Y/N): ";
        string choice;
        choice = check_input(choice);
        if(choice == "Y"){
            pokemon.push_back({"Pikachu", "Electric", 15, 15, 5, "Thunder Bolt", 8, "Electric", "Volt Tackle", 9, "Electric", "Quick Attack", 6, "Normal", "Electro Web", 7, "Electric"});
            cout << "You Caught a Pikachu!" << endl;
        }
        else{
            cout << "No Catch I Guess ¯_(ツ)_/¯" << endl;
        }
    }
    else if(num < 90 & num > 75){
        cout << "A wild Eevee appered! Do you want to catch it(Y/N): ";
        string choice;
        choice = check_input(choice);
        if(choice == "Y"){
            pokemon.push_back({"Eevee", "Normal", 15, 15, 5, "Tackle", 2, "Normal", "Quick Attack", 4, "Normal", "Swift", 6, "Normal", "Trail Blaze", 5, "Grass"});
            cout << "You Caught an Eevee!" << endl;
        }
        else{
            cout << "No Catch I Guess ¯_(ツ)_/¯" << endl;
        }
    }
    cout << endl;
}

void explore(vector<UserPokemons>& pokemon){
    int ran_num = rand_num_gen(5);

    if(ran_num == 1|| ran_num == 2){
       int ran_pokemon = rand_num_gen(100);
        gen_pokemon(ran_pokemon, pokemon);
    }
    else{
        cout << "You found nothing! So unlucky" << endl << endl;
    }
}

void see_pokemon(vector<UserPokemons> pokemon){
    for( auto& pair : pokemon){
        cout << pair.name << ": Hp: " << pair.current_hp << "/"  << pair.max_hp << " Level: " << pair.level << endl;
    }
    cout << endl;
}

void heal(vector<UserPokemons>& pokemon){

}

void battle(vector<UserPokemons>& pokemon){

}


int main(){
    vector<UserPokemons> pokemon;
    

    srand(time(nullptr));
    this_thread::sleep_for(std::chrono::milliseconds(500));
    print_nice("Welcome to the world of pokemon! This world is inhabited by creatures called pokemon! For some people, they are pets. Others use them for fights. What will you use them for as you explore this world?", true);
    


    while(true){
        int choice;
        cout << "Pokemon" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Heal" << endl << "4. See Pokemon" << endl << "5. Exit" << endl << "Choose a Number: ";

        while(!(cin >> choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << "Pokemon" << endl << "1. Explore" << endl << "2. Battle" << endl << "3. Heal" << endl << "4. Exit" << endl << "Choose a Number: ";
        }

        if(choice == Main::Explore){
            explore(pokemon);
        }
        else if(choice == Main::Battle){
            battle(pokemon);
        }
        else if(choice == Main::Heal){
            heal(pokemon);
        }
        else if(choice == Main:: See_Pokemon){
            see_pokemon(pokemon);
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
