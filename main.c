#include <stdio.h>
#include <stdlib.h>
#include "trencito.h"

int main() {

    // COMPLETAR

    // A Continuacion dejamos algunos ejemplos de como
    // llama a las funciones pedidas. Este codigo debe
    // ser borrado / modificado.

    // strDuplicate
    char* dup = strDuplicate("hola");
    printf("strDuplicate(\"hola\") -> \"%s\"\n", dup);
    free(dup);
    //String vacio
    char* dup1 = strDuplicate("");      
    printf("strDuplicate(\"vacio\") -> \"%s\"\n", dup1);
    free(dup1);
    //String de un caracter
    char* dup2 = strDuplicate("J");     //String de un caracter
    printf("strDuplicate(\"J\") -> \"%s\"\n", dup2);
    free(dup2);
    // Dejamos fuera los caracteres %""\ porque intervienen en printf
    char* dup3 = strDuplicate("!#$&/()=?¿'¡^*¨Ç-.,;:_ºª@·<>{}qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM");
    printf("strDuplicate(\"!#$&/()=?¿'¡^*¨Ç-.,;:_ºª@·<>{}qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM\") -> \"%s\"\n", dup3);
    free(dup3);
    // Oración simple con espacios
    char* dup4 = strDuplicate("Si es que el tecla no elude a Schiavi"); 
    printf("strDuplicate(\"Si es que el tecla no elude a Schiavi\") -> \"%s\"\n", dup4);
    free(dup4);
    
    
    
    
    
//-------------------------------------------------------------------------
    
    
 
    // strCompare
    printf("strCompare(\"abc\",\"abc\") -> %i\n", strCompare("abc","abc"));
    
    printf("strCompare(\"abcd\",\"abc\") -> %i\n", strCompare("abcd","abc"));
    
    printf("strCompare(\"abc\",\"abcd\") -> %i\n", strCompare("abc","abcd"));
    
    //Dos strings vacios
    printf("strCompare(\"vacio\",\"vacio\") -> %i\n", strCompare("",""));    
    //Dos strings de un caracter         
    printf("strCompare(\"F\",\"A\") -> %i\n", strCompare("F","A"));             
    //Strings iguales hasta un caracter
    printf("strCompare(\"Hola\",\"Hols\") -> %i\n", strCompare("Hola","Hols"));   
    printf("strCompare(\"Hols\",\"Hola\") -> %i\n", strCompare("Hols","Hola"));  
    //Strings diferentes
    printf("strCompare(\"Buen\",\"Dia\") -> %i\n", strCompare("Buen","Dia"));       
    printf("strCompare(\"Dia\",\"Buen\") -> %i\n", strCompare("Dia","Buen"));








//------------------------------------------------------------------------







    // strConcatenate
    char* concat = strConcatenate(strDuplicate("123"),strDuplicate("456"));
    printf("strConcatenate(\"123\",\"456\") -> \"%s\"\n", concat);
    free(concat);
    //String vacio y uno de 3 caracteres 
    char* concat1 = strConcatenate(strDuplicate(""),strDuplicate("456"));           
    printf("strConcatenate(\"vacio\",\"456\") -> \"%s\"\n", concat1);
    free(concat1);
    //String de tres caracteres y uno vacio 
    char* concat2 = strConcatenate(strDuplicate("123"),strDuplicate(""));           
    printf("strConcatenate(\"123\",\"vacio\") -> \"%s\"\n", concat2);
    free(concat2);
    //Dos strings de 1 caracter
    char* concat3 = strConcatenate(strDuplicate("A"),strDuplicate("B"));            
    printf("strConcatenate(\"A\",\"B\") -> \"%s\"\n", concat3);
    free(concat3);
    //Dos strings de 5 caracteres
    char* concat4 = strConcatenate(strDuplicate("Aquel"),strDuplicate("Bruja"));    
    printf("strConcatenate(\"Aquel\",\"Bruja\") -> \"%s\"\n", concat4);
    free(concat4);





//-------------------------------------------------------------------------





    // trainDanceNew
    struct trainDance* td = trainDanceNew("Matias", 1, "Agatha", 2);
    printf("trainDanceNew(\"Matias\",1,\"Agatha\",2) -> ");
    trainDancePrint(td);
    printf("\n");
    
    struct trainDance* td2 = trainDanceNew("Pablo", 1, "Eric", 2);
    printf("trainDanceNew(\"Pablo\",1,\"Eric\",2) -> ");
    trainDancePrint(td2);
    printf("\n");
    
    
    
//-------------------------------------------------------------------------

    // trainDanceGetNode
    struct node* n = trainDanceGetNode(td, "Matias");
    printf("trainDanceGetNode(td,\"Matias\") -> %s %i\n",n->name,n->group);
    n = trainDanceGetNode(td, "Agatha");
    printf("trainDanceGetNode(td,\"Agatha\") -> %s %i\n",n->name,n->group);
    //Esta primero en el tren
    n = trainDanceGetNode(td2, "Pablo");                           
    printf("trainDanceGetNode(td2,\"Pablo\") -> %s %i\n",n->name,n->group);
    //Esta ultimo en el tren
    n = trainDanceGetNode(td2, "Eric");                                         
    printf("trainDanceGetNode(td2,\"Eric\") -> %s %i\n",n->name,n->group);
  
    //No esta en la tren
    n = trainDanceGetNode(td2,"David");                                        
    printf("trainDanceGetNode(td2,\"David\") -> %s %i\n",n);





//------------------------------------------------------------------------




    // trainDanceGroupCount
    int result = trainDanceGroupCount(td, 1);
    printf("trainDanceGroupCount(td, 1) -> %i\n", result);
    result = trainDanceGroupCount(td, 1);
    printf("trainDanceGroupCount(td, 2) -> %i\n", result);
    
    
    
    
    
//------------------------------------------------------------------------   
    
  
    

    // trainDanceGetNames
    char* names = trainDanceGetNames(td, ",");
    printf("trainDanceGetNames(td,\",\") -> %s\n",names);
    free(names);
    //Baile 2 personas
    names = trainDanceGetNames(td2, ",");
    printf("trainDanceGetNames(td2,\",\") -> %s\n",names);
    free(names);

    //Baile de 3 personas
    trainDanceAddToDance(td2, "Pablo", "Eric", "David", 1);         //Entre Pablo y Eric, agrego a David -> td2 = Pablo, David, Eric
    names = trainDanceGetNames(td2, ",");
    printf("trainDanceGetNames(td2,\",\") -> %s\n",names);
    free(names);

    //Baile 4 personas
    trainDanceAddToDance(td2, "David", "Eric", "Agustin", 1);       //Entre David y Eric, agrego a Agustin -> td2 = Pablo, David, Agustin, Eric
    names = trainDanceGetNames(td2, ",");
    printf("trainDanceGetNames(td2,\",\") -> %s\n",names);
    free(names);




//------------------------------------------------------------------------







    // trainDanceAddToDance
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Carla", 2);
    printf("trainDanceAddToDance(\"Matias\",\"Agatha\",\"Carla\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Pepo", 2);
    printf("trainDanceAddToDance(\"Matias\",\"Agatha\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Agatha", "Matias", "Pepo", 2);
    printf("trainDanceAddToDance(\"Agatha\",\"Matias\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    //--td2 = Pablo, David, Agustin, Eric--
    //En cualquier posicion
    result = trainDanceAddToDance(td2, "David", "Agustin", "Esteban", 2);                  
    printf("trainDanceAddToDance(\"David\",\"Agustin\",\"Esteban\",2) -> %i - ",result);    
    trainDancePrint(td2);
    printf("\n");
    //--td2 = Pablo, David, Esteban, Agustin, Eric--
    //Al final de la lista
    result = trainDanceAddToDance(td2, "Eric", "Pablo", "Lucas", 1);                        
    printf("trainDanceAddToDance(\"Eric\",\"Pablo\",\"Lucas\",1) -> %i - ",result);         
    trainDancePrint(td2);
    printf("\n");
    //--td2 = Pablo, David, Esteban, Agustin, Eric, Lucas--
    //Al principio de la lista (entre la primera y la segunda posicion)
    result = trainDanceAddToDance(td2, "Pablo", "David", "Estanislao", 2);                  
    printf("trainDanceAddToDance(\"Pablo\",\"David\",\"Estanislao\",2) -> %i - ",result);   
    trainDancePrint(td2);
    printf("\n");
    //td2 = Pablo, Estanislao, David, Esteban, Agustin, Eric, Lucas
    trainDanceDelete(td2);
  
  
  
  
  
  //-----------------------------------------------------------------------
  
  
  

  
    
    // trainDanceImTired
    result = trainDanceImTired(td, "Agatha");
    printf("trainDanceImTired(td, \"Agatha\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Ricardo");
    printf("trainDanceImTired(td, \"Ricardo\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Matias");
    printf("trainDanceImTired(td, \"Matias\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    
    struct trainDance* td3 = trainDanceNew("Manuel", 1, "Pedro", 2);
    printf("trainDanceNew(\"Manuel\",1,\"Pedro\",2) -> ");
    trainDancePrint(td3);
    printf("\n");
    
    result = trainDanceImTired(td3, "Manuel");                             //Un baile de solo 2
    printf("trainDanceImTired(td3, \"Manuel\") -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");

    trainDanceAddToDance(td3, "Manuel", "Pedro", "Ramon",2);               //td3 = Manuel, Ramon, Pedro
    trainDanceAddToDance(td3, "Manuel", "Ramon", "Tobias",1);              //td3 = Manuel, Tobias, Ramon, Pedro

    result = trainDanceImTired(td3, "Pedro");                              //Al ultimo de la lista
    printf("trainDanceImTired(td3, \"Pedro\") -> %i - ",result);           //td3 = Manuel, Tobias, Ramon
    trainDancePrint(td3);
    printf("\n");
    result = trainDanceImTired(td3, "Manuel");                             //Al primero de la lista
    printf("trainDanceImTired(td3, \"Manuel\") -> %i - ",result);          //td3 =Tobias, Ramon
    trainDancePrint(td3);
    printf("\n");
    trainDanceDelete(td3);
    
    
    
//----------------------------------------------------------------------------  
    
    
       
    

    // trainDanceGotToMosh
    struct trainDance* tdr1;
    struct trainDance* tdm1;
    trainDanceGotToMosh(&td, &tdr1, &tdm1, 2);
    printf("trainDanceGotToMosh(td, &tdr1, &tdm1, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr1 != 0) trainDancePrint(tdr1); else printf("0");
    printf(" - ");
    if(tdm1 != 0) trainDancePrint(tdm1); else printf("0");
    printf("\n");
    trainDanceAddToDance(td, "Pepo", "Carla", "Diana", 1);
    trainDanceAddToDance(td, "Carla", "Pepo", "Marcos", 1);
    trainDanceGotToMosh(&td, &tdr1, &tdm1, 2);
    printf("trainDanceGotToMosh(td, &tdr, &tdm, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr1 != 0) trainDancePrint(tdr1); else printf("0");
    printf(" - ");
    if(tdm1 != 0) trainDancePrint(tdm1); else printf("0");
    printf("\n");
    
    
    
    //Empezamos nuevo TD y caso 1 en ambas
    struct trainDance* tdr;
    struct trainDance* tdm;
    struct trainDance* td4 = trainDanceNew("Dele Alli", 2, "Diogo Jota", 1);
    printf("trainDanceNew(\"Dele Alli\",2,\"Diogo Jota\",1) -> ");
    trainDancePrint(td4);
    printf("\n");
    trainDanceGotToMosh(&td4, &tdr, &tdm, 1);
    printf("trainDanceGotToMosh(td4, &tdr, &tdm, 1) -> ");
    if(td4 != 0) trainDancePrint(td4); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");
    //Hacemos caso 2 en MOSH y 1 en REMAINS
    trainDanceAddToDance(td4,"Dele Alli", "Diogo Jota", "Wilfred Zaha", 1);
    trainDanceGotToMosh(&td4, &tdr, &tdm, 1);
    printf("trainDanceGotToMosh(td4, &tdr, &tdm, 1) -> ");
    if(td4 != 0) trainDancePrint(td4); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");
    //Hacemos Caso 2 en ambas
    trainDanceAddToDance(td4,"Dele Alli", "Wilfred Zaha", "Kostas Tsimikas", 2);
    trainDanceGotToMosh(&td4, &tdr, &tdm, 1);
    printf("trainDanceGotToMosh(td4, &tdr, &tdm, 1) -> ");
    if(td4 != 0) trainDancePrint(td4); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");
    

 
    // trainDanceDelete
    trainDanceDelete(tdr);
    trainDanceDelete(tdm);
    trainDanceDelete(tdr1);
    trainDanceDelete(tdm1);



}

