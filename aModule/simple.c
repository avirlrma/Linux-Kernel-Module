#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* KERN_INFO tells the prioirty of the message and stands 
for Informational message*/

int simple_init(void){
	printk(KERN_INFO "Module loaded\n");
	return 0;
}

void simple_exit(void){
	printk(KERN_INFO "Module unloaded\n");
}

//macros for setting up the above functions
module_init(simple_init);
module_exit(simple_exit);

//Module_info

MODULE_DATE("SOME DAT ddE")
MODULE_AUTHOR("Aviral Verma");
MODULE_DESCRIPTION("simple test module");
