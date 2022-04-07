/**
 * This is List Data Structure implementation. Student must implement all functions from ListNS namespace.
 * Please check the description of each function before function prototype.
 * THe implementation must be located in file List.cpp
 */

#ifndef SFEDU_ICTIS_AP_DSA_LIST_H
#define SFEDU_ICTIS_AP_DSA_LIST_H

template<typename TYPE>
struct DoublyListNode {
    TYPE key;
    DoublyListNode<TYPE> *next;
    DoublyListNode<TYPE> *previous;
};

template<typename TYPE>
struct DoublyList {
    DoublyListNode<TYPE> *head;
    DoublyListNode<TYPE> *tail;
};

namespace ListNS {

	template<typename TYPE>
	int deleteNode(DoublyList<TYPE>* list , DoublyListNode<TYPE>* node ) ;

    /**
    * TODO Implement function that initialize new @DoublyList.
    * @tparam TYPE the type of stored in list information.
    * @return the pointer to the newly created @DoublyList structure.
    */
    template<typename TYPE>
    DoublyList<TYPE> *newList();

    /**
    * TODO Implement function that add new values to the head of @DoublyList.
    * @tparam TYPE the type of stored in list information.
    * @param list - the target list to where we should add value
    * @param value - the value that we should add to the @list
    * @return The number of insert items.
    */
    template<typename TYPE>
    int addAsAFirst(DoublyList<TYPE> *list, TYPE value);

    /**
    * TODO Implement function that add new values to the tail of @DoublyList.
    * @tparam TYPE the type of stored in list information.
    * @param list - the target list to where we should add value
    * @param value - the value that we should add to the @list
    * @return The number of insert items.
    */
    template<typename TYPE>
    int addAsALast(DoublyList<TYPE> *list, TYPE value);

    /**
    * TODO Implement function that add new value after given node of @DoublyList.
    * @tparam TYPE the type of stored in list information.
    * @param list - the target list to where we should add value
    * @param value - the value that we should add to the @list
    * @return The number of insert items.
    */
    template<typename TYPE>
    int insertAfterNode(DoublyList<TYPE> *list, DoublyListNode<TYPE> *node, TYPE value);

    /**
    * TODO Implement function that find node by value in @DoublyList.
    * @tparam TYPE the type of stored in list information.
    * @param list - the target list to where we should add value
    * @param value - the value that we should  find in the @list
    * @return the pointer to the found node or nullptr if no such node.
    */
    template<typename TYPE>
    DoublyListNode<TYPE> *find(DoublyList<TYPE> *list, TYPE value);

    /**
     * TODO function should properly delete @list. Firstly the structure members must be deleted and after @list itself should be deleted.
     * @tparam TYPE the type of stored in queue information
     * @param lsit the pointer to the list which should be properly deleted.
     */
    template<typename TYPE>
    void deleteList(DoublyList<TYPE> *list);

}

#endif //SFEDU_ICTIS_AP_DSA_LIST_H
