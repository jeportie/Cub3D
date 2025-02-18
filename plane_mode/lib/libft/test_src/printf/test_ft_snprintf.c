#include <check.h>
#include "../../include/libft.h"
#include "../../../libgc/include/libgc.h"

static t_gc *gcl;

void setup(void)
{
    gcl = gc_init();
    if (!gcl)
    {
        perror("gc_init");
        exit(EXIT_FAILURE);
    }
}

void teardown(void)
{
    gc_cleanup(gcl);
    free(gcl);
}

START_TEST(test_simple)
{
    char    str_mock[256];
    int     int_mock;
    char    libc_result[256];
    char    libft_result[256];


    snprintf(libc_result, sizeof(libc_result), "This is a test without args");
    ft_snprintf(libft_result, sizeof(libft_result), "This is a test without args");

    ck_assert_str_eq(libc_result, libft_result);
}
END_TEST

/* Test empty format string */
START_TEST(test_empty_format)
{
    char libc_result[10];
    char libft_result[10];

    snprintf(libc_result, sizeof(libc_result), "");
    ft_snprintf(libft_result, sizeof(libft_result), "");
    ck_assert_str_eq(libc_result, libft_result);
}
END_TEST

/* Test with exact buffer size (no space for '\0') */
START_TEST(test_exact_size)
{
    char libc_result[6];
    char libft_result[6];
    int ret_libc = snprintf(libc_result, 6, "Hello");
    int ret_libft = ft_snprintf(libft_result, 6, "Hello");

    // Should write "Hello" + '\0' => total 6 chars. Fits exactly.
    ck_assert_int_eq(ret_libc, ret_libft);
    ck_assert_str_eq(libc_result, libft_result);
}
END_TEST

/* Test truncation */
START_TEST(test_truncation)
{
    char libc_result[6];
    char libft_result[6];
    int ret_libc = snprintf(libc_result, 6, "Hello World!");
    int ret_libft = ft_snprintf(libft_result, 6, "Hello World!");

    // "Hello World!" is 12 chars. With size=6, we store "Hello" + '\0'.
    ck_assert_str_eq(libc_result, libft_result);
    // Check the return values for truncated output (should be the full length)
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

/* Test various format specifiers */
START_TEST(test_various_specifiers)
{
    char libc_result[256];
    char libft_result[256];
    int ret_libc = snprintf(libc_result, sizeof(libc_result), 
                            "Int:%d Char:%c Str:%s Hex:%x Pointer:%p",
                            42, 'A', "Test", 255, (void*)0x1234);
    int ret_libft = ft_snprintf(libft_result, sizeof(libft_result), 
                                "Int:%d Char:%c Str:%s Hex:%x Pointer:%p",
                                42, 'A', "Test", 255, (void*)0x1234);
    ck_assert_str_eq(libc_result, libft_result);
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

/* Test NULL string pointer */
START_TEST(test_null_string)
{
    char libc_result[256];
    char libft_result[256];
    char *null_str = NULL;

    int ret_libc = snprintf(libc_result, sizeof(libc_result), "Null str: %s", null_str);
    int ret_libft = ft_snprintf(libft_result, sizeof(libft_result), "Null str: %s", null_str);

    ck_assert_str_eq(libc_result, libft_result);
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

/* Test NULL pointer for %p */
START_TEST(test_null_pointer)
{
    char libc_result[256];
    char libft_result[256];
    void *ptr = NULL;

    int ret_libc = snprintf(libc_result, sizeof(libc_result), "Pointer: %p", ptr);
    int ret_libft = ft_snprintf(libft_result, sizeof(libft_result), "Pointer: %p", ptr);

    ck_assert_str_eq(libc_result, libft_result);
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

/* Test very large number (INT_MAX, INT_MIN) */
START_TEST(test_large_numbers)
{
    char libc_result[256];
    char libft_result[256];
    int ret_libc = snprintf(libc_result, sizeof(libc_result), 
                            "Max:%d Min:%d", INT_MAX, INT_MIN);
    int ret_libft = ft_snprintf(libft_result, sizeof(libft_result), 
                                "Max:%d Min:%d", INT_MAX, INT_MIN);

    ck_assert_str_eq(libc_result, libft_result);
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

/* Test literal percent sign */
START_TEST(test_percent_sign)
{
    char libc_result[256];
    char libft_result[256];
    int ret_libc = snprintf(libc_result, sizeof(libc_result),
                            "100%% completion");
    int ret_libft = ft_snprintf(libft_result, sizeof(libft_result),
                                "100%% completion");

    ck_assert_str_eq(libc_result, libft_result);
    ck_assert_int_eq(ret_libc, ret_libft);
}
END_TEST

Suite *name_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("NAME");
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);

    // Existing test
    tcase_add_test(tc_core, test_simple);
    
    // New tests
    tcase_add_test(tc_core, test_empty_format);
    tcase_add_test(tc_core, test_exact_size);
    tcase_add_test(tc_core, test_truncation);
    tcase_add_test(tc_core, test_various_specifiers);
    tcase_add_test(tc_core, test_null_string);
    tcase_add_test(tc_core, test_null_pointer);
    tcase_add_test(tc_core, test_large_numbers);
    tcase_add_test(tc_core, test_percent_sign);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;   // Track number of failed tests
    Suite *name;         // Suite object
    SRunner *name_r;     // Test suite runner

    name = name_suite();
    name_r = srunner_create(name);

    srunner_run_all(name_r, CK_NORMAL); 

    number_failed = srunner_ntests_failed(name_r);
    srunner_free(name_r);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

/* 
 * ####################### USEFUL TIPS #######################
 * 
 * 1. **Modularize Your Tests**:
 *    - Divide test cases logically into suites and test functions.
 *    - Each test should focus on a single functionality or edge case.
 * 
 * 2. **Use Fixtures for Reusability**:
 *    - Use `setup` and `teardown` for initializing and cleaning up shared resources.
 * 
 * 3. **Custom Assertions**:
 *    - Implement helper functions for complex custom assertions to simplify test logic.
 * 
 * 4. **CI/CD Integration**:
 *    - Ensure the test suite is compatible with automated pipelines.
 *    - Use `CK_VERBOSE` for debugging failures in CI environments.
 * 
 * 5. **Memory Management**:
 *    - Always clean up resources in `teardown` to avoid memory leaks during repeated test runs.
 * 
 * 6. **Test Edge Cases**:
 *    - Include edge cases, invalid inputs, and extreme values in your test cases.
 * 
 * 7. **Error Logs**:
 *    - Use `srunner_set_log()` to log test results for debugging.
 * 
 * 8. **Tags for Selective Runs**:
 *    - Use `tcase_set_tags()` and `srunner_run_tagged()` for large projects to selectively run tests.
 * 
 * 9. **Debugging Failures**:
 *    - For persistent test failures, use debugging tools like `gdb` with verbose output.
 * 
 * 10. **Code Coverage**:
 *     - Ensure your tests cover all branches and conditions in your code.
 * 
 * ######################## CHECK FUNCTIONS ########################

## ck_assert functions in the Check framework:
|-------------------------------|---------------------------------------------|
| **Function**                  | **Description -> Check if ...**             |
|-------------------------------|---------------------------------------------|
|ck_assert(expr)                |the expression expr is true (non-zero).      |
|ck_assert_msg(expr, ...)       |expr is true, with message on failure.       |
|ck_assert_int_eq(val1, val2)   |two integers are equal.                      |
|ck_assert_int_ne(val1, val2)   |two integers are not equal.                  |
|ck_assert_int_lt(val1, val2)   |val1 is less than  al2.                      |
|ck_assert_int_le(val1, val2)   |val1 is less than or equal to `val2`.        |
|ck_assert_int_gt(val1, val2)   |val1 is greater than `val2`.                 |
|ck_assert_int_ge(val1, val2)   |val1 is greater than or equal to `val2`.     |
|ck_assert_float_eq(val1, val2) |two floats are equal.                        |
|ck_assert_float_ne(val1, val2) |two floats are not equal.                    |
|ck_assert_float_lt(val1, val2) |val1 is less than `val2`.                    |
|ck_assert_float_le(val1, val2) |val1 is less than or equal to `val2`.        |
|ck_assert_float_gt(val1, val2) |val1 is greater than val2.                   |
|ck_assert_float_ge(val1, val2) |val1 is greater than or equal to val2.       |
|ck_assert_ptr_eq(ptr1, ptr2)   |two pointers are equal.                      |
|ck_assert_ptr_ne(ptr1, ptr2)   |two pointers are not equal.                  |
|ck_assert_str_eq(str1, str2)   |two strings are equal.                       |
|ck_assert_str_ne(str1, str2)   |two strings are not equal.                   |
|ck_assert_str_lt(str1, str2)   |str1 is less than str2.                      |
|ck_assert_str_le(str1, str2)   |str1 is less than or equal to str2.          |
|ck_assert_str_gt(str1, str2)   |str1 is greater than str2.                   |
|ck_assert_str_ge(str1, str2)   |str1 is greater than or equal to str2.       |
|ck_assert_mem_eq(ptr1, ptr2, n)|two memory regions are equal for n bytes.    |
|ck_assert_mem_ne(ptr1, ptr2, n)|two memory regions are not equal for n bytes.|
|-------------------------------|---------------------------------------------|

### Suite Management

|-----------------------------------------------------|----------------------------------------------|
| **Function**                                        | **Description**                              |
|-----------------------------------------------------|----------------------------------------------|
|Suite *suite_create(const char *name)                | Creates a new test suite with the given name.|
|void suite_add_tcase(Suite *suite, TCase *tcase)     | Adds a test case to a test suite.            |
|Suite *suite_create_full(const char *name, TCase *tc)| Creates a full suite with a single test case.|
|-----------------------------------------------------|----------------------------------------------|

### Test Case Management

|-----------------------------------------------------|---------------------------------------------|
| **Function**                                        | **Description**                             |
|-----------------------------------------------------|---------------------------------------------|
|TCase *tcase_create(const char *name)                | Creates a new test case with the given name.|
|void tcase_add_test(TCase *tc, TFun test_function)   | Adds a test function to a test case.        |
|void tcase_add_loop_test(TCase *tc,                  | Adds a looping test to a test case,         |
|           TFun test_function, int start, int end)   | running the function multiple times.        |
|void tcase_set_timeout(TCase *tc, double timeout)    | Sets a timeout for a test case.             |
|void tcase_add_checked_fixture(TCase *tc,            | Adds setup and teardown functions.          |
|void (*setup)(void), void (*teardown)(void))         | Adds setup and teardown functions.          |
|-----------------------------------------------------|---------------------------------------------|

### Test Runner Management

|--------------------------------------------------------------|-----------------------------------------------------------|
| **Function**                                                 | **Description**                                           |
|--------------------------------------------------------------|-----------------------------------------------------------|
|SRunner *srunner_create(Suite *suite)                         | Creates a new test suite runner.                          |
|void srunner_add_suite(SRunner *runner, Suite *suite)         | Adds a suite to a suite runner.                           |
|void srunner_run_all(SRunner *runner, enum print_output)      | Runs all test cases in all suites managed by the runner.  |
|void srunner_run_tagged(SRunner *runner,                      | Runs only tests tagged with a specific label.             |
|         enum print_output, const char *tag)                  | Runs only tests tagged with a specific label.             |
|int srunner_ntests_failed(SRunner *runner)                    | Returns the number of tests that failed.                  |
|void srunner_free(SRunner *runner)                            | Frees the memory allocated to the suite runner.           |
|void srunner_set_log(SRunner *runner, const char *logfile)    | Specifies a file to log test results.                     |
|void srunner_set_tap(SRunner *runner, const char *tapfile)    | Specifies a file for TAP (Test Anything Protocol) results.|
|void srunner_set_fork_status(SRunner *runner, int fork_status)| Sets forking mode: `CK_FORK` or `CK_NOFORK`.              |
|void srunner_set_xml(SRunner *runner, const char *xmlfile)    | Specifies a file to output test results in XML format.    |
|void srunner_print(SRunner *runner,                           | Prints test results directly to the console               |
|        enum print_output)                                    | with the specified verbosity.                             |
|--------------------------------------------------------------|-----------------------------------------------------------|
*/
