#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;

    this = (LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    Node* siguiente;
    int count;
    if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this)) {
        siguiente = this->pFirstNode;
        for (count = 0 ;count < ll_len(this) ; count++ ) {
            if(count == nodeIndex) {
                pNode = siguiente;
            }
            siguiente = siguiente->pNextNode;
       }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* unaLista, int nodeIndex, void* pElement)
{
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevoNodo;

    if (unaLista != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(unaLista)) {
        nuevoNodo = (Node*) malloc(sizeof(Node));

        if (nuevoNodo != NULL ) {
            nuevoNodo->pElement = pElement;
            nuevoNodo->pNextNode = NULL;

            if (nodeIndex == 0) {
                nuevoNodo->pNextNode = unaLista->pFirstNode;
                unaLista->pFirstNode = nuevoNodo;
            } else {

                prev = getNode(unaLista,nodeIndex-1);
                next = prev->pNextNode;
                prev->pNextNode = nuevoNodo;
                nuevoNodo->pNextNode = next;
                //chequear
            }
            unaLista->size += 1;
            returnAux  = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indice = 0;

    if(this != NULL ){
        indice = ll_len(this);
        if (addNode(this,indice,pElement) == 0){
          returnAux = 0;
        }
    }
    return returnAux;
}
//  ******* OJO CORREGIR *******************
/** \brief Retorna un puntero al elemento que se encuentra en el índice especificado.

 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* node;

    if(this != NULL && index >= 0 && index < ll_len(this)){

        node = getNode(this,index);
        returnAux = node->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* actual;

    if(this != NULL && index >= 0 && index < ll_len(this)){

            actual = getNode(this,index);
            actual->pElement = pElement;
            returnAux = 0;

    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* actual;
    Node* prev;
    Node* next;
    if (this != NULL && index >= 0 && index < ll_len(this)) {

        if (index == 0 ) {

            actual = getNode(this,index);
            this->pFirstNode = actual->pNextNode;
            free(actual);
            this->size--;
            returnAux = 0;
        }else if (index >= 1) {

                actual = getNode(this,index);
                prev = getNode(this,index-1);
                next = actual->pNextNode;
                prev->pNextNode = next;
                free(actual);
                this->size--;
                returnAux = 0;

                }
            }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int len;
    if (this != NULL) {
        len = ll_len(this);
        for (i=0; i<len ; i++) {
            ll_remove(this,i);
       }
        /*this->pFirstNode = NULL;
        this->size = 0;*/

        returnAux = 0;
    }


    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if (this !=  NULL) {

      if (ll_clear(this) == 0) {
         free(this);
         returnAux = 0;
         }
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int len;
    Node* nodo;
    if (this != NULL) {
        len = ll_len(this);
        //recorro la lista para buscar que nodo contiene ese elemento.
        for (i=0 ; i<len; i++) {
           nodo =  getNode(this,i);
           if (nodo->pElement ==  pElement) {
                returnAux = i;
           }
        }

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if( ll_len(this))
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if (this != NULL&& index >= 0 && index <= ll_len(this)) {
        addNode(this,index,pElement);
        returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o
 (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    void* aux;

    if (this != NULL && index >= 0 && index < ll_len(this)){

            aux = ll_get(this, index);

            ll_remove(this,index);

            returnAux = aux;

    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* siguien;
    int bandera = 0;
    if (this != NULL) {

        siguien = this->pFirstNode;

        while (siguien != NULL) {
            if (siguien->pElement == pElement) {
                returnAux = 1;
                bandera = 1;
            }
            siguien = siguien->pNextNode;
        }

        if (bandera == 0) {
            returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief  Determina si TODOS los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this, LinkedList* this2)
{
    int returnAux = -1;
    int indice;
    int verificar = 1;
    void* auxElement;

    if (this != NULL && this2 != NULL) {
        for (indice = 0 ; indice < ll_len(this2) ; indice++) {
            auxElement = ll_get(this2,indice);

            if(ll_contains(this,auxElement) == 0){

                returnAux = 0;
                verificar = 0;
                break;
            }
        }

        if (verificar == 1 ){
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* clonList = NULL;
    int i;
    void* pElement;
    if ((this != NULL) && (from >= 0 && to <= ll_len(this))) {

        clonList = ll_newLinkedList();
        if(clonList != NULL){
             for (i = from ; i < to ; i++) {
                pElement = ll_get(this,i);
                ll_add(clonList,pElement);
            }
        }
    }
    return clonList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* oneList)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElement;
    if(oneList != NULL){
        cloneArray = ll_newLinkedList();
        for(i= 0; i<ll_len(oneList); i++){
            pElement = ll_get(oneList,i);
            addNode(cloneArray,i,pElement); //verificar
        }
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        (0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order) {

    int returnAux = -1;
    void* auxElemet;
    Node* currentNode;
    Node* nextNode;
    int i;
    int j;
    int len;

    if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) {
        len = ll_len(this);
        for (i = 0; i < len -1; i++) {
            currentNode = getNode(this,i);
            for(j = i + 1; j < len; j++){
                nextNode = getNode(this,j);
                if (order == 0 && currentNode->pElement != NULL && nextNode->pElement != NULL ) {
                    if (pFunc(currentNode->pElement,nextNode->pElement) == -1) {

                        auxElemet = currentNode->pElement;
                        currentNode->pElement = nextNode->pElement;
                        nextNode->pElement = auxElemet;
                        returnAux = 0;
                    }
                }else if (order == 1 && currentNode->pElement != NULL && nextNode->pElement != NULL) {
                    if(pFunc(currentNode->pElement,nextNode->pElement) == 1 ) {

                        auxElemet = currentNode->pElement;
                        currentNode->pElement = nextNode->pElement;
                        nextNode->pElement = auxElemet;
                        returnAux = 0;
                    }
                }
            }
        }
    }
   return returnAux;
}

LinkedList* ll_filter(LinkedList* lista, int (*fn)(void* element)){

    LinkedList* nuevalista = NULL;
    void* elemento;
    int i;
    if ( lista != NULL && fn != NULL){
        nuevalista = ll_newLinkedList();
        if ( nuevalista != NULL) {
            for(i=0 ; i < ll_len(lista) ; i++){
                elemento = ll_get(lista,i);
                if(elemento != NULL && ((*fn)(elemento))== 1) {
                    ll_add(nuevalista,elemento);
                }
            }
        }
    }
 return nuevalista;
}

int ll_count(LinkedList* listuno, int (*fn)(void* element)){
     int acumulador = 0;

     int i;
     void* elemento;

     if (listuno != NULL && fn != NULL) {
        for (i=0 ; i<ll_len(listuno) ; i++ ) {
             elemento = ll_get(listuno,i);
             if(elemento != NULL){
               acumulador = acumulador + (fn(elemento));
             }
        }
     }
    return acumulador;
}

