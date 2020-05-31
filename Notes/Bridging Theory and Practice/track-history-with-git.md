# Track History with Git

## 下载 kernel 源代码

```bash
git clone https://aosp.tuna.tsinghua.edu.cn/kernel/goldfish/ -b android-goldfish-3.4 --depth=1   
```

## 在新分支上开发

```bash
git checkout -b android-goldfish-3.4 oom
```

## 配置并编译 kernel

参考 handout 修改 Makefile 和编译选项。

```bash
make menuconfig
make -j4
```

## 和原先的 kernel 代码比较

```bash
git diff android-goldfish-3.4 > patch.diff
```

`patch.diff` 里面的内容类似这样：

```diff
diff --git a/Makefile b/Makefile
index 9f440dd8..bda521d0 100644
--- a/Makefile
+++ b/Makefile
@@ -192,8 +192,10 @@ SUBARCH := $(shell uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc64/ \
 # Default value for CROSS_COMPILE is not to prefix executables
 # Note: Some architectures assign CROSS_COMPILE in their arch/*/Makefile
 export KBUILD_BUILDHOST := $(SUBARCH)
-ARCH		?= $(SUBARCH)
-CROSS_COMPILE	?= $(CONFIG_CROSS_COMPILE:"%"=%)
+#ARCH		?= $(SUBARCH)
+#CROSS_COMPILE	?= $(CONFIG_CROSS_COMPILE:"%"=%)
+ARCH		?= arm
+CROSS_COMPILE	?= arm-linux-androideabi-
 
 # Architecture as present in compile.h
 UTS_MACHINE 	:= $(ARCH)
```
