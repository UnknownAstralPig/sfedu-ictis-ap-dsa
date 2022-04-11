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
        if (!queue->head)
            queue->head = queue->tail = new QueueNode<TYPE>{ value , NULL };
        else
	    queue->tail = queue->tail->next = new QueueNode<TYPE>{ value , NULL } ;

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
        if (!queue)
            return;

        if( queue->head )
            do
            {
                queue->tail = queue->head->next;
                delete queue->head;
                queue->head = queue->tail ;
            } while (queue->head);
        delete queue;

        return;
    }
};
