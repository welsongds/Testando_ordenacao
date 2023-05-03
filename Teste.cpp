#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void insertionSort(int v[10000], int n)
{
	int i, j, x;
	for(i = 1; i < n; i++) {
		x = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > x) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = x;
	}

}

void bubbleSort(int b[10000], int n)
{
	int i, j, aux;
	for(i = n-1; i > 0; i--) {
		for(j = 0; j < i; j++) {
			if(b[j] > b[j+1]) {
			aux = b[j]; b[j] = b[j+1]; b[j+1] = aux; //troca
			}
		}
	}
}


void selectionSort(int s[10000], int n)
{
	int i, j, aux, min;
	for(i = 0; i < n-1; i++) {
		min = i;
	for(j = i+1; j < n; j++) {
	if(s[j] < s[min]) {
		min = j;
	}
	}
	aux = s[i]; s[i] = s[min]; s[min] = aux; //troca
	}
}

void copiar(int copiado[], int original[])
{
    int count;
 
    for(count=0 ; count < 10000 ; count++)
        copiado[count] = original[count];
}

int main()
{
	//Declarando as variáveis
	
	int v[10000],s[10000],b[10000], n, i;
    clock_t start_i,start_b,start_s, end_i, end_b, end_s;	
	srand(time(NULL));
    double time_spent_i = 0.0;
    double time_spent_b = 0.0;
    double time_spent_s = 0.0;
    
    //Laço responsável por criar o vetor com os valores
    //aleatórios, utilizando a função rand()
	for(i = 0; i < 10000; i++) {
		v[i]=(int) rand();
		//printf("%d\t", rand()% 100);	
	}
	copiar(b, v);
	copiar(s, v);
	//Apenas para imprimir o conteúdo do vetor
	/*for(i = 0; i < 1000; i++) {
		printf("%d\t", v[i]);	
	}	
	printf("-------------------------------------------------------------------------------------\n");
	
	for(i = 0; i < 1000; i++) {
		printf("%d\t", b[i]);	
	}	
	printf("-------------------------------------------------------------------------------------\n");
	
	for(i = 0; i < 1000; i++) {
		printf("%d\t", s[i]);	
	}	
	printf("-------------------------------------------------------------------------------------\n");
	*/
	//Criei essa variável para iniciar o tempo de ordenação
	start_i = clock();
	//Ativando a função para classificar com o método insert
	insertionSort(v, 10000);
	end_i = clock();
	/*for(i = 0; i < 10000; i++) {
		printf("%d\t", v[i]);	
	}
	printf("-------------------------------------------------------------------------------------\n");
	*/
	//Criei essa variável para iniciar o tempo de ordenação
	start_b = clock();
	//Ativando a função para classificar com o método bolha
	bubbleSort(b, 10000);
	end_b = clock();
	/*for(i = 0; i < 10000; i++) {
		printf("%d\t", b[i]);	
	}
	printf("-------------------------------------------------------------------------------------\n");
	*/
	//Criei essa variável para iniciar o tempo de ordenação
	start_s = clock();
	//Ativando a função para classificar com o método seleção
	selectionSort(s, 10000);
	end_s = clock();
	/*for(i = 0; i < 10000; i++) {
		printf("%d\t", s[i]);	
	}	
	printf("-------------------------------------------------------------------------------------\n");
	*/
	//Variável criada para calcular a diferença entre o star e o end
    time_spent_i += (double)(end_i - start_i) / CLOCKS_PER_SEC;
	time_spent_b += (double)(end_b - start_b) / CLOCKS_PER_SEC;
	time_spent_s += (double)(end_s - start_s) / CLOCKS_PER_SEC;
	
	
	printf("\n");
    printf("Tempo do Insertion em %f segundos\n", time_spent_i);
    printf("-------------------------------------------------------------------------------------\n");
    printf("Tempo do Bubble em %f segundos\n", time_spent_b);
    printf("-------------------------------------------------------------------------------------\n");
    printf("Tempo do Selection em %f segundos\n", time_spent_s);
    
    
	return 0;
}
