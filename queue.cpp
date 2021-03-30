#include "queue.hpp"

void queue_init(queue_t* queue)
{
    queue =  (queue_t*)malloc(sizeof(queue_t));
}

int queue_empty(queue_t* queue)
{
    return queue->pthread_queue.empty();
}

void queue_add(queue_t* queue, pthread_t thread)
{
    queue->pthread_queue.push(thread);
}

pthread_t queue_remove(queue_t* queue)
{
    pthread_t front_thread = queue->pthread_queue.front();
    queue->pthread_queue.pop();
    return front_thread;
}

pthread_t queue_destroy(queue_t* queue)
{
    free(queue);
}

