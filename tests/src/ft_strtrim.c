#include "config.h"

#define STRTRIM_STR "      Test string     "
#define STRTRIM_SET " T"
#define STRTRIM_TRIMMED "est string"

Test(ft_strtrim, returns_trimmed_string)
{
	char	*trimmed;
	
	trimmed = ft_strtrim(STRTRIM_STR, STRTRIM_SET);
	cr_expect(zero(int, strcmp(trimmed, STRTRIM_TRIMMED)),
		"ft_strtrim: string not trimmed correctly (expected %s got %s)",
		STRTRIM_TRIMMED, trimmed);
	free(trimmed);
}

Test(ft_strtrim, returns_copy_of_string_when_no_character_to_trim)
{
	char	*trimmed;

	trimmed = ft_strtrim(STRTRIM_STR, "ABC");
	cr_expect(zero(int, strcmp(trimmed, STRTRIM_STR)),
		"ft_strtrim: expected to get a copy of original string");
	free(trimmed);
}

Test(ft_strtrim, returns_empty_string_when_all_characters_are_trimmed)
{
	char	*trimmed;

	trimmed = ft_strtrim(STRTRIM_STR, STR);
	cr_expect(zero(int, strcmp(trimmed, "")),
		"ft_strtrim: expected to return an empty string \
		after trimming every character");
	free(trimmed);
}
