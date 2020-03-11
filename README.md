# iboot
Easy bootloader for Embedded Systems


使用方法：#make && cd sd_fuse/fusing && ./sd_fuse.sh

软件功能：Bootloader
软件本版：0.1
目录框架：
    Arch    -   架构相关
    Soc     -   Soc相关
    Board   -   板载相关
    lib     -   自定义和静态库文件
    common  -   main函数等通用函数
    driver  -   驱动相关
    Doc     -   参考文档
    Know    -   必要的知识
    include -   头文件 
    sd_fuse -   SD卡烧录 
    BAK     -   备份文件
适用平台：tiny4412
平台分析：
    内核架构-   armv7(Cotext-A9)
    片上系统-   Exynos4412
    板载资源-   RAM     -       DDR3    1G 2片
                FLASH   -       eMMC    4G 1片
                                SD      4G 1个(外接)
                COM     -       RS-232C    1个
                其它未用资源略 
                
