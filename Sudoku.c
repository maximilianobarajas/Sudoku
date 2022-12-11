#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
struct juegodatos {
  char nombredeljugador[50];
  int numerodemodificaciones;
  int matrizdejuego [9][9];
  int edad;

};
void guardar(int matriz[9][9]) ;
void guardarclon(int matriz[9][9]);
void guardarsolucion(int matriz[9][9]);
void reiniciar(int matriz[9][9],int matrizclonada[9][9]);
int cuadrante(int x, int y, int num, int sudoku[9][9]);
void rotar(int matriz[9][9]);
int fcolumnas(int sudoku[9][9]);
void cargar(int matriz[9][9],int k);
int ffilas(int sudoku[9][9]);
int modificar_cuadrantes(int opcion,int sudoku[9][9]);
int fsfilas(int sudoku[9][9],int x,int y);
int fcolumnas(int sudoku[9][9]);
int ccaracteres(int sudoku[9][9]);
int main(){ 
   int i,j,n=1; 
   struct juegodatos juegoactual;
   printf("Ingresa tu nombre: \n");
   fgets(juegoactual.nombredeljugador,50,stdin);
   printf("Tu nombre es ");
   puts(juegoactual.nombredeljugador);
   printf("\n");
   printf("Ingresa tu edad: \n");
   scanf("%d",&juegoactual.edad);


   int sudoku[9][9]={{8,0,6,0,0,3,0,9,0},
	                  {0,4,0,0,1,0,0,6,8},
	                  {2,0,0,8,7,0,0,0,5},
	                  {1,0,8,0,0,5,0,2,0},
	                  {0,3,0,1,0,0,0,5,0},
	                  {7,0,5,0,3,0,9,0,0},
	                  {0,2,1,0,0,7,0,4,0},
	                  {6,0,0,0,2,0,8,0,0},
	                  {0,8,7,6,0,4,0,0,3},
	                     };	
	int sudokuclon[9][9]={{8,0,6,0,0,3,0,9,0},
	                  {0,4,0,0,1,0,0,6,8},
	                  {2,0,0,8,7,0,0,0,5},
	                  {1,0,8,0,0,5,0,2,0},
	                  {0,3,0,1,0,0,0,5,0},
	                  {7,0,5,0,3,0,9,0,0},
	                  {0,2,1,0,0,7,0,4,0},
	                  {6,0,0,0,2,0,8,0,0},
	                  {0,8,7,6,0,4,0,0,3},
	                     };	  
	 int solucion[9][9]={{8,7,6,5,4,3,1,9,2},
	                  {5,4,3,2,1,9,7,6,8},
	                  {2,1,9,8,7,6,4,3,5},
	                  {1,9,8,7,6,5,3,2,4},
	                  {4,3,2,1,9,8,6,5,7},
	                  {7,6,5,4,3,2,9,8,1},
	                  {3,2,1,9,8,7,5,4,6},
	                  {6,5,4,3,2,1,8,7,9},
	                  {9,8,7,6,5,4,2,1,3},
	                     };
    int r,o;

    for(r=0;r<9;r++){
     for(o=0;o<9;o++){

         juegoactual.matrizdejuego[r][o]=sudoku[r][o];
     }

    }
	       
	int salida=1;
	printf("Hola, Este es un juego de sudoku realizado en C para la UEA de Programación Estructurada\n");
	printf("Antes de resolver el sudoku ten presente que las casillas vacias estan dadas por 0 \n");
	printf("El sudoku original es:\n\n");
	      	for(i=0;i<9;i++){ 
			printf("\n"); 
		    for(j=0;j<9;j++){

			printf("%d\t",sudoku[i][j]);
			
			if(j==2 || j == 5 || j ==8){
				
				printf("|");
			}
			
			}
			
			if (i==2 || i == 5 || i ==8){
				printf("\n");
				printf("__________________________");
				
			}
			} 
	        printf("\n\n");
	

	int opcionmenu;
	while (salida){
	    printf("Escribe el número de la operación que quieres realizar: \n");
	    printf("1 -- Imprimir Sudoku \n");
	    printf("2 -- Ingresar un valor en el sudoku \n");
	    printf("3 -- Cambiar un valor ya ingresado \n");
	    printf("4 -- Crear un nuevo juego \n");
	    printf("5 -- Salir\n");
	    printf("6 -- He resuelto el sudoku\n");
	    printf("7 -- Cargar un juego\n");
	    printf("8 -- Guardar juego actual \n");
	    scanf("%d",&opcionmenu);
	    if (opcionmenu==5){
	        break;
	    }
	    
	    else if(opcionmenu == 8){
	    	
	    	guardar(sudoku);
            guardarclon(sudokuclon);
            guardarsolucion(solucion);
	    	
	    	
		}
	    
        else if(opcionmenu==7){

            cargar(sudokuclon,1);
            cargar(sudoku,2);
            cargar(solucion,3);
            cargar(juegoactual.matrizdejuego,2);




        }
	    
	    else if(opcionmenu==6){
	        int s=0;
	        int u=0;
	        int correcto=1;
	        for(u=0;u<9;u++){
	            if (correcto==0){break;}
	            for(s=0;s<9;s++){
	                
	                
	                if (solucion[u][s]!=sudoku[u][s]){
	                    correcto=0;
	                    break;
	                    
	                }
	            }
	        } 
	     if (correcto==0){
	         
	         printf("Tu solucion no es correcta \n");
	     } else if(correcto==1){
	         printf("Tu solucion es correcta \n");
	         
	     }
	        
	    }

        
	    else if(opcionmenu ==1){
	      	for(i=0;i<9;i++){ 
			printf("\n"); 
		    for(j=0;j<9;j++){

			printf("%d\t",sudoku[i][j]);
			
			if(j==2 || j == 5 || j ==8){
				
				printf("|");
			}
			
			}
			
			if (i==2 || i == 5 || i ==8){
				printf("\n");
				printf("__________________________");
				
			}
			} 
	        printf("\n\n");
	    }
	    else if (opcionmenu == 2 || opcionmenu == 3){
	        int x;
	        int y;
	        int num;
	        int g;
	        int h;
	        int u;
	        int d;
	        int condicion_paraeditar=0;
	        printf("Ingresa la primera coordenada del número que quieres cambiar:\n");
	        scanf ("%d", &x);
	        printf("Ingresa la segunda coordenada del número que quieres cambiar:\n");
	        scanf("%d",&y);
	        if (sudokuclon[x][y]==0){
	        printf("Ingresa el número que quieres almacenar en dichas coordenadas:\n");
	        scanf("%d",&num);
	    
	        for (g=0;g<9;g++){
	            
	            if (sudoku[x][g]==num || sudoku[g][y]==num ){
	                
	                condicion_paraeditar=1;
	                printf("Ese numero ya esta en esa cruz\n");
	                
	            }
	            
	        }
	        
	        if (num>9){
	        	condicion_paraeditar=1;
			}
	        
	        
	        if(cuadrante(x,y,num,sudoku) != 0){
	        	
	        	printf("Ya esta en el cuadrante\n");
	        	condicion_paraeditar=1;
	        	
			}
	        
	        
	        if (condicion_paraeditar==0){
	            sudoku [x][y]=num;
                juegoactual.numerodemodificaciones++;
                juegoactual.matrizdejuego[x][y]=num;


	            
	        }
	        else {
	            printf("No válido\n");
	        }
	 }
	 else if (sudokuclon[x][y]!=0){
	     printf("No puedes editar esa linea\n");
	 }
	        
	    }
	    
	    else if (opcionmenu ==4){
	        reiniciar(sudoku,sudokuclon);
            reiniciar(juegoactual.matrizdejuego,sudokuclon);
            juegoactual.numerodemodificaciones=0;
	        ccaracteres(sudoku);
	        ccaracteres(solucion);
	        ccaracteres(sudokuclon);
            ccaracteres(juegoactual.matrizdejuego);
	        rotar(sudoku);
	        rotar(solucion);
	        rotar(sudokuclon);
            rotar(juegoactual.matrizdejuego);
            int r = rand() % 6 + 1;
            modificar_cuadrantes(r,sudoku);
            modificar_cuadrantes(r,sudokuclon);
            modificar_cuadrantes(r,solucion);
            modificar_cuadrantes(r,juegoactual.matrizdejuego);

	    }
	}
	return 0;
}   
int ffilas(int sudoku[9][9]){
	int copia[9][9];
	int i,j; 
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){ 
			copia[i][j]=sudoku[i][j];}}	
	for(i=0;i<9/2;i++){ 
		for(j=0;j<9;j++){ 
			sudoku[i][j]=sudoku[8-i][j];
			sudoku[8-i][j]=copia[i][j];}}
			
	printf("\n\n");
	return 0;
	}
int fcolumnas(int sudoku[9][9]){
	int copia[9][9];
	int i,j; 
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){ 
			copia[i][j]=sudoku[i][j];}}
	for(i=0;i<9;i++){ 
		for(j=0;j<9/2;j++){ 
			sudoku[i][j]=sudoku[i][8-j];
			sudoku[i][8-j]=copia[i][j];}}
	printf("\n\n");
	return 0;
	}
int fscolumnas(int sudoku[9][9],int x,int y){
	int copia[9][9];
	int i,j; 
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){ 
			copia[i][j]=sudoku[i][j];}}
	for(i=0;i<=8;i++){
		for(j=y;j<=y+1;j++){
			sudoku[i][j]=sudoku[i][j+1];}}
	for(i=0;i<=x;i++){
		sudoku[i][j]=copia[i][j-2];}
	
	return 0;
	}	

int fsfilas(int sudoku[9][9],int x,int y){
	int copia[9][9];
	int i,j; 
	
	for(i=0;i<9;i++){ 
		for(j=0;j<9;j++){ 
			copia[i][j]=sudoku[i][j];}}
	
	
	for(j=0;j<=8;j++){
		for(i=x;i<=x+1;i++){
			sudoku[i][j]=sudoku[i+1][j];}}
	
	for(j=0;j<=y;j++){
		sudoku[i][j]=copia[i-2][j];}
	
	return 0;
	}
int modificar_cuadrantes(int opcion,int sudoku[9][9]){
	switch(opcion){
		case 1:{
				fscolumnas(sudoku,8,0);
			break;}
		
		case 2:{
			fscolumnas(sudoku,8,3);
			break;}
		
		case 3:{
			fscolumnas(sudoku,8,6);
			break;}
		
		case 4:{
			fsfilas(sudoku,0,8);
			break;}
		
		case 5:{
			fsfilas(sudoku,3,8);
			break;}
		
		case 6:{
			fsfilas(sudoku,6,8);
			break;}
		
	}
}
int ccaracteres(int sudoku[9][9]){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(sudoku[i][j]==9){
				sudoku[i][j]=1;}
			else if (sudoku[i][j]!=9&&sudoku[i][j]!=0){
				sudoku[i][j]=sudoku[i][j]+1;}
			}}
	return 0;
}
void rotar(int matriz[9][9]){
    int matriz_v[9][9];                          						 
    int cant_rotaciones=1;   										                                    
    int i,j,rotaciones;                        							  
    for(rotaciones = 0; rotaciones < cant_rotaciones; rotaciones++){            
        for(i = 0; i < 9; i++){            
            for(j = 0; j < 9; j++){        
                matriz_v[j][i] = matriz[i][9-1-j];}}           
    	for(i = 0; i < 9; i++){      										           
        for(j = 0; j < 9 ; j++){             
            matriz[i][j] = matriz_v[i][j];}}}}           
void reiniciar(int matriz[9][9], int matrizclonada[9][9]){
    int i;
    int j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            matriz[i][j]=matrizclonada[i][j];
        }
    }
}
int cuadrante(int x, int y, int num, int sudoku[9][9]){
int condicion=0,i,j;
    if(x<3){x=0;} 
    else if(x<6){x=3;} 
    else{x=6;}

    if(y<3){y=0;} 
    else if(y<6){y=3;} 
    else{y=6;}

    for(i=x; i<=x+2; i++){
        for (j=y; j<=y+2;j++)
        if (sudoku[i][j] == num){
            condicion++;
        }
    }
    return condicion;
}


void guardar(int matriz[9][9]) {
    printf("Entro a guardar\n");
    int i,j,n=0;
    char numero;
    FILE* fichero;
    fichero = fopen("Progreso.txt", "wt");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            numero=matriz[i][j]+'0';
            fputc(numero,fichero); 
        }
    }
    fclose(fichero);
    printf("Guardado completado\n");
}


void guardarclon(int matriz[9][9]) {
    printf("Entro a guardar\n");
    int i,j,n=0;
    char numero;
    FILE* fichero;
    fichero = fopen("Sudoku.txt", "wt");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            numero=matriz[i][j]+'0';
            fputc(numero,fichero); 
        }
    }
    fclose(fichero);
    printf("Guardado de sudoku sin llenar completado\n");
}
void cargar(int matriz[9][9],int k){
    int i,j;
    if(k==1){
        FILE* archivo;
        archivo = fopen("Sudoku.txt","r");
        if(archivo!=NULL){
            for(i=0;i<9;i++){
                for(j=0;j<9;j++){
                    matriz[i][j]=fgetc(archivo)-'0';
            }
        }
    fclose(archivo);
    }}
    else if(k==2){
    FILE* archivo;
    archivo = fopen("Progreso.txt","r");
    if(archivo!=NULL){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                matriz[i][j]=fgetc(archivo)-'0';
            }
        }
    fclose(archivo);
    }}

   else if(k==3){
    FILE* archivo;
    archivo = fopen("Solucion.txt","r");
    if(archivo!=NULL){
        for(i=0;i<9;i++){
            for(j=0;j<9;j++){
                matriz[i][j]=fgetc(archivo)-'0';
            }
        }
    fclose(archivo);
    }

   }

    printf("Sudoku cargado\n");
}
void guardarsolucion(int matriz[9][9]){

    printf("Entro a guardar\n");
    int i,j,n=0;
    char numero;
    FILE* fichero;
    fichero = fopen("Solucion.txt", "wt");
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            numero=matriz[i][j]+'0';
            fputc(numero,fichero); 
        }
    }
    fclose(fichero);
    printf("Guardado de sudoku sin llenar completado\n");
}
