/*
 * This program is purposefully broken. used to test valgrind and it gives this output:
 colan@blam:~/Documents/WorkSpace/c_theHardWay$ valgrind ./a.out 
==15363== Memcheck, a memory error detector
==15363== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==15363== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==15363== Command: ./a.out
==15363== 
--15363-- run: /usr/bin/dsymutil "./a.out"
warning: no debug symbols in executable (-arch x86_64)
I am 75508336 years old.
==15363== Conditional jump or move depends on uninitialised value(s)
==15363==    at 0x1001ED8AF: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100000F57: main (in ./a.out)
==15363== 
==15363== Conditional jump or move depends on uninitialised value(s)
==15363==    at 0x1001EDE98: __ultoa (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001EB36C: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100000F57: main (in ./a.out)
==15363== 
==15363== Conditional jump or move depends on uninitialised value(s)
==15363==    at 0x10000B722: _platform_memchr$VARIANT$Haswell (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15363==    by 0x1001E2F84: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001ED65A: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100000F57: main (in ./a.out)
==15363== 
==15363== Syscall param write(buf) points to uninitialised byte(s)
==15363==    at 0x1002F570E: write$NOCANCEL (in /usr/lib/system/libsystem_kernel.dylib)
==15363==    by 0x1001E8201: _swrite (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E072B: __sflush (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E303F: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001ED9C4: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100000F57: main (in ./a.out)
==15363==  Address 0x100a7b675 is 5 bytes inside a block of size 4,096 alloc'd
==15363==    at 0x1000099FB: malloc (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15363==    by 0x1001E3AF5: __smakebuf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001F8B49: __swsetup (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100213481: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15363==    by 0x100000F43: main (in ./a.out)
==15363== 
I am 1 inches tall.
==15363== 
==15363== HEAP SUMMARY:
==15363==     in use at exit: 26,233 bytes in 189 blocks
==15363==   total heap usage: 273 allocs, 84 frees, 32,473 bytes allocated
==15363== 
==15363== LEAK SUMMARY:
==15363==    definitely lost: 0 bytes in 0 blocks
==15363==    indirectly lost: 0 bytes in 0 blocks
==15363==      possibly lost: 2,064 bytes in 1 blocks
==15363==    still reachable: 0 bytes in 0 blocks
==15363==         suppressed: 24,169 bytes in 188 blocks
==15363== Rerun with --leak-check=full to see details of leaked memory
==15363== 
==15363== For counts of detected and suppressed errors, rerun with: -v
==15363== Use --track-origins=yes to see where uninitialised values come from
==15363== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
colan@blam:~/Documents/WorkSpace/c_theHardWay$ valgrind ./ex4.c 
valgrind: ./ex4.c: Permission denied
colan@blam:~/Documents/WorkSpace/c_theHardWay$ valgrind ./a.out
==15366== Memcheck, a memory error detector
==15366== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==15366== Using Valgrind-3.12.0.SVN and LibVEX; rerun with -h for copyright info
==15366== Command: ./a.out
==15366== 
I am 75508336 years old.
==15366== Conditional jump or move depends on uninitialised value(s)
==15366==    at 0x1001ED8AF: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100000F57: main (in ./a.out)
==15366== 
==15366== Conditional jump or move depends on uninitialised value(s)
==15366==    at 0x1001EDE98: __ultoa (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001EB36C: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100000F57: main (in ./a.out)
==15366== 
==15366== Conditional jump or move depends on uninitialised value(s)
==15366==    at 0x10000B722: _platform_memchr$VARIANT$Haswell (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15366==    by 0x1001E2F84: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001ED65A: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100000F57: main (in ./a.out)
==15366== 
==15366== Syscall param write(buf) points to uninitialised byte(s)
==15366==    at 0x1002F570E: write$NOCANCEL (in /usr/lib/system/libsystem_kernel.dylib)
==15366==    by 0x1001E8201: _swrite (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E072B: __sflush (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E303F: __sfvwrite (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001ED9C4: __vfprintf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1002136C8: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100000F57: main (in ./a.out)
==15366==  Address 0x100a7b675 is 5 bytes inside a block of size 4,096 alloc'd
==15366==    at 0x1000099FB: malloc (in /usr/local/Cellar/valgrind/HEAD/lib/valgrind/vgpreload_memcheck-amd64-darwin.so)
==15366==    by 0x1001E3AF5: __smakebuf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001F8B49: __swsetup (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100213481: __v2printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E9389: vfprintf_l (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x1001E7223: printf (in /usr/lib/system/libsystem_c.dylib)
==15366==    by 0x100000F43: main (in ./a.out)
==15366== 
I am 1 inches tall.
==15366== 
==15366== HEAP SUMMARY:
==15366==     in use at exit: 26,233 bytes in 189 blocks
==15366==   total heap usage: 273 allocs, 84 frees, 32,473 bytes allocated
==15366== 
==15366== LEAK SUMMARY:
==15366==    definitely lost: 0 bytes in 0 blocks
==15366==    indirectly lost: 0 bytes in 0 blocks
==15366==      possibly lost: 2,064 bytes in 1 blocks
==15366==    still reachable: 0 bytes in 0 blocks
==15366==         suppressed: 24,169 bytes in 188 blocks
==15366== Rerun with --leak-check=full to see details of leaked memory
==15366== 
==15366== For counts of detected and suppressed errors, rerun with: -v
==15366== Use --track-origins=yes to see where uninitialised values come from
==15366== ERROR SUMMARY: 4 errors from 4 contexts (suppressed: 0 from 0)
 */

 int main()
 {
 	int age = 10;
 	int height;

 	printf("I am %d years old.\n");
 	printf("I am %d inches tall.\n", height);

 	return 0;
 }