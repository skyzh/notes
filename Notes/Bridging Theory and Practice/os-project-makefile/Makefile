INSTALL_PATH=/data/local
ARCH=armeabi
SHELL:=/bin/bash
TESTCASE_COLOR=\033[1;34m
NO_COLOR=\033[0m
LIMIT=

all: run

build_syscall_test: FORCE
	@echo -e "$(TESTCASE_COLOR)building syscall test...$(NO_COLOR)"
	cd test_syscall && ndk-build

build_project2_test: FORCE
	@echo -e "$(TESTCASE_COLOR)building project test...$(NO_COLOR)"
	cd test_project2 && ndk-build

push: build_syscall_test build_project2_test
	@echo -e "$(TESTCASE_COLOR)pushing executables...$(NO_COLOR)"
	@adb push ./test_syscall/obj/local/$(ARCH)/test_syscall $(INSTALL_PATH)
	@adb push ./test_project2/obj/local/$(ARCH)/project2_test $(INSTALL_PATH)
	@adb shell "chmod 777 $(INSTALL_PATH)/project2_test"

run: push
	@echo -e "$(TESTCASE_COLOR)running syscall test...$(NO_COLOR)"
	@adb shell "cd $(INSTALL_PATH) && ./test_syscall $(LIMIT)"

test: push
	@echo -e "$(TESTCASE_COLOR)running project2 test...$(NO_COLOR)"
	@adb shell "su 10070 $(INSTALL_PATH)/project2_test u0_a70 100000000 160000000"

clean: FORCE
	cd test_syscall && ndk-build clean
	cd test_project2 && ndk-build clean

emulator: FORCE
	make -C $(KID)
	cd ~/android-sdk-linux/tools && ./emulator -no-window @OsPrj -show-kernel -kernel $(KERNEL_PATH)
FORCE:

.PHONY: FORCE
