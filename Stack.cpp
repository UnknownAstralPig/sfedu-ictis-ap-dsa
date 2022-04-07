#include <Stack.h>
#include <cstddef>

namespace StackNS
{
    template<typename TYPE>
    Stack<TYPE>* newStack()
    {
        return new Stack<TYPE>{ NULL };
    }

    template<typename TYPE>
    int push(Stack<TYPE>* stack, TYPE value)
    {
        if( !stack->head )
            stack->head = new StackNode<TYPE>{ value , NULL };
        else
            stack->head = new StackNode<TYPE>{ value , stack->head };

        return 1;
    }

    template<typename TYPE>
    StackNode<TYPE>* pop(Stack<TYPE>* stack)
    {
        StackNode<TYPE>* tmp;

        if (!stack->head)
            return NULL;

        tmp = stack->head;

        stack->head = stack->head->next;

        return tmp;
    }

    template<typename TYPE>
    void deleteStack(Stack<TYPE>* stack)
    {
        StackNode<TYPE>* tmp;

        if (!stack->head)
            return;

        do
        {
            tmp = stack->head->next;
            delete stack->head;
            stack->head = tmp;
        } while (stack->head);

        delete stack;

        return;
    }
};
