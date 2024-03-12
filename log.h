#ifndef LOG_H
#define LOG_H

#include <stdlib.h>
#include<stdio.h>
#include <string.h>
typedef struct task_log_t {
  char *buffer;
  int buffer_size;
  int message_size;
  int head;
  int current_pos;
} task_log_t;

task_log_t *task_log(int buffer_size, int message_size);
void send_log(task_log_t *task_log, const char *message);
void display_logs(task_log_t *task_log);

#endif /* LOG_H */

