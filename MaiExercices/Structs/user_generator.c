#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct user_group
{
	const char		*group_name;
	const int group_uid : 7;
}					group;

typedef struct user_data
{
	unsigned int	uid;
	group			*list;
	char			name[];
}					user;

user	*user_generator(const char *name, group *groups, const int uid)
{
	user	*employee;
	size_t	name_len;

	if (name == NULL)
		return (NULL);
	name_len = strlen(name) + 1;
	employee = malloc(sizeof(user) + name_len);
	if (!employee)
		return (NULL);
	strcpy(employee->name, name);
	employee->uid = uid;
	employee->list = groups;
	return (employee);
}

int	main(void)
{
	group group_list[5] = {[0] = {.group_name = "Sales", .group_uid = 1},
		[1] = {.group_name = "Engineering", .group_uid = 2},
		[2] = {.group_name = "Marketing", .group_uid = 3},
		[3] = {.group_name = "Management", .group_uid = 4},
		[4] = {.group_name = NULL, .group_uid = 0}};
	user *john;
	puts("This is our first user!");
	john = user_generator("John", group_list, 5);
	printf("Name:\t%s\n", john->name);
	printf("UID:\t%d\n", john->uid);
	puts("Groups:");
	group *group_list_ptr = NULL;
	group_list_ptr = group_list;
	while (group_list_ptr->group_name != NULL)
	{
		printf("\t%s :\t%d\n", group_list_ptr->group_name,
			group_list_ptr->group_uid);
		group_list_ptr++;
	}
	free(john);
	return (0);
}