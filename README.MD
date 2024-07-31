# Description
I added a hello.c and copy.c module, as well as a makefile for these modules. For these modules, I needed to update the .config file. This project was completed for UMBC's CMSC 421.

## 📄arch/x86/entry/syscalls/syscall_64.tbl
I added the following syscalls to the table contained within the file. 
The changes made to this document are on lines 548 and 549 respectively. All syscalls are formatted in this table as  
*number* *abi* *name* *entry point*

## 📄include/linux/syscalls.h
The headerfiles for syscalls. I was required to add lines to perform linkages between the sys_hello(), and the sys_memory_copy() funtions.
Changes were made to this file on lines 1384, and 1386, and include the following:  

asmlinkage long sys_hello(void);  
asmlingage long sys_memory_copy(unsigned char __user *to, unsigned char _user *from, int size):  

## 📁project0
The files **hello.c**, and **copy.c** were added to this directory, as well as their respective makefile. When this was run, there were **hello.o**, and **copy.o** object files created. These have remained within this directory. From these object files, o.cmd files were generated, in the form of **.hello.o.cmd**, and **.copy.o.cmd**. The following files were also modified, though, I am not sure as to the context of the changes made to them: **.built-in.a.cmd**, **.modules.order.cmd**, **built-in.a**, and **modules.order**

## 📄.config
The github diff here reads over 10,000 lines, I am not sure what changes I made here.

## 📄Makefile
This is the makefile for copy.c and hello.c.

# Linux kernel

There are several guides for kernel developers and users. These guides can
be rendered in a number of formats, like HTML and PDF. Please read
Documentation/admin-guide/README.rst first.

In order to build the documentation, use ``make htmldocs`` or
``make pdfdocs``.  The formatted documentation can also be read online at:

    https://www.kernel.org/doc/html/latest/

There are various text files in the Documentation/ subdirectory,
several of them using the Restructured Text markup notation.

Please read the Documentation/process/changes.rst file, as it contains the
requirements for building and running the kernel, and information about
the problems which may result by upgrading your kernel.


# Disclaimer
This was completed for UMBC's CMSC 421 Course, and I am open to removing it from github upon request from UMBC faculty. If you would like to request this repository's removal, please send me an email at **nathanwooddell@gmail.com**.