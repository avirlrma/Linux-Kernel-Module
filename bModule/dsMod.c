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

	static LIST_HEAD(head);

int dsMod_init(void){
	struct date* first;
	struct date* second;
	struct date* third;
	struct date* ptr;
	printk(KERN_INFO "Module loaded");
	first = kmalloc(sizeof(&first),GFP_KERNEL);
	first->day =  2;
	first->month = 3;
	INIT_LIST_HEAD(&first->list);
	list_add_tail(&first->list, &head);
	second = kmalloc(sizeof(&second),GFP_KERNEL);
	second->day =  4;
	second->month = 5;
	INIT_LIST_HEAD(&second->list);
	list_add_tail(&second->list, &first->list);
	third = kmalloc(sizeof(&third),GFP_KERNEL);
	third->day =  6;
	third->month = 7;
	INIT_LIST_HEAD(&third->list);
	list_add_tail(&third->list, &second->list);
	list_for_each_entry(ptr,&head,list){
		printk(KERN_INFO "%d",ptr->day);
		printk(KERN_INFO "%d",ptr->month);
		printk(KERN_INFO "\n");
	}
	return 0;
}

void dsMod_exit(void){
	struct date *ptr,*next;
	printk(KERN_INFO "Unloaded the module\n");
	list_for_each_entry_safe(ptr,next,&head,list){
		list_del(&ptr->list);
		kfree(ptr);
	}
}

module_init(dsMod_init);
module_exit(dsMod_exit);

MODULE_AUTHOR("Aviral Verma");
MODULE_DESCRIPTION("Module to demonstrate use of kernel data structures");
MODULE_LICENSE("GPL");