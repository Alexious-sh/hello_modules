#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int __init hello_init(void)
{
	return 0;
}

int print_hello(void) {
	printk(KERN_EMERG "Hello, world!\n");
	return 0;

}

static void __exit hello_exit(void)
{
	/* Do nothing here right now */
}

EXPORT_SYMBOL(print_hello);
module_init(hello_init);
module_exit(hello_exit);

