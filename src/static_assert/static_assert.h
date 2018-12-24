/*-
 * Copyright (C) 2018, Zhenghui Zhou <zhouzhenghui@gmail.com> 
 */

#ifndef __STATIC_ASSERT_H
#define __STATIC_ASSERT_H

#include <stddef.h>

/**
 * @file
 * @brief Compile time assertion.
 */

/**
 * @brief assert a compile time dependency by static definition.
 * @param cond: the compile-time condition which must be true.
 * @param msg: a valid identifier which may be displayed as the error message.
 *
 * Your compile will fail if the condition isn't true, or can't be evaluated
 * by the compiler. It can be used out of functions.
 *
 * @see STATIC_ASSERT_OR_ZERO()
 *
 * @par Example:
 * @code
 *  #include <stddef.h>
 *    ...
 *  STATIC_ASSERT(offsetof(struct foo, string) == 0 \
 *            , string_should_be_first_member_of_struct_foo);
 * @endcode
 */
 /** @cond */
#define STATIC_ASSERT_CONCAT_1(x, y) x##y
#define STATIC_ASSERT_CONCAT(x, y) STATIC_ASSERT_CONCAT_1(x, y)
 /** @endcond */
#if defined(__COUNTER__) && __COUNTER__ != __COUNTER__
# define STATIC_ASSERT(cond, msg) \
    typedef struct { int STATIC_ASSERT_CONCAT(static_assertion_failed_, msg) : !!(cond); } \
      STATIC_ASSERT_CONCAT(static_assertion_failed_, __COUNTER__)
#else
# if defined(__GNUC__) && !defined(__cplusplus)
#   define STATIC_ASSERT_HELPER(cond, msg) \
      (!!sizeof(struct { unsigned int static_assertion_failed_##msg: (cond) ? 1 : -1; }))
#   define STATIC_ASSERT(cond, msg) \
      extern int (*assert_function__(void)) [STATIC_ASSERT_HELPER(cond, msg)]
# else
#   define STATIC_ASSERT(cond, msg) \
      extern char static_assertion_failed_##msg[1]; \
      extern char static_assertion_failed_##msg[(cond)?1:2]
# endif /* __GNUC__ */
#endif /* __COUNTER__ */

/**
 * @brief assert a compile time dependency, as a struct type.
 * @param cond: the compile-time condition which must be true.
 * @param msg: a valid identifier which may be displayed as the error message.
 *
 * Your compile will fail if the condition isn't true, or can't be evaluated
 * by the compiler.  Use it to define anything by yourself.
 *
 * @see STATIC_ASSERT_OR_ZERO()
 *
 * @par Example:
 * @code
 *  typedef ASSERT_ASSERT_OR_TYPE(offsetof(struct foo, string) == 0 \
 *                    , string_should_be_first_member_of_struct_foo) foo;
 * @endcode
 */
#define STATIC_ASSERT_OR_TYPE(cond, msg) \
  struct { int STATIC_ASSERT_CONCAT(static_assertion_failed_, msg) : !!(cond); }

/**
 * @brief assert a compile time dependency, as an expression.
 * @param cond: the compile-time condition which must be true.
 * @param msg: a valid identifier which may be displayed as the error message.
 *
 * Your compile will fail if the condition isn't true, or can't be evaluated
 * by the compiler.  This can be used in an expression: its value is "0".
 *
 * @see STATIC_ASSERT()
 * @see STATIC_ASSERT_OR_ZERO()
 *
 * @par Example:
 * @code
 *  (void)STATIC_ASSERT_OR_ZERO(offsetof(struct foo, string) == 0 \
 *                  , string_should_be_first_member_of_struct_foo);
 * @endcode
 * or
 * @code
 *  #define foo_to_char(foo) \
 *         ((char *)(foo) \
 *          + STATIC_ASSERT_OR_ZERO(offsetof(struct foo, string) == 0) \
 *                , string_should_be_first_member_of_struct_foo)
 *  @endcode
 */
#if defined(__cplusplus) && (!defined(__GNUC__) || __GNUC__ >= 6 || defined(__clang__))
/** @cond */
  namespace {
    template <class T, int N> struct __StaticAssert;
    template <class T> struct __StaticAssert<T, 0> {
      enum { value = 0 };  
    };
  }
/** @endcond */
# define STATIC_ASSERT_OR_ZERO(cond, msg) \
    (__StaticAssert<class msg, !(cond)>::value)
#else
# define STATIC_ASSERT_OR_ZERO(cond, msg) \
    offsetof(struct { int _1; STATIC_ASSERT_OR_TYPE(cond, msg) _2; }, _1)
#endif

#endif /* __STATIC_ASSERT_H */
