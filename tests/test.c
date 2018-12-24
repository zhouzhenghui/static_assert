#include "static_assert/static_assert.h"

struct foo {
  char *string;
  int size;
};

STATIC_ASSERT(offsetof(struct foo, string) == 0, string_should_be_first_member_of_struct_foo);
typedef STATIC_ASSERT_OR_TYPE(offsetof(struct foo, string) == 0, string_should_be_first_member_of_struct_foo) foo_type;
STATIC_ASSERT(STATIC_ASSERT_OR_ZERO(offsetof(struct foo, string) == 0, string_should_be_first_member_of_struct_foo) == 0, STATIC_ASSERT_OR_ZERO_should_equal_zero);
STATIC_ASSERT(0, THIS_ERROR_MESSAGE_TELLS_THAT_ALL_TESTS_ARE_SUCCESSFUL);
