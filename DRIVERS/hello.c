#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/fs.h>    /*for character driver support*/
#include<linux/uaccess.h>
#include<asm/uaccess.h>


#define BUFFER_LENGTH 512

static char kbuf [BUFFER_LENGTH] ;




ssize_t  fileread (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"file is getting read\n");
	copy_to_user(buffer,kbuf,BUFFER_LENGTH);
	return 0;
	
}

ssize_t file_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
	printk(KERN_INFO"file is getting write\n");
	copy_from_user(kbuf,buffer,BUFFER_LENGTH);
	

	printk(KERN_INFO"%s", kbuf);


	return 0;
}

int file_open (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO"file opened\n");
	return 0;
}

int file_close (struct inode *pinode, struct file *pfile)
{
	printk(KERN_INFO"file closed\n");
	return 0;
}


struct file_operations file_Operations = {
	//.owner = THIS_MODULE,
	.open  = file_open,
	.read  = fileread,
	.write = file_write,
	.release = file_close,
};

 
static int __init  hello_init(void)
{
	printk(KERN_INFO"Hello world module entry point");
	
	/*register with the kernel and indicate that we are registring a character device drive*/ 

	register_chrdev( 240 , "My char drv", &file_Operations);


	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_INFO"Hello world module exit point");
	unregister_chrdev( 240 , "My char drv");
 	
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("AMARNATH PUJARI");
MODULE_DESCRIPTION("character driver");
