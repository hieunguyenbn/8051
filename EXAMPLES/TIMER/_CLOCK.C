/* Chuong trinh thuong tru hien dong ho o goc phai phia tren man hinh */
#include <dos.h>
#include <conio.h>

#define INTR 0x1C
#define ATTR 0x7900

#ifdef __cplusplus
	#define __CPPARGS ...
#else
	#define __CPPARGS
#endif

extern unsigned _heaplen = 1024;
extern unsigned _stklen  = 512;
void interrupt ( *oldhandler)(__CPPARGS);
typedef unsigned int (far *s_arrayptr);
struct time t;

void interrupt handler(__CPPARGS)
{
  s_arrayptr screen[80];
  static int count,ticker;
  int tam;
  screen[0] = (s_arrayptr) MK_FP(0xB800,0);
  count++;

  if (ticker==0)
  {
    t.ti_sec++;
    ticker=( ((count%5)==0)?19:18);
    if (t.ti_sec==60)
	  {
	    t.ti_sec=0;
	    t.ti_min++;
	  }
    if (t.ti_min==60)
	  {
	    t.ti_min=0;
	    t.ti_hour++;
	  }
    if (t.ti_hour==24)
      t.ti_hour=0;

    screen[0][72] = t.ti_hour/10 + '0' + ATTR;
    screen[0][73] = t.ti_hour%10 + '0' + ATTR;
    screen[0][74] = ':' + ATTR;
    screen[0][75] = t.ti_min/10 + '0' + ATTR;
    screen[0][76] = t.ti_min%10 + '0' + ATTR;
    screen[0][77] = ':' + ATTR;
    screen[0][78] = t.ti_sec/10 + '0' + ATTR;
    screen[0][79] = t.ti_sec%10 + '0' + ATTR;
  }
  ticker--;
  oldhandler();
}

int main(void)
{
  gettime(&t);
  oldhandler = getvect(INTR);
  setvect(INTR, handler);
  getch();
  setvect(INTR,oldhandler);
  keep(0, (_SS + (_SP/16) - _psp));
  return 0;
}

