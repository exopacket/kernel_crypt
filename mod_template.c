//
// Created by root on 9/3/23.
//

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_AUTHOR("Me and <my@address.com>");
MODULE_DESCRIPTION("Linux kernel module template");
MODULE_LICENSE("GPL");
MODULE_ALIAS("mod_template");

static int __init mt_init(void)
{
    printk("Module loaded.");

    return 0;
}

static void __exit mt_exit(void)
{
    printk("Module unloaded.");
}

module_init(mt_init);
module_exit(mt_exit);