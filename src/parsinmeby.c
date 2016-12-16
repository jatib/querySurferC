#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#define LIMITE 500

void procesoArchivo(char *archivo,int cuenta);

int main()
{
	FILE *fichero;
	char ARCHIVO[50][50],query[50];

	DIR *dir;
	struct dirent *ent;
	dir = opendir (".");

	int filas=0;

	while ((ent = readdir (dir)) != NULL)
    {
      /* Nos devolverá el directorio actual (.) y el anterior (..), como hace ls */
      if ( (strcmp(ent->d_name, ".")!=0) )//&& (strcmp(ent->d_name, "..")!=0) )
    	{
    		for (int i = 0; i < strlen(ent->d_name); ++i)
    		{
    			ARCHIVO[filas][i]=ent->d_name[i];
    		}
    		//printf("%s\n",ent->d_name);
      		/* Una vez tenemos el archivo, lo pasamos a una función para procesarlo. */
      		//procesoArchivo(ent->d_name,z);
      		filas++;
    	}
    }

	printf("Ingresa cadena a buscar:\n");
	scanf("%s",query);
	printf("\n\n\n");

	if (dir == NULL)
    printf("No puedo abrir el directorio");

	for (int z = 0; z < filas; ++z)
	{
		int caracter,num_lineas,cadena,contador_char = 0, mayor,valor_inicial,valor;
		fichero = fopen(ARCHIVO[z],"r");

		if (fichero != NULL)
		{
			int n = 0,final,k=0;
			
			final = strlen(query);
			//printf("último indice no nulo(%d) y longitud de la cadena(%d) \n", final, final+1);
			//printf("valor inicial query:%c ",query[n]);
			//printf("| valor final:%c\n",query[final]);

			while( /*((caracter = fgetc(fichero)) != EOF ) || */n != final)
			{
				int a=(((caracter = fgetc(fichero)) != EOF ) || n != final);
				

				if(caracter == query[n]){
					n++;
					//printf("|1:%d:%d|",k,n);
				}else{
					if(n!=0){
						n=0;
					}
				}
				if(caracter == EOF)break;
				k++;

				//printf("%d",a);
			}

			//if(k==0)printf("No entré al ciclo\n");
				//else printf("Paso del ciclo %d\n",k);
			if(n==final){
				printf("Encontré el query %s, está en: ",query);
				printf("%s\n",ARCHIVO[z]);
				printf("Caracteres contados: %d\n\n\n",k);
			}/*else{
				if(caracter==EOF)printf("Llegué al final del arcivho y no encontré el query %s\n", query);
				printf("Archivo parseado: %s\n",ARCHIVO[z]);
				printf("Caracteres contados: %d\n\n\n",k);
			}*/
		}
	}
  	return EXIT_SUCCESS;
}
