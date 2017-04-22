#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "emu6809.h"
#include "console.h"

void wersi_mk1_hw(tt_u16 adr,tt_u8 val)
{

#if 0
  /* slave RAM */
  if( (adr>=0x0000) && (adr<=0x00ff) )
  {
    printf("Slave RAM #0x%04x = 0x%02x.\n",adr,val);
  }
#endif

  /* peripherals */
  if( (adr>=0x0100) && (adr<=0x01ff) )
  {
    printf("Peripheral #0x%04x = 0x%02x.\n",adr,val);
  }

#if 0
  /* copro */
  if( (adr>=0x0200) && (adr<=0x1fff) )
  {
    printf("Coprocessor RAM #0x%04x = 0x%02x.\n",adr,val);
  }

  /* work */
  if( (adr>=0x2000) && (adr<=0x3fff) )
  {
    printf("Work RAM #0x%04x = 0x%02x.\n",adr,val);
  }

  /* voice */
  if( (adr>=0x4000) && (adr<=0x7fff) )
  {
    printf("Voice bank #0x%04x = 0x%02x.\n",adr,val);
  }
#endif

}
