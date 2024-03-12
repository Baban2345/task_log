#include <stdio.h>
#include "log.h"

int main() {
  // Create a task-specific log for Task A
  task_log_t *task_a = task_log(4, 100);
  if (task_a == NULL) {
    printf("Failed to create task log\n");
    return 1;
  }

  send_log(task_a, "Log message 1 from Task A");
  send_log(task_a, "Log message 2 from Task A");
  send_log(task_a, "Log message 3 from Task A ");
  send_log(task_a, "Log message 4 from Task A");
  send_log(task_a, "Log message 5 from Task A");
  send_log(task_a, "Log message 6 from Task A ");

  // Create a separate log for Task B
  task_log_t *task_b_log = task_log(5, 50);
  if (task_b_log == NULL) {
    printf("Failed to create task log\n");
    return 1;
  }

  send_log(task_b_log, "Log message 1 from Task B");
  send_log(task_b_log, "Log message 1 from Task B");
  send_log(task_b_log, "Log message 2 from Task B");
  send_log(task_b_log, "Log message 3 from Task B ");
  send_log(task_b_log, "Log message 4 from Task B");
  send_log(task_b_log, "Log message 5 from Task B");
  send_log(task_b_log, "Log message 6 from Task B ");

  // Display logs for Task A
  printf("\nTask A logs:\n");
  display_logs(task_a);

  // Display logs for Task B
  printf("\nTask B logs:\n");
  display_logs(task_b_log);

  // Free the allocated memory
  free(task_a->buffer);
  free(task_a);
  free(task_b_log->buffer);
  free(task_b_log);

  return 0;
}

