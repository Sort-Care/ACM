#include <stdio.h>
#include <math.h>

#define QUEUESIZE 1000

typedef struct {
    int q[QUEUESIZE + 1];
    int first;
    int last;
    int count;
} queue;

init_queue(queue *q){
    q->first = 0;
    q->last = QUEUESIZE -1;
    q->count = 0;
}

/*
  Put element x into queue pointed by pointer qe
*/
enqueue(queue *qe, int x)
{
        //check for overflow
    if(qe->count >= QUEUESIZE)
        printf("Warning: queue overflow enqueue x=%d\n", x);
    else{//valid operation
            //move the position of last element
        qe->last = (qe->last + 1) % QUEUESIZE;
            //assign the inserted value to the new last position
            //PERSONALLY: I think there is a naming issue here
            //argument q and struct parameter q are the same
            //which could cause confusion
            //altering arg q to qe
        qe->q[qe->last] = x;        
    }
}


/*
  pop the first element in queue
*/
int dequeue(queue* qe)
{
    int x;

        //bound check
    if (qe->count <= 0) printf("Warning: empty queue dequeue.\n");
    else{
            //safe to pop
            //assign the first element's value to x
        x = qe->q[qe->first];
            //update the first position
        qe->first = (qe->first + 1) % QUEUESIZE;
            //update the size
        q->count = q->count -1;   
    }
    return (x);
}


/*
  Tell if the queue is empty
*/
int empty(queue* qe){
    if(qe->count <= 0) return (TRUE);
    else return (FALSE);
}


/********************* Dictionary **********************
/*
Types of dictionaries:
1. Static: array
2. Semi-dynamic: (deletion not supported) Hash tables
*/

