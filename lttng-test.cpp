#include <stdio.h>
#include <unistd.h>
#include <lttng/lttng.h>
#include <lttng/tracepoint.h>
#include <wchar.h>
#include "repro-tracepoint.h"



int main() {
    puts("Hello, World!\nPress Enter to continue...");
    getchar();

    const char* utf8_text_value = "Hello, UTF8 Sequence Text!";
    const wchar_t *wchar_text_value = L"Hello, WChar Sequence Text!";

    // Emit the tracepoint event with the sequence text field
    lttng_ust_tracepoint(naricc_test_provider, test_event, utf8_text_value, wchar_text_value);

    // Disable the event and destroy the session

    return 0;
}
