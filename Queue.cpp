#include <Queue.h>
#include <cstddef>

namespace QueueNS {

    template<typename TYPE>
    Queue<TYPE>* newQueue()
    {
        return new Queue<TYPE>{ NULL , NULL };
    }

    template<typename TYPE>
    int enqueue(Queue<TYPE>* queue, TYPE value)
    {
        QueueNode<TYPE>* tmp;

        if (!queue->head)
            queue->head = queue->tail = new QueueNode<TYPE>{ value , NULL };
        else
	{
	    queue->tail->next = new QueueNode<TYPE>{ value , NULL } ;
	    queue->tail = queue->tail->next ;
	}

        return 1;
    }


    template<typename TYPE>
    QueueNode<TYPE>* dequeue(Queue<TYPE>* queue)
    {
        QueueNode<TYPE>* tmp;

	if( !queue->head )
		return NULL ;
        tmp = queue->head;
        queue->head = queue->head->next;

        return tmp;
    }

    template<typename TYPE>
    void deleteQueue(Queue<TYPE>* queue)
    {
        QueueNode<TYPE>* tmp;

        if (!queue)
            return;

        if( queue->head )
            do
            {
                tmp = queue->head->next;
                delete queue->head;
                queue->head = tmp;
            } while (queue->head);
        delete queue;

        return;
    }
};
