// the following header files are found at /usr/src/linux-headers-4.15.0-22/include/linux/sched.h
// but you don't have to worry,Makefile handles this.
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
//has the task_struct structure of process
#include <linux/sched.h>

/* KERN_INFO tells the prioirty of the message and stands 
for Informational message*/

int ps_init(void){
	printk(KERN_INFO "Module loaded\n");
	struct task_struct *task;
	for_each_node(task){	
		printk(KERN_INFO "%s ",task_pid_nr(task));
	}
	return 0;
}

void ps_exit(void){
	printk(KERN_INFO "Module unloaded\n");
}

//macros for setting up the above functions
module_init(ps_init);
module_exit(ps_exit);


//Module_info
MODULE_AUTHOR("Aviral Verma");
MODULE_DESCRIPTION("Module to display process list");
MODULE_LICENSE("GPL");