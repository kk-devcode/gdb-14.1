/* This program is intended to be started outside of gdb, and then
   attached to by gdb.  Thus, it simply spins in a loop.  The loop
   is exited when & if the variable 'should_exit' is non-zero.  (It
   is initialized to zero in this program, so the loop will never
   exit unless/until gdb sets the variable to non-zero.)
   */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

float  bidule = 0.0;
volatile int  should_exit = 0;

int main ()
{
  int  local_i = 0;

  /* Cannot sleep a very long time, as attach.exp assumes the
     process will exit before the standard GDB timeout.  */
  sleep( 10 ); /* System call causes register fetch to fail */
               /* This is a known HPUX "feature"            */
  while (! should_exit)
    {
      local_i++;
    }
  return (0);
}
