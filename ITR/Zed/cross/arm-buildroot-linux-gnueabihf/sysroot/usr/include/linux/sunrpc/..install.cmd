cmd_/local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc/.install := /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc ./include/uapi/linux/sunrpc debug.h; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc ./include/linux/sunrpc ; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc ./include/generated/uapi/linux/sunrpc ; for F in ; do echo "\#include <asm-generic/$$F>" > /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc/$$F; done; touch /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/sunrpc/.install