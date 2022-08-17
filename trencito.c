#include "trencito.h"

int len(char* s) {
	int i=0;
	while(s[i]!=0){
	i++;
	}
    return i;
}

//------------------------------------------------------------------------------

char* strDuplicate(char* s) {
	char *nuevo=malloc(sizeof(char)*(len(s)+1));
	int lon = (len(s)+1);
	for(int i=0; i<lon; i++){
	nuevo[i]=s[i];
	}
    return nuevo;
} 
/* Para la función duplicate utilicé un iterador con el largo del char ingresado, para copiar cada letra del mismo en una variable char nueva donde utilizamos malloc para pedir el espacio necesario.
*/


//--------------------------------------------------------------------------------


int strCompare(char* a, char* b) {
	int r;
	int contadora=len(a);
	int contadorb=len(b);
	if(contadora > contadorb){
	r = -1;
	return r;
	}
	if(contadora < contadorb){
	r = 1;
	return r;
	}
	if(contadora == 0 && contadorb == 0){
	r = 0;
	return r;
	}
	else{
	for(int i=0; i<contadora; i++){
		if(a[i]<b[i]){
		r = 1;
		return r;
		}
		if(a[i]>b[i]){
		r = -1;
		return r;
		}
		else{
		r = 0;
		}
	}
	}
    return r;
}
/*Primero que nada, uso varios ifs para verificar los casos donde el largo de un char es mayor que otra, y directamente devolver la función. Luego, si ninguna de las condiciones se cumplen (o sea, tienen el mismo largo), entra en un for donde compara letra por letra de ambos char para determinar el orden lexicográfico.
*/

//--------------------------------------------------------------------------

char* strConcatenate(char* src1, char* src2) {

	int len1 = len(src1);
	int len2 = len(src2);
	char *concatenated= malloc((len1+len2+1) *sizeof(char));
    	for(int i=0;i<(len(src1));i++){
    	concatenated[i]=src1[i];
    	}
     	for(int j=0;j<(len(src2)+1);j++){
    	concatenated[len1+j]=src2[j];
    	}
    	free(src1);
    	free(src2);
    return concatenated;

}
/*Primero que nada saco el largo de los char a concatenar con la funcion len, para luego utilizarlos en el malloc. Para concatenar, utilizo 2 for, el primero ingresa los valores del primer char, y el segundo parte desde la posicion len1+j para concatenar el segundo char de manera correcta. Detalle: el segundo for sigue hasta len2+1 para asi poner el 0 al final del concatenado. Para finalizar, libera la memoria de src1 y src2.
*/

//-------------------------------------------------------------------------

struct trainDance* trainDanceNew(char* name0, int group0, char* name1, int group1) {
    struct node* n0 = (struct node*)malloc(sizeof(struct node));
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    n0->name = strDuplicate(name0);
    n0->group = group0;
    n0->next = n1;
    n1->name = strDuplicate(name1);
    n1->group = group1;
    n1->next = n0;
    struct trainDance* td = (struct trainDance*)malloc(sizeof(struct trainDance));
    td->first = n0;
    td->count = 2;
    return td;
}

//------------------------------------------------------------------------

struct node* trainDanceGetNode(struct trainDance* train, char* name) {
	struct node* Current = train->first;
	int cantidad = train->count;
	for(int i=0 ; i<cantidad ; i++){
		if( strCompare(Current->name, name) == 0){
			return Current;
		}
		else{
		Current = Current->next;
		}
	}
    return 0;
}
/*Para esta funcion, defino un current que sera el primer nodo del tren, para luego iterar sobre los diferentes nodos en el for para buscar el nodo cuyo nombre sea igual al nombre ingresado. Si se encuentra, la función directamente lo devuelve. Si no encuentra nada, simplemente sale del for y devuelve 0 */


//-------------------------------------------------------------------------

int trainDanceGroupCount(struct trainDance* train, int group) {
    struct node* n = train->first;
    int result = 0;
    do {
        if (n->group == group)
            result = result + 1;
        n = n->next;
    } while ( n != train->first );
    return result;
}

//------------------------------------------------------------------------

char* trainDanceGetNames(struct trainDance* train, char* separator) {
	
	struct node* Current = train->first;
	int total=0;
	for(int o=0;o<(train->count);o++){
	total = total + len(Current->name);
	Current = Current->next;
	}
	total=total+(train->count);
	char*names ;
	for(int i=0;i<(train->count);i++){
	if(i==0){
	names = strDuplicate(Current->name);
	}
	else{
	names=strConcatenate(names,strConcatenate(strDuplicate(separator),strDuplicate(Current->name)));
	}
	Current = Current->next;
	}
	names[total-1]=0;

	
    return names;
}

/* Para esta función, primero calculo el largo de todos los nombres de los nodos del tren usando un for y la funcion len. Luego, los sumo todos y le sumo la cantidad de nodos del tren (para incluir el separador y el 0 en lo que se devuelve). Luego, mediante un for, concateno el names (definido en la primera iteración del for como el nombre del primer nodo del tren) con la concatenación del separador y el nombre del siguiente. Cabe aclarar que se utilizan strDuplicate para evitar la perdida de los valores ingresados en los concatenate. 
*/


//-------------------------------------------------------------------------

int trainDanceAddToDance(struct trainDance* train, char* name1, char* name2, char* nameNew, int groupNew) {

	struct node*nodo1 = trainDanceGetNode(train, name1);
	struct node*nodo2 = trainDanceGetNode(train, name2);
	struct node*consec = nodo1->next;
	if((consec)==(nodo2)){
	struct node* nodonuevo = (struct node*)malloc(sizeof(struct node));
	nodonuevo->name = strDuplicate(nameNew);
 	nodonuevo->group = groupNew;
 	nodonuevo->next = nodo2;
 	nodo1->next = nodonuevo;
 	train->count= (train->count)+1;
	}

	return 0;
}


/*Para la siguiente función, se definen los 2 nodos y se determina si son consecutivos. Si lo son, se entra al IF y se agrega el nodo cambiando el next del nodo1 y definiendo el next del nuevo nodo como nodo2.*/


//------------------------------------------------------------------------------



int trainDanceImTired(struct trainDance* train, char* name){
	if(train->count < 3){
	return 0;
	}
	struct node* nodo1 = trainDanceGetNode(train, name);
	if(nodo1==0){
	return 0;
	}
	struct node* anterior;
	struct node* current = nodo1;
	struct node* consec = current->next;
	int cantidad= (train->count)+1;
	for(int i=0;i<cantidad;i++){
		if((current->next)==(nodo1)){
		anterior = current;
		}
		current=current->next;
		}
	anterior->next = consec;
	train->count = (train->count)-1;
	if((train->first)==nodo1){
	train->first = consec ;
	}
	free(nodo1->name);
	free(nodo1);
	


    return 0;
}
/* Para ImTired, primero se verifica si el tren posee 3 o más nodos, de modo contrario, no se realiza nada. Despues se chequea si el nodo existe en ese tren. Si existe, se definen current, consec y anterior. Luego, se comparan los nodos para ver cuando el consec sea igual al nodo1, y así saber cual modificar y quitarlo de la lista, cambiando el next del anterior. Para finalizar, se verifica si el nodo es el primero, para asi cambiar el train->first. Cabe destacar, que se libera la memoria del nodo que se retiró */





//----------------------------------------------------------------------------





void trainDanceGotToMosh(struct trainDance** train, struct trainDance** trainMosh, struct trainDance** trainRemains, int groupMosh) {
	if(((*train)->count)<4){
	*trainMosh=0;
	*trainRemains=0;
	return;
	}
	int TotalTren =(*train)->count;
	int GrupoMosh= trainDanceGroupCount(*train,groupMosh);
	int GrupoRemains= (*train)->count - GrupoMosh;
	int z=0;
	int x=0;
	struct node*Current=(*train)->first;
	struct node*Mosh1;
	struct node*Mosh2;
	struct node*Remains1;
	struct node*Remains2;
	if(GrupoMosh<2 || GrupoRemains<2){
	*trainMosh=0;
	*trainRemains=0;
	return;
	} 
	for(int i=0;i<TotalTren;i++){
	if(Current->group==groupMosh && z==0){
	Mosh1=Current;
	z++;
	}
	if(Current->group==groupMosh && z==1){
	Mosh2=Current;
	}
	if(Current->group!=groupMosh && x==0){
	Remains1=Current;
	x++;
	}
	if(Current->group!=groupMosh && x==1){
	Remains2=Current;
	}
	Current=Current->next;
	}
	*trainMosh = trainDanceNew((Mosh1->name),(Mosh1->group),(Mosh2->name),(Mosh2->group));
	*trainRemains = trainDanceNew((Remains1->name),(Remains1->group),(Remains2->name),(Remains2->group));
	struct node*PreviousMosh=Mosh2;
	struct node*PreviousRem=Remains2;
	if(TotalTren>4){
	for(int i=0;i<TotalTren;i++){
	if((Current->group)==groupMosh && Current!=Mosh1 && Current!=Mosh2){
	trainDanceAddToDance(*trainMosh,Mosh1->name,PreviousMosh->name,Current->name,Current->group);
	PreviousMosh=Current;
	
	}
	if((Current->group)!=groupMosh && Current!=Remains1 && Current!=Remains2){
	trainDanceAddToDance(*trainRemains,Remains1->name,PreviousRem->name,Current->name,Current->group);
	PreviousRem=Current;
	}
	Current=Current->next;
	}
	}
	trainDanceDelete(*train);
	*train=0;
	return;
			
}
/* Para GotToMosh, primero se chequea si la cantidad de nodos del tren es mayor a 4, y si la cantidad de grupos (tanto remains como mosh) sean mayor o igual que 2. Luego, si pasa todos los chequeos, se crean 2 trenes con la funcion trainDanceNew para luego mediante un for ir agregando los diferentes nodos. Para Mosh se verifica que cada nodo sea pertenezca al grupo, y para el remains se verifica que no sea del grupo de Mosh. Para finalizar, se libera la memoria del tren ingresado (si se puede realizar el mosh y remains).*/




//----------------------------------------------------------------------------------------






void trainDanceDelete(struct trainDance* train) {

	struct node* n = train->first;
	do {
	struct node* toDelete = n;
	n = n->next;
	free(toDelete->name);
	free(toDelete);
	} while ( n != train->first );
	free(train);
	
}

//----------------------------------------------------------------------------------

void trainDancePrint(struct trainDance* train) {
    struct node* n = train->first;
    printf("(%i)",train->count);
    do {
        printf("[%s,%i]",n->name,n->group);
        n = n->next;
    } while ( n != train->first );
}

