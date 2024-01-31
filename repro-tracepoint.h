#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER naricc_test_provider

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./repro-tracepoint.h"

#if !defined(_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>
#include <wchar.h>

// Define the tracepoint event with a sequence text field
TRACEPOINT_EVENT(naricc_test_provider, test_event,
    TP_ARGS(
        const char*, utf8_text_value,
        const wchar_t*, wchar_text_value
    ),
    TP_FIELDS(
        ctf_sequence_text(char, utf8_text_sequence, utf8_text_value, size_t, strlen(utf8_text_value))
        ctf_sequence_text(char, wchar_text_sequence, wchar_text_value, size_t, wcslen((wchar_t*)wchar_text_value) * 2 + 2)
    )
)


/*
 * TRACEPOINT_EVENT(), TRACEPOINT_EVENT_CLASS(),
 * TRACEPOINT_EVENT_INSTANCE(), TRACEPOINT_LOGLEVEL(),
 * and `TRACEPOINT_ENUM()` are used here.
 */

#endif /* _TP_H */

#include <lttng/tracepoint-event.h>