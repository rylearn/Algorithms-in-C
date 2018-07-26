#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *protected_buf;
	int front;
	int back;
	int n;
} common_buf;

pthread_cond_t cond_producer = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_consumer = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void common_buf_init(common_buf *buf, int n) {
	buf->protected_buf = calloc(n, sizeof(int));
	buf->front = buf->back = 0;
	buf->n = n;
}

void common_buf_delete(common_buf *buf) {
	free(buf);
}

void common_buf_insert(common_buf *buf, int new_elem) {
	pthread_cond_wait(&cond_producer, &mutex);
	pthread_mutex_lock(&mutex);
	buf->back = (buf->back + 1) % buf->n;
	buf->protected_buf[buf->back] = new_elem;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond_consumer);
}

int common_buf_remove(common_buf *buf) {
	int val;
	pthread_cond_wait(&cond_consumer, &mutex);
	pthread_mutex_lock(&mutex);
	val = buf->protected_buf[buf->front];
	buf->front = (buf->front + 1) % buf->n;
	pthread_mutex_unlock(&mutex);
	pthread_cond_signal(&cond_producer);
	return val;
}

int main() {
	int n = 10;
	int *arr = calloc(n, sizeof(int));
	common_buf buf = 
	{
		.protected_buf = arr,
		.front = 0,
		.back = 0,
		.n = n,
	};
	pthread_t thread_id;
	thread_create(&thread_id, NULL, common_buf_insert, );
	thread_create(&thread_id, NULL, common_buf_remove, NULL);
	while(true) {

	}

	return 0;
}
