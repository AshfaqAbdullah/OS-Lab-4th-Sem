#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    while(1) {

        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        // Pick left fork
        sem_wait(&forks[id]);

        // Pick right fork
        sem_wait(&forks[(id + 1) % N]);

        printf("Philosopher %d is Eating\n", id);
        sleep(2);

        // Put left fork
        sem_post(&forks[id]);

        // Put right fork
        sem_post(&forks[(id + 1) % N]);

        printf("Philosopher %d finished Eating\n", id);
    }
}

int main() {

    pthread_t phil[N];
    int id[N];

    for(int i = 0; i < N; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for(int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&phil[i], NULL, philosopher, &id[i]);
    }

    for(int i = 0; i < N; i++) {
        pthread_join(phil[i], NULL);
    }

    return 0;
}
