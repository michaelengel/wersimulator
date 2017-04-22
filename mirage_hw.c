#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "emu6809.h"
#include "console.h"

void mirage_hw(tt_u16 adr,tt_u8 val)
{
  tt_u16 offset;

  /* Filter Hardware */
  if( (adr>=0xe408) && (adr<=0xe40f) )
  {
    printf("Filter Cutoff #0x%02x = 0x%02x.\n",adr-0xe408,val);
  }

  if( (adr>=0xe410) && (adr<=0xe417) )
  {
    printf("Filter Resonance #0x%02x = 0x%02x.\n",adr-0xe410,val);

  }

  if( (adr>=0xe418) && (adr<=0xe41f) )
  {
    printf("Mux Addr Pre-Set #0x%02x = 0x%02x.\n",adr-0xe418,val);

  }

  /* Q-chip registers */ 
  if( (adr>=0xec00) && (adr<=0xecef) )
  {
    offset=adr-0xec00;
    if( offset==0xe0 )
    {
      printf("Q-Chip: Osc. Int. Reg: 0x%02x\n",val);
    }

    if(offset==0xe1)
    {
      printf("Q-Chip: Osc. Ena. Reg: 0x%02x\n",val);
    }

    if(offset==0xe2)
    {
      printf("Q-Chip: A/D Conv. Reg: 0x%02x\n",val);
    }

    if( (offset<=0x1f))
    {
      printf("Q-Chip: Freq Reg LSB #0x%02x = 0x%02x\n",offset,val);
    }

    if( (offset>=0x20) && (offset<=0x3f))
    {
      printf("Q-Chip: Freq Reg MSB #0x%02x = 0x%02x\n",offset-0x20,val);
    }

    if( (offset>=0x40) && (offset<=0x5f))
    {
      printf("Q-Chip: Volume Reg #0x%02x = 0x%02x\n",offset-0x40,val);
    }

    if( (offset>=0x60) && (offset<=0x7f))
    {
      printf("Q-Chip: Data Reg #0x%02x = 0x%02x\n",offset-0x60,val);
    }

    if( (offset>=0x80) && (offset<=0x9f))
    {
      printf("Q-Chip: Wavetable Pointer Reg #0x%02x = 0x%02x\n",offset-0x80,val);
    }

    if( (offset>=0xa0) && (offset<=0xbf))
    {
      printf("Q-Chip: Osc. Control Reg #0x%02x = 0x%02x\n",offset-0xa0,val);
    }

    if( (offset>=0xc0) && (offset<=0xef))
    {
      printf("Q-Chip: Osc. Control Reg #0x%02x = 0x%02x\n",offset-0xc0,val);
    }
    
  }

}
