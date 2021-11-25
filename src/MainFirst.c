#include "Pokemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//static Pokemon** getPokemons(char* fileName, int size);


int numOfTypes;
int numOfPokemons;
Pokemon** PokemonsArr;
PokemonType** TypesArr;
PokemonType** allTypes;
PokemonType* addType = NULL;




int main(int argc,char *argv[]){
	numOfTypes = atoi(argv[1]);
	numOfPokemons = atoi(argv[2]);
	//allTypes = (PokemonType**)malloc(sizeof(PokemonType*) * numOfTypes);


	//PokemonsArr = getPokemons(argv[3], numOfPokemons);

	FILE* file = fopen(argv[3], "r");
	//PokemonType* newType;
	char data[300];
	char begin[300];
	strcpy(begin, "Pokemons\r\n");

	char tmp[300];//dat2
	char* until;
	char* end;//cat
	char read[5] = ",\r\n";

	char me[300];
	strcpy(me, "effective-against-me");
	char others[300];
	strcpy(others, "effective-against-others");

	fgets(data, 300, file);
	fgets(data, 300, file);
	strcpy(tmp, data);
	end = strtok(tmp, ",");

	while (end != NULL){
		printf("%s\n", end);
		end = strtok(NULL, read);
	}

	fgets(data, 300, file);

	tmp = strtok(data, ",");
	tmp = strtok(tmp, "\t");

	while ((strcmp(data, begin)) != 0){
		printf("%s\n",data);

		until = strtok(NULL, ":");











		fgets(data,300,file);
		tmp = strtok(data, "\t");
		tmp = strtok(tmp, " ");
	}





	return 0;
}







/*static Pokemon** getPokemons(char* fileName, int size){
	Pokemon** arr;
	arr = (Pokemon**)malloc(sizeof(Pokemon*) * size);
	if (arr == NULL){
		free(arr);
		return NULL;
	}

	int idx = 0;
	char begin[300];
	char curr[300];
	char* read;
	char name[300];
	char species[300];
	double height;
	double weight;
	int attack;
	char end[5] = ",\r\n";
	char type[300];
	strcpy(begin,"Pokemons\r\n");

	FILE* file = fopen(fileName, "r");
	char data[300];

	do {
		strcpy(curr,fgets(data,300,file));
	}while(strcmp(curr,begin) != 0);

	fgets(data,300,file);
	read = strtok(data, ",");

	while ((strcmp(read, begin)) != 0){

		while (read != NULL){
				strcpy(name, read);
				strcpy(begin, read);
				read = strtok(NULL,",");
				strcpy(species, read);
				read = strtok(NULL,",");
				height = atof(read);
				read = strtok(NULL,",");
				weight = atof(read);
				read = strtok(NULL,",");
				attack = atoi(read);
				read = strtok(NULL, end);
				strcpy(type, read);

				addType = searchType(allTypes, type, numOfTypes);
				if (addType == NULL)
					continue;

				arr[idx] = init_Pokemon(name, species, height, weight, attack, addType);
				idx++;

				read = strtok(NULL, end);
		}

		fgets(data,300,file);
		read = strtok(data, ",");

	}
	fclose(file);

	return arr;
}*/




