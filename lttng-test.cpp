#include <stdio.h>
#include <unistd.h>
#include <lttng/lttng.h>
#include <lttng/tracepoint.h>
#include <wchar.h>
#include "repro-tracepoint.h"



int main() {
    puts("Hello, World!\nPress Enter to continue...");
    getchar();


    const wchar_t *text_value = L"Hello, Sequence Text!";
    size_t text_length = wcslen(text_value);


    // Emit the tracepoint event with the sequence text field
    lttng_ust_tracepoint(naricc_test_provider, test_event, (char*)text_value);

    // Disable the event and destroy the session

    return 0;
}
