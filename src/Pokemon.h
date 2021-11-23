#ifndef POKEMON_H_
#define POKEMON_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum e_bool {false, true}bool;
typedef enum e_status {success, failure}status;


typedef struct PokemonType_s{
	char *typeName;
	int numOfPok;
	int countMe;
	int countOther;
	struct PokemonType_s** effective_against_me;
	struct PokemonType_s** effective_against_others;
}PokemonType;



typedef struct PokemonInfo_s{
	double height;
	double weight;
	int attack;
}PokemonInfo;



typedef struct Pokemon_s{
	char *pokName;
	char *species;
	PokemonType *type;
	PokemonInfo *info;
}Pokemon;





Pokemon* init_Pokemon(char* name, char* species, double height, double weight, int attack, PokemonType* type);

PokemonInfo* init_pokemonInfo(double height, double weight, int attack);

PokemonType* init_PokemonType(char* name);

void addto_against_me(PokemonType* A, PokemonType* B);

void addto_against_others(PokemonType* A, PokemonType* B);

status deletefrom_against_me(PokemonType* A, PokemonType* B);






void freeType(PokemonType* tmp);





#endif /* POKEMON_H_ */
