/***************************************************************************/
/* DEMO3231.C                                                              */
/***************************************************************************/
#include        <stdio.h>               /* Prototypes for I/O functions */
#include        <DS5000.h>              /* Register declarations for DS5000 */
/************************* bit definitions ****************************/
sbit    scl = P0^0;             /* I2C pin definitions */
sbit    sda = P0^1;
sbit    E = P1^0;               /* DCM LCD module control signal definitions */
sbit    RS = P1^1;
sbit    RW = P1^2;
sbit    CLK = P2^5;             /* DS1267 control signal definitions */
sbit    RSTb = P2^6;
sbit    DQ = P2^7;
sbit    int0 = P3^2;
/**************************** defines *******************************/
#define ADDRTC  0xd0    /* DS3231 slave address (write) */
#define ACK     0
#define NACK    1
/*********************** Function Prototypes **************************/
void    start();
void    stop();
uchar   i2cwrite(uchar d);
uchar   i2cread(char);
void    wr_dsp_dat(uchar);
void    wr_dsp_ins(uchar);
uchar   rd_dsp_ins();
void    hex2asc(uchar);
void    dsp_adj(uchar pos);
void    init_dsp();
void    writebyte();
void    initialize_DS3231();
void    disp_regs();
void    rd_temp();
void    frq_out_tog();
void    init_alrm();
void    comm_init();
/************************* Global Variables ***************************/
xdata   uchar   sec, min, hr, dy, dt, mn, yr;
/**************************** functions ******************************/
void start()            /* --------- Initiate start condition ---------- */
{
        sda = 1;  scl = 1;
        sda = 0; 
}
void stop()             /* ---------- Initiate stop condition ----------- */
{
        sda = 0;  sda = 0;
        scl = 1;  scl = 1;  sda = 1;
}
uchar i2cwrite(uchar d)         /* ----------------------------- */
{
uchar i;

        scl = 0;
        for (i = 0;i < 8; i++)
        {
                if (d & 0x80)
                        sda = 1; /* Send the msbits first */
                else
                        sda = 0;
                scl = 0;
                scl = 1;
                d = d << 1;     /* do shift here to increase scl high time */
                scl = 0;
        }
        sda = 1;        /* Release the sda line */
        scl = 0;
        scl = 1;
        i = sda;
        if (i) printf("Ack bit missing  %02X\n",(unsigned int)d);
        scl = 0;
        return(i);
}
uchar i2cread(char b)   /* ----------------------------------- */
{
uchar i, d;

        d = 0;
        sda = 1;             /* Let go of sda line */
        scl = 0;
        for (i = 0; i < 8; i++) /* read the msb first */
        {
                scl = 1;
                d = d << 1;
                d = d | (unsigned char)sda;
                scl = 0;
        }
        sda = b;          /* low for ack, high for nack */
        scl = 1;
        scl = 0;

        sda = 1;          /* Release the sda line */
        return d;
}
void    wr_dsp_dat(uchar dat)   /* -------- write one byte to the display --------- */
{
        P0 = dat;
        RS = 1; /* data register */
        RW = 0; /* write */
        E = 1;
        E = 0;          /* latch data in */
}
void    wr_dsp_ins(uchar dat)   /* ---- write one byte to the display instruction ----- */
{
        P0 = dat;
        RS = 0; /* instruction register */
        RW = 0; /* write */
        E = 1;
        E = 0;          /* latch data in */
}
uchar   rd_dsp_ins()    /* ---- read one byte from the instruction registers ----- */
{
uchar   dat;
        P0 = 0xff;      /* set up for read */
        RS = 0; /* instruction register */
        RW = 1; /* read */
        E = 1;
        dat = P0;
        E = 0;
        return(dat);
}
void    init_dsp()      /* -------- initialize DMC-16207 LCD display ------- */
{
        while((rd_dsp_ins() & 0x80));   /* wait for display */

        wr_dsp_ins(0x38);       /* Set 8-bit data, 2-line display, 5X7 font */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_ins(0x0c);       /* Display on, cursor off, blink off */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_ins(0x06);       /* Entry mode set: increment, no display shift */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_ins(0x01);       /* clear display */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_ins(0x80);       /* move to start of line 1 */
        while((rd_dsp_ins() & 0x80));

        wr_dsp_ins(0x50);       /* Set CG RAM address */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x07);       /* write 1st line of custom char to CG RAM */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x05);       /* write 2nd line */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x07);       /* write 3rd line */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x00);       /* write 4th line */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x00);       /* write 5th line */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x00);       /* write 6th line */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(0x00);       /* write 7th line */
        while((rd_dsp_ins() & 0x80));
}
void    hex2asc(uchar hex)      /* -- convert the upper and lower nibbles to 2 ascii characters -- */
{
        if( ( (hex & 0xf0) >> 4) < 0x0a)
                wr_dsp_dat( ( (hex & 0xf0) >> 4) + 48 );        /* prints 0-9 */
        else
                wr_dsp_dat( ( (hex & 0xf0) >> 4) + 55 );        /* prints A-F */
        while((rd_dsp_ins() & 0x80));

        if( (hex & 0x0f) < 0x0a)
                wr_dsp_dat( (hex & 0x0f) + 48 );
        else
                wr_dsp_dat( (hex & 0x0f) + 55 );
        while((rd_dsp_ins() & 0x80));
}
void    dsp_adj(uchar pos)      /* ------ adjust contrast on LCD display ------- */
{
char    inc;

        RSTb = CLK = 0;                 /* initialize for 1st pass */
        RSTb = 1;                               /* enable DS1267 */
        DQ = 0;                         /* write stack select bit */
        CLK = 1;                                /* toggle clk with data valid */
        CLK = 0;

        for (inc = 7; inc >= 0; inc--)  /* write wiper 0 */
        {
                DQ = ((pos >> inc) & 0x01);     /* shift x bits left */
                CLK = 0;                        /* toggle clk with data valid */
                CLK = 1;
        }
        for (inc = 7; inc >= 0; inc--)  /* write wiper 1 */
        {
                DQ = ((pos >> inc) & 0x01);     /* shift x bits left */
                CLK = 0;                        /* toggle clk with data valid */
                CLK = 1;
        }
        RSTb = 0;                               /* reset the 1267 (/RST & CLK low) */
        CLK = 0;
}
void writebyte()        /* ----------------------------------------------- */
{
uchar Add, Data;

        printf("\nADDRESS (hex):");             /* Get Address & Data */
        scanf("%bx", &Add);
        printf("DATA (hex):");
        scanf("%bx", &Data);

        start();
        i2cwrite(ADDRTC);
        i2cwrite(Add);
        i2cwrite(Data);
        stop();
}
void    initialize_DS3231()     /* ----- set time & date; user data entry ------ */
/* Note: NO error checking is done on the user entries! */
{
        printf("\nEnter the year (0-99): ");
        scanf("%bx", &yr);
        printf("Enter the month (1-12): ");
        scanf("%bx", &mn);
        printf("Enter the date (1-31): ");
        scanf("%bx", &dt);
        printf("Enter the day (1-7): ");
        scanf("%bx", &dy);
        printf("Enter the hour (1-23): ");
        scanf("%bx", &hr);
        /* hr = hr & 0x3f;      /* force clock to 24 hour mode */
        printf("Enter the minute (0-59): ");
        scanf("%bx", &min);
        printf("Enter the second (0-59): ");
        scanf("%bx", &sec);

        start();
        i2cwrite(ADDRTC);       /* write slave address, write 1339 */
        i2cwrite(0x00); /* write register address, 1st clock register */
        i2cwrite(sec);
        i2cwrite(min);
        i2cwrite(hr);
        i2cwrite(dy);
        i2cwrite(dt);
        i2cwrite(mn);
        i2cwrite(yr);
        i2cwrite(0x10); /* enable sqw, 1hz output */
        stop();
}
void    disp_regs()     /* --- display date/time on LCD display --- */
{
uchar   age, prv_sec=99;

        while(!RI)      /* Read & Display Clock Registers */
        {
                while(int0);    /* loop until int pin goes low */
                start();
                i2cwrite(ADDRTC);
                i2cwrite(0x0f);
                i2cwrite(0);            /* clear alarm flags */
                stop();

                start();
                i2cwrite(ADDRTC);
                i2cwrite(0);
                start();
                i2cwrite(ADDRTC | 1);
                sec = i2cread(ACK);
                min = i2cread(ACK);
                hr = i2cread(ACK);
                dy = i2cread(ACK);
                dt = i2cread(ACK);
                mn = i2cread(ACK);
                yr = i2cread(NACK);
                stop();

                wr_dsp_ins(0x80);       /* move to start of line 1 */
                while((rd_dsp_ins() & 0x80));
                hex2asc(yr);
                wr_dsp_dat('/');
                while((rd_dsp_ins() & 0x80));
                hex2asc(mn);
                wr_dsp_dat('/');
                while((rd_dsp_ins() & 0x80));
                hex2asc(dt);
                wr_dsp_dat(' ');
                while((rd_dsp_ins() & 0x80));
                hex2asc(dy);
                wr_dsp_dat(' ');
                while((rd_dsp_ins() & 0x80));

                start();
                i2cwrite(ADDRTC);
                i2cwrite(0x10);
                start();
                i2cwrite(ADDRTC | 1);
                age = i2cread(NACK);
                stop();

                wr_dsp_dat(' ');
                while((rd_dsp_ins() & 0x80));
                hex2asc(age);

                wr_dsp_ins(0xc0);       /* move to start of line 2 */
                while((rd_dsp_ins() & 0x80));
                hex2asc(hr);
                wr_dsp_dat(':');
                while((rd_dsp_ins() & 0x80));
                hex2asc(min);
                wr_dsp_dat(':');
                while((rd_dsp_ins() & 0x80));
                hex2asc(sec);

                rd_temp();
        }
        RI = 0;  /* Swallow keypress to exit loop */
}
void    rd_temp()       /* -------- display temperature -------- */
{
char    str[8];
int     itemp;
float   ftemp;

        do
        {
                start();
                i2cwrite(ADDRTC);
                i2cwrite(0x0e);         /* address of control register */
                start();
                i2cwrite(ADDRTC + 1);   /* send the device address for read */
                itemp = i2cread(NACK);  /* get the control register value */
                stop();
        }       while(itemp & 0x20);            /* wait until CNVT bit goes inactive */

        start();
        i2cwrite(ADDRTC);
        i2cwrite(0x11);                 /* address of temperature MSB */
        start();
        i2cwrite(ADDRTC + 1);           /* send the device address for read */
        itemp = ( (int) i2cread(ACK) << 5 );
        itemp += ( i2cread(NACK) >> 3);
        stop();
        if(itemp & 0x1000)      itemp += 0xe000;        /* if sign bit set, make 16 bit 2's comp */

        ftemp = 0.03125 * (float) itemp;        /* convert to degrees C */
        /* ftemp = ftemp * 9 / 5 + 32;  /* skip this if you don't want degrees F */

        sprintf(str, "%5.2f", ftemp);

        wr_dsp_ins(0xc9);                       /* go to line 2, column 10 */
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(str[0]);
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(str[1]);
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(str[2]);
        while((rd_dsp_ins() & 0x80));
        wr_dsp_dat(str[3]);
        while((rd_dsp_ins() & 0x80));

        wr_dsp_dat(0x02);       /* display programed 3rd char in CG RAM */
        while((rd_dsp_ins() & 0x80));
}
void    frq_out_tog()   /* --- toggle en32khz bit to enable/disable sqw --- */
{
uchar   val;

        start();
        i2cwrite(ADDRTC);
        i2cwrite(0x0f);                 /* control/status reg address */
        start();
        i2cwrite(ADDRTC + 1);           /* send the device address for read */
        val = i2cread(NACK);
        stop();
        val ^= 0x08;    /* toggle en32khz bit */
        start();
        i2cwrite(ADDRTC);
        i2cwrite(0x0f);                 /* control/status reg address */
        i2cwrite(val);
        stop();
}
void    init_alrm()     /* --- enable alarm 1 for once-per-second --- */
{
        start();
        i2cwrite(ADDRTC);
        i2cwrite(7);            /* 1st alarm 1 reg address */
        i2cwrite(0x80); /* mask alarm register */
        i2cwrite(0x80);
        i2cwrite(0x80);
        i2cwrite(0x80);
        stop();

        start();
        i2cwrite(ADDRTC);
        i2cwrite(0x0e); /* control/status reg address */
        i2cwrite(0x05); /* enable interrupts, alarm 1 output */ 
}
void    comm_init()     /* ------ reset DS3231 comm interface ------ */
{
        do      /* because the DS3231 I2C interface is active for both supplies */
        {       /*  after a micro reset, we must get the comm into a known state */
                sda = 1;        /* make sure master has released SDA */
                scl = 1;
                if(sda) /* if sda is high, generate a start */
                {
                        sda = 0;        /* The DS3231 will recognize a valid start */
                        sda = 1;        /*  condition anywhere in a I2C data transfer */
                }
                scl = 0;
        }       while(sda == 0);        /* if the DS3231 is holding sda low, try again */
}
main() {
uchar i, M, M1;

        dsp_adj(0x10);  /* adjust contrast on LCD display */
        init_dsp();             /* initialize LCD display */
        comm_init();
        init_alrm();            /* enable alarm */
        disp_regs();

        while(1)
        {
                printf("\nDS3231 build date: %s\n", __DATE__);
                printf("I Init DS3231 S Show temp\n");
                printf("R Read Time   W Write Byte\n");
                printf("F Frq out     D Display adj\n");
                printf("Enter Menu Selection: ");

                M = _getkey();

                switch(M) 
                {
                        case 'D':
                        case 'd':       printf("val: ");        scanf("%bx", &M1);
                                        dsp_adj(M1);    break;

                        case 'F':
                        case 'f':       frq_out_tog();  break;

                        case 'I':
                        case 'i':       initialize_DS3231();    break;

                        case 'R':
                        case 'r':       disp_regs();    break;

                        case 'S':
                        case 's':       rd_temp();      break;

                        case 'W':
                        case 'w':       writebyte();    break;
                }
        }
}