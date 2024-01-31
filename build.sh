g++ -c -I. repro-tracepoint.cpp
g++ -c lttng-test.cpp
g++ -o lttng-test lttng-test.o repro-tracepoint.o -llttng-ust -ldl
