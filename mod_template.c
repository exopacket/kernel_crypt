//
// Created by root on 9/3/23.
//

#include <linux/kernel.h>
#include <linux/module.h>
#include "src/kernel_crypt.h"

MODULE_AUTHOR("Me and <my@address.com>");
MODULE_DESCRIPTION("Linux kernel module template");
MODULE_LICENSE("GPL");
MODULE_ALIAS("mod_template");

static int __init modtemplate_init(void)
{

    crypto_res_t* o;
    encrypt("test", o);

    printk(KERN_ALERT "Module loaded.\n");

    return 0;
}

static void __exit modtemplate_exit(void)
{
    printk(KERN_ALERT "Module unloaded.\n");
}

module_init(modtemplate_init);
module_exit(modtemplate_exit);