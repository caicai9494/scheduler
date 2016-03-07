#ifndef LZ_ERROR_H
#define LZ_ERROR_H

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <string>

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

template <typename T>
void DBG_(const T& t) 
{
    std::cout << t;
}

#define DBG(var) \
    do {\
	std::cout << "[" #var ": \n";\
	DBG_(var);\
	std::cout << "]\n"; \
    } while(0)\

#define ASSERT_EQ(lhs, rhs) \
    if (lhs != rhs) { \
	printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
	printf(#lhs " != " #rhs "\n"); \
	exit(EXIT_FAILURE); \
    } \

#define ASSERT_TRUE(condition) \
    if (!(condition)) { \
	printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
	printf(#condition "\n"); \
	exit(EXIT_FAILURE); \
    } \

//TODO:not working yet
#define ASSERT_DEATH(code,msg) \
    do {\
	int ret;\
	int status;\
	if ((ret = fork()) > 0) {\
	    code;\
	}\
	else if (ret == 0) {\
	    if (waitpid(-1, &status, 0) > 0) {\
		if (WIFEXITED(status)) {\
		    printf("Assertion Fail at %s:line %d\n", __FILE__, __LINE__); \
		    printf(msg); \
		    exit(EXIT_FAILURE); \
		}\
	    }\
	    else {\
	    }\
	}\
	else {\
	}\
    } while (0)

#endif
