/*
1.- Crear pointer para saber que hay un front y rear.
2.- Inicializar front y rear en -1.
3.- Incrementar rear cuando se agregue un elemento.
4.- Retornar el valor de front al quitar un elemento e incrementar front al usar deQueue.
5.- Revisar si hay espacio antes de agregar un elemento.
6.- Revisar si hay elementos antes de remover un elemento.
7.- Al remover todos los elementos, front y rear deben ser igual a -1.

..- rear no puede llegar a 5.

FIFO - First In First Out
*/

#include <stdio.h>
#define SIZE 5

int values[SIZE] = {0,0,0,0,0}, front=-1, rear=-1, aux=0;

bool notAvailable(int X[])
{
	for(int i=0;i<5;i++) 
	{
		if(X[i]==0) //Si la celda está vacía, rear tendrá el valor de esa celda ahora.
		{
			rear=i;
			return false; // si el elemento es igual a cero, la celda está vacía y termina.
		}
	}
	
	return true;
}

int isEmpty(int X[])
{
	for(int i=0;i<5;i++) 
	{
		if(X[i]!=0)
		{
			aux=i;
			return false; //Si alguna celda tiene un elemento, es falso que esté vacía.
		}
	}
	return true;
}

void enQueue(int value)
{
	if(notAvailable(values)) printf("Nuestro queue esta lleno.\n");
	else
	{
		if(front == -1) front=0;
		notAvailable(values);
		values[rear]=value;
		printf("Se inserto el valor %d correctamente. front = %d, rear = %d\n", values[rear], front, rear);
	}
	return;
}

void deQueue(void)
{
	if(front == -1) printf("No hay nada papito, el queue esta vacio.\n");
	else
	{
		printf("Se elimino el valor %d correctamente. front = %d, rear = %d\n", values[front], front, rear);
		
		values[front]=0;
		if(isEmpty(values)) front=rear=-1;
		else front=aux;
		printf("El siguiente valor a eliminar es el %d\n", values[front], front);
	}
	return;
}

main(int argc, char const * argv[])
{
	enQueue(1); //Inserta 1 en la posición 0.
	enQueue(2); //Inserta 2 en la posición 1.
	enQueue(3); //Inserta 3 en la posición 2.
	deQueue();  //Elimina el 1. Ahora, front "apunta" a 2 y rear a 3.
	deQueue();  //Elimina el 2. Ahora, front "apunta" a 3 y rear a 3.
	enQueue(7); //Inserta 7 en la posición 0.
	enQueue(8); //Inserta 8 en la posición 1.
	enQueue(9); //Inserta 9 en la posición 3.
	enQueue(5);//Inserta 10 en la posición 4.
	deQueue();  //Elimina el 3. Ahora, front "apunta" a 7 y rear a 5.
	deQueue();  //Elimina el 7. Ahora, front "apunta" a 8 y rear a 5.
	deQueue();	//Elimina el 8. Ahora, front "apunta" a 9 y rear a 5.
	deQueue();  //ELimina el 9. Ahora, front "apunta" a 5 y rear a 5;
	deQueue();  //Elimina el 5. Si se intenta eliminar de nuevo, hay error.
	deQueue();
	enQueue(12);
	enQueue(18);
	enQueue(16);
	enQueue(17);
	deQueue();
	enQueue(1);
	for(int i=0;i<5;i++) printf("Elemento %d: %d. front = %d, rear = %d\n", i, values[i], front , rear);
	return 0;
}
