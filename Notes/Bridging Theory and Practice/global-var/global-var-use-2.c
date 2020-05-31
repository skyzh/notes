// If you do not want to change or create header file,
// just declare all global vars and structs when using them

struct TestStruct {
    int x;
};

extern struct TestStruct test_struct;

extern int global_int;

void test() {
    int result = test_struct.x;
    int result_2 = global_int;
}
