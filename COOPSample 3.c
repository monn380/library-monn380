//
//  main.c
//  some namespace class
//
//  Created by Shvabrik Rr on 19.11.2026.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdatomic.h>

#pragma mark Class internal variables

typedef struct
{
	atomic_uint ref_count;
	
	char *string;
} sn_class; // sn means some namespace

#pragma mark Methods

// allocation and initialization
sn_class *sn_class_create(void)
{
	sn_class *class = malloc(sizeof(sn_class));
	
	if (!class)
	{
		return NULL;
	}
	
	atomic_init(&class->ref_count, 1);
	class->string = strdup("be");
	
	if (!(class->string))
	{
		return NULL;
	}
	
	return class;
};

// memory managmend based on reference counter
sn_class *sn_class_retain(sn_class *class)
{
	if(class)
	{
		atomic_fetch_add(&class->ref_count, 1);
	}
	return class;
}

void sn_class_release(sn_class *class)
{
	if(!class)
	{
		return;
	}
	
	if(atomic_fetch_sub(&class->ref_count, 1) == 1)
	{
		free(class->string);
		free(class);
	}
	
	return;
}

// get & set property method
char *sn_class_get_string(sn_class *class)
{
	return class->string;
}

void sn_class_set_string(sn_class *class, char *newString)
{
	if(class && newString)
	{
		free(class->string);
		(class)->string = strdup(newString);
	}
	
	return;
}

// other methods
void sn_class_say_string(sn_class *class)
{
	printf("%s!\n", class->string);
}

#pragma mark Main

int main(int argc, const char * argv[]) {
	// insert code here...
	sn_class *class = sn_class_create();
	
	sn_class_say_string(class);
	
	sn_class_release(class);
	
	return 0;
}
