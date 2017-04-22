/* motorola.c -- Motorola S1 support 
   Copyright (C) 1999 Noah Vawter

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include "binary.h"
#include "config.h"
#include "emu6809.h"

int load_binary(char *filename, long offset)
{
  char buf[201];
  int num_bytes,i,done=0;
  long start_addr;
  unsigned char value;
  int fi;
	
  start_addr = offset;
  fi=open(filename,O_RDONLY);
  if(fi<0)
  {
    printf("can't open it, sorry.\n");
    return(0);
  }
  
  num_bytes = read(fi,buf,200);
  while(!done)
  {
    /* read data */
    for(i=0;i<num_bytes;i++)
    {
      value = buf[i];

      set_memb(start_addr+i,value);
      //    printf("0x%08x: 0x%02x\n",start_addr+i,value);
    }

    start_addr+=num_bytes;
    num_bytes = read(fi,buf,200);
    if(num_bytes <= 0) done=1;
  }
  close(fi);
  return(1);
}
