#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_READERS 5
#define NUM_WRITERS 2
#define MAX_ITERATIONS 10

int shared_resource = 0;
int iterations = 0;
sem_t mutex;
sem_t wrt;
int reader_count = 0;

void *reader(void *arg) {
    int reader_id = *((int *)arg);
    while (iterations < MAX_ITERATIONS) {
        sem_wait(&mutex);
        reader_count++;
        if (reader_count == 1) {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        
        printf("Reader %d reads: %d\n", reader_id, shared_resource);
        
        sem_wait(&mutex);
        reader_count--;
        if (reader_count == 0) {
            sem_post(&wrt);
        }
        sem_post(&mutex);

        sleep(1);
        iterations++;
    }
    pthread_exit(NULL);
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);
    while (iterations < MAX_ITERATIONS) {
        sem_wait(&wrt);
        shared_resource++;
        printf("Writer %d writes: %d\n", writer_id, shared_resource);
        sem_post(&wrt);
        sleep(1);
        iterations++;
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t reader_threads[NUM_READERS], writer_threads[NUM_WRITERS];
    int reader_args[NUM_READERS], writer_args[NUM_WRITERS];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i < NUM_READERS; i++) {
        reader_args[i] = i + 1;
        pthread_create(&reader_threads[i], NULL, reader, &reader_args[i]);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        writer_args[i] = i + 1;
        pthread_create(&writer_threads[i], NULL, writer, &writer_args[i]);
    }

    for (int i = 0; i < NUM_READERS; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    for (int i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
