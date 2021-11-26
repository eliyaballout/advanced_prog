#include "Pokemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//static Pokemon** getPokemons(char* fileName, int size);
//static PokemonType** getTypes(char* fileName, int size);
static void printPokemons(Pokemon** arr, int size);


int numOfTypes;
int numOfPokemons;
Pokemon** PokemonsArr;
PokemonType** TypesArr;
PokemonType** allTypes;
PokemonType* addType = NULL;




int main(int argc,char *argv[]){
	numOfTypes = atoi(argv[1]);
	numOfPokemons = atoi(argv[2]);


	FILE* file = fopen(argv[3], "r");
	PokemonType* newType = NULL;

	char data[300];
	char tmp[300];//dat2
	fgets(data, 300, file);
	fgets(data, 300, file);
	strcpy(tmp, data);

	PokemonType** allTypes = (PokemonType**)malloc(sizeof(PokemonType*) * numOfTypes);
	char read[5] = ",\r\n";//token
	char* until;//str
	char* end;//cat
	int idx = 0;
	until = strtok(data, "\r\n");
	end = strtok(tmp, ",");

	while (end != NULL){
		allTypes[idx] = init_PokemonType(end);
		end = strtok(NULL, read);
		idx++;
	}

	fgets(data, 300, file);


	char begin[300];//p
	strcpy(begin, "Pokemons\r\n");

	char me[300];
	strcpy(me, "effective-against-me");

	char others[300];
	strcpy(others, "effective-against-other");

	end = strtok(data, "\t");
	end = strtok(end, " ");


	//fgets(data, 300, file);





	//fgets(data, 300, file);


	while ((strcmp(data, begin)) != 0){
		addType = searchType(allTypes, end, numOfTypes);
		if (addType == NULL){
			//fgets(data, 300, file);
			//end = strtok(data, "\t");
			//end = strtok(end, " ");
			//continue;
		}
		until = strtok(NULL, ":");

		if (strcmp(until, me) == 0){
			until = strtok(NULL, read);
			while (until != NULL){
				newType = searchType(allTypes, until, numOfTypes);
				if (newType == NULL){
					//addto_against_me(addType, newType);
					until = strtok(NULL, read);
					continue;
				}
				addto_against_me(addType, newType);
				until = strtok(NULL, read);
			}
		}

		else if (strcmp(until, others) == 0){
			until = strtok(NULL, read);
			while (until != NULL){
				newType = searchType(allTypes, until, numOfTypes);
				if (newType == NULL){
					//addto_against_others(addType, newType);
					until = strtok(NULL, read);
					continue;
				}
				addto_against_others(addType, newType);
				until = strtok(NULL, read);
			}
		}

		fgets(data,300,file);
		end = strtok(data, "\t");
		end = strtok(end, " ");
	}



///////////////////////////////////////////////////////////////////////////////////////



	Pokemon** arr;
	arr = (Pokemon**)malloc(sizeof(Pokemon*) * numOfPokemons);
/*	if (arr == NULL){
		free(arr);
		return NULL;*/


	//int idx = 0;
	//char begin[300];
	//char curr[300];
	//char* read;
	char name[300];
	char species[300];
	double height;
	double weight;
	int attack;
	//char end[5] = ",\r\n";
	char type[300];
	//strcpy(begin,"Pokemons\r\n");


	fgets(data, 300, file);
	end = strtok(data, ",");\
	idx = 0;

	while (strcmp(end, begin) != 0){
		while(end != NULL){
			strcpy(name, end);
			strcpy(begin, end);
			end = strtok(NULL,",");
			strcpy(species, end);
			end = strtok(NULL,",");
			height = atof(end);
			end = strtok(NULL,",");
			weight = atof(end);
			end = strtok(NULL,",");
			attack = atoi(end);
			end = strtok(NULL, read);
			strcpy(type, end);

			addType = searchType(allTypes, type, numOfTypes);
			if (addType == NULL){
				//read = strtok(NULL, end);
				//continue;
			}

			arr[idx] = init_Pokemon(name, species, height, weight, attack, addType);
			idx++;

			end = strtok(NULL,read);


		}
		fgets(data, 300, file);
		end = strtok(data, ",");
	}
	fclose(file);







/*	do {
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
				if (addType == NULL){
					read = strtok(NULL, end);
					continue;
				}

				arr[idx] = init_Pokemon(name, species, height, weight, attack, addType);
				idx++;

				read = strtok(NULL, end);
		}

		fgets(data,300,file);
		read = strtok(data, ",");

	}*/














	//TypesArr = getTypes(argv[3], numOfTypes);
	//PokemonsArr = getPokemons(argv[3], numOfPokemons);


	char ch = '1';

	while (true){
		printf("Please choose one of the following numbers:\n");
		printf("1 : Print all Pokemons\n");
		printf("2 : Print all Pokemons types\n");
		printf("3 : Add type to effective against me list\n");
		printf("4 : Add type to effective against others list\n");
		printf("5 : Remove type from effective against me list\n");
		printf("6 : Remove type from effective against others list\n");
		printf("7 : Print Pokemon by name\n");
		printf("8 : Print Pokemons by type\n");
		printf("9 : Exit\n");

		scanf("%s", &ch);

		switch(ch){

		case '1':
			printPokemons(arr, numOfPokemons);
			break;

		case '2':
			printf("this is case 2\n");
			break;

		case '3':
			printf("this is case 3\n");
			break;

		case '4':
			printf("this is case 4\n");
			break;

		case '5':
			printf("this is case 5\n");
			break;

		case '6':
			printf("this is case 6\n");
			break;

		case '7':
			printf("this is case 7\n");
			break;

		case '8':
			printf("this is case 8\n");
			break;

		case '9':
			printf("this is case 9\n");
			printf("shutting down the program\n");
			exit(1);
			break;


		default:
			printf("Please choose a valid number.\n");
			break;








		}


	}




	return 0;
}






static void printPokemons(Pokemon** arr, int size){

	if (arr == NULL)
		return;
	int i;
	for (i = 0; i < size; i++)
		print_Pokemon(arr[i]);
}






/*static PokemonType** getTypes(char* fileName, int size){
	allTypes = (PokemonType**)malloc(sizeof(PokemonType*) * size);
	if (allTypes == NULL)
		return NULL;

	FILE* file = fopen(fileName, "r");
	PokemonType* newType = NULL;
	int idx = 0;
	char data[300];
	char begin[300];//p
	strcpy(begin, "Pokemons\r\n");

	char tmp[300];//dat2
	char* until;//str
	char* end;//cat
	char read[5] = ",\r\n";//token

	char me[300];
	strcpy(me, "effective-against-me");
	char others[300];
	strcpy(others, "effective-against-other");

	fgets(data, 300, file);
	fgets(data, 300, file);
	strcpy(tmp, data);
	end = strtok(tmp, ",");
	until = strtok(data, "\r\n");
	while (end != NULL){
		allTypes[idx] = init_PokemonType(end);
		end = strtok(NULL, read);
		idx++;
	}

	fgets(data, 300, file);
	end = strtok(data, "\t");
	end = strtok(end, " ");


	while ((strcmp(data, begin)) != 0){
		addType = searchType(allTypes, end, numOfTypes);
		if (addType == NULL){
			fgets(data, 300, file);
			end = strtok(data, "\t");
			end = strtok(end, " ");
			printf("data %s\n", end);
			continue;
		}
		until = strtok(NULL, ":");

		if (strcmp(until, me) == 0){
			until = strtok(NULL, read);
			while (until != NULL){
				newType = searchType(allTypes, until, numOfTypes);
				if (newType != NULL){
					addto_against_me(addType, newType);
					until = strtok(NULL, read);
					//continue;
				}
				//addto_against_me(addType, newType);
				//until = strtok(NULL, read);
			}
		}

		else if (strcmp(until, others) == 0){
			until = strtok(NULL, read);
			while (until != NULL){
				newType = searchType(allTypes, until, numOfTypes);
				if (newType != NULL){
					addto_against_others(addType, newType);
					until = strtok(NULL, read);
					//continue;
				}
				//addto_against_others(addType, newType);
				//until = strtok(NULL, read);
			}
		}

		fgets(data,300,file);
		end = strtok(data, "\t");
		end = strtok(end, " ");
		printf("data %s\n", end);
	}
	fclose(file);

	return allTypes;
}*/



/*
static Pokemon** getPokemons(char* fileName, int size){
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
				if (addType == NULL){
					read = strtok(NULL, end);
					continue;
				}

				arr[idx] = init_Pokemon(name, species, height, weight, attack, addType);
				idx++;

				read = strtok(NULL, end);
		}

		fgets(data,300,file);
		read = strtok(data, ",");

	}
	fclose(file);

	return arr;
}
*/




