#include <linux/kernel.h>
#include <linux/uaccess.h>
#include <linux/syscalls.h>
#include <linux/errno.h>

SYSCALL_DEFINE3(memory_copy, unsigned char __user *,to,
		unsigned char __user *, from, int, size){
	/*
	A few notes on memory copy the variables passed in are:
	to : the destination of the  copied memory
	from : the source of the copied memory
	size : the size of the memory, used as a bound
	NOTE: Must check for fails, and stop execution when they are found
	 */

	// Variable Creation
	unsigned char * src = (unsigned char *) from; // the source
	unsigned char * dst = (unsigned char *) to; // the destination
	int i = 0; // starting counter
	unsigned char tmp; // used to hold variable between runs

	// Preliminary Checks
	int src_test = access_ok(src,size);
	int dst_test = access_ok(dst,size);

	// ensure that the memory is good to access
	if(src_test != 0 && dst_test != 0){
		return -EFAULT;
	}

	// Assignment Loop
	for(i = 0; i < size; i++){

		// Iterate through the source
		if(get_user(tmp, &src[i]) != -EFAULT){

			// copy to the destination
			if(put_user(tmp, &dst[i])== -EFAULT){
				return -EFAULT;
			}

		// If there is nothing in the source, it should return error
		}else{
			return -EFAULT;
		}
	}

	// This should be the successful return
	return 0;
}
