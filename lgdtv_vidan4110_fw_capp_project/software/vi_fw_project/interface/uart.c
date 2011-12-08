#include "uart.h"
#include "tube.h"

#define BOTH_EMPTY (UART_LSR_TEMT | UART_LSR_THRE)

#define WAIT_FOR_XMITR \
        do { \
                lsr = REG8(UART_BASE + UART_LSR); \
        } while ((lsr & BOTH_EMPTY) != BOTH_EMPTY)

#define WAIT_FOR_THRE \
        do { \
                lsr = REG8(UART_BASE + UART_LSR); \
        } while ((lsr & UART_LSR_THRE) != UART_LSR_THRE)

#define CHECK_FOR_CHAR (REG8(UART_BASE + UART_LSR) & UART_LSR_DR)

#define WAIT_FOR_CHAR \
         do { \
                lsr = REG8(UART_BASE + UART_LSR); \
         } while ((lsr & UART_LSR_DR) != UART_LSR_DR)

//added by eskim
int IsCharInUART() {
	return CHECK_FOR_CHAR;
}

void uart_init_param(unsigned int sys_clock, unsigned int baud_rate) {
	int divisor;

	tube_print("SYS_CLOCK\n");
	TUBE_0_PRINT_WORD(sys_clock);
	tube_print("BAUD_RATE\n");
	TUBE_0_PRINT_WORD(baud_rate);

	/* Reset receiver and transmiter */
	REG8(UART_BASE + UART_FCR) = UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR
			| UART_FCR_CLEAR_XMIT | UART_FCR_TRIGGER_14;

	/* Disable all interrupts */
	REG8(UART_BASE + UART_IER) = 0x00;

	/* Set 8 bit char, 1 stop bit, no parity */
	REG8(UART_BASE + UART_LCR) = UART_LCR_WLEN8 & ~(UART_LCR_STOP
			| UART_LCR_PARITY);

	/* Set baud rate */
	divisor = sys_clock / (16 * baud_rate);
	REG8(UART_BASE + UART_LCR) |= UART_LCR_DLAB;
	REG8(UART_BASE + UART_DLL) = divisor & 0x000000ff;
	REG8(UART_BASE + UART_DLM) = (divisor >> 8) & 0x000000ff;
	REG8(UART_BASE + UART_LCR) &= ~(UART_LCR_DLAB);
}

void uart_putc(char c) {
	unsigned char lsr;

	WAIT_FOR_THRE;
	REG8(UART_BASE + UART_TX) = c;
	//if(c == '\n') {
	//	WAIT_FOR_THRE;
	//	REG8(UART_BASE + UART_TX) = '\r';
	//}
	WAIT_FOR_XMITR;
}

char uart_getc(void) {
	unsigned char lsr;
	char c;

	WAIT_FOR_CHAR;
	c = REG8(UART_BASE + UART_RX);

	return c;
}

void uart_print(const char *p) {
	while (*p != '\0')
		uart_putc(*p++);
}

static const char hex_table[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

void uart_printInt(const int i) {
	uart_putc('0');
	uart_putc('x');
	uart_putc(hex_table[(i & 0xf0000000) >> 28]);
	uart_putc(hex_table[(i & 0x0f000000) >> 24]);
	uart_putc(hex_table[(i & 0x00f00000) >> 20]);
	uart_putc(hex_table[(i & 0x000f0000) >> 16]);
	uart_putc(hex_table[(i & 0x0000f000) >> 12]);
	uart_putc(hex_table[(i & 0x00000f00) >> 8]);
	uart_putc(hex_table[(i & 0x000000f0) >> 4]);
	uart_putc(hex_table[(i & 0x0000000f)]);
}

