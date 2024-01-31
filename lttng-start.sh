lttng-sessiond --daemonize
lttng list --userspace
lttng create my-user-space-session
lttng enable-event --userspace naricc_test_provider:test_event

lttng start
