#include "Pokemon.h"


Pokemon* init_Pokemon(char* name, char* species, double height, double weight, int attack, PokemonType* type){
	Pokemon* pokemon = (Pokemon*)malloc(sizeof(Pokemon));
	pokemon->pokName = (char*)malloc(strlen(name) + 1);
	pokemon->species = (char*)malloc(strlen(species) + 1);

	if (pokemon == NULL || pokemon->pokName == NULL || pokemon->species == NULL){
		free(pokemon);
		free(pokemon->pokName);
		free(pokemon->species);
		return NULL;
	}

	strcpy(pokemon->pokName, name);
	strcpy(pokemon->species, species);
	pokemon->info = init_pokemonInfo(height, weight, attack);
	pokemon->type = type;
	pokemon->type->numOfPok++;

	return pokemon;
}



PokemonInfo* init_pokemonInfo(double height, double weight, int attack){
	PokemonInfo* info = (PokemonInfo*)malloc(sizeof(PokemonInfo));
	if (info == NULL){
		free(info);
		return NULL;
	}

	info->height = height;
	info->weight = weight;
	info->attack = attack;

	return info;
}



PokemonType* init_PokemonType(char* name){
	PokemonType* type = (PokemonType*)malloc(sizeof(PokemonType));
	type->typeName = (char*)malloc(strlen(name) + 1);
	if (type == NULL || type->typeName == NULL){
		free(type);
		free(type->typeName);
		return NULL;
	}

	strcpy(type->typeName, name);
	type->numOfPok = 0;
	type->countMe = 0;
	type->countOther = 0;
	type->effective_against_me = (PokemonType**)malloc(sizeof(PokemonType*));
	type->effective_against_me = (PokemonType**)malloc(sizeof(PokemonType*));

	return type;
}



void addto_against_me(PokemonType* A, PokemonType* B){
	A->effective_against_me = (PokemonType**)realloc(A->effective_against_me, sizeof(PokemonType*) * (A->countMe) + 1);
	if (A->effective_against_me == NULL)
		free(A->effective_against_me);

	A->effective_against_me[A->countMe] = B;
	A->countMe++;
}



void addto_against_others(PokemonType* A, PokemonType* B){
	A->effective_against_others = (PokemonType**)realloc(A->effective_against_others, sizeof(PokemonType*) * (A->countOther) + 1);
	if (A->effective_against_others == NULL)
		free(A->effective_against_others);

	A->effective_against_others[A->countOther] = B;
	A->countOther++;
}



status deletefrom_against_me(PokemonType* A, char* typename){
	int i;
	PokemonType* tmp;
	for (i = 0; i < A->countMe - 1; i++){
		if (strcmp(A->effective_against_me[i]->typeName, typename) == 0){
			freeType(A->effective_against_me[i]);
			A->effective_against_me[i] = NULL;
		}

	}



	return success;
}







void freeType(PokemonType* tmp){
	if (tmp == NULL)
		return;

	free(tmp->typeName);
	free(tmp->effective_against_me);
	free(tmp->effective_against_others);
	free(tmp);
}













