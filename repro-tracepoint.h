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
        char*, text_value
    ),
    TP_FIELDS(
        ctf_sequence_text(char, text_sequence, text_value, size_t, wcslen((wchar_t*)text_value) * 2 + 2)
    )
)


/*
 * TRACEPOINT_EVENT(), TRACEPOINT_EVENT_CLASS(),
 * TRACEPOINT_EVENT_INSTANCE(), TRACEPOINT_LOGLEVEL(),
 * and `TRACEPOINT_ENUM()` are used here.
 */

#endif /* _TP_H */

#include <lttng/tracepoint-event.h>