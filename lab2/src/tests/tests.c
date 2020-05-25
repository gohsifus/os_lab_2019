//#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "revert_string.h"

void testRevertString(void) {
printf("%d\n",__LINE__);
  char simple_string[] = "Hello";
  char str_with_spaces[] = "String with spaces";
  char str_with_odd_chars_num[] = "abc";
  char str_with_even_chars_num[] = "abcd";

printf("%d\n",__LINE__);
  RevertString(simple_string);
  //CU_ASSERT_STRING_EQUAL_FATAL(simple_string, "olleH");
  assert(0==strcmp("olleH",simple_string));

printf("%d\n",__LINE__);
  RevertString(str_with_spaces);
  //CU_ASSERT_STRING_EQUAL_FATAL(str_with_spaces, "secaps htiw gnirtS");
  assert(0==strcmp("secaps htiw gnirtS",str_with_spaces));

printf("%d\n",__LINE__);
  RevertString(str_with_odd_chars_num);
  //CU_ASSERT_STRING_EQUAL_FATAL(str_with_odd_chars_num, "cba");
  assert(0==strcmp("cba",str_with_odd_chars_num));

printf("%d\n",__LINE__);
  RevertString(str_with_even_chars_num);
  //CU_ASSERT_STRING_EQUAL_FATAL(str_with_even_chars_num, "dcba");
  assert(0==strcmp("dcba",str_with_even_chars_num));
printf("%d\n",__LINE__);
printf("[OK]\n");
}

int main() {
    testRevertString();

return 0;
}
