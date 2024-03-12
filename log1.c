#include "log.h"

#include <time.h>





task_log_t *task_log(int buffer_size, int message_size) {

 task_log_t *task_log = malloc(sizeof(task_log_t));

 if (task_log == NULL) {

  return NULL; // Handle allocation failure

 }

 task_log->buffer = malloc(buffer_size * message_size);

 if (task_log->buffer == NULL) {

  free(task_log);

  return NULL; // Handle allocation failure

 }

 task_log->buffer_size = buffer_size;

 task_log->message_size = message_size;

 task_log->head = 0;

 task_log->current_pos = 0;

 return task_log;

}



void send_log(task_log_t *task_log, const char *message) {

 if (task_log == NULL) {

  return; // Handle null pointer

 }



 int next_pos = (task_log->current_pos + 1) % task_log->buffer_size;



 // Check if buffer is full and needs to override oldest message

 if (next_pos == task_log->head) {

  task_log->head = (task_log->head + 1) % task_log->buffer_size; // Advance head to overwrite

 }



 time_t current_time = time(NULL);

  char timestamp[20]; // Buffer to store timestamp

  strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&current_time));



  // Append timestamp and message to the buffer

  snprintf(task_log->buffer + task_log->current_pos * task_log->message_size,

       task_log->message_size - 1, "[%s] %s", timestamp, message);

  task_log->buffer[task_log->current_pos * task_log->message_size + task_log->message_size - 1] = '\0';



  task_log->current_pos = next_pos;

}



void display_logs(task_log_t *task_log) {

 if (task_log == NULL) {

  return; // Handle null pointer

 }



 int i = task_log->head;

 while (i != task_log->current_pos) {

  printf("%s\n", task_log->buffer + i * task_log->message_size);

    i = (i + 1) % task_log->buffer_size;

 }

}

