#include <stdint.h>
#include <stdlib.h>
#include <libndls.h>
#include <stdio.h>


#define s_SIZE                  0x4600

const size_t cpu_status_size = (15 * sizeof(uint16_t));

void write_save_state(uint8_t* saved_state_cpu_status_addr, uint8_t* saved_state_cpu_cpsr, void* state_ds_addr);

void write_save_state(uint8_t* saved_state_cpu_status_addr, uint8_t* saved_state_cpu_cpsr, void* state_ds_addr){
    size_t data_size = cpu_status_size + sizeof(uint8_t) + s_SIZE;
    uint8_t *data = malloc(data_size);
    uint8_t *data_start = data;


    memcpy(data, state_ds_addr, s_SIZE);
    data += s_SIZE;

    memcpy(data, saved_state_cpu_status_addr, cpu_status_size);
    data += cpu_status_size;

    memcpy(data, saved_state_cpu_cpsr, 1);

    FILE* savefile = fopen("/documents/ndless/test.tns", "wb");
    fwrite(data_start, data_size, 1, savefile);
    fclose(savefile);
}