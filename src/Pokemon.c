#include "Pokemon.h"


Pokemon* init_Pokemon(char* name, char* species, double height, double weight, int attack, PokemonType* type){
	Pokemon* pokemon = (Pokemon*)malloc(sizeof(Pokemon));
	pokemon->pokName = (char*)malloc(strlen(name) + 1);
	pokemon->species = (char*)malloc(strlen(species) + 1);

	if (pokemon == NULL || pokemon->pokName == NULL || pokemon->species == NULL)
		return NULL;

	strcpy(pokemon->pokName, name);
	strcpy(pokemon->species, species);
	pokemon->info = init_pokemonInfo(height, weight, attack);
	pokemon->type = type;
	pokemon->type->numOfPok++;

	return pokemon;
}



PokemonInfo* init_pokemonInfo(double height, double weight, int attack){
	PokemonInfo* info = (PokemonInfo*)malloc(sizeof(PokemonInfo));
	if (info == NULL)
		return NULL;

	info->height = height;
	info->weight = weight;
	info->attack = attack;

	return info;
}



PokemonType* init_PokemonType(char* name){
	PokemonType* type = (PokemonType*)malloc(sizeof(PokemonType));
	type->typeName = (char*)malloc(strlen(name) + 1);
	if (type == NULL || type->typeName == NULL)
		return NULL;

	strcpy(type->typeName, name);
	type->numOfPok = 0;
	type->countMe = 0;
	type->countOther = 0;
	type->effective_against_me = (PokemonType**)malloc(sizeof(PokemonType*));
	type->effective_against_others = (PokemonType**)malloc(sizeof(PokemonType*));

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
	int i,j,idx = -1;
	PokemonType* tmp;
	for (i = 0; i < A->countMe; i++){
		if (strcmp(A->effective_against_me[i]->typeName, typename) == 0){
			freeType(A->effective_against_me[i]);
			A->effective_against_me[i] = NULL;
			idx = i;
			for (j = idx; j < A->countMe - 1;j++){
				tmp = A->effective_against_me[i];
				A->effective_against_me[i] = A->effective_against_me[i + 1];
				A->effective_against_me[i + 1] = tmp;
			}
			A->countMe--;
		}
	}

	if (idx == -1)
		return failure;

	PokemonType** ptmp;
	ptmp = (PokemonType**)realloc(A->effective_against_me, (sizeof(PokemonType*) * A->countMe));
	A->effective_against_me = ptmp;
	return success;
}



status deletefrom_against_others(PokemonType* A, char* typename){
	int i,j,idx = -1;
	PokemonType* tmp;
	for (i = 0; i < A->countOther; i++){
		if (strcmp(A->effective_against_others[i]->typeName, typename) == 0){
			freeType(A->effective_against_others[i]);
			A->effective_against_others[i] = NULL;
			idx = i;
			for (j = idx; j < A->countOther - 1;j++){
				tmp = A->effective_against_others[i];
				A->effective_against_others[i] = A->effective_against_others[i + 1];
				A->effective_against_others[i + 1] = tmp;
			}
			A->countOther--;
		}
	}

	if (idx == -1)
		return failure;

	PokemonType** ptmp;
	ptmp = (PokemonType**)realloc(A->effective_against_others, (sizeof(PokemonType*) * A->countOther));
	A->effective_against_others = ptmp;
	return success;
}



status print_Pokemon(Pokemon* pokemon){
	if (pokemon == NULL)
		return failure;

	printf("%s :\n%s, %s Type.\nHeight: %.2f m    Weight: %.2f kg    Attack: %d\n\n",
			pokemon->pokName, pokemon->species, pokemon->type->typeName, pokemon->info->height, pokemon->info->weight, pokemon->info->attack);

	return success;
}



status print_Type(PokemonType* type){
	int i;
	if (type == NULL)
		return failure;

	if (type->numOfPok == 0)
		printf("Type %s -- %d pokemons\n\n", type->typeName, type->numOfPok);

	else{
		printf("Type %s -- %d pokemons\n", type->typeName, type->numOfPok);
		if (type->countMe != 0){
			printf("\tThese types are super-effective against %s:", type->typeName);
			for (i = 0; i < type->countMe; i++){
				if (i == type->countMe - 1)
					printf("%s\n", type->effective_against_me[type->countMe - 1]->typeName);
				else
					printf("%s,", type->effective_against_me[i]->typeName);
			}
		}

		if (type->countOther != 0){
			printf("\t%s moves are super-effective against:", type->typeName);
			for (i = 0; i < type->countOther; i++){
				if (i == type->countOther - 1)
					printf("%s\n\n", type->effective_against_others[type->countOther - 1]->typeName);
				else
					printf("%s,", type->effective_against_others[i]->typeName);
			}
		}
	}

	return success;
}



PokemonType* searchType(PokemonType** allTypes, char* typeName, int numOfTypes){
	int i;
	for (i = 0; i < numOfTypes; i++){
		if (allTypes[i] == NULL)
			return NULL;

		if (strcmp(allTypes[i], typeName) == 0)
			return allTypes[i];
	}

	return NULL;
}



void freePokemon(Pokemon* tmp){
	if (tmp == NULL)
		return;

	free(tmp->pokName);
	free(tmp->species);
	free(tmp->info);
	//freeType(tmp->type);
	free(tmp);
}



void freeType(PokemonType* tmp){
	if (tmp == NULL)
		return;

	free(tmp->typeName);
	free(tmp->effective_against_me);
	free(tmp->effective_against_others);
	free(tmp);
}





