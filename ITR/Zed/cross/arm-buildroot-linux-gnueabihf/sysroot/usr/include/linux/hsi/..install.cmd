cmd_/local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi/.install := /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi ./include/uapi/linux/hsi cs-protocol.h hsi_char.h; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi ./include/linux/hsi ; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi ./include/generated/uapi/linux/hsi ; for F in ; do echo "\#include <asm-generic/$$F>" > /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi/$$F; done; touch /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/linux/hsi/.install
