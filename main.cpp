#include <bits/stdc++.h>

using namespace std;

int getHeaviestBackpack(ifstream& fromfile, int quantity);
int getLighterBackpacks(ifstream& fromfile, int heaviestBackpack, int times);
int main()
{
    ifstream fromFile("U1.txt");
    ofstream toFile("U1rez.txt");
    int quantity; //kiekis kupriniu
    fromFile>>quantity;
    int heaviest_backpack = getHeaviestBackpack(fromFile, quantity);//grazina sunkiausios kuprines mase
    int lighter_backpacks = getLighterBackpacks(fromFile, heaviest_backpack, 2);//grazina kupriniu skaiciu, kurios yra 2 ar daugiau kartu lengvesnes
    toFile<<heaviest_backpack<<" "<<lighter_backpacks;//iraso i faila
    return 0;
}

int getHeaviestBackpack(ifstream& fromfile, int quantity){
    int tempBackpack; //laikinai info laikyti apie kuprines mase
    int heaviestBackpack = 0;
    for(int i = 0; i < quantity; i++){
        fromfile>>tempBackpack;
        if(tempBackpack > heaviestBackpack) heaviestBackpack = tempBackpack; //jei randa sunkesne isimina
    }
    return heaviestBackpack;
}
int getLighterBackpacks(ifstream& fromfile, int heaviestBackpack, int times){
    fromfile.clear();
    fromfile.seekg(0, ios::beg);//grazina i txt failo pradzia
    int tempBackpack;
    int lighterBackpacks = 0;
    int quantity;
    fromfile>>quantity;
    for(int i = 0; i < quantity; i++){
        fromfile>>tempBackpack;
        if(tempBackpack*times <= heaviestBackpack) lighterBackpacks++; //jei randa 2 kartus lengvesne isimina
    }
    return lighterBackpacks;
}
