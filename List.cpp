#include <List.h>
#include <cstddef>
#include <iostream>

namespace ListNS
{
	template<typename TYPE>
	DoublyList<TYPE>* newList()
	{
		return new DoublyList<TYPE>{ NULL,NULL };
	}

	template<typename TYPE>
	int addAsAFirst(DoublyList<TYPE>* list, TYPE value)
	{
		DoublyListNode<TYPE>* n ;
		if (!list)
			return 0 ;

		if (!list->head)
			list->head = list->tail = new DoublyListNode<TYPE>{ value , NULL , NULL } ;
		else
			list->head = list->head->previous = new DoublyListNode<TYPE>{ value , list->head , NULL } ;

		return 1;
	}

	template<typename TYPE>
	int addAsALast(DoublyList<TYPE>* list, TYPE value)
	{
		if (!list )
			return 0;

		if (!list->head)
			list->head = list->tail = new DoublyListNode<TYPE>{ value , NULL , NULL } ;
		else
			list->tail = list->tail->next = new DoublyListNode<TYPE>{ value , NULL , list->tail } ;

		return 1;
	}

	template<typename TYPE>
	DoublyListNode<TYPE>* find(DoublyList<TYPE>* list, TYPE value)
	{
		DoublyListNode<TYPE>* end,
			*beg;

		if (!list->head)
			return NULL;

		for (end = list->tail, beg = list->head; beg != end && beg->previous != end && end->key != value && beg->key != value  ; end = end->previous, beg = beg->next) ;

		if (end->key == value)
			return end;
		else if(beg->key == value)
			return beg;

		return NULL;
	}

	template<typename TYPE>
	int insertAfterNode(DoublyList<TYPE>* list, DoublyListNode<TYPE>* node, TYPE value)
	{
		if( !node || !list )
			return 0 ;

		node = node->next = new DoublyListNode<TYPE>{ value , node->next , node } ;

		if( node->next )
			node->next->previous = node ;

		if( node->previous == list->tail )
			list->tail = node ;


		return 1;
	}


	template<typename TYPE>
	void deleteList(DoublyList<TYPE>* list)
	{
		if (!list->head)
			return;

		do
		{
			list->head = list->tail->previous;
			delete list->tail ;
			list->tail = list->head;
		} while (list->tail);

		delete  list ;
	}

	template<typename TYPE>
	int deleteNode(DoublyList<TYPE>* list , DoublyListNode<TYPE>* node )
	{
		DoublyListNode<TYPE>* del ;

		if( !node || !list )
			return 0 ;

		del = node ;

		if( node == list->head )
		{
			list->head = list->head->next ;
			list->head->previous = NULL ;
		}
		else if( node == list->tail )
		{
			list->tail = list->tail->previous ;
			list->tail->next = NULL ;
		}
		else
		{
			node->previous->next = node->next ;
			node->next->previous = node->previous ;
		}

		delete del ;
		return 1 ;
	}
};
