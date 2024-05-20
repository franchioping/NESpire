#include <nspireio/nspireio.h>
#include <libndls.h>
#include <nspireio/platform-nspire.h>

void util_stuff(int argc, char **argv);


void util_stuff(int argc, char **argv){

    // init console
    nio_console console;
    nio_init(&console, NIO_MAX_COLS , NIO_MAX_ROWS, 0, 0, NIO_COLOR_BLACK, NIO_COLOR_WHITE, true);
    nio_set_default(&console);
    nio_printf("test\n");
    nio_printf("argc: %d\n", argc);
    for(int i = 0; i < argc; i++){
        nio_printf("arg %d: %s\n", i, argv[i]);
    }

    wait_key_pressed();
    return;
}


