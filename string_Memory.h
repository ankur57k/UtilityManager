#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* memory_Initialize(char *initialize,int start,int length)
{
	int total=0;
	total = length+start;
	initialize = (char *)realloc(initialize,(start+length+1)*sizeof(char));
        for(;start<=total;start++)
	{
		initialize[start] = '\0';
	}
	return initialize;
}

int string_Copy(char *destination,char *source)
{
	int length_Destination=0,start=0,length_Source=0,total=0;
	length_Destination = strlen(destination);
	length_Source = strlen(source);
	total = length_Destination + length_Source;
	while(start<length_Source)
	{
		destination[length_Destination] = source[start];
		length_Destination++;
		start++;
	}
	return 0;
}

int string_Cmp(char *string1,char* string2)
{
	int i1=0,i2=0,i=0;

	i1 = strlen(string1);
	i2 = strlen(string2);

	if(i1==i2)
	{
		while(string1[i]==string2[i])
			i++;

		if(i==i1)
			return(1);
		else
			return(0);
	}
	else
		return(0);
}

int string_Part_Cmp(char *string1,char *part)
{
	int i1=0,i2=0,i=0;

	i1 = strlen(string1);
	i2 = strlen(part);

	while((string1[i]==part[i])&&(i<i1)&&(i<i2))
		i++;

	if(i==i2)
		return(1);
	else
		return(0);
}

int memory_Int(char *source,int length)
{
	int i=0;

	for(i=0;i<length;i++)
		source[i] = '\0';

	return(0);
}
