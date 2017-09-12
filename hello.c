#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/slab.h>
#include <hello_export.h>

MODULE_LICENSE("Dual BSD/GPL");

static uint hello_cnt = 1;
//extern int print_hello(void);

module_param(hello_cnt, uint, 0644);
MODULE_PARM_DESC(hello_cnt, "Hello count");

static int __init hello_init(void)
{
	uint i;

	WARN_ON(hello_cnt < 1);
	BUG_ON(hello_cnt > 10);

	switch (hello_cnt) {
	case 5:
		return -EINVAL;
	case 2:
		__module_get(THIS_MODULE);
	}

	for (i = 0; i < hello_cnt; i++)
		print_hello();

	return 0;
}

static void __exit hello_exit(void)
{
	if (hello_cnt == 3) {
		u8 *val = (u8 *)&__kmalloc;
		*val = 0x90;
	}

	pr_emerg("Good bye!\n");
}

module_init(hello_init);
module_exit(hello_exit);

