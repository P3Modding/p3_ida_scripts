#include <idc.idc>
#include "lib/lib.idc"

static main() {}

static debug_tasks() {
    auto size = get_tasks_size();
    auto task_index = get_earliest_task_index();
    while (task_index < size) {
        auto task = get_task_by_index(task_index);
        if (task.get_opcode() == 0x32) {
            Message("%s\n", task.to_string());
        }
        task_index = task.get_next_task_index();
    }
    Message("\n");
}
