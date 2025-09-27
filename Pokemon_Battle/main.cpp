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
    {"Pikachu", "Electric", 20, 20, 1, "Thunder Bolt", 8, "Electric", "Quick Attack", 7, "Normal", "Electro Ball", 9, "Electric", "Volt Tackle", 10, "Electric"},
    {"Magnemite", "Electric", 13, 13, 1, "Thunder Wave", 6, "Electric", "Tackle", 5, "Normal", "Spark", 7, "Electric", "Supersonic", 2, "Normal"},
    // Fire
    {"Charmander", "Fire", 15, 15, 1, "Flame Charge", 8, "Fire", "Scratch", 6, "Normal", "Flamethrower", 9, "Fire", "Growl", 0, "Normal"},
    {"Vulpix", "Fire", 14, 14, 1, "Ember", 7, "Fire", "Quick Attack", 6, "Normal", "Fire Spin", 8, "Fire", "Tail Whip", 2, "Normal"},
    // Grass
    {"Bulbasaur", "Grass", 15, 15, 1, "Vine Whip", 8, "Grass", "Tackle", 5, "Normal", "Razor Leaf", 9, "Grass", "Growl", 0, "Normal"},
    {"Oddish", "Grass", 13, 13, 1, "Tackle", 5, "Normal", "Trailblaze", 7, "Grass", "Sweet Scent", 0, "Normal", "Drain", 6, "Grass"},
    // Water
    {"Squirtle", "Water", 15, 15, 1, "Water Gun", 9, "Water", "Rapid Spin", 8, "Normal", "Bubble", 7, "Water", "Growl", 0, "Normal"},
    {"Psyduck", "Water", 12, 12, 1, "Bubble", 6, "Water", "Scratch", 6, "Normal", "Headache", 0, "Normal", "Tail Whip", 2, "Normal"},
    // Normal
    {"Eevee", "Normal", 14, 14, 1, "Tackle", 5, "Normal", "Quick Attack", 6, "Normal", "Swift", 8, "Normal", "Growl", 0, "Normal"},
    {"Rattata", "Normal", 13, 13, 1, "Tackle", 5, "Normal", "Quick Attack", 5, "Normal", "Growl", 0, "Normal", "Tail Whip", 2, "Normal"}
    };

float operator== (string attack_type, AllPokemon defender){
    if(attack_type == "Fire" & defender.type == "Water")
        return 0.5;
    else if(attack_type == "Fire" & defender.type == "Grass")
        return 1.5;
    else if(attack_type == "Water" & defender.type == "Grass")
        return 0.5;
    else if(attack_type == "Water" & defender.type == "Fire")
        return 1.5;
    else if(attack_type == "Grass" & defender.type == "Fire")
        return 0.5;
    else if(attack_type == "Grass" & defender.type == "Water")
        return 1.5;
    else if(attack_type == "Electric" & defender.type == "Grass")
        return 0.5;
    else if(attack_type == "Electric" & defender.type == "Water")
        return 1.5;
    else
        return 1;
}

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

bool operator==(AllPokemon catching, const vector<UserPokemons>& pokemon){
    for(auto& pair : pokemon){
            if(catching.name == pair.name){
                return true;
            }
    }
    return false;
}

void gen_pokemon(int num, const vector<AllPokemon>& all_pokemon,vector<UserPokemons>& pokemon){
    cout <<"You found a wild " << all_pokemon[num].name << "!" << endl;
    cout << "Do you want to catch it? (Y/N): ";
    string catch_choice;
    catch_choice = check_input(catch_choice);

    if(catch_choice == "Y" || catch_choice == "y"){
        if(all_pokemon[num] == pokemon){
            cout << "You alredy have this Pokemon!" << endl;
            return;
        }
        
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
    if(pokemon.size() >= 6){
        cout << "You have 6 pokemon!" << endl;
        return;
    }
    
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
            cout << pair.name << " Is at full health" << endl;
        }
        else{
            cout << pair.name << " has been healed " << pair.max_hp - pair.current_hp  << " HP" << endl;
            pair.current_hp = pair.max_hp;
        }
    }
    cout << endl;  
}

AllPokemon battle_heal(AllPokemon user_pokemon){
    if(user_pokemon.max_hp == user_pokemon.current_hp){
        cout << user_pokemon.name << "Is at full health" << endl;
    }
    else{
        cout << user_pokemon.name << " has been healed " << 6*user_pokemon.level/2  << " HP" << endl;
        user_pokemon.current_hp += 6*user_pokemon.level/2;
        
        if(user_pokemon.max_hp == user_pokemon.current_hp){
            user_pokemon.current_hp = user_pokemon.max_hp;
        }
    }
    return user_pokemon;
}

float type_advantage(string attack_type, AllPokemon defender){
    float advantage;

    advantage = attack_type == defender;

    return advantage;
}

AllPokemon attack(AllPokemon attacker, AllPokemon defender, string attack_name, int attack_dmg, string attack_type){
    float advantage = type_advantage(attack_type, defender);
    cout << attacker.name << " used " << attack_name << " and did " << (attack_dmg + (3*attacker.level)) * advantage << " damage" << endl;
    defender.current_hp -= attack_dmg + ((2*attacker.level) * advantage);

    return attacker, defender;
}

AllPokemon user_turn(AllPokemon user_pokemon, AllPokemon opponent_pokemon){
    cout << "Your Turn!" << endl << "1. Attack     2. Heal" << endl << "Choose a Number: ";
    int choice;

    while(!(cin >> choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << "Your Turn!" << endl << "1. Attack     2. Heal" << endl << "Choose a Number: ";
    }

    if(choice == Battle::Attack){
        cout << endl;
        cout << user_pokemon.name << ": Hp: " << user_pokemon.current_hp << endl;
        cout << "1. " << user_pokemon.attack_1 << "     2. " << user_pokemon.attack_2 << endl;
        cout << "3. " << user_pokemon.attack_3 << "     4. " << user_pokemon.attack_4 << endl;
        cout << "Choose a Number: ";

        int attack_choice;

        while(!(cin >> attack_choice)){
            cout << "Put a Number!" << endl << endl;
            cin.clear();
            cin.ignore();
            cout << endl;
            cout << user_pokemon.name << ": Hp: " << user_pokemon.current_hp << endl;
            cout << "1. " << user_pokemon.attack_1 << "     2. " << user_pokemon.attack_2 << endl;
            cout << "3. " << user_pokemon.attack_3 << "     4. " << user_pokemon.attack_4 << endl;
            cout << "Choose a Number: ";
        }

        if(attack_choice == 1){
            user_pokemon, opponent_pokemon = attack(user_pokemon, opponent_pokemon, user_pokemon.attack_1, user_pokemon.attack_1_dmg, user_pokemon.type_1);
        }
        else if(attack_choice == 2){
            user_pokemon, opponent_pokemon = attack(user_pokemon, opponent_pokemon, user_pokemon.attack_2, user_pokemon.attack_2_dmg, user_pokemon.type_2);
        }
        else if(attack_choice == 3){
            user_pokemon, opponent_pokemon = attack(user_pokemon, opponent_pokemon, user_pokemon.attack_3, user_pokemon.attack_3_dmg, user_pokemon.type_3);
        }
        else if(attack_choice == 4){
            user_pokemon, opponent_pokemon = attack(user_pokemon, opponent_pokemon, user_pokemon.attack_4, user_pokemon.attack_4_dmg, user_pokemon.type_4);
        }
        else{
            cout << "You missed your turn! You didnt tell your pokemon what to do." << endl;
        }

    }
    else if(choice == Battle::Health){
        user_pokemon = battle_heal(user_pokemon);
    }
    else{
        cout << "Put an Option Next Time! You missed your turn" << endl;
    }

    return user_pokemon, opponent_pokemon;

}

AllPokemon opponent_turn(AllPokemon user_pokemon, AllPokemon opponent_pokemon){
    int attack_choice = rand_num_gen(4);
    if(attack_choice == 1){
        user_pokemon, opponent_pokemon = attack(opponent_pokemon, user_pokemon, opponent_pokemon.attack_1, opponent_pokemon.attack_1_dmg, opponent_pokemon.type_1);
    }
    else if(attack_choice == 2){
        user_pokemon, opponent_pokemon = attack(opponent_pokemon, user_pokemon, opponent_pokemon.attack_2, opponent_pokemon.attack_2_dmg, opponent_pokemon.type_2);
    }
    else if(attack_choice == 3){
        user_pokemon, opponent_pokemon = attack(opponent_pokemon, user_pokemon, opponent_pokemon.attack_3, opponent_pokemon.attack_3_dmg, opponent_pokemon.type_3);
    }
    else if(attack_choice == 4){
        user_pokemon, opponent_pokemon = attack(opponent_pokemon, user_pokemon, opponent_pokemon.attack_4, opponent_pokemon.attack_4_dmg, opponent_pokemon.type_4);
    }

    return user_pokemon, opponent_pokemon;
}

AllPokemon choose_pokemon(const vector<UserPokemons>& pokemon, const vector<AllPokemon>& all_pokemon){
    int i = 0;
    cout << "Pokemon Choice" << endl;
    for( auto& pair : pokemon){
        i++;
        cout << i << ". " << pair.name << endl;
    }
    cout << "Choose a Number: ";

    int pokemon_choice;

    if(!(cin >> pokemon_choice)){
        cout << "" << endl << endl;
        cin.clear();
        cin.ignore();
    }
    AllPokemon user_pokemon;
    if(pokemon_choice == 1){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    else if(pokemon_choice == 2 && pokemon.size() >= 2){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
        
    }
    else if(pokemon_choice == 3 && pokemon.size() >= 3){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    else if(pokemon_choice == 4 && pokemon.size() >= 4){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    else if(pokemon_choice == 5 && pokemon.size() >= 5){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    else if(pokemon_choice == 6 && pokemon.size() >= 6){
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[pokemon_choice - 1].name, pokemon[pokemon_choice - 1].type, pokemon[pokemon_choice - 1].max_hp, pokemon[pokemon_choice - 1].current_hp, pokemon[pokemon_choice - 1].level, pokemon[pokemon_choice - 1].attack_1, pokemon[pokemon_choice - 1].attack_1_dmg, pokemon[pokemon_choice - 1].type_1, pokemon[pokemon_choice - 1].attack_2, pokemon[pokemon_choice - 1].attack_2_dmg, pokemon[pokemon_choice - 1].type_2, pokemon[pokemon_choice - 1].attack_3, pokemon[pokemon_choice - 1].attack_3_dmg, pokemon[pokemon_choice - 1].type_3, pokemon[pokemon_choice - 1].attack_4, pokemon[pokemon_choice - 1].attack_4_dmg, pokemon[pokemon_choice - 1].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    else{
        cout << "Not an Option!" << endl << endl;
        AllPokemon user_pokemon; 
        user_pokemon = {pokemon[0].name, pokemon[0].type, pokemon[0].max_hp, pokemon[0].current_hp, pokemon[0].level, pokemon[0].attack_1, pokemon[0].attack_1_dmg, pokemon[0].type_1, pokemon[0].attack_2, pokemon[0].attack_2_dmg, pokemon[0].type_2, pokemon[0].attack_3, pokemon[0].attack_3_dmg, pokemon[0].type_3, pokemon[0].attack_4, pokemon[0].attack_4_dmg, pokemon[0].type_4 };
        return user_pokemon;
        cout << "You sent out " << user_pokemon.name << "!" << endl;
    }
    return user_pokemon;
}

void battle(vector<UserPokemons>& pokemon, const vector<AllPokemon>& all_pokemon){
    if(pokemon.empty()){
        cout << "You have no pokemon! You cant battle!" << endl << endl;
        return;
    }
    
    string opponent_names[8] = {"James", "Jack", "Max", "Joey", "Jasper", "Mathew", "Mart", "Mason"};
    AllPokemon opponent_pokemon;
    opponent_pokemon = all_pokemon[rand_num_gen(10) - 1];
    string opponent_name = opponent_names[rand_num_gen(8) - 1];

    cout << "Trainer " << opponent_name << " want to battle you!" << endl;
    cout << opponent_pokemon.name << " was sent out" << endl << endl;
    AllPokemon user_pokemon = choose_pokemon(pokemon, all_pokemon);

    bool win;
    while(true){
        user_pokemon, opponent_pokemon = user_turn(user_pokemon, opponent_pokemon);
        if(opponent_pokemon.current_hp < 1){
            cout << "You Won!" << endl;
            win = true;
            cout << user_pokemon.name << " Leveled Up" << endl;
            user_pokemon.level +=1;
            break;
        }
        cout << opponent_pokemon.name << ": " << opponent_pokemon.current_hp << " HP" << endl;
        user_pokemon, opponent_pokemon = opponent_turn(user_pokemon, opponent_pokemon);
        if(user_pokemon.current_hp < 1){
            cout << "You Lost! Trainer " << opponent_name << " won" << endl << endl;
            win = false;
            break;
        }
    }
    
    if(win == true){
        for(auto& pair : pokemon){
            if(user_pokemon.name == pair.name){
                pair.level = user_pokemon.level;
                pair.current_hp = user_pokemon.current_hp;
                pair.max_hp +=5;
            }
        }
    }
    else{
        for(auto& pair : pokemon){
            if(user_pokemon.name == pair.name){
                pair.current_hp = user_pokemon.current_hp;
            }
        }
    }
    
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
