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

    
vector<AllPokemon> all_pokemon = {
    // Electric
    {"Pikachu", "Electric", 20, 20, 5, "Thunder Bolt", 8, "Electric", "Quick Attack", 7, "Normal", "Electro Ball", 9, "Electric", "Volt Tackle", 10, "Electric"},
    {"Magnemite", "Electric", 13, 13, 5, "Thunder Wave", 6, "Electric", "Tackle", 5, "Normal", "Spark", 7, "Electric", "Supersonic", 2, "Normal"},
    // Fire
    {"Charmander", "Fire", 15, 15, 5, "Flame Charge", 8, "Fire", "Scratch", 6, "Normal", "Flamethrower", 9, "Fire", "Growl", 0, "Normal"},
    {"Vulpix", "Fire", 14, 14, 5, "Ember", 7, "Fire", "Quick Attack", 6, "Normal", "Fire Spin", 8, "Fire", "Tail Whip", 2, "Normal"},
    // Grass
    {"Bulbasaur", "Grass", 15, 15, 5, "Vine Whip", 8, "Grass", "Tackle", 5, "Normal", "Razor Leaf", 9, "Grass", "Growl", 0, "Normal"},
    {"Oddish", "Grass", 13, 13, 5, "Tackle", 5, "Normal", "Trailblaze", 7, "Grass", "Sweet Scent", 0, "Normal", "Drain", 6, "Grass"},
    // Water
    {"Squirtle", "Water", 15, 15, 5, "Water Gun", 9, "Water", "Rapid Spin", 8, "Normal", "Bubble", 7, "Water", "Growl", 0, "Normal"},
    {"Psyduck", "Water", 12, 12, 5, "Bubble", 6, "Water", "Scratch", 6, "Normal", "Headache", 0, "Normal", "Tail Whip", 2, "Normal"},
    // Normal
    {"Eevee", "Normal", 14, 14, 5, "Tackle", 5, "Normal", "Quick Attack", 6, "Normal", "Swift", 8, "Normal", "Growl", 0, "Normal"},
    {"Rattata", "Normal", 13, 13, 5, "Tackle", 5, "Normal", "Quick Attack", 5, "Normal", "Growl", 0, "Normal", "Tail Whip", 2, "Normal"}
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
        this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    if(line_new == true)
        cout << endl;
}

int rand_num_gen(int chance){
    int ran_num = (rand() % chance) + 1;

    return ran_num;
}

void gen_pokemon(int num, const vector<AllPokemon>& all_pokemon,vector<UserPokemons>& pokemon){
    cout <<"You found a wild " << all_pokemon[num].name << "!" << endl;
    cout << "Do you want to catch it? (Y/N): ";
    string catch_choice;
    catch_choice = check_input(catch_choice);

    if(catch_choice == "Y" || catch_choice == "y"){
        cout << "You caught " << all_pokemon[num].name << "!" << endl;
        UserPokemons caught_pokemon;
        caught_pokemon.name = all_pokemon[num].name;
        caught_pokemon.type = all_pokemon[num].type;
        caught_pokemon.max_hp = all_pokemon[num].max_hp;
        caught_pokemon.current_hp = all_pokemon[num].current_hp;
        caught_pokemon.level = all_pokemon[num].level;
        caught_pokemon.attack_1 = all_pokemon[num].attack_1;
        caught_pokemon.attack_1_dmg = all_pokemon[num].attack_1_dmg;
        caught_pokemon.type_1 = all_pokemon[num].type_1;
        caught_pokemon.attack_2 = all_pokemon[num].attack_2;
        caught_pokemon.attack_2_dmg = all_pokemon[num].attack_2_dmg;
        caught_pokemon.type_2 = all_pokemon[num].type_2;
        caught_pokemon.attack_3 = all_pokemon[num].attack_3;
        caught_pokemon.attack_3_dmg = all_pokemon[num].attack_3_dmg;
        caught_pokemon.type_3 = all_pokemon[num].type_3;
        caught_pokemon.attack_4 = all_pokemon[num].attack_4;
        caught_pokemon.attack_4_dmg = all_pokemon[num].attack_4_dmg;
        caught_pokemon.type_4 = all_pokemon[num].type_4;
        pokemon.push_back(caught_pokemon);
    }
    else{
        cout << all_pokemon[num].name << " ran away!" << endl << endl;
    }
    cout << endl;
}

void explore(vector<UserPokemons>& pokemon, vector<AllPokemon>& all_pokemon){
    int ran_num = rand_num_gen(5);

    if(ran_num == 1|| ran_num == 2){
       int ran_pokemon = rand_num_gen(10) - 1 ;
        gen_pokemon(ran_pokemon,all_pokemon,pokemon);
    }
    else{
        cout << "You found nothing! So unlucky" << endl << endl;
    }
}

void see_pokemon(const vector<UserPokemons>& pokemon){
    for( auto& pair : pokemon){
        cout << pair.name << ": Hp: " << pair.current_hp << "/"  << pair.max_hp << " Level: " << pair.level << endl;
    }
    cout << endl;
}

void heal(vector<UserPokemons>& pokemon){
    for(auto& pair : pokemon){
        if(pair.max_hp == pair.current_hp){
            cout << pair.name << "Is at full health" << endl;
        }
        else{
            cout << pair.name << " has been healed " << pair.max_hp - pair.current_hp  << " HP" << endl;
            pair.current_hp = pair.max_hp;
        }
    }
    cout << endl;  
}

void battle_heal(vector<UserPokemons>& pokemon){

}

void choose_pokemon(const vector<UserPokemons>& pokemon){
    int i = 0;
    for( auto& pair : pokemon){
        i++;
        cout << i << ". " << pair.name << endl;
    }

    int pokemon_choice;

    if(!(cin >> pokemon_choice)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
    }

    if(pokemon_choice == 1){

    }
    else if(pokemon_choice == 2){
        
    }
    else if(pokemon_choice == 3){
        
    }
    else if(pokemon_choice == 4){
        
    }
    else if(pokemon_choice == 5){
        
    }
    else if(pokemon_choice == 6){
        
    }
}

void battle(vector<UserPokemons>& pokemon, const vector<AllPokemon>& all_pokemon){
    if(pokemon.empty()){
        cout << "You have no pokemon! You cant battle!" << endl << endl;
        return;
    }
    
    string opponent_names[8] = {"James", "Jack", "Max", "Joey", "Jasper", "Mathew", "Mart", "Mason"};
    AllPokemon opponent_pokemon;
    opponent_pokemon = all_pokemon[rand_num_gen(10) - 1];
    string opponent_name = opponent_names[rand_num_gen(opponent_names.size()) - 1];

    cout << "Trainer " << opponent_name << " want to battle you!" << endl;
    cout << opponent_pokemon.name << " was sent out" << endl;




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
            explore(pokemon, all_pokemon);
        }
        else if(choice == Main::Battle){
            battle(pokemon, all_pokemon);
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
