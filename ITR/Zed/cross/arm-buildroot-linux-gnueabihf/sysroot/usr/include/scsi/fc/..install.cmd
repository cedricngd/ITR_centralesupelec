cmd_/local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc/.install := /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc ./include/uapi/scsi/fc fc_els.h fc_fs.h fc_gs.h fc_ns.h; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc ./include/scsi/fc ; /bin/bash scripts/headers_install.sh /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc ./include/generated/uapi/scsi/fc ; for F in ; do echo "\#include <asm-generic/$$F>" > /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc/$$F; done; touch /local/home/anvar/develop/br-tree/buildroot-2018.02/../board/ZedBoard/cross/arm-buildroot-linux-gnueabihf/sysroot/usr/include/scsi/fc/.install