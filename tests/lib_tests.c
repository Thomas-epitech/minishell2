/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** lib tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "my.h"

static void redirect_all_stdout(void)
{
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(is_digit, with_digit_chars)
{
    cr_assert(is_digit('0'));
    cr_assert(is_digit('1'));
    cr_assert(is_digit('2'));
    cr_assert(is_digit('3'));
    cr_assert(is_digit('4'));
    cr_assert(is_digit('5'));
    cr_assert(is_digit('6'));
    cr_assert(is_digit('7'));
    cr_assert(is_digit('8'));
    cr_assert(is_digit('9'));
}

Test(is_digit, with_non_digit_chars)
{
    cr_assert_not(is_digit('a'));
    cr_assert_not(is_digit('p'));
    cr_assert_not(is_digit('"'));
    cr_assert_not(is_digit(3));
}

Test(is_digit, with_lowercase_letters)
{
    for (int l = 'a'; l <= 'z'; l++)
        cr_assert(is_letter(l));
}

Test(is_digit, with_uppercase_letters)
{
    for (int l = 'A'; l <= 'Z'; l++)
        cr_assert(is_letter(l));
}

Test(is_digit, random_non_letter_char)
{
    cr_assert_not(is_letter('4'));
    cr_assert_not(is_letter('"'));
    cr_assert_not(is_letter(2));
    cr_assert_not(is_letter('='));
    cr_assert_not(is_letter('#'));
}

TestSuite(mini_printf, .init = redirect_all_stdout);

Test(mini_printf, simple_string1)
{
    mini_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(mini_printf, one_formatted_int2)
{
    mini_printf("three: %d", 3);
    cr_assert_stdout_eq_str("three: 3");
}

Test(mini_printf, one_formatted_int3)
{
   mini_printf("There are %d letters in the alphabet.", 26);
   cr_assert_stdout_eq_str("There are 26 letters in the alphabet.");
}

Test(mini_printf, one_formatted_char4)
{
    mini_printf("%c is my favorite letter!", 't');
    cr_assert_stdout_eq_str("t is my favorite letter!");
}

Test(mini_printf, one_formatted_string5)
{
    mini_printf("My name is %s", "John");
    cr_assert_stdout_eq_str("My name is John");
}

Test(mini_printf, one_formatted_char_and_string6)
{
    mini_printf("%c is the best %s of the alphabet.", 'k', "letter");
    cr_assert_stdout_eq_str("k is the best letter of the alphabet.");
}

Test(mini_printf, formatted_char_and_int7)
{
    mini_printf("In the word \"taramasalata\", there are %d %c.", 6, 'a');
    cr_assert_stdout_eq_str("In the word \"taramasalata\", there are 6 a.");
}

Test(mini_printf, one_formatted_str_and_int8)
{
    mini_printf("There are %d vowels in the word \"%s\".", 4, "queue");
    cr_assert_stdout_eq_str("There are 4 vowels in the word \"queue\".");
}

Test(mini_printf, one_formatted_str_char_and_int9)
{
    mini_printf("%c is the %dth letter of the %s.", 'o', 15, "alphabet");
    cr_assert_stdout_eq_str("o is the 15th letter of the alphabet.");
}

Test(mini_printf, formatted_percentage10)
{
    mini_printf("%d%% of people are %s handed.", 11, "left");
    cr_assert_stdout_eq_str("11% of people are left handed.");
}

Test(mini_printf, multiple_formatted_percentage11)
{
    mini_printf("%%%%%%");
    cr_assert_stdout_eq_str("%%%");
}

Test(mini_printf, return_regular_string12)
{
   cr_assert_eq(mini_printf("Hello world!"), 12);
}

Test(mini_printf, return_formatted_char13)
{
    cr_assert_eq(mini_printf("I love the letter %c", 'x'), 19);
}

Test(mini_printf, return_formatted_int14)
{
    cr_assert_eq(mini_printf("The Hawaiian alphabet only has %d letters", 13), 41);
}

Test(mini_printf, return_formatted_int_15)
{
    cr_assert_eq(mini_printf("The Hawaiian alphabet only has %i letters", 13), 41);
}

Test(mini_printf, return_formatted_string16)
{
    cr_assert_eq(mini_printf("i hate %s", "mondays"), 14);
}

Test(mini_printf, return_formatted_percentage17)
{
    cr_assert_eq(mini_printf("8%% of people have an extra rib."), 31);
}

Test(mini_printf, return_formatted_char_only18)
{
    cr_assert_eq(mini_printf("%c", 'f'), 1);
}

Test(mini_printf, return_formatted_int_only19)
{
    cr_assert_eq(mini_printf("%d", 5318), 4);
}

Test(mini_printf, return_formatted_int_only20)
{
    cr_assert_eq(mini_printf("%i", 4781548), 7);
}

Test(mini_printf, return_formatted_string_only21)
{
   cr_assert_eq(mini_printf("%s", "onion"), 5);
}

Test(mini_printf, return_formatted_percentage_only22)
{
    cr_assert_eq(mini_printf("%%"), 1);
}

Test(my_getnbr, basic_positive) {
    cr_assert_eq(my_getnbr("123"), 123);
}

Test(my_getnbr, basic_negative) {
    cr_assert_eq(my_getnbr("-123"), -123);
}

Test(my_getnbr, begin_with_plus) {
    cr_assert_eq(my_getnbr("+42"), 42);
}

Test(my_getnbr, multiple_signs) {
    cr_assert_eq(my_getnbr("--42"), 42);
    cr_assert_eq(my_getnbr("-+42"), -42);
    cr_assert_eq(my_getnbr("+-42"), -42);
}

Test(my_getnbr, ends_with_non_digits) {
    cr_assert_eq(my_getnbr("42abc"), 42);
    cr_assert_eq(my_getnbr("-99xyz"), -99);
}

Test(my_getnbr, single_sign) {
    cr_assert_eq(my_getnbr("+"), 0);
    cr_assert_eq(my_getnbr("-"), 0);
}

Test(my_getnbr, empty_string) {
    cr_assert_eq(my_getnbr(""), 0);
}

Test(my_getnbr, only_non_digits) {
    cr_assert_eq(my_getnbr("abc"), 0);
    cr_assert_eq(my_getnbr("-abc"), 0);
}

Test(my_intlen, basic_tests)
{
    cr_assert_eq(my_intlen(5432), 4);
    cr_assert_eq(my_intlen(54253543), 8);
    cr_assert_eq(my_intlen(2), 1);
}

Test(my_intlen, zero)
{
    cr_assert_eq(my_intlen(0), 1);
}

Test(my_intlen, largest_int)
{
    cr_assert_eq(my_intlen(2147483647), 10);
}

Test(my_itoa, regular_int)
{
    cr_assert_str_eq(my_itoa(4324), "4324");
}

Test(my_perror, regular_message_with_no_line_break, .init=redirect_all_stdout)
{
    my_perror("message", "error", false);
    cr_assert_stderr_eq_str("message: error.");
}

Test(my_perror, regular_message_with_line_break, .init=redirect_all_stdout)
{
    my_perror("message", "error", true);
    cr_assert_stderr_eq_str("message: error.\n");
}
