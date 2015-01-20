/* test.h */
/* $Id: test.h 1098 2006-06-18 14:35:41Z stsp $ */


void test_process_init(int fd, int client_p, void *apparg);
#define TLS_APP_PROCESS_INIT test_process_init

#undef TLS_CUMULATE_ERRORS

void test_errflush(int child_p, char *errbuf, size_t num, void *apparg);
#define TLS_APP_ERRFLUSH test_errflush
