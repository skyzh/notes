#include <linux/mutex.h>

struct TestStruct {
    int x, y;
};

struct TestStruct test_struct;
int initialized = 0;

void init_test_struct() {
    test_struct.x = 1;
    test_struct.y = 2;
}

DEFINE_MUTEX(init_mutex);

void some_syscall() {
    // ensure struct is initialized only ONCE
    mutex_lock(&init_mutex);
    if (!initialized) {
        initialized = 1;
        init_test_struct();
    }
    mutex_unlock(&init_mutex);
}
