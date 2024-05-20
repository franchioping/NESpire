#include <stdint.h>
#include <stdlib.h>
#include <libndls.h>
#include <stdio.h>


#define s_SIZE                  0x4600;

void write_save_state(uint32_t saved_state_cpu_status_addr, uint32_t saved_state_cpu_cpsr);

void write_save_state(uint32_t saved_state_cpu_status_addr, uint32_t saved_state_cpu_cpsr){
    size_t lenght = s_SIZE;

    size_t data_size = s_SIZE + sizeof(uint32_t);
    uint32_t *data = malloc(data_size);


    memcpy(data, saved_state_cpu_status_addr, lenght);

    data[data_size-1] = saved_state_cpu_cpsr;

    FILE* savefile = fopen("/documents/ndless/test.tns", "wb");
    fwrite(data, data_size, 1, savefile);
    fclose(savefile);
}