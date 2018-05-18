#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/slab.h>

struct date{
	int day;
	int month;
	// this one basically has two pointers to front and back
	struct list_head list; 
};

int dsMod_init(void){
	static LIST_HEAD(head);
	printk(KERN_INFO "Module loaded");
	struct date* first;
	first = kmalloc(sizeof(&first),GFP_KERNEL);
	first->day =  2;
	first->month = 3;
	INIT_LIST_HEAD(&first->list);
	list_add_tail(&first->list, &head);
	struct date* second;
	second = kmalloc(sizeof(&second),GFP_KERNEL);
	second->day =  4;
	second->month = 5;
	INIT_LIST_HEAD(&second->list);
	list_add_tail(&second->list, &first->list);
	struct date* third;
	third = kmalloc(sizeof(&third),GFP_KERNEL);
	third->day =  6;
	third->month = 7;
	INIT_LIST_HEAD(&third->list);
	list_add_tail(&third->list, &second->list);
	struct date* ptr;
	list_for_each_entry(ptr,&head,list){
		printk(KERN_INFO "%d",ptr->day);
		printk(KERN_INFO "%d",ptr->month);
		printk(KERN_INFO "\n");
	}
	return 0;
}

void dsMod_exit(void){
	printk(KERN_INFO "Unloaded the module\n");
}

module_init(dsMod_init);
module_exit(dsMod_exit);

MODULE_AUTHOR("Aviral Verma");
MODULE_DESCRIPTION("Module to demonstrate use of kernel data structures");
MODULE_LICENSE("GPL");