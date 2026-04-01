#include <stdio.h>
#include <stdarg.h>


#define uart_num UART_NUM_2
/*
void myUART_setup(int baud)
{
   
    
    //uart config
    uart_config_t uart_config = {
    .baud_rate = baud,
    .data_bits = UART_DATA_8_BITS,
    .parity = UART_PARITY_DISABLE,
    .stop_bits = UART_STOP_BITS_1,
    .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
    .rx_flow_ctrl_thresh = 122,
};
    uart_param_config(uart_num, &uart_config);
     
    //pin config
    uart_set_pin(uart_num, 1, 3, -1, -1);    // Set UART pins(TX: IO4, RX: IO5, RTS: IO18, CTS: IO19)
    
    //driver install
    
    QueueHandle_t uart_queue;
    uart_driver_install(uart_num, 1024, 1024, 10, &uart_queue, 0);


}






void myUART_printf(const char *fmt, ...) 
{
    char buf[256]; // Adjust size as needed
    va_list args;
    va_start(args, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    if (len > 0) {
        uart_write_bytes(uart_num, buf, len);
    }
}*/